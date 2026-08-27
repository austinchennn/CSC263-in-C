#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/*
 * Open Addressing 哈希表 —— Linear Probing（线性探测）
 *
 *   probe(k, i) = (h(k) + i) mod m,   h(k) = k mod m,   i = 0, 1, 2, ...
 *
 * 三种 slot 状态见 ../README.md：EMPTY / OCCUPIED / DELETED(tombstone)。
 * 与 2.2.2 / 2.2.3 的唯一区别就是 probe() 函数。
 */

typedef enum { EMPTY, OCCUPIED, DELETED } SlotState;

typedef struct {
    SlotState state;
    int key;
    int value;
} Slot;

typedef struct {
    Slot *T;   /* 长度为 m 的数组，元素直接存这里，不用链表 */
    int m;     /* 数组长度 */
    int n;     /* 已存元素数（不含 DELETED）；α = n/m ≤ 1 */
} HashTable;

HashTable *createHashTable(int m);
void freeHashTable(HashTable *ht);

/* Linear Probing 的探测函数：第 i 次探测的 slot 下标 */
int probe(const HashTable *ht, int key, int i);

/* 插入 / 更新；表满且无可复用 tombstone 时返回 false */
bool hashInsert(HashTable *ht, int key, int value);

/* 查找：命中返回 slot 下标（并通过 value_out 带回 value），未命中返回 -1 */
int hashSearch(const HashTable *ht, int key, int *value_out);

/* 删除：把 slot 标记为 DELETED；key 不存在返回 false */
bool hashDelete(HashTable *ht, int key);

double loadFactor(const HashTable *ht);

#endif
