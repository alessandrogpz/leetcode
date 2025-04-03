
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head);
    void DisplayLinkedList(ListNode *head);
    ListNode *ReverseLinkedList(ListNode *head);
};

#endif
