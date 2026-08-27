#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/*
 * Open Addressing 哈希表 —— Quadratic Probing（二次探测）
 *
 *   probe(k, i) = (h(k) + i²) mod m,   h(k) = k mod m,   i = 0, 1, 2, ...
 *   （即 c1 = 0, c2 = 1）
 *
 * 硬约束：m 取素数，且 α = n/m < 1/2，否则可能明明有空位却探测不到。
 * 三种 slot 状态见 ../README.md。与 2.2.1 / 2.2.3 的唯一区别是 probe()。
 */

typedef enum { EMPTY, OCCUPIED, DELETED } SlotState;

typedef struct {
    SlotState state;
    int key;
    int value;
} Slot;

typedef struct {
    Slot *T;
    int m;     /* 数组长度，取素数 */
    int n;     /* 已存元素数；应维持 α = n/m < 0.5 */
} HashTable;

HashTable *createHashTable(int m);
void freeHashTable(HashTable *ht);

/* Quadratic Probing 的探测函数：第 i 次探测的 slot 下标 */
int probe(const HashTable *ht, int key, int i);

bool hashInsert(HashTable *ht, int key, int value);
int hashSearch(const HashTable *ht, int key, int *value_out);
bool hashDelete(HashTable *ht, int key);

double loadFactor(const HashTable *ht);

#endif
