#include "hashtable.h"
#include <stdio.h>

/* 打印每个 bucket 下挂的链表，直观看到 collision 与分布 */
static void dump(const HashTable *ht) {
    printf("m = %d, n = %d, alpha = %.2f\n", ht->m, ht->n, loadFactor(ht));
    for (int i = 0; i < ht->m; i++) {
        printf("  T[%2d]:", i);
        for (HashNode *cur = ht->T[i]; cur != NULL; cur = cur->next) {
            printf(" -> (%d, %d)", cur->key, cur->value);
        }
        printf("\n");
    }
}

int main(void) {
    /* m = 13：一个不接近 2 的幂的素数 */
    HashTable *ht = createHashTable(13);

    int keys[] = {1, 14, 27, 5, 18, 31, 44, 100, -7};
    for (int i = 0; i < (int)(sizeof(keys) / sizeof(keys[0])); i++) {
        hashInsert(ht, keys[i], keys[i] * 10);
    }
    /* 1, 14, 27 全部 mod 13 == 1 -> 同一个 bucket，链在一起 */
    dump(ht);

    hashInsert(ht, 14, 999);            /* 已存在 key，更新 value */
    HashNode *r = hashSearch(ht, 14);
    printf("\nsearch 14 -> %d (expect 999)\n", r ? r->value : -1);

    printf("delete 27 -> %s\n", hashDelete(ht, 27) ? "true" : "false");
    printf("delete 27 -> %s (already gone)\n", hashDelete(ht, 27) ? "true" : "false");
    printf("search 27 -> %s\n", hashSearch(ht, 27) ? "found" : "NULL");
    printf("search -7 -> %d (negative key)\n",
           hashSearch(ht, -7) ? hashSearch(ht, -7)->value : -1);

    printf("\n");
    dump(ht);

    freeHashTable(ht);
    return 0;
}
