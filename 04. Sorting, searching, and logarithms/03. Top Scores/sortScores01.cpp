#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore)
{
    // sort the scores in O(n) time
    vector<int> key ( highestPossibleScore + 1,0 );
    vector<int> orderedScores;
    for ( int value : unorderedScores) {
        key[ value ]++;
    }
    int index = 0;
    for ( size_t i = key.size()-1; i > 0 ; i-- ) {
        if ( key[i] > 0 ) {
            while ( index++ < key[i] ) {
                orderedScores.push_back(i);
            }
        index = 0;
        }
    }

    return orderedScores;
}


















// tests

const lest::test tests[] = {
    {CASE("no scores") {
        const vector<int> scores;
        const vector<int> expected;
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("one score") {
        const vector<int> scores {55};
        const vector<int> expected {55};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("two scores") {
        const vector<int> scores {30, 60};
        const vector<int> expected {60, 30};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("many scores") {
        const vector<int> scores {37, 89, 41, 65, 91, 53};
        const vector<int> expected {91, 89, 65, 53, 41, 37};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }},
    {CASE("repeated scores") {
        const vector<int> scores {20, 10, 30, 30, 10, 20};
        const vector<int> expected {30, 30, 20, 20, 10, 10};
        const auto actual = sortScores(scores, 100);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}