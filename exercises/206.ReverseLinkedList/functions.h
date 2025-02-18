#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int val);
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    void insert(int val);
    void remove(int val);
    void reverse();
    void printLL();
};

// ------------------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head);
};

#endif
