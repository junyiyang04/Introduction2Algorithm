#include <chapter12.h>
// binary search tree

// ******************************************************************
// *                                                                *
// *                     binary search tree                         *
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
        printf("%3d\n", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(BTree_Node* p)
{
    if(p != NULL){
        Inorder(p->lchild);
        printf("%3d\n", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(BTree_Node* p)
{
    if(p != NULL){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%3d\n", p->data);
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

/// @brief calculate pointer to the node with data 'key'
/// @param root I- the root of the binary search tree
/// @param key I- the value of the target node
/// @return pointer to the node with data 'key'
BTree_Node* iterativeTreeSearch(BTree_Node* root, int key)
{
    BTree_Node** p = &root;
    while(*p != NULL && key != (*p)->data){
        if(key < (*p)->data)
            *p = (*p)->lchild;
        else
            *p = (*p)->rchild;
    }
    return *p;
}

/// @brief calculate the pointer to the mimimum node 
/// @param root I- the root of binary search tree
/// @return pointer to the minimum node
BTree_Node* treeMinimum(BTree_Node* root)
{
    BTree_Node** p = &root;
    if(*p != NULL)
        while((*p)->lchild != NULL)
            (*p) = (*p)->lchild;        
    return *p;
}

/// @brief calculate the pointer to the maximum node 
/// @param root I- the root of binary search tree
/// @return pointer to the maximum node
BTree_Node* treeMaximum(BTree_Node* root)
{
    BTree_Node** p = &root;
    if((*p) != NULL)
        while((*p)->rchild != NULL)
            (*p) = (*p)->rchild;
    return *p;
}

/// @brief calculate the pointer to the successor of node 'p'
/// @param p I- a node of binary search tree
/// @return pointer to the successor node
BTree_Node* treeSuccessor(BTree_Node* p)
{
    if(p->rchild != NULL) //这样直接使用会不会出问题
        return treeMinimum(p->rchild);

    BTree_Node** p_cp = &p;
    while((*p_cp)->parent != NULL && (*p_cp) == (*p_cp)->parent->rchild){
        (*p_cp) = (*p_cp)->parent; // while the node has no right child, the successor will be found upwards the tree
    }
    return (*p_cp)->parent;
}

/// @brief calculate the pointer to the predecessor of node 'p'
/// @param p I- a node of binary search tree
/// @return pointer to the predecessor node
BTree_Node* treePredecessor(BTree_Node* p)
{
    if(p->lchild != NULL) //这样直接使用会不会出问题
        return p->rchild;
    BTree_Node** p_cp = &p;
    while((*p_cp)->parent != NULL && (*p_cp) == (*p_cp)->parent->lchild){
        (*p_cp) = (*p_cp)->parent; // while the node has no left child, the predecessor will be found upwards the tree
    }
    return (*p_cp)->parent;
}


/// @brief used to add nodes to a binary search tree
/// @author Cillian Young
/// @param root IO- the root of the binary search tree(double * will allow the root to be inited as both NULL and others)
/// @param p1 I- the node to insert
/// @note the parameter 'p1' is not suitable, the only value need to pass through this position is the node's data
void treeInsert(BTree_Node** root, BTree_Node* p1) //
{
    BTree_Node* y = NULL;
    BTree_Node* x = *root; // x is uesd to search position to insert from root and transmit the value to y
    BTree_Node* p = (BTree_Node*)malloc(sizeof(BTree_Node)); // check if the pointer is created successfully
    p->data = p1->data;    
    while(x != NULL){
        y = x;
        if(x->data < p->data)
            x = x->rchild;
        else
            x = x->lchild;
    }
    p->parent = y;
    if(y == NULL)
        *root = p;
    else if(p->data < y->data)
        y->lchild = p;
    else
        y->rchild = p;
}

/// @brief move subtrees around within the binary search tree(to my understanding, replacing u's place in the tree with v)
/// @param root the root on behalf of the binary search tree
/// @param u the position where want to move the subtree
/// @param v subtree root
/// @note this operation don't change the location of u v
void transPlant(BTree_Node* root, BTree_Node* u,BTree_Node* v)
{
    if(u->parent == NULL)
        root = v;
    else if(u == u->parent->lchild) // u in the left branch 
        u->parent->lchild = v;
    else // u in the right branch
        u->parent->rchild = v;
    if(v != NULL)
        v->parent = u->parent; // 不用首先判断v->parent是否为空吗
    free(u); // free the useless node
}

/// @brief delete the node p
/// @param root the root of the tree 
/// @param p the node waiting to be deleted
void treeDelete(BTree_Node* root, BTree_Node* p)
{
    if(p->lchild == NULL) // case 1,2: the node p has only one child
        transPlant(root, p, p->rchild);
    else if(p->rchild == NULL)
        transPlant(root, p, p->lchild);
    else{
        BTree_Node* y = treeMinimum(p->rchild);
        if(y->parent != p){ // case 3: the node p has two child but and it's succesor is next to itself 
            transPlant(root, y, y->rchild); // 这个操作将y节点空闲出来并且链接y->r到原来y的位置
            y->rchild = p->rchild;
            y->rchild->parent = y;
        }
        transPlant(root, p, y); // case 4: the node p has two child but and it's succesor isn't next to itself
        y->lchild = p->lchild;
        y->lchild->parent = y;
    }
}

void callBinarySearchTree()
{
    std::cout << "> Running test for chapter 12" << std::endl;
    int insert_size = 6;
    BTree_Node* root = NULL;
    for(int i = 0; i < insert_size; i++){
        BTree_Node p;
        p.data = i;
        treeInsert(&root, &p);
    }
    for(int i = 0; i < insert_size; i++){
        BTree_Node p;
        p.data = 7 - i;
        treeInsert(&root, &p);
    }
    // in order
    Inorder(root);

    // min
    BTree_Node* minnode = treeMinimum(root);
    if(minnode) printf("min: %d\n", minnode->data);

    // max
    BTree_Node* maxnode = treeMaximum(root);
    if(maxnode) printf("max: %d\n", maxnode->data);

    // search
    BTree_Node* node = iterativeTreeSearch(root, 3);
    printf("pointer : %p\n", node);
    if(node) printf("nodedata: %d\n", node->data);

    // successor
    BTree_Node* successor = treeSuccessor(node);
    if(successor) printf("successor: %d\n", successor->data);

    // predecessor
    BTree_Node* predecessor = treePredecessor(node);
    if(predecessor) printf("predecessor: %d\n", predecessor->data);

    // delete node
    treeDelete(root, node);
    Inorder(root);
}
