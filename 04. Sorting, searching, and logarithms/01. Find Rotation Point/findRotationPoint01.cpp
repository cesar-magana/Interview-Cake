#include <iostream>
#include <string>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

size_t findRotationPoint(const vector<string>& words)
{
    size_t low = 0;
    size_t high = words.size() - 1;

    while (low < high) {
        size_t guess = low + ((high - low) / 2);

        if (words[guess] >= words[0]) {
            low = guess;
        }
        else {
            high = guess;
        }

        if (low + 1 == high) {
            break;
        }
    }
    return high;
}

















// tests

const lest::test tests[] = {
    {CASE("small array") {
        const vector<string> words {"cape", "cake"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 1;
        EXPECT(actual == expected);
    }},
    {CASE("medium array") {
        const vector<string> words {"grape", "orange", "plum", "radish", "apple"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 4;
        EXPECT(actual == expected);
    }},
    {CASE("large array") {
        const vector<string> words {"ptolemaic", "retrograde", "supplant", "undulate",
            "xenoepist", "asymptote", "babka", "banoffee", "engender", "karpatka",
            "othellolagkage"};
        const size_t actual = findRotationPoint(words);
        const size_t expected = 5;
        EXPECT(actual == expected);
    }},
    {CASE("possibly missing edge case") {
        // are we missing any edge cases?

    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}