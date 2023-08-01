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
// *                   single link list                             *
// *                                                                *
// ******************************************************************


// void CreateLinkList(LNode** head)
// {
//     *head = (LNode*)malloc(sizeof(LNode));
//     (*head)->next = NULL;
// }

// /// @brief length of link list
// /// @param head 
// /// @return 
// int lengthLinkList(LNode* head)
// {
//     LNode* p = head;
//     int i = 0;
//     while(p->next != NULL){
//         p = p->next;
//         i++;
//     }
//     return i;
// }


// void insertLinkList(LNode* head, int idx, int value)
// {
//     LNode *p;

// }


void callLNode()
{
    LNode<int> link;
    // std::cout << link.head()->next << std::endl;
}