#include "header.h"

ListNode* removeElements(ListNode* head, int val)
{
    ListNode dummy;
    dummy.next = head;
    ListNode* pre = &dummy;
    while (head)
    {
        if (head->val == val)
        {
            pre->next = head->next;
        }
        else
        {
            pre = head;
        }
        head = head->next;
    }
    return dummy.next;
}