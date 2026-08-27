#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/*
 * Multiplication Method 哈希表（碰撞用 Chaining 解决）
 *
 *   1. 把 k 乘以实数常数 A（0 < A < 1）
 *   2. 取 k * A 的小数部分 x（0 < x < 1）
 *   3. h(k) = floor(m * x)
 *
 * 见 W5 Hash Tables/3_Hash Function：
 *   - 优点：对 m 的取值不敏感，因此 m 可以直接取 2 的幂（这里 demo 用 16）
 *   - 常用 A = (sqrt(5) - 1) / 2 ≈ 0.6180339887（Knuth 建议值）
 *
 * 与 Division Method Implementation 的唯一区别就是 hashMultiplication()，
 * 其余 Chaining 的插入 / 查找 / 删除逻辑完全相同。
 */

/* 链表节点：一个 key-value 对（Chaining 里挂在某个 bucket 下） */
typedef struct HashNode {
    int key;
    int value;
    struct HashNode *next;
} HashNode;

/* 哈希表：长度为 m 的 bucket 数组 T + 当前元素数 n */
typedef struct {
    HashNode **T;   /* 长度为 m 的数组，T[i] 是第 i 条链表的表头（可能为 NULL） */
    int m;          /* bucket 数量；乘法散列下取 2 的幂也没问题 */
    int n;          /* 当前存储的元素个数，用于计算 load factor α = n/m */
} HashTable;

HashTable *createHashTable(int m);
void freeHashTable(HashTable *ht);

/* Multiplication Method：返回 key 落在的 bucket 下标，范围 [0, m-1] */
int hashMultiplication(const HashTable *ht, int key);

/* 插入：若 key 已存在则更新其 value，否则新节点头插到对应链表 */
void hashInsert(HashTable *ht, int key, int value);

/* 查找：命中返回该节点指针，未命中返回 NULL */
HashNode *hashSearch(const HashTable *ht, int key);

/* 删除：成功返回 true，key 不存在返回 false */
bool hashDelete(HashTable *ht, int key);

/* load factor α = n / m */
double loadFactor(const HashTable *ht);

#endif
