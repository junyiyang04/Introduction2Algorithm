#include <iostream>
#include "export_macro.h"

typedef struct _RBTree_Node_
{
    int data;
    struct _RBTree_Node_ *lchild, *rchild, *parent;
    int color;
}RBTree_Node;

