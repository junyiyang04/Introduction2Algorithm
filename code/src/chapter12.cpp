#include <chapter12.h>
// binary search tree

// ******************************************************************
// *                                                                *
// *                     Inorder Tree Walk                          *
// *                     Preorder Tree Walk                         *
// *                     Postorder Tree Walk                        *
// *                                                                *
// ******************************************************************


/**
 *              f
 *         _____|_____
 *        |           |
 *        d           g
 *     ___|___        |___
 *    |       |           |
 *    b       e           i
 *  __|__               __|__
 * |     |             |     |
 * a     c             h     j
 * preorder : f d b a c e g i h j
 * inorder  : a b c d e f g h i j
 * postorder: a c b e d h j i g f
*/
void Preorder(BTree_Node* p)
{
    if(p != NULL){
        printf("%3d", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(BTree_Node* p)
{
    if(p != NULL){
        Inorder(p->lchild);
        printf("%3d", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(BTree_Node* p)
{
    if(p != NULL){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%3d", p->data);
    }
}


/**
 *              15
 *         _____|_____
 *        |           |
 *        6           18
 *     ___|___     ___|___
 *    |       |   |       |
 *    3       7   17      20
 *  __|__     |__  
 * |     |       |
 * 2     4       13
 *             __|
 *            |      
 *            9
*/
BTree_Node* treeSearch(BTree_Node* p, int key)
{
    if( p == NULL || p->data == key){
        return p;
    }
    if(key < p->data){
        return treeSearch(p->lchild, key);
    }
    else
        return treeSearch(p->rchild, key);
}

BTree_Node* iterativeTreeSearch(BTree_Node* p, int key)
{
    while(p != NULL && key != p->data){
        if(key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return p;
}

BTree_Node* treeMinimum(BTree_Node* p)
{
    if(p != NULL)
        while(p->lchild != NULL)
            p = p->lchild;
    return p;
}

BTree_Node* treeMaximum(BTree_Node* p)
{
    if(p != NULL)
        while(p->rchild != NULL)
            p = p->rchild;
    return p;
}

BTree_Node* treeSuccessor(BTree_Node* p)
{
    if(p->rchild != NULL) //这样直接使用会不会出问题
        return treeMinimum(p->rchild);
    BTree_Node* p_cp = p;
    while(p_cp->parent != NULL && p_cp == p_cp->parent->rchild)
    {
        p_cp = p_cp->parent;
    }
    return p_cp->parent;
}

BTree_Node* treePredecessor(BTree_Node* p)
{
    if(p->lchild != NULL) //这样直接使用会不会出问题
        return p->rchild;
    BTree_Node* p_cp = p;
    while(p_cp->parent != NULL && p_cp == p_cp->parent->lchild)
    {
        p_cp = p_cp->parent;
    }
    return p_cp->parent;
}

void treeInsert(BTree_Node* root, BTree_Node* p)
{
    BTree_Node* y = NULL;
    BTree_Node* x = root;
    while(x != NULL){
        y = x;
        if(x->data < p->data)
            x = x->rchild;
        else
            x = x->lchild;
    }
    p->parent = y;
    if(y == NULL)
        root = p;
    else if(p->data < y->data)
        y->lchild = p;
    else
        y->rchild = p;
}
