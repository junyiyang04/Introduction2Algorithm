#include <chapter13.h>



// ******************************************************************
// *                                                                *
// *                     Red-Black trees                            *
// *                    - left rotate                               *
// *                    - right rotate                              *
// *                    - rb insert                                 *
// *                                                                *
// ******************************************************************


/**
 *      |                        |
 *      x      left rotate       y
 *     / \    ------------->    / \
 *    α   y   <-------------   x   γ
 *       / \   right rotate   / \
 *      β   γ                α   β
 */
void leftRotate(RBTree_Node* root, RBTree_Node* x)
{
    RBTree_Node* y;
    y = x->rchild;
    x->rchild = y->lchild;
    if( y->lchild != NULL) // 这里要不要改成sentinel T.nil
        y->lchild->parent = x;
    y->parent = x->parent;
    if( x->parent == NULL)
        root = y;
    else if(x == x->parent->lchild)
        x->parent->lchild = y;
    else
        x->parent->rchild = y;
    y->lchild = x;
    x->parent = y;
}

