# Approaches to Deleting the Middle Node of a Singly Linked List

This document explains two methods to delete the middle node from a singly linked list. Both methods ultimately remove the middle element, but they differ in how they locate the node to delete.

## 1. Counting Nodes Approach (`deleteMiddle_1`)

### Description

This approach consists of two main steps:

1. **Count the Nodes:**  
   Traverse the entire list to count the total number of nodes.
2. **Locate and Delete the Middle Node:**
   - Calculate the middle index using integer division (`numberOfNodes / 2`).
   - Traverse the list a second time to reach the node immediately _before_ the middle node.
   - Update the `next` pointer of this node to bypass the middle node.
   - Delete the middle node.

### Example Code

```cpp
Node* deleteMiddle_1(Node* head) {
    // Edge case: Empty list or single-node list.
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Count the number of nodes.
    int numberOfNodes = 0;
    Node* temp = head;
    while (temp != nullptr) {
        numberOfNodes++;
        temp = temp->next;
    }

    // Determine the index (0-based) of the middle node.
    int nodeToDelete = numberOfNodes / 2;

    // Traverse to the node immediately before the middle.
    temp = head;
    for (int i = 0; i < nodeToDelete - 1; i++) {
        temp = temp->next;
    }

    // Delete the middle node.
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return head;
}
```

### Time Complexity

- **Counting the nodes:** O(n)
- **Traversing to the middle:** O(n)  
  **Overall Time Complexity:** O(n) (since both passes are linear)

## 2. Two-Pointer (Slow and Fast) Approach (`deleteMiddle_2`)

### Description

This method uses two pointers:

- **Slow Pointer:** Advances one node at a time.
- **Fast Pointer:** Advances two nodes at a time.

As the fast pointer reaches the end of the list, the slow pointer will be at the middle node. Additionally, a `prev` pointer is maintained to keep track of the node preceding the slow pointer. Once the middle node is located, it is removed by adjusting the `next` pointer of the `prev` node.

### Example Code

```cpp
Node* deleteMiddle_2(Node* head) {
    // Edge case: Empty list or single-node list.
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;  // Tracks the node before slow.

    // Move fast two steps and slow one step until fast reaches the end.
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // 'slow' now points to the middle node.
    prev->next = slow->next;
    delete slow;

    return head;
}
```

### Time Complexity

- **Single traversal using two pointers:** O(n)  
  **Overall Time Complexity:** O(n)

## Summary of Time Complexities

- **Both methods have an overall time complexity of O(n).**
- The counting approach requires two passes through the list, while the two-pointer approach finds the middle node in a single pass.
- **Space Complexity for both methods:** O(1) auxiliary space (no additional data structures are used).

## Conclusion

Both approaches effectively remove the middle node from a singly linked list:

- The **Counting Nodes Approach** is straightforward and easy to understand, but it requires two passes.
- The **Two-Pointer Approach** is more efficient in practice since it accomplishes the task in one pass, though it requires careful handling of pointers.

---
