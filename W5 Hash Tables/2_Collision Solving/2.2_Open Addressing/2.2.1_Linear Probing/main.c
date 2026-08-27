#include "hashtable.h"
#include <stdio.h>

static void dump(const HashTable *ht) {
    printf("m = %d, n = %d, alpha = %.2f\n", ht->m, ht->n, loadFactor(ht));
    for (int i = 0; i < ht->m; i++) {
        printf("  T[%2d] ", i);
        switch (ht->T[i].state) {
            case EMPTY:    printf("."); break;
            case DELETED:  printf("<deleted>"); break;
            case OCCUPIED: printf("(%d, %d)  h(k)=%d", ht->T[i].key,
                                  ht->T[i].value, ((ht->T[i].key % ht->m) + ht->m) % ht->m);
                           break;
        }
        printf("\n");
    }
}

int main(void) {
    HashTable *ht = createHashTable(13);   /* h(k) = k mod 13 */

    /* 1, 14, 27 都 mod 13 == 1 -> 线性探测把它们排到 T[1], T[2], T[3] */
    int keys[] = {1, 14, 27, 5, 40};       /* 5 -> T[5];  40 mod 13 == 1 -> 继续往后 */
    for (int i = 0; i < (int)(sizeof(keys) / sizeof(keys[0])); i++) {
        hashInsert(ht, keys[i], keys[i] * 10);
    }
    dump(ht);

    int v;
    printf("\nsearch 27 -> slot %d, value %d\n", hashSearch(ht, 27, &v), v);
    printf("search 99 -> %d (expect -1)\n", hashSearch(ht, 99, &v));

    /* 删除 14（在 T[2]），它变 tombstone；27 仍能通过跨过 tombstone 找到 */
    printf("\ndelete 14 -> %s\n", hashDelete(ht, 14) ? "true" : "false");
    printf("search 27 after delete -> slot %d (探测链跨过 T[2] 的 tombstone)\n",
           hashSearch(ht, 27, &v));
    dump(ht);

    /* 再插入一个 mod 13 == 1 的 key，复用 T[2] 的 tombstone */
    printf("\ninsert 53 (53 mod 13 == 1) -> 复用 tombstone\n");
    hashInsert(ht, 53, 530);
    dump(ht);

    freeHashTable(ht);
    return 0;
}
