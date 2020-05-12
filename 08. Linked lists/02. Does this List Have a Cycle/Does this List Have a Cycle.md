# Does this List Have a Cycle

**You have a singly-linked list ↴ and want to check if it contains a cycle.**

A singly-linked list is built with nodes, where each node has:

- node->next_—the next node in the list.
- node->value_—the data held in the node. For example, if our linked list stores timestamps, node->value_ might be the number of seconds past the Unix epoch.

For example:

```cpp
class LinkedListNode
{
public:
    int value_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        value_(value),
        next_(nullptr)
    {
    }
};
```



A **cycle** occurs when a node’s next_ points *back to a previous node in the list*. The linked list is no longer linear with a beginning and end—instead, it cycles through a loop of nodes.

**Write a function containsCycle() that takes the first node in a singly-linked list and returns a boolean indicating whether the list contains a cycle.**