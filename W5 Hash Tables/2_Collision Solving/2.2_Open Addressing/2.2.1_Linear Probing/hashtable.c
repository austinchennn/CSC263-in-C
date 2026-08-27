#include "hashtable.h"
#include <stdlib.h>
#include <assert.h>

/**
 * @brief 创建含 m 个 slot 的空表（全部 EMPTY）。
 */
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
 * @brief Linear Probing：probe(k, i) = (h(k) + i) mod m。
 */
int probe(const HashTable *ht, int key, int i) {
    return (h(ht, key) + i) % ht->m;
}

/**
 * @brief 插入或更新 key。
 *        沿探测序列走：命中同 key 则覆盖 value；记录第一个 DELETED 以便复用；
 *        遇到 EMPTY 说明 key 一定不在表中，此时放到「第一个 DELETED」或这个 EMPTY。
 * @return 成功 true；表满且没有可复用的 DELETED 返回 false。
 */
bool hashInsert(HashTable *ht, int key, int value) {
    int first_deleted = -1;

    for (int i = 0; i < ht->m; i++) {
        int s = probe(ht, key, i);

        if (ht->T[s].state == OCCUPIED) {
            if (ht->T[s].key == key) {
                ht->T[s].value = value;   /* 已存在：更新 */
                return true;
            }
        } else if (ht->T[s].state == DELETED) {
            if (first_deleted < 0) first_deleted = s;
        } else { /* EMPTY：探测链到头，key 不在表中 */
            int pos = (first_deleted >= 0) ? first_deleted : s;
            ht->T[pos].state = OCCUPIED;
            ht->T[pos].key = key;
            ht->T[pos].value = value;
            ht->n++;
            return true;
        }
    }

    /* 走完全部 m 个 slot 都没遇到 EMPTY */
    if (first_deleted >= 0) {
        ht->T[first_deleted].state = OCCUPIED;
        ht->T[first_deleted].key = key;
        ht->T[first_deleted].value = value;
        ht->n++;
        return true;
    }
    return false;   /* 表满 */
}

/**
 * @brief 查找 key。遇到 EMPTY 即停（返回未命中）；DELETED 要跳过继续。
 * @return 命中的 slot 下标，未命中 -1。
 */
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

/**
 * @brief 删除 key：标记为 DELETED（tombstone），不能置 EMPTY，否则会截断探测链。
 */
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
