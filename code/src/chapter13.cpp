#include <chapter13.h>



// ******************************************************************
// *                                                                *
// *                     Red-Black trees                            *
// *                    - left rotate                               *
// *                    - right rotate                              *
// *                    - rb insert-fix-up(for color)               *
// *                    - rb insert                                 *
// *                    - rb delete                                 *
// ******************************************************************


/**
 *      |                        |
 *      x      left rotate       y
 *     / \    ------------->    / \
 *    α   y   <-------------   x   γ
 *       / \   right rotate   / \
 *      β   γ                α   β
 */
void rightRotate(RBTree_Node* root, RBTree_Node* y)
{
    RBTree_Node* x;
    x = y->lchild;
    y->lchild = x->rchild;
    if( x->rchild != NULL) // 这里要不要改成sentinel T.nil
        x->rchild->parent = y;
    x->parent = y->parent;
    if( y->parent == NULL)
        root = x;
    else if(y == y->parent->rchild)
        y->parent->rchild = x;
    else
        y->parent->lchild = x;
    x->rchild = y;
    y->parent = x;
}

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

void rbInsertFixUp(RBTree_Node* root, RBTree_Node* z)
{
    while(z->parent->color == RBT_Color::RED){
        if(z->parent == z->parent->parent->lchild){
            RBTree_Node* y = z->parent->parent->rchild; // uncle
            // case 1
            if(y->color == RBT_Color::RED){ 
                z->parent->color = RBT_Color::BLACK;
                y->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                z = z->parent->parent;
            }
            // case 2
            else if(z == z->parent->rchild){ // 作为右边的孩子，进行左旋转
                z = z->parent;
                leftRotate(root, z);
            }
            // case 3
            z->parent->color = RBT_Color::BLACK;
            z->parent->parent->color = RBT_Color::RED;
            rightRotate(root, z->parent->parent);
        }
        else{
            // case 1
            // case 2
            // case 3
        }
    }
    root->color = RBT_Color::RED; // the final check
}

void RBTreeInsert(RBTree_Node* root, RBTree_Node* z)
{
    RBTree_Node* y = NULL; // y will be set as the smallest data that bigger than z.data
    RBTree_Node* x = root;
    while(x != NULL){
        y = x;
        if(z->data < x->data)
            x = x->lchild;
        else
            x = x->rchild;
    }
    z->parent = y;
    if( NULL == y)
        root = z;
    else if(z->data < y->data)
        y->lchild = z;
    else
        y->rchild = z;
    z->lchild = NULL;
    z->rchild = NULL;
    z->color = RBT_Color::RED;
    // using the rbInsertFixUp to re-color nodes
    rbInsertFixUp(root, z);
}

