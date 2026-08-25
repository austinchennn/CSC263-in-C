#include "bst.h"

/**
 * @brief 根据数组创建二叉搜索树。
 * @param a 整数数组。
 * @param n 数组长度。
 * @return 指向根节点的指针。
 */
BSTNode* Create(int a[], int n) {
    BSTNode* root = NULL;
    for (int i = 0; i < n; i++) {
        Insert(&root, a[i]);
    }
    return root;
}
