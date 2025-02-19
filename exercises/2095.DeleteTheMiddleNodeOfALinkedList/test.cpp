#define BOOST_TEST_MODULE 2095.DeleteTheMiddleNodeOfALinkedList
#include <boost/test/included/unit_test.hpp>
#include "functions.h"

// Helper function to free all nodes in a linked list.
static void freeList(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

BOOST_AUTO_TEST_CASE(test_deleteMiddle_empty)
{
    // For an empty list, deletion should return nullptr.
    Node *head = nullptr;
    BOOST_CHECK(deleteMiddle_1(head) == nullptr);
    BOOST_CHECK(deleteMiddle_2(head) == nullptr);
}

BOOST_AUTO_TEST_CASE(test_deleteMiddle_single)
{
    // For a single-node list, deletion should return nullptr.
    Node *head1 = new Node(10);
    Node *head2 = new Node(10);
    BOOST_CHECK(deleteMiddle_1(head1) == nullptr);
    BOOST_CHECK(deleteMiddle_2(head2) == nullptr);
    // No need to free further since the single node is deleted.
}

BOOST_AUTO_TEST_CASE(test_deleteMiddle_two_nodes)
{
    // For a two-node list: 1 -> 2, the middle (second) node is deleted.
    // After deletion, only the head should remain.
    Node *head1 = new Node(1);
    head1->next = new Node(2);

    Node *head2 = new Node(1);
    head2->next = new Node(2);

    Node *result1 = deleteMiddle_1(head1);
    Node *result2 = deleteMiddle_2(head2);

    BOOST_REQUIRE(result1 != nullptr);
    BOOST_CHECK_EQUAL(result1->data, 1);
    BOOST_CHECK(result1->next == nullptr);

    BOOST_REQUIRE(result2 != nullptr);
    BOOST_CHECK_EQUAL(result2->data, 1);
    BOOST_CHECK(result2->next == nullptr);

    // Free the remaining nodes.
    freeList(result1);
    freeList(result2);
}

BOOST_AUTO_TEST_CASE(test_deleteMiddle_three_nodes)
{
    // For a three-node list: 1 -> 2 -> 3, the middle (node 2) should be deleted.
    // Expected resulting list: 1 -> 3.
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    Node *result1 = deleteMiddle_1(head1);
    Node *result2 = deleteMiddle_2(head2);

    // Check deleteMiddle_1 result.
    BOOST_REQUIRE(result1 != nullptr);
    BOOST_CHECK_EQUAL(result1->data, 1);
    BOOST_REQUIRE(result1->next != nullptr);
    BOOST_CHECK_EQUAL(result1->next->data, 3);
    BOOST_CHECK(result1->next->next == nullptr);

    // Check deleteMiddle_2 result.
    BOOST_REQUIRE(result2 != nullptr);
    BOOST_CHECK_EQUAL(result2->data, 1);
    BOOST_REQUIRE(result2->next != nullptr);
    BOOST_CHECK_EQUAL(result2->next->data, 3);
    BOOST_CHECK(result2->next->next == nullptr);

    freeList(result1);
    freeList(result2);
}

BOOST_AUTO_TEST_CASE(test_deleteMiddle_four_nodes)
{
    // For a four-node list: 1 -> 2 -> 3 -> 4, the middle is chosen as the node at index 2 (node with data 3).
    // After deletion, expected list: 1 -> 2 -> 4.
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);

    Node *result1 = deleteMiddle_1(head1);
    Node *result2 = deleteMiddle_2(head2);

    // Check deleteMiddle_1 result.
    BOOST_REQUIRE(result1 != nullptr);
    BOOST_CHECK_EQUAL(result1->data, 1);
    BOOST_REQUIRE(result1->next != nullptr);
    BOOST_CHECK_EQUAL(result1->next->data, 2);
    BOOST_REQUIRE(result1->next->next != nullptr);
    BOOST_CHECK_EQUAL(result1->next->next->data, 4);
    BOOST_CHECK(result1->next->next->next == nullptr);

    // Check deleteMiddle_2 result.
    BOOST_REQUIRE(result2 != nullptr);
    BOOST_CHECK_EQUAL(result2->data, 1);
    BOOST_REQUIRE(result2->next != nullptr);
    BOOST_CHECK_EQUAL(result2->next->data, 2);
    BOOST_REQUIRE(result2->next->next != nullptr);
    BOOST_CHECK_EQUAL(result2->next->next->data, 4);
    BOOST_CHECK(result2->next->next->next == nullptr);

    freeList(result1);
    freeList(result2);
}
