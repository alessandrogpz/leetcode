# Maximum Twin Sum of a Linked List - Approach

## Problem Description

Given a linked list of even length, we define the "twin" of node `i` as node `n-1-i` where `n` is the number of nodes in the list. For example, if `n = 4`, then node 0 is the twin of node 3, and node 1 is the twin of node 2.

The problem asks us to find the maximum twin sum in the linked list. A twin sum is the sum of a node and its twin.

## Approach

Our solution uses the "slow and fast pointers" technique to efficiently solve this problem without using extra data structures like vectors. This approach offers optimal time and space complexity.

### Algorithm Overview

1. Find the middle of the linked list using slow and fast pointers
2. Reverse the second half of the linked list
3. Traverse both halves simultaneously, calculating twin sums
4. Find the maximum twin sum
5. Restore the original linked list structure (for proper memory cleanup)

### Step-by-Step Explanation

#### 1. Finding the Middle of the Linked List

We use two pointers - a slow pointer and a fast pointer. The slow pointer moves one step at a time, while the fast pointer moves two steps. When the fast pointer reaches the end, the slow pointer will be at the middle.

```cpp
ListNode *slow = head;
ListNode *fast = head;

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```

#### 2. Reversing the Second Half

Once we find the middle, we reverse the second half of the linked list:

```cpp
ListNode *prev = nullptr;
ListNode *current = slow;
ListNode *next = nullptr;

while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
```

After this step, `prev` points to the head of the reversed second half.

#### 3. Calculating the Maximum Twin Sum

We traverse both halves simultaneously and calculate the twin sums:

```cpp
ListNode *firstHalf = head;
ListNode *secondHalf = prev;
int maxSum = 0;

while (secondHalf) {
    int twinSum = firstHalf->val + secondHalf->val;
    maxSum = std::max(maxSum, twinSum);

    firstHalf = firstHalf->next;
    secondHalf = secondHalf->next;
}
```

#### 4. Restoring the Original Linked List

For proper memory cleanup, we restore the original linked list by reversing the second half again and reconnecting it to the first half:

```cpp
// Re-reverse the second half
current = prev;
prev = nullptr;

while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}

// Reconnect the first half with the restored second half
ListNode *temp = head;
while (temp->next != slow && temp->next != nullptr) {
    temp = temp->next;
}
temp->next = slow;
```

## Time and Space Complexity Analysis

### Time Complexity: O(n)

- Finding the middle of the linked list: O(n/2) ≈ O(n)
- Reversing the second half: O(n/2) ≈ O(n)
- Calculating the maximum twin sum: O(n/2) ≈ O(n)
- Restoring the original linked list: O(n/2) ≈ O(n)

Overall, the time complexity is O(n) where n is the number of nodes in the linked list.

### Space Complexity: O(1)

Our solution uses only a constant amount of extra space regardless of input size. We only use a few pointer variables and an integer to keep track of the maximum sum.

This is a significant improvement over the original approach which used O(n) extra space for storing values in vectors.

## Advantages Over the Previous Implementation

1. **Memory Efficiency**: Unlike the previous implementation that created vectors to store both halves, this solution uses O(1) extra space.

2. **No Memory Leaks**: The previous implementation modified the original linked list without restoring it, causing memory leaks. Our approach correctly restores the linked list structure before returning.

3. **Simplified Logic**: The original code had complex conditional logic for different list lengths. The new implementation handles all cases uniformly.

4. **Better Readability**: The algorithm follows a clear logical flow that's easier to understand and maintain.

## Edge Cases Handled

- Lists with minimum length (2 nodes)
- Lists with equal values throughout
- Lists with maximum values (up to 10^5)
- Lists of various even lengths
