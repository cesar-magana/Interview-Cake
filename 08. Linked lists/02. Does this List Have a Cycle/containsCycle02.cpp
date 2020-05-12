#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

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


bool containsCycle(const LinkedListNode* first)
{
    // check if the linked list contains a cycle
    const LinkedListNode* slow = first;
    const LinkedListNode* fast = first;
    while(fast != NULL && fast->next_ != NULL) {
        slow = slow->next_;
        fast = fast->next_->next_;
        if(slow == fast)
            return true;
    }
    return false;
}



  













// tests

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values);
void freeLinkedListNodes(vector<LinkedListNode*>& nodes);

const lest::test tests[] = {
    {CASE("linked list with no cycle") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        EXPECT(containsCycle(nodes[0]) == false);
        freeLinkedListNodes(nodes);
    }},
    {CASE("cycle loops to beginning") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        nodes[3]->next_ = nodes[0];
        EXPECT(containsCycle(nodes[0]) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("cycle loops to middle") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4, 5});
        nodes[4]->next_ = nodes[2];
        EXPECT(containsCycle(nodes[0]) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("two node cycle at end") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4, 5});
        nodes[4]->next_ = nodes[3];
        EXPECT(containsCycle(nodes[0]) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("empty list") {
        EXPECT(containsCycle(nullptr) == false);
    }},
    {CASE("one element linked list no cycle") {
        auto node = new LinkedListNode(1);
        EXPECT(containsCycle(node) == false);
        delete node;
    }},
    {CASE("one element linked list cycle") {
        auto node = new LinkedListNode(1);
        node->next_ = node;
        EXPECT(containsCycle(node) == true);
        delete node;
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