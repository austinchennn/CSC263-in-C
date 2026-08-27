#include "hashtable.h"
#include <stdio.h>

static void dump(const HashTable *ht) {
    printf("m = %d, n = %d, alpha = %.2f\n", ht->m, ht->n, loadFactor(ht));
    for (int i = 0; i < ht->m; i++) {
        printf("  T[%2d] ", i);
        switch (ht->T[i].state) {
            case EMPTY:    printf("."); break;
            case DELETED:  printf("<deleted>"); break;
            case OCCUPIED: printf("(%d, %d)  h(k)=%d", ht->T[i].key, ht->T[i].value,
                                  ((ht->T[i].key % ht->m) + ht->m) % ht->m);
                           break;
        }
        printf("\n");
    }
}

int main(void) {
    HashTable *ht = createHashTable(13);   /* 素数；保持 α < 0.5 */

    /* 1, 14, 27, 40, 53 全部 mod 13 == 1，探测偏移 0,1,4,9,16%13=3 -> T[1],T[2],T[5],T[10],T[4] */
    int keys[] = {1, 14, 27, 40, 53};
    for (int i = 0; i < (int)(sizeof(keys) / sizeof(keys[0])); i++) {
        printf("insert %d -> %s\n", keys[i],
               hashInsert(ht, keys[i], keys[i] * 10) ? "ok" : "FAIL");
    }
    printf("\n");
    dump(ht);
    /* 注意落点是 1,2,5,10,4 —— 不连续，没有 Linear 那种成片占用 */

    int v;
    printf("\nsearch 53 -> slot %d, value %d\n", hashSearch(ht, 53, &v), v);
    printf("delete 27 -> %s\n", hashDelete(ht, 27) ? "true" : "false");
    printf("search 40 after delete -> slot %d (跨过 tombstone)\n", hashSearch(ht, 40, &v));

    printf("\n");
    dump(ht);

    freeHashTable(ht);
    return 0;
}
