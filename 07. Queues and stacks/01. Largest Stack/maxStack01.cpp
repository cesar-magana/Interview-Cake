#include <iostream>
#include <stack>
#include<bits/stdc++.h> 


// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// fill in the definitions for push(), pop(), and getMax()


class MaxStack
{
private:
    stack<int> stk_;
    stack<int> max_;

public:
    void push(int item)
    {
        stk_.push( item );
        if ( max_.empty() || item >= max_.top() ) {
            max_.push(item);
        }
    }

    int pop()
    {
        int item = stk_.top();
        stk_.pop();   
        if ( item == max_.top() ) {
            max_.pop();
            
        }
        return item;
    }

    int getMax() const
    {
        return max_.top();
    }
};


















// tests

const lest::test tests[] = {
    {CASE("MaxStack test") {
        MaxStack s;
        s.push(5);
        EXPECT(s.getMax() == 5);
        s.push(4);
        s.push(7);
        s.push(7);
        s.push(8);
        EXPECT(s.getMax() == 8);
        EXPECT(s.pop() == 8);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 7);
        EXPECT(s.pop() == 7);
        EXPECT(s.getMax() == 5);
        EXPECT(s.pop() == 4);
        EXPECT(s.getMax() == 5);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}