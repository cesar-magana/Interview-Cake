#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set> 

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

unsigned int findRepeat(const vector<unsigned int>& numbers)
{
    // find a number that appears more than once
    unordered_set<unsigned int> seen;
    
    for ( size_t i = 0; i < numbers.size(); i++ ) {
        if ( seen.find( numbers[i] ) != seen.end() ) {
            return numbers[i];
        } 
        else {
            seen.insert( numbers[i] );
        }
    }
    
    throw invalid_argument("No duplicate");
}


















// tests

const lest::test tests[] = {
    {CASE("just the repeated number") {
        const vector<unsigned int> numbers {1, 1};
        const unsigned int expected = 1;
        const unsigned int actual = findRepeat(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("short vector") {
        const vector<unsigned int> numbers {1, 2, 3, 2};
        const unsigned int expected = 2;
        const unsigned int actual = findRepeat(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("medium vector") {
        const vector<unsigned int> numbers {1, 2, 5, 5, 5, 5};
        const unsigned int expected = 5;
        const unsigned int actual = findRepeat(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("long vector") {
        const vector<unsigned int> numbers {4, 1, 4, 8, 3, 2, 7, 6, 5};
        const unsigned int expected = 4;
        const unsigned int actual = findRepeat(numbers);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}