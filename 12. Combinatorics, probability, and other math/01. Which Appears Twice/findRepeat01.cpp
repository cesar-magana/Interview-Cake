#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

unsigned int findRepeat(const vector<unsigned int>& numbers)
{
    // find the number that appears twice
    unsigned int n = numbers.size();
    unsigned int realSum = (n-1)*(n)/2;
    unsigned int vectorSum = 0;
    for ( unsigned int i = 0; i < n; i++ ) {
        vectorSum += numbers[i];
    }
    return vectorSum-realSum;
}


















// tests

const lest::test tests[] = {
    {CASE("short vector") {
        const vector<unsigned int> numbers {1, 2, 1};
        const unsigned int expected = 1;
        const unsigned int actual = findRepeat(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("medium vector") {
        const vector<unsigned int> numbers {4, 1, 3, 4, 2};
        const unsigned int expected = 4;
        const unsigned int actual = findRepeat(numbers);
        EXPECT(actual == expected);
    }},
    {CASE("long vector") {
        const vector<unsigned int> numbers {1, 5, 9, 7, 2, 6, 3, 8, 2, 4};
        const unsigned int expected = 2;
        const unsigned int actual = findRepeat(numbers);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}