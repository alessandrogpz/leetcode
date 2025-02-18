#define BOOST_TEST_MODULE 206.ReverseLinkedList
#include <boost/test/included/unit_test.hpp>
#include "functions.h" // This header includes your classes and functions
#include <sstream>
#include <string>

// Helper function to capture output from LinkedList::printLL()
std::string capturePrintLL(LinkedList &list)
{
    std::stringstream buffer;
    std::streambuf *oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());
    list.printLL();
    std::cout.rdbuf(oldCoutBuffer); // restore original buffer
    return buffer.str();
}

// Helper function to convert a ListNode chain into a string representation.
// Example: 3->2->1
std::string listNodeToString(ListNode *head)
{
    std::stringstream ss;
    while (head)
    {
        ss << head->val;
        if (head->next)
            ss << "->";
        head = head->next;
    }
    return ss.str();
}

BOOST_AUTO_TEST_CASE(test_linked_list_insert_print)
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    std::string output = capturePrintLL(list);
    // Expected output: each value followed by "->", ending with "NULL\n"
    BOOST_CHECK_EQUAL(output, "10->20->30->NULL\n");
}

BOOST_AUTO_TEST_CASE(test_linked_list_remove)
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Remove a middle value
    list.remove(20);
    std::string output = capturePrintLL(list);
    BOOST_CHECK_EQUAL(output, "10->30->NULL\n");

    // Removing a non-existent value (20 is already removed)
    // Note: This will print "Value not found\n" to std::cout.
    // For simplicity, we won't capture that output here.
    list.remove(20);
}

BOOST_AUTO_TEST_CASE(test_linked_list_reverse)
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Reverse the linked list
    list.reverse();
    std::string output = capturePrintLL(list);
    BOOST_CHECK_EQUAL(output, "30->20->10->NULL\n");
}

BOOST_AUTO_TEST_CASE(test_solution_reverse_list)
{
    // Manually create a linked list using ListNode: 1->2->3->NULL
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;

    Solution sol;
    ListNode *reversed = sol.reverseList(n1);
    std::string result = listNodeToString(reversed);
    BOOST_CHECK_EQUAL(result, "3->2->1");

    // Clean up: delete all nodes in the reversed list
    while (reversed)
    {
        ListNode *temp = reversed;
        reversed = reversed->next;
        delete temp;
    }
}

BOOST_AUTO_TEST_CASE(test_solution_empty_list)
{
    // Test reversing an empty list (nullptr)
    Solution sol;
    ListNode *reversed = sol.reverseList(nullptr);
    BOOST_CHECK_EQUAL(reversed, nullptr);
}
