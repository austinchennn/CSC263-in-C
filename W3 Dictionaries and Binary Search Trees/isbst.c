#include "bst.h"
#include <stdlib.h>

// 只需要看中序遍历是不是从小到大, 可以一边遍历一边判断
// 每遍历到一个数就和前一个数比较
//如果>前一个数就继续遍历，否则说明不是二叉搜索树

/** 
 * @brief 判断二叉树是否为二叉搜索树。
 * @param root 根节点指针（可能为 NULL）。
 * @return 如果是二叉搜索树返回 true，否则返回 false。
*/
// 辅助函数：prev/result 用指针传递，这样递归调用之间共享同一份状态
static void isBSThelper(BSTNode* root, BSTNode** prev, bool* result) {
    if (root == NULL || *result == false) {
        return;
    }
    // 中序遍历：左子树 -> 根节点 -> 右子树

    // 左
    isBSThelper(root->left, prev, result);

    // 根
    if (*prev == NULL) { // 即root是第一个节点
        *prev = root;
    } else if (root->data > (*prev)->data) { // 当前节点大于前一个节点，符合二叉搜索树的性质
        *prev = root;
    } else { // 当前节点小于等于前一个节点，不符合二叉搜索树的性质
        *result = false;
        return;
    }

    // 右
    isBSThelper(root->right, prev, result);
}

bool isBST(BSTNode* root) {
    BSTNode* prev = NULL; // 用于记录中序遍历的前一个节点
    bool result = true; // 用于记录是否是二叉搜索树

    isBSThelper(root, &prev, &result);
    return result;
}