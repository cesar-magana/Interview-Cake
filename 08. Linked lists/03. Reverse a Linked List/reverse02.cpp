#include <iostream>
#include <vector>
#include <stack>

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

LinkedListNode* reverse(LinkedListNode* head)
{
    // reverse the linked list in place
    if( !head ){
        return head;
    }
    // You should be able to implement a stack to solve this 
    stack<LinkedListNode*> s; 
    LinkedListNode* cursor = head; 
    while( cursor ){
        s.push( cursor );
        head = cursor; // when this is done, head will reference the tail
        cursor = cursor->next_;
    }
    // cursor is null now 
    while( !s.empty() ){
        cursor = s.top();
        s.pop();
        // This will eventually fail 
        if ( s.empty() ){
            cursor->next_ = NULL;
        }else{
            cursor->next_ = s.top();
        }
    }
    return head;
}


















// tests

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values);
void freeLinkedListNodes(vector<LinkedListNode*>& nodes);
bool isListReversed(const LinkedListNode* list, const vector<LinkedListNode*>& originalNodes);

const lest::test tests[] = {
    {CASE("short linked list") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2});
        auto result = reverse(nodes[0]);
        EXPECT(isListReversed(result, nodes) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("long linked list") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4, 5, 6});
        auto result = reverse(nodes[0]);
        EXPECT(isListReversed(result, nodes) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("one element linked list") {
        auto list = new LinkedListNode(1);
        auto actual = reverse(list);
        auto result = (actual == list);
        EXPECT(result == true);
        delete list;
    }},
    {CASE("empty linked list") {
        auto actual = reverse(nullptr);
        EXPECT(actual == nullptr);
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

bool isListReversed(const LinkedListNode* list, const vector<LinkedListNode*>& originalNodes)
{
    size_t i = 0;
    for (auto it = originalNodes.rbegin(); list != nullptr
            && it != originalNodes.rend(); ++it, ++i) {
        if (list != *it) {
            return false;
        }
        list = list->next_;
    }
    return list == nullptr && i == originalNodes.size();
}