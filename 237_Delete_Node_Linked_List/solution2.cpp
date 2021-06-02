#include "header.h"

// Copy value of next node to node, and delete next node.

void deleteNode2(ListNode* node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}