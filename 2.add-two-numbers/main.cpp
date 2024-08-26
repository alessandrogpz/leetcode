#include <iostream>
#include <cmath>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void printList(ListNode* head);
int listToInt(ListNode* head);

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};

int main()
{
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    printList(l1);
    listToInt(l1);

    std::cout << listToInt(l1) + listToInt(l2);

    return 0;
}

void printList(ListNode* head)
{
    ListNode* current = head;

    while( current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int listToInt(ListNode* head)
{
    ListNode* current = head;
    int finalNumber = 0;
    int listSize = 0;

    // Get listSize
    while( current != nullptr)
    {
        ++ listSize;
        current = current->next;
    }
    //std::cout << listSize;

    current = head;
    int listPos = listSize;
    // Calculate finalNumber
    while( current != nullptr)
    {
        if (listSize - listPos == 0)
        {
            finalNumber = current->val;
            current = current->next;
            --listPos;
        }
            finalNumber += current->val * pow(10, listSize - listPos);
            current = current->next;
            --listPos;
    }

    //std::cout << finalNumber;

    return finalNumber;
}