# Delete Node

**Delete a node from a singly-linked list, ↴ given \*only\* a \*variable pointing to that node.\***

The input could, for example, be the variable b below:

```cpp
class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode * next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

LinkedListNode* a = new LinkedListNode(1);
LinkedListNode* b = new LinkedListNode(2);
LinkedListNode* c = new LinkedListNode(3);

a->next_ = b;
b->next_ = c;

deleteNode(b);
```