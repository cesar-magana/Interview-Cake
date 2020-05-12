# Reverse a Linked List

**Hooray! It's opposite day. Linked lists go the opposite way today.**

Write a function for reversing a linked list. ↴ Do it in place. ↴

Your function will have one input: the head of the list.

Your function should return the new head of the list.

Here's a sample linked list node class:

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
```