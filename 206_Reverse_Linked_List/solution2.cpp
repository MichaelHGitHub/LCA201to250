#include "header.h"

static ListNode* helper(ListNode* head, ListNode** tail);

ListNode* reverseList2(ListNode* head)
{
    ListNode* last = nullptr;
    ListNode* new_head = helper(head, &last);
    return new_head;
}

ListNode* helper(ListNode* head, ListNode** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    ListNode* last = nullptr;
    ListNode* new_head = helper(head->next, &last);

    last->next = head;
    head->next = nullptr;
    *tail = head;

    return new_head;
}