#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/*
 * Division Method 哈希表（碰撞用 Chaining 解决）
 *
 *   h(k) = k mod m
 *
 * 见 W5 Hash Tables/3_Hash Function：m 应取一个「不接近 2 的整数次幂的素数」，
 * 否则 k mod 2^p 只由 k 的低 p 位决定，key 无法被充分打散。
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
    int m;          /* bucket 数量，建议取素数 */
    int n;          /* 当前存储的元素个数，用于计算 load factor α = n/m */
} HashTable;

HashTable *createHashTable(int m);
void freeHashTable(HashTable *ht);

/* Division Method：返回 key 落在的 bucket 下标，范围 [0, m-1] */
int hashDivision(const HashTable *ht, int key);

/* 插入：若 key 已存在则更新其 value，否则新节点头插到对应链表 */
void hashInsert(HashTable *ht, int key, int value);

/* 查找：命中返回该节点指针，未命中返回 NULL */
HashNode *hashSearch(const HashTable *ht, int key);

/* 删除：成功返回 true，key 不存在返回 false */
bool hashDelete(HashTable *ht, int key);

/* load factor α = n / m */
double loadFactor(const HashTable *ht);

#endif
