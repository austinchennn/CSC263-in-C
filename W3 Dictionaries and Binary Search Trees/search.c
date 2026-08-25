#include "bst.h"

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
