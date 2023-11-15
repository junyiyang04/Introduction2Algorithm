#include <iostream>
#include "export_macro.h"


// using enum class to address some limitations of enum
enum class RBT_Color{
    RED = 0,
    BLACK
};
typedef struct _RBTree_Node_
{
    int data;
    struct _RBTree_Node_ *lchild, *rchild, *parent;
    RBT_Color color;
}RBTree_Node;




I2A_API void callRedBlackTree();