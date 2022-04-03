#include "header.h"

bool isPalindrome_r(ListNode* head)
{
    ListNode *fast = head, *slow = head;
    int size = 0;

    // Find the mid-node of the list and count the number of nodes
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        ++size;
        if (fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            ++size;
        }
    }
    ++size;

    // If number is odd, move slow to the start of second
    if(size > 1 && size % 2 != 0)
    {
        slow = slow->next;
    }

    // Revert the second half of the list
    while (slow != fast)
    {
        ListNode* temp = slow;
        slow = slow->next;

        temp->next = fast->next;
        fast->next = temp;
    }

    // compare the two halves of the list if they are palindrome
    bool isPalindrome = true;
    size /= 2;
    slow = head;
    for (int i = 0; i < size; i++)
    {
        if (slow->val != fast->val)
        {
            isPalindrome = false;
            break;
        }
        slow = slow->next;
        fast = fast->next;
    }

    return isPalindrome;
}