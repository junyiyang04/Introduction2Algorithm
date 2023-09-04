#include "chapter10.h"
#include "common.h"
#include <vector>
// ******************************************************************
// *                                                                *
// *                            stacks                              *
// *                                                                *
// ******************************************************************

template <typename T>
void stackEmpty()
{
    std::vector<int> a;
    a.push_back(1);
}

// ******************************************************************
// *                                                                *
// *                   single linkded list                          *
// *               - whose head stores nothing                      *
// *               - elements counting start from 0                 *
// *                                                                *
// ******************************************************************


void CreateLinkList(LNode** head)
{
    *head = (LNode*)malloc(sizeof(LNode));
    (*head)->next = NULL;
}



/// @brief find the NO.idx Node
/// @param head -I head of the link list 
/// @param idx -I  index of the node
/// @return the pointer to the node 
LNode* getNode(LNode* head, int idx)
{
    LNode *p = head;
    int loc = -1; 
    while(p->next != NULL && loc < idx)
    {
        p = p->next;
        loc++;
    }
    if(loc < idx || idx < -1)
    {
        abortMesage("Error: idx is out of range of the LNode");
        abort();
    }
    return p;
}

/// @brief length of link list
/// @param head 
/// @return 
int lengthLinkList(LNode* head)
{
    LNode* p = head;
    int i = 0;
    while(p->next != NULL){
        p = p->next;
        i++;
    }
    return i;
}


void insertLinkList(LNode* head, int idx, int value)
{
    LNode *p;
    LNode *tmp;
    p = getNode(head, idx - 1);
    tmp = (LNode*)malloc(sizeof(LNode));
    if(tmp)
    {
        tmp->data = value;
        tmp->next = p->next;
        p->next = tmp;
    }
}

void deleteNode(LNode* head, int idx)
{
    LNode *p;
    LNode *tmp;
    p = getNode(head, idx - 1);
    tmp = p->next;
    p->next = tmp ->next;
    free(tmp);
}

/// @brief empty the link list
/// @param head 
void emptyLNode(LNode* head)
{
    LNode *p, *q;
    p = head->next;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    head->next = NULL;
}

/// @brief delete the link list
/// @param head 
void deleteLNode(LNode* head)
{
    emptyLNode(head);
    free(head);
    head = NULL;
}

void showLinkList(LNode* head)
{
    int cnt = 1;
    LNode* p = head->next;
    while(p != NULL)
    {
        printf("No.%d element is %d\n", ++cnt, p->data);
        p = p->next;
    }
}

void callLNode()
{
    printf(">> Calling the link list \n");
    int size = 5;
    LNode *head;
    CreateLinkList(&head);
    for (int i = 0; i < size; i++)
        insertLinkList(head, 0, i);
    
    int cnt = 0;
    LNode* p = head->next;
    while(p != NULL)
    {
        printf("No.%d element is %d\n", ++cnt, p->data);
        p = p->next;
    }
    emptyLNode(head);
    int len = lengthLinkList(head);
    printf("the length of the list is %d\n", len);
    std::cout << head->next << std::endl;
    deleteLNode(head);
    std::cout << head->next << std::endl;
    head = NULL;
}
// ******************************************************************
// *                                                                *
// *                    double linked list                          *
// *               - whose head acts as a sentinel                  *
// *                                                                *
// ******************************************************************

void createDoubleLinkList(DLNode** head)
{
    *head = (DLNode*)malloc(sizeof(DLNode));
    (*head)->next = *head;
    (*head)->prev = *head;
}

/// @brief get the the node of the double linked list
/// @param head I- the head of the double linked list
/// @param idx I- index
/// @return the node
DLNode* getDNode(DLNode* head, int idx)
{
    DLNode *p = head;
    int loc = -1; 
    while(p->next != head && loc < idx)
    {
        p = p->next;
        loc++;
    }
    if(loc < idx || idx < -1)
    {
        abortMesage("Error: idx is out of range of the LNode");
        abort();
    }
    return p;
}

/// @brief the length of the double linked list
/// @param head I- the head of the double linked list
/// @return the length
int lengthDoubleLinkList(DLNode* head)
{
    DLNode* p = head;
    int i = 0;
    while(p->next != head){
        p = p->next;
        i++;
    }
    return i;
}

/// @brief insert an element in the double linked list
/// @param head I-
/// @param idx I- the index of the double linked list
/// @param value the value of the element
void insertDoubleLinkList(DLNode* head, int idx, int value)
{
    DLNode *p;
    DLNode *tmp;
    p = getDNode(head, idx - 1);
    tmp = (DLNode*)malloc(sizeof(DLNode));
    if(tmp)
    {
        tmp->data = value;
        tmp->next = p->next;
        p->next = tmp;
        tmp->prev = p;
        tmp->next->prev = tmp;
    }
}


void pushBackDLNode(DLNode* head, int value)
{
    DLNode* p = head->prev;
    DLNode* tmp;
    tmp = (DLNode*)malloc(sizeof(DLNode));
    if(tmp)
    {
        tmp->data = value;
        tmp->next = p->next;
        p->next = tmp;
        tmp->prev = p;
        tmp->next->prev = tmp;
    }
}

void pushFrontDLNode(DLNode* head, int value)
{
    insertDoubleLinkList(head, 0, value);
}

/// @brief delete the No.idx element of the double linked list
/// @param head I-
/// @param idx I- the index of the element that gonna to be deleted
void deleteDNode(DLNode* head, int idx)
{
    DLNode *p;
    DLNode *tmp;
    p = getDNode(head, idx - 1);
    tmp = p->next;
    p->next = tmp ->next;
    p->next->prev = p;
    free(tmp);
}

/// @brief empty the double linked list
/// @param head I-
void emptyDLNode(DLNode* head)
{
    DLNode *p, *q;
    p = head->next;
    while(p != head)
    {
        q = p;
        p = p->next;
        free(q);
    }
    head->next = head;
    head->prev = head;
}

/// @brief delete the double linked list
/// @param head 
void deleteDLNode(DLNode* head)
{
    emptyDLNode(head);
    free(head);
    head = NULL;
}

void callDLNode()
{
    printf(">> Calling the double linked list \n");
    int size = 5;
    DLNode *head;
    createDoubleLinkList(&head);
    head->data = 1000;
    for (int i = 0; i < size; i++)
    {
        pushFrontDLNode(head, i);
        pushBackDLNode(head, i);
    }
    int len = lengthDoubleLinkList(head);
    printf("the length of the double linked list is %d\n", len);
    int cnt = 0;
    DLNode* p = head->next;
    while(p != head)
    {
        printf("No.%d element is %d\n", ++cnt, p->data);
        p = p->next;
    }

    emptyDLNode(head);
    len = lengthDoubleLinkList(head);
    printf("the length of the double linked list is %d\n", len);
    std::cout << head->next << std::endl;
    deleteDLNode(head);
    std::cout << head->next << std::endl;
    head = NULL;
}