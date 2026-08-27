#include "hashtable.h"
#include <stdio.h>

static int H1(int k, int m) { int r = k % m; return r < 0 ? r + m : r; }
static int H2(int k, int m) { int r = k % (m - 1); return 1 + (r < 0 ? r + (m - 1) : r); }

static void dump(const HashTable *ht) {
    printf("m = %d, n = %d, alpha = %.2f\n", ht->m, ht->n, loadFactor(ht));
    for (int i = 0; i < ht->m; i++) {
        printf("  T[%2d] ", i);
        switch (ht->T[i].state) {
            case EMPTY:    printf("."); break;
            case DELETED:  printf("<deleted>"); break;
            case OCCUPIED: {
                int k = ht->T[i].key;
                printf("(%d, %d)  h1=%d h2=%d", k, ht->T[i].value,
                       H1(k, ht->m), H2(k, ht->m));
                break;
            }
        }
        printf("\n");
    }
}

int main(void) {
    HashTable *ht = createHashTable(13);   /* 素数 */

    /* 1, 14, 27, 40 全部 h1 == 1，但 h2 各不相同 -> 探测序列发散，无 secondary clustering
       h2(1)=2, h2(14)=3, h2(27)=4, h2(40)=5 */
    int keys[] = {1, 14, 27, 40, 5};
    for (int i = 0; i < (int)(sizeof(keys) / sizeof(keys[0])); i++) {
        printf("insert %d  (h1=%d, h2=%d) -> %s\n", keys[i],
               H1(keys[i], 13), H2(keys[i], 13),
               hashInsert(ht, keys[i], keys[i] * 10) ? "ok" : "FAIL");
    }
    printf("\n");
    dump(ht);

    int v;
    printf("\nsearch 40 -> slot %d, value %d\n", hashSearch(ht, 40, &v), v);
    /* 27 在 T[5]；key 5 的探测序列是 5 -> 11，正好先经过 T[5] */
    printf("delete 27 -> %s\n", hashDelete(ht, 27) ? "true" : "false");
    printf("search 5 after delete -> slot %d (探测经过 T[5] 的 tombstone 后继续到 T[11])\n",
           hashSearch(ht, 5, &v));

    printf("\n");
    dump(ht);

    freeHashTable(ht);
    return 0;
}
