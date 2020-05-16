#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

bool contains(const vector<int>& v, int n)
{
    // check if an integer is present in the vector
    size_t floorIndex = 0;
    size_t ceilingIndex = v.size();
    
    while ( floorIndex < ceilingIndex ) {
        size_t midIndex = floorIndex + ( ceilingIndex-floorIndex )/2;
        if ( n == v[ midIndex ] ) {
            return true;
        }
        else if ( n > v[ midIndex ] ) {
            floorIndex = midIndex + 1;
        }
        else {
            ceilingIndex = midIndex;
        }
    }

    return false;
}


















// tests

const lest::test tests[] = {
    {CASE("empty vector") {
        const vector<int> v;
        EXPECT(contains(v, 1) == false);
    }},
    {CASE("one item vector number present") {
        const vector<int> v {1};
        EXPECT(contains(v, 1) == true);
    }},
    {CASE("one item vector number absent") {
        const vector<int> v {1};
        EXPECT(contains(v, 2) == false);
    }},
    {CASE("small vector number present") {
        const vector<int> v {2, 4, 6};
        EXPECT(contains(v, 4) == true);
    }},
    {CASE("small vector number absent") {
        const vector<int> v {2, 4, 6};
        EXPECT(contains(v, 5) == false);
    }},
    {CASE("large vector number present") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 8) == true);
    }},
    {CASE("large vector number absent") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 0) == false);
    }},
    {CASE("large vector number first") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 1) == true);
    }},
    {CASE("large vector number last") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 10) == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}