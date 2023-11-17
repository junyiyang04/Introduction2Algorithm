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

void RBTreeInorder(RBTree_Node* p)
{
    if(p != &Nil){
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
void rightRotate(RBTree_Node* root, RBTree_Node* y)
{
    RBTree_Node* x;
    x = y->lchild;
    y->lchild = x->rchild;
    if( x->rchild != &Nil) // 这里要不要改成sentinel T.nil
        x->rchild->parent = y;
    x->parent = y->parent;
    if( y->parent == &Nil)
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
    if( y->lchild != &Nil) // 这里要不要改成sentinel T.nil
        y->lchild->parent = x;
    y->parent = x->parent;
    if( x->parent == &Nil)
        root = y;
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
void rbInsertFixUp(RBTree_Node* root, RBTree_Node* z)
{
    printf("> entered fix up: %p\n", z);
    // parent is red will violate the priperties of red black tree
    while(z->parent->color == RBT_Color::RED){
        printf("> entered violation solver\n");
        // LEFT: when parent is a left child
        if(z->parent == z->parent->parent->lchild){ 
            printf("> entered left\n");

            RBTree_Node* y = z->parent->parent->rchild; // uncle
            // case1: 
            // indicator node z is the target to change, after adjustment indicator node z will go up to z1
            //     node                   node
            //     |                      |
            //     b                      r(z1)
            //    / \       re-color     / \
            //   r   r(y)  --------->   b   b       color changed in location
            //  /                      /
            // r(z)                   r(z)
            if(y->color == RBT_Color::RED){ 
                printf("> entered case1\n");

                z->parent->color = RBT_Color::BLACK;
                y->color = RBT_Color::BLACK;
                z->parent->parent->color = RBT_Color::RED;
                z = z->parent->parent;
            }
            else if(z == z->parent->rchild){
                printf("> entered case2\n");
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
        }
    }
    root->color = RBT_Color::BLACK; // the final check
}

/// @brief 
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

    // using the rbInsertFixUp to re-color nodes
    rbInsertFixUp(*root, z);
}

void callRedBlackTree()
{
    printf("> Running test for chapter 13\n");
    int insert_size = 2;
    RBTree_Node* root = NULL;
    for(int i = 0; i < insert_size; i++){
        RBTree_Node p;
        p.data = insert_size - i;
        RBTreeInsert(&root, &p);
    }

    RBTreeInorder(root);
}