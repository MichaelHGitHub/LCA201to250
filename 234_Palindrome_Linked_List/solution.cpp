#include "header.h"

// Three steps:
// 1. Use two runners to find the length of the list and head 
// of the second half. 
// 2. Revert the first half of the list. 
// 3. Compare the nodes of the two half.

bool isPalindrome(ListNode* head)
{
    if (!head)
    {
        return false;
    }

    ListNode *node1 = head, *node2 = head;
    int count = 0;

    // After the loop is done, node1 will be pointing at the head
    // of the second half.
    while (node2)
    {
        node1 = node1->next;
        node2 = node2->next;
        ++count;
        if (node2)
        {
            node2 = node2->next;
            ++count;
        }
    }

    // Revert the first half of the list. 
    ListNode dummy;
    dummy.next = head;
    ListNode* temp = head->next;
    head->next = nullptr;
    int half = count / 2;
    for (int i = 1; i < half; i++)
    {
        node2 = temp->next;
        temp->next = dummy.next;
        dummy.next = temp;
        temp = node2;
    }
    node2 = dummy.next;

    // Compare the two half of the list.
    while (node1 && node2)
    {
        if (node1->val != node2->val)
        {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    return true;
}