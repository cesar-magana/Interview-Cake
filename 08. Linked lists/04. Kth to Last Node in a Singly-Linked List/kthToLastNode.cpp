#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head)
{
    // return the kth to last node in the linked list
    if ( k < 1) {
        throw invalid_argument("Not valid k");
    }
    LinkedListNode* node = head;
    for ( size_t i = 0; i < k; i++ ) {
        if ( !head ) throw invalid_argument("Not valid k");
        head = head->next_;
    }
    while ( head ) {
        head = head->next_;
        node = node->next_;
    }
    return node;
}


















// tests

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values);
void freeLinkedListNodes(vector<LinkedListNode*>& nodes);

const lest::test tests[] = {
    {CASE("first to last node") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 1;
        auto actual = kthToLastNode(k, listNodes[0]);
        auto result = (actual == listNodes[listNodes.size() - k]);
        EXPECT(result == true);
        freeLinkedListNodes(listNodes);
    }},
    {CASE("second to last node") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 2;
        auto actual = kthToLastNode(k, listNodes[0]);
        auto result = (actual == listNodes[listNodes.size() - k]);
        EXPECT(result == true);
        freeLinkedListNodes(listNodes);
    }},
    {CASE("first node") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 4;
        auto actual = kthToLastNode(k, listNodes[0]);
        auto result = (actual == listNodes[listNodes.size() - k]);
        EXPECT(result == true);
        freeLinkedListNodes(listNodes);
    }},
    {CASE("k is greater than linked list length") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 5;
        EXPECT_THROWS(kthToLastNode(k, listNodes[0]));
        freeLinkedListNodes(listNodes);
    }},
    {CASE("k is zero") {
        auto listNodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        const size_t k = 0;
        EXPECT_THROWS(kthToLastNode(k, listNodes[0]));
        freeLinkedListNodes(listNodes);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values)
{
    vector<LinkedListNode*> nodes;
    for (int value: values) {
        auto node = new LinkedListNode(value);
        if (!nodes.empty()) {
            nodes.back()->next_ = node;
        }
        nodes.push_back(node);
    }
    return nodes;
}

void freeLinkedListNodes(vector<LinkedListNode*>& nodes)
{
    for (auto node: nodes) {
        delete node;
    }
    nodes.clear();
}