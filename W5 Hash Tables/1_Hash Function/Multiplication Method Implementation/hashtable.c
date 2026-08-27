#include "hashtable.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/* Knuth 建议的常数 A = (sqrt(5) - 1) / 2 */
static const double A = 0.6180339887498949;

/**
 * @brief 创建一个含 m 个 bucket 的空哈希表。
 * @param m bucket 数量；乘法散列对 m 不敏感，取 2 的幂也可以。
 */
HashTable *createHashTable(int m) {
    assert(m > 0);
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->T = (HashNode **)calloc((size_t)m, sizeof(HashNode *));
    ht->m = m;
    ht->n = 0;
    return ht;
}

/**
 * @brief 释放哈希表及其所有链表节点。
 */
void freeHashTable(HashTable *ht) {
    if (ht == NULL) return;
    for (int i = 0; i < ht->m; i++) {
        HashNode *cur = ht->T[i];
        while (cur != NULL) {
            HashNode *next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(ht->T);
    free(ht);
}

/**
 * @brief Multiplication Method：h(k) = floor(m * frac(k * A))。
 *        frac(y) = y - floor(y) 取小数部分；floor 向负无穷取整，
 *        所以即使 key 为负，结果也落在 [0, 1)，无需额外修正。
 */
int hashMultiplication(const HashTable *ht, int key) {
    double product = (double)key * A;
    double x = product - floor(product);   /* 小数部分，范围 [0, 1) */
    int i = (int)(ht->m * x);
    if (i == ht->m) i = ht->m - 1;         /* 浮点边界兜底 */
    return i;
}

/**
 * @brief 插入 key-value 对（Chaining，头插；已存在则覆盖 value）。
 */
void hashInsert(HashTable *ht, int key, int value) {
    int i = hashMultiplication(ht, key);

    for (HashNode *cur = ht->T[i]; cur != NULL; cur = cur->next) {
        if (cur->key == key) {
            cur->value = value;
            return;
        }
    }

    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = ht->T[i];
    ht->T[i] = node;
    ht->n++;
}

/**
 * @brief 查找 key，命中返回节点指针，未命中返回 NULL。
 */
HashNode *hashSearch(const HashTable *ht, int key) {
    int i = hashMultiplication(ht, key);
    for (HashNode *cur = ht->T[i]; cur != NULL; cur = cur->next) {
        if (cur->key == key) return cur;
    }
    return NULL;
}

/**
 * @brief 删除 key，成功返回 true，不存在返回 false。
 */
bool hashDelete(HashTable *ht, int key) {
    int i = hashMultiplication(ht, key);
    HashNode *prev = NULL;
    HashNode *cur = ht->T[i];

    while (cur != NULL) {
        if (cur->key == key) {
            if (prev == NULL) {
                ht->T[i] = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            ht->n--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

/**
 * @brief load factor α = n / m。
 */
double loadFactor(const HashTable *ht) {
    return (double)ht->n / (double)ht->m;
}
