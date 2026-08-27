#include "hashtable.h"
#include <stdlib.h>
#include <assert.h>

HashTable *createHashTable(int m) {
    assert(m > 1);   /* h2 用到 m-1 作模数 */
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->T = (Slot *)malloc(sizeof(Slot) * (size_t)m);
    for (int i = 0; i < m; i++) ht->T[i].state = EMPTY;
    ht->m = m;
    ht->n = 0;
    return ht;
}

void freeHashTable(HashTable *ht) {
    if (ht == NULL) return;
    free(ht->T);
    free(ht);
}

/* h1(k) = k mod m */
static int h1(const HashTable *ht, int key) {
    int r = key % ht->m;
    if (r < 0) r += ht->m;
    return r;
}

/* h2(k) = 1 + (k mod (m-1))，落在 [1, m-1]；m 素数时与 m 互质、且非 0 */
static int h2(const HashTable *ht, int key) {
    int r = key % (ht->m - 1);
    if (r < 0) r += (ht->m - 1);
    return 1 + r;
}

/**
 * @brief Double Hashing：probe(k, i) = (h1(k) + i * h2(k)) mod m。
 */
int probe(const HashTable *ht, int key, int i) {
    long off = ((long)i * h2(ht, key)) % ht->m;
    return (int)((h1(ht, key) + off) % ht->m);
}

/**
 * @brief 插入或更新 key（逻辑与 Linear / Quadratic 版一致，只是 probe 不同）。
 * @return 成功 true；表满返回 false。
 *         m 素数时 gcd(h2, m) = 1，探测序列遍历所有 slot，表没满必成功。
 */
bool hashInsert(HashTable *ht, int key, int value) {
    int first_deleted = -1;

    for (int i = 0; i < ht->m; i++) {
        int s = probe(ht, key, i);

        if (ht->T[s].state == OCCUPIED) {
            if (ht->T[s].key == key) {
                ht->T[s].value = value;
                return true;
            }
        } else if (ht->T[s].state == DELETED) {
            if (first_deleted < 0) first_deleted = s;
        } else { /* EMPTY */
            int pos = (first_deleted >= 0) ? first_deleted : s;
            ht->T[pos].state = OCCUPIED;
            ht->T[pos].key = key;
            ht->T[pos].value = value;
            ht->n++;
            return true;
        }
    }

    if (first_deleted >= 0) {
        ht->T[first_deleted].state = OCCUPIED;
        ht->T[first_deleted].key = key;
        ht->T[first_deleted].value = value;
        ht->n++;
        return true;
    }
    return false;
}

int hashSearch(const HashTable *ht, int key, int *value_out) {
    for (int i = 0; i < ht->m; i++) {
        int s = probe(ht, key, i);
        if (ht->T[s].state == EMPTY) return -1;
        if (ht->T[s].state == OCCUPIED && ht->T[s].key == key) {
            if (value_out != NULL) *value_out = ht->T[s].value;
            return s;
        }
    }
    return -1;
}

bool hashDelete(HashTable *ht, int key) {
    int s = hashSearch(ht, key, NULL);
    if (s < 0) return false;
    ht->T[s].state = DELETED;
    ht->n--;
    return true;
}

double loadFactor(const HashTable *ht) {
    return (double)ht->n / (double)ht->m;
}
