// 206. Reverse Linked List

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

// Constraints:
// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000

#include "functions.h"

int main(int argc, char *argv[])
{

    LinkedList linkedList;

    linkedList.insert(10);
    linkedList.insert(20);
    linkedList.insert(30);

    linkedList.printLL();

    linkedList.remove(20);
    linkedList.remove(40);

    linkedList.printLL();

    linkedList.insert(50);

    linkedList.reverse();
    linkedList.printLL();

    return 0;
}
