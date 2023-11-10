#include <iostream>
#include "export_macro.h"

typedef struct _BTree_Node_
{
    int data;
    struct _BTree_Node_ *lchild, *rchild, *parent;
}BTree_Node;


I2A_API void Preorder(BTree_Node* p);
I2A_API void Inorder(BTree_Node* p);
I2A_API void Postorder(BTree_Node* p);
I2A_API BTree_Node* treeSearch(BTree_Node* p, int key);
I2A_API BTree_Node* iterativeTreeSearch(BTree_Node* p, int key);
I2A_API BTree_Node* treeMinimum(BTree_Node* p);
I2A_API BTree_Node* treeMaximum(BTree_Node* p);
I2A_API BTree_Node* treeSuccessor(BTree_Node* p);
I2A_API BTree_Node* treePredecessor(BTree_Node* p);
I2A_API void treeInsert(BTree_Node* root, BTree_Node* p);
I2A_API void transPlant(BTree_Node* root,const BTree_Node* u,BTree_Node* v);
I2A_API void treeDelete(BTree_Node* root, BTree_Node* p);


I2A_API void callBinarySearchTree();
