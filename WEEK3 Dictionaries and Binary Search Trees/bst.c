#include "bst.h"
#include <stdlib.h>

static BSTNode* FindMin(BSTNode* root);
static BSTNode* FindMax(BSTNode* root);

/**
 * @brief 在二叉搜索树中递归查找值。
 * @param root 根节点指针（可能为 NULL）。
 * @param x 要查找的整数值。
 * @return 指向找到的节点，未找到返回 NULL。
 */
BSTNode* Search(BSTNode* root, int x) {
    if (root == NULL){ //查找失败 
        return NULL;
    } else if (x < root->data) { // 查找左子树
        return Search(root->left, x);
    } else if (x > root->data) { //查找右子树
        return Search(root->right, x);
    } else { // 查找成功
        return root;
    }

}

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

/**
 * @brief 删除二叉搜索树中的节点。
 * @param root 根节点指针的引用（可能为 NULL）。
 * @param x 要删除的整数值。
 */
void Delete(BSTNode** root, int x) {

     if (*root == NULL) { // 不存在要删除的节点
        return;
    } else if (x < (*root)->data) { //x小于当前节点值，去左子树删除
        Delete(&((*root)->left), x);
    } else if (x > (*root)->data) {//x大于当前节点值，去右子树删除
        Delete(&((*root)->right), x);
    } else { 
        //1.左右子树都为空，直接删除节点
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }

        //2.左不空，右空，删除节点后让左子树顶替当前节点
        else if ((*root)->left != NULL && (*root)->right == NULL) {
            BSTNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        }

        //3.左空，右不空，删除节点后让右子树顶替当前节点
        else if ((*root)->left == NULL && (*root)->right != NULL) {
            BSTNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        }

        //4.左右子树都不为空，前驱/后继值替代，删除原来的前驱/后继
        else {
            //以直接后继节点为例 
            // 找到右子树的最小值节点（后继节点）
            BSTNode* successor = FindMin((*root)->right);
            // 用后继节点的值替代当前节点的值   
            (*root)->data = successor->data;
            // 删除后继节点
            Delete(&((*root)->right), successor->data);
        }
    }
}


/**
 * -----------私有函数：查找最小值节点和最大值节点-----------
 */


/**
 * @brief 查找二叉搜索树中的最小值节点。
 * @param root 根节点指针，调用者需保证非 NULL。
 * @return 指向最小值节点的指针。
 */
static BSTNode* FindMin(BSTNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

/**
 * @brief 查找二叉搜索树中的最大值节点。
 * @param root 根节点指针（可能为 NULL）。
 * @return 指向最大值节点的指针，若树为空则返回 NULL。
 */
static BSTNode* FindMax(BSTNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}