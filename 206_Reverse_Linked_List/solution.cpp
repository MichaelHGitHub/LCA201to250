#include "header.h"

ListNode* reverseList(ListNode* head)
{
    if (!head)
    {
        return head;
    }

    ListNode dummy;
    dummy.next = head;
    ListNode* current = head->next;
    head->next = nullptr;

    while (current)
    {
        ListNode* next = current->next;
        current->next = dummy.next;
        dummy.next = current;

        current = next;
    }
    return dummy.next;
}