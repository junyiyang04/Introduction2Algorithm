#include <chapter13.h>
#include <chapter12.h>


// ******************************************************************
// *                                                                *
// *                     Red-Black trees                            *
// *                    - left rotate                               *
// *                    - right rotate                              *
// *                    - rb insert-fix-up(for color)               *
// *                    - rb insert                                 *
// *                    - rb delete                                 *
// *                                                                *
// *                                                                *
// ******************************************************************




// the leaf node
RBTree_Node Nil{0, NULL, NULL, NULL, RBT_Color::BLACK};

/// @brief calculate pointer to the node with data 'key'
/// @param root I- the root of the binary search tree
/// @param key I- the value of the target node
/// @return pointer to the node with data 'key'
RBTree_Node* iterativeRBTreeSearch(RBTree_Node* root, int key)
{
    RBTree_Node** p = &root;
    while(*p != NULL && *p != &Nil && key != (*p)->data){
        if(key < (*p)->data)
            *p = (*p)->lchild;
        else
            *p = (*p)->rchild;
    }
    return *p;
}

void RBTreeInorder(RBTree_Node* p)
{
    if(p != &Nil && p != NULL){
        RBTreeInorder(p->lchild);
        if(p->parent != &Nil){
            if(p->parent->lchild == p){
                char loc[5] = "left";
                printf("%s, ", loc);
            }
            else{
                char loc[6] = "right";
                printf("%s, ", loc);
            }
        }
        else{
            char loc[6] = "root";
            printf("%s, ", loc);
        }
        printf("%5d, %5d, %18p\n", p->data, p->color, p); // %16p 14 + 2
        RBTreeInorder(p->rchild);
    }
    else if(p == NULL) printf(">>>RED_BLACK_TREE_WARNING: empty red black tree\n");
}

/// @brief 
/// @param p 
void RBTreeHeightCheck(RBTree_Node* p)
{
    if(p != &Nil && p != NULL){
        RBTreeHeightCheck(p->lchild);
        if(p->lchild == &Nil || p->rchild == &Nil){
            int height = 0;
            RBTree_Node* iter = p;
            while(iter->parent != &Nil){
                if(iter->color == RBT_Color::BLACK){
                    height++;
                }
                iter = iter->parent;
            }
            printf("> The height of this leaf is: %d\n", height);;
        }
        RBTreeHeightCheck(p->rchild);
    }
    else if(p == NULL) printf(">>>RED_BLACK_TREE_WARNING: empty red black tree\n");
}

/**
 *  旋转操作的方向就是将树靠内部（中间）的子树移动的方向
 *      |                        |
 *      x      left rotate       y
 *     / \    ------------->    / \
 *    α   y   <-------------   x   γ
 *       / \   right rotate   / \
 *      β   γ                α   β
 */
void rightRotate(RBTree_Node** root, RBTree_Node* y)
{
    RBTree_Node* x = y->lchild;
    y->lchild = x->rchild;
    if( x->rchild != &Nil)
        x->rchild->parent = y;
    x->parent = y->parent;
    if( y->parent == &Nil)
        *root = x;
    else if(y == y->parent->rchild)
        y->parent->rchild = x;
    else
        y->parent->lchild = x;
    x->rchild = y;
    y->parent = x;
}

void leftRotate(RBTree_Node** root, RBTree_Node* x)
{
    RBTree_Node* y;
    y = x->rchild;
    x->rchild = y->lchild;
    if( y->lchild != &Nil)
        y->lchild->parent = x;
    y->parent = x->parent;
    if( x->parent == &Nil)
        *root = y;
    else if(x == x->parent->lchild)
        x->parent->lchild = y;
    else
        x->parent->rchild = y;
    y->lchild = x;
    x->parent = y;
}


/// @brief solve the violation of the new inserted node
/// @param root I- the root of the red black tree
/// @param z I- the new inserted node
/// @note through case 2, going up perhaps means indicator node goes to a smaller node
void rbInsertFixUp(RBTree_Node** root, RBTree_Node* z)
{
    // parent is red will violate the priperties of red black tree
    while(z->parent->color == RBT_Color::RED){ // z will always be a red node
        // LEFT: when parent is a left child
        if(z->parent == z->parent->parent->lchild){
            RBTree_Node* y = z->parent->parent->rchild; // uncle
            // case1:
            // indicator node z is the target to change, after adjustment indicator node z will go up to z1
            //     node                   node
            //     |                      |
            //     b                    r(z1)
            //    / \       re-color     / \
            //   r   r(y)  --------->   b   b       node's color changed in location
            //  /                      /
            // r(z)                   r(z)
            if(y->color == RBT_Color::RED){ 
                z->parent->color = RBT_Color::BLACK;
                y->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                z = z->parent->parent;
            }
            else if(z == z->parent->rchild){
                // case2: this option will transform case2 into case3 without solving any violation
                // * uncle y is black and z is the right child, indicator node z will go up to z1
                // * through this case, going up perhaps means indicator node goes to a smaller node
                // * rc, rcz,lc,lcz stand for child
                //        node                           node
                //         |                              |
                //        b(pp)                          b(pp) 
                //       /     \       rotate           /     \
                //      r      b(y)   --------->      r(z)    b(y)
                //     / \                           /    \
                //   lc  r(z)                      r(z1)  rcz
                //      /   \                     /    \
                //    lcz   rcz                  lc    lcz
                z = z->parent;    
                leftRotate(root, z);
                // case3: 
                //          node                       node                       node
                //           |                          |                          |
                //          b(pp)                      r(pp)                       b
                //         /     \     re-color       /     \      rotate      /        \
                //        r      b(y)  -------->     b      b(y)  -------->  r(z)      r(pp)
                //      /   \                      /   \                    /    \    /    \
                //    r(z)  rc                   r(z)  rc                  lcz   lcz rc    b(y)
                //   /    \                     /    \                     
                //  lcz   rcz                  lcz   rcz                   looks like more balanced       

                z->parent->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                rightRotate(root, z->parent->parent);            
            }
            else{
                z->parent->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                rightRotate(root, z->parent->parent);    // there is perhaps an error
            }
        }
        // RIGHT: when parent is a right child
        else{
            RBTree_Node* y = z->parent->parent->lchild; // uncle
            // case1: 
            if(y->color == RBT_Color::RED){ 
                z->parent->color = RBT_Color::BLACK;
                y->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                z = z->parent->parent;
            }
            else if(z == z->parent->lchild){
                // case2: this option will transform case2 into case3 without solving any violation
                z = z->parent;    
                rightRotate(root, z);
                // case3:
                z->parent->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                leftRotate(root, z->parent->parent);            
            }
            else{
                // case3:
                z->parent->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                leftRotate(root, z->parent->parent);  
            }
        }
    }
    (*root)->color = RBT_Color::BLACK; // the final check
}

/// @brief  insert a node into red black tree
/// @param root I- the root node which should be init as pointer NULL or pointer of other node 
/// @param z1 I- only the color and the data is important
void RBTreeInsert(RBTree_Node** root, RBTree_Node* z1)
{
    RBTree_Node* y = &Nil; // y will be set as the smallest data that bigger than z.data
    RBTree_Node* x = *root;
    RBTree_Node* z = (RBTree_Node*)malloc(sizeof(RBTree_Node));
    if(z != &Nil) // prevent dereference NULL
        z->data = z1->data;
    // the NULL here will help with initial the tree's root(user can initial the root as NULL instead of Nil,
    // the latter one is neither available nor easy to use outside the code);
    while(x != &Nil && x != NULL){ 
        y = x;
        if(x->data < z->data)
            x = x->rchild;
        else
            x = x->lchild;
    }
    if (z != &Nil) // prevent dereference NULL
        z->parent = y;
    if( &Nil == y)
        *root = z;
    else if(z->data > y->data)
        y->rchild = z;
    else
        y->lchild = z;
    z->lchild = &Nil; // check if this measure takes effect
    z->rchild = &Nil;
    z->color = RBT_Color::RED;
    RBTree_Node* iter = z;
    // printf("\n");
    // printf("> pointer: %p, data: %d, color: %d", z, z->data, z->color);
    // while(iter->parent != &Nil){
    //     iter = iter->parent;
    //     printf(" ---> parent\n> pointer: %p, data: %d, color: %d", iter, iter->data, iter->color);
    // }
    // printf("\n\n");
    // using the rbInsertFixUp to re-color nodes
    rbInsertFixUp(root, z);
}


/// @brief calculate the pointer to the mimimum node 
/// @param root I- the root of red black tree
/// @return pointer to the minimum node
RBTree_Node* RBTreeMinimum(RBTree_Node* root)
{
    RBTree_Node** p = &root;
    if(*p != &Nil && *p != NULL)
        while((*p)->lchild != &Nil)
            (*p) = (*p)->lchild;        
    return *p;
}

/// @brief remove the node u and connect v with u's parent mutually(regardless the child u)
/// @param root IO- the root of the red black tree
/// @param u I- the node waiting to be deleted
/// @param v I- the node waiting to be connected
void RBTransplant(RBTree_Node** root, RBTree_Node* u, RBTree_Node* v)
{
    if(u->parent == &Nil)
        *root = v;
    else if(u->parent->lchild = u)
        u->parent->lchild = v;
    else
        u->parent->rchild = v;
    // if(v != &Nil) // 应该是要加这一句的，毕竟Nil has no parent, but Nil can not be achieved outside, so useless
        v->parent =u->parent;
}


void RBTreeDeleteFixup(RBTree_Node** root, RBTree_Node* x)
{

}


void RBTreeDelete(RBTree_Node** root, RBTree_Node* z)
{
    RBTree_Node* y = z;
    RBT_Color y_original_color = y->color;
    RBTree_Node* x;
    if(z->lchild == &Nil){
        printf("> left nil\n");
        x = z->rchild;
        RBTransplant(root, z, z->rchild);
    }
    else if(z->rchild == &Nil){
        printf("> right nil\n");
        x = z->lchild;
        RBTransplant(root, z, z->lchild);
    }
    else{
        printf("> no nil\n");
        y = RBTreeMinimum(z->rchild);
        y_original_color = y->color;
        x = y->rchild;
        if(y->parent == z){
            x->parent = y; // 测试是否必要
        }
        else{
            RBTransplant(root, y, y->rchild);
            y->rchild = z->rchild;
            y->rchild->parent = y;
        }
        RBTransplant(root, z, y);
        y->lchild = z->lchild;
        y->lchild->parent = y;
        y->color = z->color;
    }
    printf("> starting the color fix up\n");
    if(y_original_color == RBT_Color::BLACK){
        RBTreeDeleteFixup(root, x);
    }
}

void callRedBlackTree()
{
    printf("> Running test for chapter 13\n");
    int insert_size = 9;
    RBTree_Node* root = NULL;
    for(int i = 0; i < insert_size; i++){
        RBTree_Node p;
        // p.data = insert_size - i;
        p.data = i;
        RBTreeInsert(&root, &p);
    }
    // insert a red black tree
    RBTreeInorder(root);

    // black height check
    RBTreeHeightCheck(root);

    // tree minimum
    RBTree_Node* min = RBTreeMinimum(root);
    if(min != NULL){
        printf("> min data-%d, color-%d, pointer-%p\n", min->data, min->color, min);
    }
    else{
        printf("> Can't find minimum node in the red black tree\n"); // %16p 14 + 2
    }
    RBTree_Node* node = iterativeRBTreeSearch(root, 5);
    if(node != NULL){
        printf("\n> node data-%d, color-%d, pointer-%p\n", node->data, node->color, node);
        // red black tree delete
        RBTreeDelete(&root, node);    
        RBTreeInorder(root);
    }
    else
        printf("> Can't find this node in the red black tree\n"); // %16p 14 + 2
    printf("> Finish running test for chapter 13\n");
}