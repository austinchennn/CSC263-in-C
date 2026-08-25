#include "bst.h"
#include <stdlib.h>

/**
 * @brief 在二叉搜索树中插入值。
 * @param root 根节点指针的引用（可能为 NULL）。
 * @param x 要插入的整数值。
 */
void Insert(BSTNode** root, int x) {
    if (*root == NULL) {
        //   0. sizeof(BSTNode) 返回的是 BSTNode 结构体在内存中占用的字节数
        //   （即 data 这个 int，加上 left、right 两个指针的大小之和）。
        //   1. malloc(sizeof(BSTNode)) 在堆上申请一块sizeof(BSTNode)大的、未初始化的内存，返回 void*
        //   2. (BSTNode *) 把这个 void* 强制转换成 BSTNode* 类型
        //   3. 赋值给 *root，让原本是 NULL 的指针指向这块新节点内存
        *root = (BSTNode*)malloc(sizeof(BSTNode));
        (*root)->data = x;
        (*root)->left = (*root)->right = NULL;
    } else if (x < (*root)->data) {
        Insert(&((*root)->left), x);
    } else if (x > (*root)->data) {
        Insert(&((*root)->right), x);
    }
}
