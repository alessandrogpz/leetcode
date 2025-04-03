#include "functions.h"
#include <iostream>
#include <vector>

int Solution::pairSum(ListNode *head)
{
    // Use slow and fast pointers to find the middle of the list
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode *prev = nullptr;
    ListNode *current = slow;
    ListNode *next = nullptr;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Calculate the maximum twin sum
    ListNode *firstHalf = head;
    ListNode *secondHalf = prev; // Start of the reversed second half
    int maxSum = 0;

    while (secondHalf)
    {
        int twinSum = firstHalf->val + secondHalf->val;
        maxSum = std::max(maxSum, twinSum);

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Restore the original list (optional but good practice)
    // Re-reverse the second half
    current = prev;
    prev = nullptr;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Reconnect the first half with the restored second half
    ListNode *temp = head;
    while (temp->next != slow && temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = slow;

    return maxSum;
}

void Solution::DisplayLinkedList(ListNode *head)
{
    ListNode *current = head;

    while (current != nullptr)
    {
        std::cout << current->val << ", ";
        current = current->next;
    }

    std::cout << '\n';
}

ListNode *Solution::ReverseLinkedList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // New head of the reversed list
}