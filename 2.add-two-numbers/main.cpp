#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *dummyHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *current = dummyHead;
        int carry = 0;

        while (p != nullptr || q != nullptr)
        {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (p != nullptr)
                p = p->next;
            if (q != nullptr)
                q = q->next;
        }

        if (carry > 0)
        {
            current->next = new ListNode(carry);
        }

        return dummyHead->next;
    }

    void printList(ListNode *head)
    {
        ListNode *current = head;

        while (current != nullptr)
        {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int listToInt(ListNode *head)
    {
        ListNode *current = head;
        int finalNumber = 0;

        while (current != nullptr)
        {
            finalNumber = finalNumber * 10 + current->val;
            current = current->next;
        }

        return finalNumber;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;

    ListNode *lFinal = solution.addTwoNumbers(l1, l2);
    solution.printList(lFinal);

    return 0;
}
