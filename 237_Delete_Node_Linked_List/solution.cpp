#include "header.h"

// Copy next value to node value until the end. 

void deleteNode(ListNode* node) {

    ListNode* temp = node;
    ListNode* pre = nullptr;

    while (temp->next)
    {
        temp->val = temp->next->val;
        pre = temp;
        temp = temp->next;
    }

    pre->next = nullptr;
}