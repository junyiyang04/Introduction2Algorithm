#include <iostream>
#include "export_macro.h"

enum RBT_Color{
    RED = 0,
    BLACK
};
typedef struct _RBTree_Node_
{
    int data;
    struct _RBTree_Node_ *lchild, *rchild, *parent;
    RBT_Color color;
}RBTree_Node;




void callRedBlackTree();