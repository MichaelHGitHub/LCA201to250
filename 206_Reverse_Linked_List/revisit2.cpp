#include "header.h"

static ListNode* reverseList(ListNode* head, ListNode** tail);

ListNode* reverseList_r2(ListNode* head)
{
    ListNode* pTail = nullptr;
    return reverseList(head, &pTail);
}

ListNode* reverseList(ListNode* head, ListNode** ppTail)
{
    if (!head)
    {
        return head;
    }

    if (!head->next)
    {
        *ppTail = head;
        return head;
    }

    ListNode* node = head->next;
    head->next = nullptr;
    ListNode* pTail = nullptr;
    ListNode* new_head = reverseList(node, &pTail);

    if (pTail)
    {
        pTail->next = head;
        *ppTail = head;
    }

    return new_head;

}