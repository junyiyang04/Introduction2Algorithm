#ifndef _CP_10_
#define _CP_10_
#include <iostream>
#include "export_macro.h"


// ******************************************************************
// *                                                                *
// *                   single linkded list                          *
// *               - whose head stores nothing                      *
// *               - elements counting start from 0                 *
// *                                                                *
// ******************************************************************
typedef struct _LNode_
{
    int data;
    _LNode_* next;
    // LNode* prior;
}LNode;

I2A_API void CreateLinkList(LNode** head);

/// @brief find the NO.idx Node
/// @param head -I head of the link list 
/// @param idx -I  index of the node
/// @return the pointer to the node 
I2A_API LNode* getNode(LNode* head, int idx);

/// @brief length of link list
/// @param head 
/// @return 
I2A_API int lengthLinkList(LNode* head);

I2A_API void insertLinkList(LNode* head, int idx, int value);

I2A_API void deleteNode(LNode* head, int idx);

/// @brief empty the link list
/// @param head 
I2A_API void emptyLNode(LNode* head);

/// @brief delete the link list
/// @param head 
I2A_API void deleteLNode(LNode* head);

I2A_API void callLNode();

I2A_API void showLinkList(LNode* head);
// ******************************************************************
// *                                                                *
// *                    double linked list                          *
// *               - whose head acts as a sentinel                  *
// *                                                                *
// ******************************************************************

/**
 * this is the double linked list whose head acts as a sentinel
*/
typedef struct _DLNode_
{
    int data;
    _DLNode_* prev;
    _DLNode_* next;
}DLNode;


I2A_API void createDoubleLinkList(DLNode** head);

/// @brief get the the node of the double linked list
/// @param head I- the head of the double linked list
/// @param idx I- index
/// @return the node
I2A_API DLNode* getDNode(DLNode* head, int idx);

/// @brief the length of the double linked list
/// @param head I- the head of the double linked list
/// @return the length
I2A_API int lengthDoubleLinkList(DLNode* head);

/// @brief insert an element in the double linked list
/// @param head I-
/// @param idx I- the index of the double linked list
/// @param value the value of the element
I2A_API void insertDoubleLinkList(DLNode* head, int idx, int value);

/// @brief delete the No.idx element of the double linked list
/// @param head I-
/// @param idx I- the index of the element that gonna to be deleted
I2A_API void deleteDNode(DLNode* head, int idx);

/// @brief empty the double linked list
/// @param head I-
I2A_API void emptyDLNode(DLNode* head);

/// @brief delete the double linked list
/// @param head 
I2A_API void deleteDLNode(DLNode* head);

I2A_API void callDLNode();
#endif
