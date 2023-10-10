#include <iostream>
#include "export_macro.h"

typedef struct _BTree_Node_
{
    int data;
    struct _BTree_Node_ *lchild, *rchild;
}BTree_Node;


I2A_API void Preorder(BTree_Node* p);
I2A_API void Inorder(BTree_Node* p);
I2A_API void Postorder(BTree_Node* p);