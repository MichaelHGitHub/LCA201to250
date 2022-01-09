#include "header.h"

ListNode* removeElements_r(ListNode* head, int val)
{
    ListNode dummy;
    dummy.next = head;
    ListNode* node = &dummy;

    while (node->next)
    {
        if (node->next->val == val)
        {
            ListNode* temp = node->next;
            node->next = node->next->next;
            delete temp;
        }
        else
        {
            node = node->next;
        }
    }
    return dummy.next;
}