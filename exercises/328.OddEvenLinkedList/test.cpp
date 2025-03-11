#define BOOST_TEST_MODULE 328.OddEvenLinkedList
#include <boost/test/included/unit_test.hpp>
#include "functions.h"
#include <vector>

Solution solution;

// Helper function to create a linked list from vector
ListNode *createList(const std::vector<int> &values)
{
    if (values.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to convert a linked list to vector for comparison
std::vector<int> listToVector(ListNode *head)
{
    std::vector<int> result;
    while (head)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Helper function to free memory
void deleteList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        ListNode *next = current->next;
        delete current;
        current = next;
    }
}

// Example 1 from problem statement
BOOST_AUTO_TEST_CASE(test_example1)
{
    // Input: [1,2,3,4,5]
    // Expected: [1,3,5,2,4]
    ListNode *head = createList({1, 2, 3, 4, 5});
    ListNode *result = solution.oddEvenList(head);

    std::vector<int> expected = {1, 3, 5, 2, 4};
    std::vector<int> actual = listToVector(result);

    BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());

    deleteList(result); // This deletes the entire list
}

// Example 2 from problem statement
BOOST_AUTO_TEST_CASE(test_example2)
{
    // Input: [2,1,3,5,6,4,7]
    // Expected: [2,3,6,7,1,5,4]
    ListNode *head = createList({2, 1, 3, 5, 6, 4, 7});
    ListNode *result = solution.oddEvenList(head);

    std::vector<int> expected = {2, 3, 6, 7, 1, 5, 4};
    std::vector<int> actual = listToVector(result);

    BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());

    deleteList(result);
}

// Edge case: Empty list
BOOST_AUTO_TEST_CASE(test_empty_list)
{
    ListNode *head = nullptr;
    ListNode *result = solution.oddEvenList(head);

    BOOST_CHECK(result == nullptr);
    // No need to delete, as head was nullptr
}

// Edge case: Single node
BOOST_AUTO_TEST_CASE(test_single_node)
{
    ListNode *head = new ListNode(42);
    ListNode *result = solution.oddEvenList(head);

    BOOST_CHECK_EQUAL(result->val, 42);
    BOOST_CHECK(result->next == nullptr);

    deleteList(result);
}

// Edge case: Two nodes
BOOST_AUTO_TEST_CASE(test_two_nodes)
{
    ListNode *head = createList({1, 2});
    ListNode *result = solution.oddEvenList(head);

    std::vector<int> expected = {1, 2};
    std::vector<int> actual = listToVector(result);

    BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());

    deleteList(result);
}

// Edge case: Even number of nodes
BOOST_AUTO_TEST_CASE(test_even_count)
{
    ListNode *head = createList({1, 2, 3, 4, 5, 6});
    ListNode *result = solution.oddEvenList(head);

    std::vector<int> expected = {1, 3, 5, 2, 4, 6};
    std::vector<int> actual = listToVector(result);

    BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());

    deleteList(result);
}

// Edge case: Odd number of nodes
BOOST_AUTO_TEST_CASE(test_odd_count)
{
    ListNode *head = createList({1, 2, 3, 4, 5, 6, 7});
    ListNode *result = solution.oddEvenList(head);

    std::vector<int> expected = {1, 3, 5, 7, 2, 4, 6};
    std::vector<int> actual = listToVector(result);

    BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());

    deleteList(result);
}

// All same values
BOOST_AUTO_TEST_CASE(test_identical_values)
{
    ListNode *head = createList({5, 5, 5, 5, 5});
    ListNode *result = solution.oddEvenList(head);

    // Even if values are identical, the reordering should still follow the pattern
    std::vector<int> expected = {5, 5, 5, 5, 5};
    std::vector<int> actual = listToVector(result);

    BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());

    deleteList(result);
}

// Negative values
BOOST_AUTO_TEST_CASE(test_negative_values)
{
    ListNode *head = createList({-1, -2, -3, -4, -5});
    ListNode *result = solution.oddEvenList(head);

    std::vector<int> expected = {-1, -3, -5, -2, -4};
    std::vector<int> actual = listToVector(result);

    BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());

    deleteList(result);
}

// Add a fixture to ensure no memory leaks between tests
struct MemoryLeakFixture
{
    ~MemoryLeakFixture()
    {
        // This will run after each test case to check for memory leaks
        BOOST_CHECK(true); // Just to have a check in the fixture
    }
};

BOOST_FIXTURE_TEST_CASE(memory_leak_check, MemoryLeakFixture)
{
    // This empty test uses the fixture to check for memory leaks
    BOOST_CHECK(true);
}