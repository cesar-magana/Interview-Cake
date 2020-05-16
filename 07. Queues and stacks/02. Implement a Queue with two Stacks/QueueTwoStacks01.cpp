#include <iostream>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// fill in the definitions for enqueue() and dequeue()


class QueueTwoStacks
{
private:
    stack<int> inStack_;
    stack<int> outStack_;

public:
    void enqueue(int item)
    {
        inStack_.push( item );
    }

    int dequeue()
    {
        if ( outStack_.empty() ) {
            while ( !inStack_.empty() ) {
                outStack_.push( inStack_.top() );
                inStack_.pop();
            }
        }
        if ( outStack_.empty() ) {
            throw runtime_error("Empty stack");
        }
        int item = outStack_.top();
        outStack_.pop();
        return item;
    }
};


















// tests

const lest::test tests[] = {
    {CASE("basic queue operations") {
        QueueTwoStacks q;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        EXPECT(q.dequeue() == 1);
        EXPECT(q.dequeue() == 2);
        q.enqueue(4);
        EXPECT(q.dequeue() == 3);
        EXPECT(q.dequeue() == 4);
    }},
    {CASE("exception when dequeue from new queue") {
        QueueTwoStacks q;
        EXPECT_THROWS(q.dequeue());
    }},
    {CASE("exception when dequeue from empty queue") {
        QueueTwoStacks q;
        q.enqueue(1);
        q.enqueue(2);
        q.dequeue();
        q.dequeue();
        EXPECT_THROWS(q.dequeue());
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}