#define BOOST_TEST_MODULE 2130.MaximumTwinSumofaLinkedList
#include <boost/test/included/unit_test.hpp>
#include "functions.h"
#include <memory>

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Custom deleter function for LinkedList
struct LinkedListDeleter
{
    void operator()(ListNode *head) const
    {
        while (head != nullptr)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Using RAII pattern with unique_ptr to guarantee cleanup
using LinkedListPtr = std::unique_ptr<ListNode, LinkedListDeleter>;

BOOST_AUTO_TEST_SUITE(MaxTwinSumTests)

BOOST_AUTO_TEST_CASE(example1)
{
    // Input: head = [5,4,2,1]
    // Output: 6
    LinkedListPtr head(createLinkedList({5, 4, 2, 1}), LinkedListDeleter());

    Solution solution;
    int result = solution.pairSum(head.get());

    BOOST_CHECK_EQUAL(result, 6);
    // No need to manually call deleteLinkedList - unique_ptr will handle it
}

BOOST_AUTO_TEST_CASE(example2)
{
    // Input: head = [4,2,2,3]
    // Output: 7
    LinkedListPtr head(createLinkedList({4, 2, 2, 3}), LinkedListDeleter());

    Solution solution;
    int result = solution.pairSum(head.get());

    BOOST_CHECK_EQUAL(result, 7);
}

BOOST_AUTO_TEST_CASE(example3)
{
    // Input: head = [1,100000]
    // Output: 100001
    LinkedListPtr head(createLinkedList({1, 100000}), LinkedListDeleter());

    Solution solution;
    int result = solution.pairSum(head.get());

    BOOST_CHECK_EQUAL(result, 100001);
}

BOOST_AUTO_TEST_CASE(edgeCase1)
{
    // Test with the minimum number of nodes (2)
    LinkedListPtr head(createLinkedList({42, 13}), LinkedListDeleter());

    Solution solution;
    int result = solution.pairSum(head.get());

    BOOST_CHECK_EQUAL(result, 55); // 42 + 13 = 55
}

BOOST_AUTO_TEST_CASE(edgeCase2)
{
    // Test with a longer list (10 nodes)
    LinkedListPtr head(createLinkedList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), LinkedListDeleter());

    Solution solution;
    int result = solution.pairSum(head.get());

    // Max twin sum would be: max(1+10, 2+9, 3+8, 4+7, 5+6) = max(11, 11, 11, 11, 11) = 11
    BOOST_CHECK_EQUAL(result, 11);
}

BOOST_AUTO_TEST_CASE(allSameValues)
{
    // Test with all same values
    LinkedListPtr head(createLinkedList({5, 5, 5, 5, 5, 5}), LinkedListDeleter());

    Solution solution;
    int result = solution.pairSum(head.get());

    BOOST_CHECK_EQUAL(result, 10); // All twin sums are 5+5 = 10
}

BOOST_AUTO_TEST_CASE(maxValueConstraint)
{
    // Test with maximum value constraint (10^5)
    LinkedListPtr head(createLinkedList({100000, 1, 1, 100000}), LinkedListDeleter());

    Solution solution;
    int result = solution.pairSum(head.get());

    BOOST_CHECK_EQUAL(result, 200000); // max(100000+100000, 1+1) = 200000
}

BOOST_AUTO_TEST_SUITE_END()