#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

/**
 * Node class represents a single element (node) in the singly linked list.
 * Each node contains:
 * - An integer `data` to store the value.
 * - A pointer `next` that points to the next node in the list.
 */
class Node
{
public:
    int data;   // Stores the value of the node
    Node *next; // Pointer to the next node in the list

    // Constructor declaration
    Node(int val);
};

/**
 * SinglyLinkedList class provides the structure and methods for managing a singly linked list.
 * It includes:
 * - Insertion at the end.
 * - Removal of a node by value.
 * - Displaying the list.
 */
class SinglyLinkedList
{
private:
    Node *head; // Pointer to the first node in the linked list (head)

public:
    // Constructor declaration: Initializes the linked list as empty.
    SinglyLinkedList();

    // Inserts a new node with the given value at the end of the list.
    void insert(int val);

    // Removes the first node with the given value.
    void remove(int val);

    // Displays the entire linked list.
    void display();

    // Destructor declaration: Cleans up memory by deleting all nodes.
    ~SinglyLinkedList();
};

// Deletes the middle node from the list and returns the updated head pointer.
Node *deleteMiddle_1(Node *head);
Node *deleteMiddle_2(Node *head);

#endif // FUNCTIONS_H
