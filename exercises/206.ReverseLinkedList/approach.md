# Approach for Reversing a Singly Linked List

This document outlines the approach taken to implement a reversal of a singly linked list using two different styles:

1. **Custom LinkedList Class** (using a `Node` structure)
2. **LeetCode-Style Implementation** (using a `ListNode` structure)

Both implementations reverse the list in **O(n)** time and **O(1)** space, with additional considerations for proper memory management.

---

## 1. Custom LinkedList Implementation

### Data Structures

- **Node Class**  
  Each node contains:

  - `data`: The value stored in the node.
  - `next`: A pointer to the next node in the list.

```cpp
class Node {
public:
    int data;
    Node \*next;
    Node(int val);
};
```

- **LinkedList Class**
  This class manages the list and includes methods for inserting, removing, reversing, and printing nodes. It encapsulates a pointer to the head node.

  ```cpp
  class LinkedList {
  private:
      Node *head;
  public:
      LinkedList();
      ~LinkedList(); // Destructor to free allocated nodes
      void insert(int val);
      void remove(int val);
      void reverse();
      void printLL();
  };
  ```

### Reversal Algorithm

1. **Initialization:**
   Set two pointers:

   - `prev` to `nullptr`
   - `curr` to the current `head` of the list

2. **Traversal and Reversal:**
   While `curr` is not `nullptr`:

   - Save `curr->next` in a temporary pointer (`nextTemp`).
   - Reverse the pointer by setting `curr->next = prev`.
   - Move `prev` and `curr` one step forward: `prev` becomes `curr`, and `curr` becomes `nextTemp`.

3. **Update Head:**
   Once the loop completes, assign `head = prev` (the new head of the reversed list).

#### Code Example

```cpp
void LinkedList::reverse() {
    Node *prev = nullptr, *curr = head;
    while (curr != nullptr) {
        Node *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    head = prev;
}
```

### Complexity Analysis

- **Time Complexity:**
  **O(n)** – Each node is visited once during the reversal.

- **Space Complexity:**
  **O(1)** – Only a fixed number of pointers are used regardless of the list size.

### Memory Management

- A destructor is implemented to traverse the list and `delete` each node to prevent memory leaks.

  ```cpp
  LinkedList::~LinkedList() {
      Node* current = head;
      while (current != nullptr) {
          Node* nextNode = current->next;
          delete current;
          current = nextNode;
      }
  }
  ```

---

## 2. LeetCode-Style Implementation

### Data Structures

- **ListNode Structure**
  LeetCode problems typically define a simple node structure for linked lists:

  ```cpp
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
  ```

- **Solution Class**
  Contains a method that reverses a linked list given its head node.

  ```cpp
  class Solution {
  public:
      ListNode* reverseList(ListNode* head);
  };
  ```

### Reversal Algorithm

The reversal process is similar to the custom implementation:

- Initialize `prev` to `nullptr` and `curr` to the head node.
- Iterate through the list, reversing the direction of each pointer.
- Return `prev` as the new head of the reversed list.

#### Code Example

```cpp
ListNode* Solution::reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr != nullptr) {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
```

### Complexity Analysis

- **Time Complexity:**
  **O(n)** – Each node is processed once.

- **Space Complexity:**
  **O(1)** – Constant extra space is used during the reversal.

---

## 3. Testing

Tests were created using **Boost.Test** to ensure both implementations work as expected. The test cases cover:

- Insertion and printing of the linked list.
- Removing nodes.
- Reversing the linked list.
- Handling edge cases, such as reversing an empty list.
- Memory leak checks (ensured by proper destructor implementation in the `LinkedList` class).

Example Boost.Test case for the reversal:

```cpp
BOOST_AUTO_TEST_CASE(test_linked_list_reverse) {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.reverse();
    std::string output = capturePrintLL(list);
    BOOST_CHECK_EQUAL(output, "30->20->10->NULL\n");
}
```

---

## 4. Conclusion

- **Efficiency:** Both implementations reverse the linked list in linear time with constant extra space.
- **Memory Safety:** The custom `LinkedList` class includes a destructor to prevent memory leaks.
- **Adaptability:**
  - The LeetCode-style solution operates directly on node pointers, making it suitable for competitive programming.
  - The custom `LinkedList` class encapsulates list operations, providing a more object-oriented design.

This approach ensures a clear, efficient, and maintainable solution for reversing singly linked lists.

```

```
