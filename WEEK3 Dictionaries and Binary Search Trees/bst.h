#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>


typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} BSTNode;


BSTNode* Search(BSTNode* root, int x);
void Insert(BSTNode **root, int x);
BSTNode* Create(int a[], int n);
void Delete(BSTNode **root, int x);



#endif