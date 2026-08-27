#include "hashtable.h"
#include <stdlib.h>
#include <assert.h>

HashTable *createHashTable(int m) {
    assert(m > 0);
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

/* h(k) = k mod m，修正负数 */
static int h(const HashTable *ht, int key) {
    int r = key % ht->m;
    if (r < 0) r += ht->m;
    return r;
}

/**
 * @brief Quadratic Probing：probe(k, i) = (h(k) + i²) mod m。
 * @note i*i 先对 m 取模，避免 i 较大时 i*i 溢出。
 */
int probe(const HashTable *ht, int key, int i) {
    long off = ((long)i * i) % ht->m;
    return (int)((h(ht, key) + off) % ht->m);
}

/**
 * @brief 插入或更新 key（逻辑与 Linear Probing 版完全一致，只是 probe 不同）。
 * @return 成功 true；找不到可用 slot 返回 false
 *         （m 素数且 α < 1/2 时不会发生）。
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
