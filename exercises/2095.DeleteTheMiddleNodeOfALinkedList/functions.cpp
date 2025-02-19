#include "functions.h"

// Node class constructor implementation.
Node::Node(int val)
{
    data = val;
    next = nullptr;
}

// SinglyLinkedList constructor implementation.
SinglyLinkedList::SinglyLinkedList()
{
    head = nullptr;
}

// Inserts a new node with the given value at the end of the linked list.
void SinglyLinkedList::insert(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Removes the first occurrence of a node with the specified value.
void SinglyLinkedList::remove(int val)
{
    if (head == nullptr)
        return;

    // Case 1: The node to remove is the head.
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Case 2: Traverse to find the node before the target node.
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != val)
    {
        temp = temp->next;
    }

    // If the value is not found, do nothing.
    if (temp->next == nullptr)
        return;

    // Delete the node.
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Displays the entire linked list.
void SinglyLinkedList::display()
{
    if (head == nullptr)
    {
        std::cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Destructor: Deletes all nodes to prevent memory leaks.
SinglyLinkedList::~SinglyLinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Deletes the middle node from the linked list and returns the updated head.
Node *deleteMiddle_1(Node *head)
{
    // Edge case: Empty list or a single-node list.
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    // Count the number of nodes.
    int numberOfNodes = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        numberOfNodes++;
        temp = temp->next;
    }

    // Determine the 0-based index of the middle node.
    int nodeToDelete = numberOfNodes / 2;

    // Edge case: Only one node should be deleted.
    if (nodeToDelete == 0)
    {
        delete head;
        return nullptr;
    }

    // Traverse to the node just before the middle node.
    temp = head;
    for (int i = 0; i < nodeToDelete - 1; i++)
    {
        temp = temp->next;
    }

    // Delete the middle node.
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return head;
}

// Deletes the middle element of a linked list using slow and fast pointers.
// Returns the head of the updated linked list.
Node *deleteMiddle_2(Node *head)
{
    // If the list is empty or contains only one node, delete head and return nullptr.
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr; // To track the node before the slow pointer.

    // Move fast two steps and slow one step until fast reaches the end.
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // 'slow' now points to the middle node.
    // Remove it by linking the previous node to the node after slow.
    if (prev != nullptr)
    {
        prev->next = slow->next;
    }
    delete slow;

    return head;
}
