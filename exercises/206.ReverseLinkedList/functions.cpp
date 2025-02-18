#include "functions.h"

// Node constructor
Node::Node(int val)
{
    data = val;
    next = nullptr;
}

// LinkedList constructor
LinkedList::LinkedList()
{
    head = nullptr;
}

// LinkedList destructor: free all nodes
LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// insert at the end
void LinkedList::insert(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Delete a node by value
void LinkedList::remove(int val)
{
    if (head == nullptr)
        return;

    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
        temp = temp->next;

    if (temp->next == nullptr)
    {
        std::cout << "Value not found\n";
        return;
    }

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Reverse this liked List
void LinkedList::reverse()
{
    Node *prev = nullptr, *curr = head;
    while (curr != nullptr)
    {
        Node *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    head = prev;
}

// Print the Linked List
void LinkedList::printLL()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << "->";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// ------------------------------------------------------------------------------

ListNode *Solution::reverseList(ListNode *head)
{
    ListNode *prev = nullptr, *curr = head;
    while (curr != nullptr)
    {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    return prev;
}
