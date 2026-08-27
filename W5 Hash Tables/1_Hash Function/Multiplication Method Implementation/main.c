#include "hashtable.h"
#include <stdio.h>

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
    /* m = 16：2 的幂。对除法散列这是最糟的选择（只看低 4 位），
       但乘法散列对 m 不敏感，依然能把 key 打散。 */
    HashTable *ht = createHashTable(16);

    int keys[] = {1, 14, 27, 5, 18, 31, 44, 100, -7, 256, 512, 4096};
    for (int i = 0; i < (int)(sizeof(keys) / sizeof(keys[0])); i++) {
        hashInsert(ht, keys[i], keys[i] * 10);
    }
    /* 256, 512, 4096 在除法散列 (mod 16) 下会全撞到 bucket 0；
       这里用乘法散列，观察它们被分散到不同 bucket */
    dump(ht);

    hashInsert(ht, 14, 999);
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
