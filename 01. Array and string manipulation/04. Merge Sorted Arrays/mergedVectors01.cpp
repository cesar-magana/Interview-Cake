#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;


void fillVector( vector<int> v, int index, vector<int>& merged ) {
    int n = v.size();
    if ( index < n ) {
        for ( int i = index; i < n; i++ ) {
            merged.push_back( v[ i ] );
        }
    }    
}


vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector)
{
    // combine the sorted vectors into one large sorted vector
    vector<int> mergedVector;
    int myIndex = 0;
    int alicesIndex = 0;
    int myLength = myVector.size();
    int alicesLength = alicesVector.size();
    
    while ( myIndex < myLength && alicesIndex < alicesLength ) {
        if ( myVector[ myIndex ] < alicesVector[ alicesIndex ] ) {
            mergedVector.push_back( myVector[ myIndex++ ] );
        } else {
            mergedVector.push_back( alicesVector[ alicesIndex++ ] );
        }
    }

    fillVector( myVector, myIndex, mergedVector );
    fillVector( alicesVector, alicesIndex, mergedVector );
 
    return mergedVector;
}


















// tests

const lest::test tests[] = {
    {CASE("both vectors are empty") {
        const vector<int> myVector;
        const vector<int> alicesVector;
        const vector<int> expected;
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("first vector is empty") {
        const vector<int> myVector;
        const vector<int> alicesVector {1, 2, 3};
        const vector<int> expected {1, 2, 3};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("second vector is empty") {
        const vector<int> myVector {5, 6, 7};
        const vector<int> alicesVector;
        const vector<int> expected {5, 6, 7};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("both vectors have some numbers") {
        const vector<int> myVector {2, 4, 6};
        const vector<int> alicesVector {1, 3, 7};
        const vector<int> expected {1, 2, 3, 4, 6, 7};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }},
    {CASE("vectors are different lengths") {
        const vector<int> myVector {2, 4, 6, 8};
        const vector<int> alicesVector {1, 7};
        const vector<int> expected {1, 2, 4, 6, 7, 8};
        const auto actual = mergeVectors(myVector, alicesVector);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}