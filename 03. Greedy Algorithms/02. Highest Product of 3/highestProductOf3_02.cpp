#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

int highestProductOf3(const vector<int>& vectorOfInts)
{
    if (vectorOfInts.size() < 3) {
        throw invalid_argument("Less than 3 items!");
    }

    // we're going to start at the 3rd item (at index 2)
    // so pre-populate highests and lowests based on the first 2 items.
    // we could also start these as null and check below if they're set
    // but this is arguably cleaner
    int highest = max(vectorOfInts[0], vectorOfInts[1]);
    int lowest  = min(vectorOfInts[0], vectorOfInts[1]);

    int highestProductOf2 = vectorOfInts[0] * vectorOfInts[1];
    int lowestProductOf2  = vectorOfInts[0] * vectorOfInts[1];

    // except this one--we pre-populate it for the first *3* items.
    // this means in our first pass it'll check against itself, which is fine.
    int highestProductOf3 = vectorOfInts[0] * vectorOfInts[1] * vectorOfInts[2];

    // walk through items, starting at index 2
    for (size_t i = 2; i < vectorOfInts.size(); ++i) {
        int current = vectorOfInts[i];

        // do we have a new highest product of 3?
        // it's either the current highest,
        // or the current times the highest product of two
        // or the current times the lowest product of two
        highestProductOf3 = max(max(
            highestProductOf3,
            current * highestProductOf2),
            current * lowestProductOf2);

        // do we have a new highest product of two?
        highestProductOf2 = max(max(
            highestProductOf2,
            current * highest),
            current * lowest);

        // do we have a new lowest product of two?
        lowestProductOf2 = min(min(
            lowestProductOf2,
            current * highest),
            current * lowest);

        // do we have a new highest?
        highest = max(highest, current);

        // do we have a new lowest?
        lowest = min(lowest, current);
    }

    return highestProductOf3;
}


















// tests

const lest::test tests[] = {
    {CASE("short vector") {
        const int actual = highestProductOf3({1, 2, 3, 4});
        const int expected = 24;
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const int actual = highestProductOf3({6, 1, 3, 5, 7, 8, 2});
        const int expected = 336;
        EXPECT(actual == expected);
    }},

    {CASE("vector has one negative") {
        const int actual = highestProductOf3({-5, 4, 8, 2, 3});
        const int expected = 96;
        EXPECT(actual == expected);
    }},

    {CASE("vector has two negatives") {
        const int actual = highestProductOf3({-10, 1, 3, 2, -10});
        const int expected = 300;
        EXPECT(actual == expected);
    }},

    {CASE("vector is all negatives") {
        const int actual = highestProductOf3({-5, -1, -3, -2});
        const int expected = -6;
        EXPECT(actual == expected);
    }},

    {CASE("exception with empty vector") {
        EXPECT_THROWS(highestProductOf3({}));
    }},

    {CASE("exception with one number") {
        EXPECT_THROWS(highestProductOf3({1}));
    }},

    {CASE("exception with two numbers") {
        EXPECT_THROWS(highestProductOf3({1, 1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}