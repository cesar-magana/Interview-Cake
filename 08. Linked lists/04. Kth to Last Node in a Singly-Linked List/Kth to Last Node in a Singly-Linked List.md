# Kth to Last Node in a Singly-Linked List

**You have a linked list ↴ and want to find the \**k\*k\*\**th to last node.**

Write a function kthToLastNode() that takes an integer k*k* and the headNode of a singly-linked list, and returns the k*k*th to last node in the list.

For example:

```cpp
class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(nullptr)
    {
    }
};

LinkedListNode* a = new LinkedListNode(1);
LinkedListNode* b = new LinkedListNode(2);
LinkedListNode* c = new LinkedListNode(3);
LinkedListNode* d = new LinkedListNode(4);
LinkedListNode* e = new LinkedListNode(5);

a->next_ = b;
b->next_ = c;
c->next_ = d;
d->next_ = e;

kthToLastNode(2, a);
// returns the node with value 4 (the 2nd to last node)
```