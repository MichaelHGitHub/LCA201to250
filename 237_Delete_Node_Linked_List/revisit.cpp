#include "header.h"

void deleteNode_r(ListNode* node)
{
    ListNode* newTail = nullptr;

    while (node->next != nullptr)
    {
        node->val = node->next->val;
        newTail = node;
        node = node->next;
    }
    newTail->next = nullptr;
    delete node;
}