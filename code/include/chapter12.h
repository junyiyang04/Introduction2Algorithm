#include <iostream>
#include "export_macro.h"

// ******************************************************************
// *                                                                *
// *                     binary search tree                         *
// *                     Inorder Tree Walk                          *
// *                     Preorder Tree Walk                         *
// *                     Postorder Tree Walk                        *
// *                                                                *
// ******************************************************************

typedef struct _BTree_Node_
{
    int data;
    struct _BTree_Node_ *lchild, *rchild, *parent;
}BTree_Node;


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
I2A_API void Preorder(BTree_Node* p);
I2A_API void Inorder(BTree_Node* p);
I2A_API void Postorder(BTree_Node* p);

/// @brief calculate pointer to the node with data 'key'
/// @param root I- the root of the binary search tree
/// @param key I- the value of the target node
/// @return pointer to the node with data 'key'
I2A_API BTree_Node* iterativeTreeSearch(BTree_Node* root, int key);


I2A_API BTree_Node* treeSearch(BTree_Node* p, int key);

/// @brief calculate the pointer to the mimimum node 
/// @param root I- the root of binary search tree
/// @return pointer to the minimum node
I2A_API BTree_Node* treeMinimum(BTree_Node* root);

/// @brief calculate the pointer to the maximum node 
/// @param root I- the root of binary search tree
/// @return pointer to the maximum node
I2A_API BTree_Node* treeMaximum(BTree_Node* root);


/// @brief calculate the pointer to the successor of node 'p'
/// @param p I- a node of binary search tree
/// @return pointer to the successor node
I2A_API BTree_Node* treeSuccessor(BTree_Node* p);

/// @brief calculate the pointer to the predecessor of node 'p'
/// @param p I- a node of binary search tree
/// @return pointer to the predecessor node
I2A_API BTree_Node* treePredecessor(BTree_Node* p);

/// @brief used to add nodes to a binary search tree
/// @author Cillian Young
/// @param root IO- the root of the binary search tree(double * will allow the root to be inited as both NULL and others)
/// @param p1 I- the node to insert
/// @note the parameter 'p1' is not suitable, the only value need to pass through this position is the node's data
I2A_API void treeInsert(BTree_Node** root, BTree_Node* p1);

/**
 *     1. the left situation(right situation is the same with the left)
 *
 *        parent                parent
 *       /        --------->   /
 *      u  (v)                v  free(u)
 *  
 *     2. the location that a node's parent transplant to is null
 *    
 *        parant(NULL)
 *       /        ---------> root = v
 *      u 
 */
/// @brief move subtrees around within the binary search tree(to my understanding, replacing u's place in the tree with v
///        , includes only the (v & u->parent) connection)
/// @param root the root on behalf of the binary search tree
/// @param u the position where want to move the subtree
/// @param v subtree root
/// @note this operation don't change the location of u v
I2A_API void transPlant(BTree_Node* root, BTree_Node* u,BTree_Node* v);

/// @brief delete the node p
/// @param root the root of the tree 
/// @param p the node waiting to be deleted
I2A_API void treeDelete(BTree_Node* root, BTree_Node* p);

/**
 * tree structure
 *   0
 *    \
 *     1
 *      \
 *       2
 *        \
 *         3
 *          \
 *           4
 *          / \
 *         4   5
 *            / \
 *           5   9
 *              /
 *             8
 *            /
 *           7
 *          / \
 *         6   8
 */
I2A_API void callBinarySearchTree();
