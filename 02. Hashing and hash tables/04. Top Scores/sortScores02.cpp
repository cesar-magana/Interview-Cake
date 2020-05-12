#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

  vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore)
{
    // vector of 0s at indices 0..highestPossibleScore
    vector<size_t> scoreCounts(highestPossibleScore + 1);

    // populate scoreCounts
    for (int score : unorderedScores) {
        ++scoreCounts[score];
    }

    // populate the final sorted array
    vector<int> sortedScores(unorderedScores.size());
    size_t currentSortedIndex = 0;

    // for each item in scoreCounts
    for (int score = highestPossibleScore; score >= 0; --score) {
        size_t count = scoreCounts[score];

        // for the number of times the item occurs
        for (size_t occurrence = 0; occurrence < count; ++occurrence) {
            // add it to the sorted array
            sortedScores[currentSortedIndex] = score;
            ++currentSortedIndex;
        }
    }

    return sortedScores;
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