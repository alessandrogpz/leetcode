
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
        : val(0), next(nullptr) {}

    ListNode(int x)
        : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next)
        : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *head;

public:
    Solution() : head(nullptr) {}

    ~Solution()
    {
        ListNode *current = head;
        while (current != nullptr)
        {
            ListNode *next = current->next;
            delete current;
            current = next;
        }
    }

    ListNode *oddEvenList(ListNode *head);
};

#endif
