#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/*
 * Open Addressing 哈希表 —— Double Hashing（双重哈希）
 *
 *   probe(k, i) = (h1(k) + i * h2(k)) mod m
 *   h1(k) = k mod m
 *   h2(k) = 1 + (k mod (m - 1))        # [1, m-1]，m 素数时与 m 互质
 *
 * m 必须取素数，才能保证 gcd(h2(k), m) = 1 => 探测序列覆盖所有 slot。
 * 三种 slot 状态见 ../README.md。与 2.2.1 / 2.2.2 的唯一区别是 probe()。
 */

typedef enum { EMPTY, OCCUPIED, DELETED } SlotState;

typedef struct {
    SlotState state;
    int key;
    int value;
} Slot;

typedef struct {
    Slot *T;
    int m;     /* 数组长度，必须取素数 */
    int n;
} HashTable;

HashTable *createHashTable(int m);
void freeHashTable(HashTable *ht);

/* Double Hashing 的探测函数：第 i 次探测的 slot 下标 */
int probe(const HashTable *ht, int key, int i);

bool hashInsert(HashTable *ht, int key, int value);
int hashSearch(const HashTable *ht, int key, int *value_out);
bool hashDelete(HashTable *ht, int key);

double loadFactor(const HashTable *ht);

#endif
