#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

size_t changePossibilities(int amount, const vector<int>& denominations)
{
    vector<size_t> waysOfDoingNCents(amount + 1);  // vector of zeros from 0..amount
    waysOfDoingNCents[0] = 1;

    for (const int coin : denominations) {
        for (int higherAmount = coin; higherAmount <= amount; ++higherAmount) {
            int higherAmountRemainder = higherAmount - coin;
            waysOfDoingNCents[higherAmount] += waysOfDoingNCents[higherAmountRemainder];
        }
    }

    return waysOfDoingNCents[amount];
}


















// tests

const lest::test tests[] = {
    {CASE("sample input") {
        const size_t actual = changePossibilities(4, {1, 2, 3});
        const size_t expected = 4;
        EXPECT(actual == expected);
    }},

    {CASE("one way to make zero cents") {
        const size_t actual = changePossibilities(0, {1, 2});
        const size_t expected = 1;
        EXPECT(actual == expected);
    }},

    {CASE("no ways if no coins") {
        const size_t actual = changePossibilities(1, {});
        const size_t expected = 0;
        EXPECT(actual == expected);
    }},

    {CASE("big coin value") {
        const size_t actual = changePossibilities(5, {25, 50});
        const size_t expected = 0;
        EXPECT(actual == expected);
    }},

    {CASE("big target amount") {
        const size_t actual = changePossibilities(50, {5, 10});
        const size_t expected = 6;
        EXPECT(actual == expected);
    }},

    {CASE("change for one dollar") {
        const size_t actual = changePossibilities(100, {1, 5, 10, 25, 50});
        const size_t expected = 292;
        EXPECT(actual == expected);
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}