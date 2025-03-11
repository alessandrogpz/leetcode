
#include "functions.h"

ListNode *Solution::oddEvenList(ListNode *head)
{
    // If list has fewer than 2 nodes, nothing to do
    if (!head || !head->next)
    {
        return head;
    }

    ListNode *odd = head;        // 1st node (odd indexed)
    ListNode *even = head->next; // 2nd node (even indexed)
    ListNode *evenHead = even;   // Save the head of even list

    // Traverse and reorder
    while (even && even->next)
    {
        odd->next = even->next; // Connect odd node to next odd
        odd = odd->next;        // Move odd pointer
        even->next = odd->next; // Connect even node to next even
        even = even->next;      // Move even pointer
    }

    // Connect the end of odd list to the beginning of even list
    odd->next = evenHead;

    return head;
}