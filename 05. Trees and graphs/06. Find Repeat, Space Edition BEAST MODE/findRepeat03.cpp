#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set> 

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

unsigned int findRepeat(const vector <unsigned int>& numbers) {
    unsigned int floor = 1;
    unsigned int ceiling = numbers.size() - 1;
    
    while (floor < ceiling) {
        unsigned int midpoint = floor + ((ceiling - floor) / 2);
        unsigned int lowerRangeFloor   = floor;
        unsigned int lowerRangeCeiling = midpoint;
        unsigned int upperRangeFloor   = midpoint + 1;
        unsigned int upperRangeCeiling = ceiling;
        unsigned int itemsInLowerRange = 0;
        
        for (unsigned int item : numbers) {
            if (item >= lowerRangeFloor && item <= lowerRangeCeiling) {
                ++itemsInLowerRange;
            }
        }
        unsigned int distinctPossibleIntegersInLowerRange = lowerRangeCeiling - lowerRangeFloor + 1;
        if (itemsInLowerRange > distinctPossibleIntegersInLowerRange) {
            floor   = lowerRangeFloor;
            ceiling = lowerRangeCeiling;
        }
        else {
            floor   = upperRangeFloor;
            ceiling = upperRangeCeiling;
        }
    }
    return floor;
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