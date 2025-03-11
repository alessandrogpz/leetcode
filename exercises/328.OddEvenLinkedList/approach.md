# Approach: Odd Even Linked List

## Problem Statement

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

- The first node is considered odd, and the second node is even, and so on.
- The relative order inside both the even and odd groups should remain as it was in the input.
- The solution must use O(1) extra space complexity and O(n) time complexity.

## Intuition

The key insight to solving this problem is to realize we can maintain two separate sublists:

1. A list of nodes at odd indices (1st, 3rd, 5th, etc.)
2. A list of nodes at even indices (2nd, 4th, 6th, etc.)

Then, after traversing the entire list, we can connect the end of the odd-indexed list to the beginning of the even-indexed list.

## Approach

1. Handle edge cases:

   - If the list is empty or has only one node, return it as is.

2. Initialize pointers:

   - `odd`: Points to the first node (index 1)
   - `even`: Points to the second node (index 2)
   - `evenHead`: Stores the head of the even-indexed list for later connection

3. Traverse the list:

   - Connect each odd-indexed node to the next odd-indexed node
   - Connect each even-indexed node to the next even-indexed node
   - Advance the pointers accordingly

4. Final connection:
   - Connect the end of the odd-indexed list to the head of the even-indexed list

## Algorithm

```cpp
ListNode* Solution::oddEvenList(ListNode *head) {
    // If list has fewer than 2 nodes, nothing to do
    if (!head || !head->next) {
        return head;
    }

    ListNode *odd = head;        // 1st node (odd indexed)
    ListNode *even = head->next; // 2nd node (even indexed)
    ListNode *evenHead = even;   // Save the head of even list

    // Traverse and reorder
    while (even && even->next) {
        odd->next = even->next;  // Connect odd node to next odd
        odd = odd->next;         // Move odd pointer
        even->next = odd->next;  // Connect even node to next even
        even = even->next;       // Move even pointer
    }

    // Connect the end of odd list to the beginning of even list
    odd->next = evenHead;

    return head;
}
```

## Walkthrough with Example

Let's illustrate this approach with the example input `[1,2,3,4,5]`:

1. Initialize:

   - `odd` = node with value 1
   - `even` = node with value 2
   - `evenHead` = node with value 2

2. First iteration of the loop:

   - Connect `odd->next` to `even->next` (1 -> 3)
   - Move `odd` to this node (odd now points to 3)
   - Connect `even->next` to `odd->next` (2 -> 4)
   - Move `even` to this node (even now points to 4)

3. Second iteration of the loop:

   - Connect `odd->next` to `even->next` (3 -> 5)
   - Move `odd` to this node (odd now points to 5)
   - `even->next` is null, so skip this step
   - `even` remains at node 4

4. Loop terminates as `even->next` is null

   - Connect `odd->next` to `evenHead` (5 -> 2)

5. Final list: `1 -> 3 -> 5 -> 2 -> 4 -> null`

## Complexity Analysis

- **Time Complexity**: O(n), where n is the number of nodes in the linked list. We traverse the list only once.
- **Space Complexity**: O(1), as we only use a constant amount of extra space regardless of the input size. We're rearranging the nodes in-place by modifying the pointers.

## Edge Cases

- Empty list: Return null
- Single node: Return the node (no changes needed)
- Even number of nodes: Process all pairs completely
- Odd number of nodes: Last odd-indexed node will point to null before the final connection

## Implementation Notes

- The solution requires careful pointer manipulation to avoid losing nodes or creating cycles.
- We need to save the head of the even-indexed list (`evenHead`) to connect it at the end.
- The checks `even && even->next` in the while loop condition ensure we don't attempt to access null pointers.
