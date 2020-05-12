#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

  int getMaxProfit(const vector<int>& stockPrices)
{
    if (stockPrices.size() < 2) {
        throw invalid_argument("Getting a profit requires at least 2 prices");
    }

    // we'll greedily update minPrice and maxProfit, so we initialize
    // them to the first price and the first possible profit
    int minPrice = stockPrices[0];
    int maxProfit = stockPrices[1] - stockPrices[0];

    // start at the second (index 1) time
    // we can't sell at the first time, since we must buy first,
    // and we can't buy and sell at the same time!
    // if we started at index 0, we'd try to buy *and* sell at time 0.
    // this would give a profit of 0, which is a problem if our
    // maxProfit is supposed to be *negative*--we'd return 0.
    for (size_t i = 1; i < stockPrices.size(); ++i) {
        int currentPrice = stockPrices[i];

        // see what our profit would be if we bought at the
        // min price and sold at the current price
        int potentialProfit = currentPrice - minPrice;

        // update maxProfit if we can do better
        maxProfit = max(maxProfit, potentialProfit);

        // update minPrice so it's always
        // the lowest price we've seen so far
        minPrice = min(minPrice, currentPrice);
    }

    return maxProfit;
}

















// tests

const lest::test tests[] = {
    {CASE("price goes up then down") {
        const int actual = getMaxProfit({1, 5, 3, 2});
        const int expected = 4;
        EXPECT(actual == expected);
    }},

    {CASE("price goes down then up") {
        const int actual = getMaxProfit({7, 2, 8, 9});
        const int expected = 7;
        EXPECT(actual == expected);
    }},

    {CASE("price goes up all day") {
        const int actual = getMaxProfit({1, 6, 7, 9});
        const int expected = 8;
        EXPECT(actual == expected);
    }},

    {CASE("price goes down all day") {
        const int actual = getMaxProfit({9, 7, 4, 1});
        const int expected = -2;
        EXPECT(actual == expected);
    }},

    {CASE("price stays the same all day") {
        const int actual = getMaxProfit({1, 1, 1, 1});
        const int expected = 0;
        EXPECT(actual == expected);
    }},

    {CASE("exception with empty prices") {
        EXPECT_THROWS(getMaxProfit({}));
    }},

    {CASE("exception with one price") {
        EXPECT_THROWS(getMaxProfit({1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}