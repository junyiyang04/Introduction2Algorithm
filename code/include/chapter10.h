#ifndef _CP_10_
#define _CP_10_
#include <iostream>


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

void CreateLinkList(LNode** head);

/// @brief find the NO.idx Node
/// @param head -I head of the link list 
/// @param idx -I  index of the node
/// @return the pointer to the node 
LNode* getNode(LNode* head, int idx);

/// @brief length of link list
/// @param head 
/// @return 
int lengthLinkList(LNode* head);

void insertLinkList(LNode* head, int idx, int value);

void deleteNode(LNode* head, int idx);

/// @brief empty the link list
/// @param head 
void emptyLNode(LNode* head);

/// @brief delete the link list
/// @param head 
void deleteLNode(LNode* head);

void callLNode();

void showLinkList(LNode* head);
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


void createDoubleLinkList(DLNode** head);

/// @brief get the the node of the double linked list
/// @param head I- the head of the double linked list
/// @param idx I- index
/// @return the node
DLNode* getDNode(DLNode* head, int idx);

/// @brief the length of the double linked list
/// @param head I- the head of the double linked list
/// @return the length
int lengthDoubleLinkList(DLNode* head);

/// @brief insert an element in the double linked list
/// @param head I-
/// @param idx I- the index of the double linked list
/// @param value the value of the element
void insertDoubleLinkList(DLNode* head, int idx, int value);

/// @brief delete the No.idx element of the double linked list
/// @param head I-
/// @param idx I- the index of the element that gonna to be deleted
void deleteDNode(DLNode* head, int idx);

/// @brief empty the double linked list
/// @param head I-
void emptyDLNode(DLNode* head);

/// @brief delete the double linked list
/// @param head 
void deleteDLNode(DLNode* head);

void callDLNode();
#endif
