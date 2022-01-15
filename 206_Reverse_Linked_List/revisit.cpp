#include "header.h"

ListNode* reverseList_r(ListNode* head)
{
    ListNode dummy;
    dummy.next = head;

    if (head)
    {
        ListNode* node = head->next;
        head->next = nullptr;

        while (node)
        {
            ListNode* temp = node->next;
            node->next = dummy.next;
            dummy.next = node;
            node = temp;
        }
    }

    return dummy.next;
}

