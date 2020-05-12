#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

unsigned int findDuplicate(const vector<unsigned int>& v)
{
    // find a number that appears more than once ... in O(n) time
    unsigned int n = v.size();
    unsigned int slow =  n - 1;
    unsigned int fast = v[ slow - 1 ];
    
    while( slow != fast ) {
        slow = v [ slow - 1 ];
        fast = v [ v[ fast - 1 ] - 1 ];
        if ( slow == fast )
            return slow;
    }
    return v[ n-1 ];
}


















// tests

const lest::test tests[] = {
    {CASE("just the repeated number") {
        const vector<unsigned int> numbers {1, 1};
        const unsigned int expected = 1;
        const unsigned int actual = findDuplicate(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("short vector") {
        const vector<unsigned int> numbers {1, 2, 3, 2};
        const unsigned int expected = 2;
        const unsigned int actual = findDuplicate(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("medium vector") {
        const vector<unsigned int> numbers {1, 2, 5, 5, 5, 5};
        const unsigned int expected = 5;
        const unsigned int actual = findDuplicate(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("long vector") {
        const vector<unsigned int> numbers {4, 1, 4, 8, 3, 2, 7, 6, 5};
        const unsigned int expected = 4;
        const unsigned int actual = findDuplicate(numbers);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}