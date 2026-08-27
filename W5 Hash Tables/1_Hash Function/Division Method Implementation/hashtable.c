#include "hashtable.h"
#include <stdlib.h>
#include <assert.h>

/**
 * @brief 创建一个含 m 个 bucket 的空哈希表。
 * @param m bucket 数量，应为「不接近 2 的幂的素数」（见头文件说明）。
 * @return 指向新哈希表的指针；每个 bucket 初始化为 NULL（空链表）。
 */
HashTable *createHashTable(int m) {
    assert(m > 0);
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    /* calloc 把 m 个指针全部清零，即所有 bucket 初始为空链表 */
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
 * @brief Division Method：h(k) = k mod m。
 * @note C 的 % 对负数结果可能为负，这里做一次修正把结果拉回 [0, m-1]。
 */
int hashDivision(const HashTable *ht, int key) {
    int i = key % ht->m;
    if (i < 0) i += ht->m;
    return i;
}

/**
 * @brief 插入 key-value 对。
 *        对照笔记 ChainedHashInsert：
 *          1. i = h(k)
 *          2. 在 T[i] 链表中查找 key
 *          3. 找到 -> 用新 value 覆盖；没找到 -> 新节点插入链表头部
 */
void hashInsert(HashTable *ht, int key, int value) {
    int i = hashDivision(ht, key);

    for (HashNode *cur = ht->T[i]; cur != NULL; cur = cur->next) {
        if (cur->key == key) {
            cur->value = value;   /* 已存在：替换 value */
            return;
        }
    }

    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = ht->T[i];        /* 头插：Θ(1) */
    ht->T[i] = node;
    ht->n++;
}

/**
 * @brief 查找 key。
 *        对照笔记 ChainedHashSearch：i = h(k) 后在 T[i] 链表里线性查找。
 * @return 命中的节点指针，未命中返回 NULL。
 */
HashNode *hashSearch(const HashTable *ht, int key) {
    int i = hashDivision(ht, key);
    for (HashNode *cur = ht->T[i]; cur != NULL; cur = cur->next) {
        if (cur->key == key) return cur;
    }
    return NULL;
}

/**
 * @brief 删除 key。
 *        对照笔记 ChainedHashDelete：i = h(k) 后在 T[i] 链表里找到并摘除。
 * @return 删除成功返回 true；key 不存在返回 false。
 */
bool hashDelete(HashTable *ht, int key) {
    int i = hashDivision(ht, key);
    HashNode *prev = NULL;
    HashNode *cur = ht->T[i];

    while (cur != NULL) {
        if (cur->key == key) {
            if (prev == NULL) {
                ht->T[i] = cur->next;   /* 删的是表头 */
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
 * @note 笔记结论：只要 m 与 n 成正比（α ∈ Θ(1)），
 *       Search / Insert / Delete 的平均运行时间都是 Θ(1 + α) = Θ(1)。
 */
double loadFactor(const HashTable *ht) {
    return (double)ht->n / (double)ht->m;
}
