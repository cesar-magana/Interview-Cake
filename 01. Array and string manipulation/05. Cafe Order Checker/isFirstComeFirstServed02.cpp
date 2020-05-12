#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders)
{
    auto takeOutOrdersIter = takeOutOrders.cbegin();
    auto dineInOrdersIter = dineInOrders.cbegin();

    for (int order : servedOrders) {

        // if we still have orders in takeOutOrders
        // and the current order in takeOutOrders is the same
        // as the current order in servedOrders
        if (takeOutOrdersIter != takeOutOrders.cend() && order == *takeOutOrdersIter) {
            ++takeOutOrdersIter;
        }

        // if we still have orders in dineInOrders
        // and the current order in dineInOrders is the same
        // as the current order in servedOrders
        else if (dineInOrdersIter != dineInOrders.cend() && order == *dineInOrdersIter) {
            ++dineInOrdersIter;
        }

        // if the current order in servedOrders doesn't match the current
        // order in takeOutOrders or dineInOrders, then we're not serving first-come,
        // first-served
        else {
            return false;
        }
    }

    // check for any extra orders at the end of takeOutOrders or dineInOrders
    if (dineInOrdersIter != dineInOrders.cend() || takeOutOrdersIter != takeOutOrders.cend()) {
        return false;
    }

    // all orders in servedOrders have been "accounted for"
    // so we're serving first-come, first-served!
    return true;
}


















// tests

const lest::test tests[] = {
    {CASE("both registers have same number of orders") {
        const vector<int> takeOutOrders {1, 4, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 4, 5, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("registers have different lengths") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register is empty") {
        const vector<int> takeOutOrders;
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {2, 3, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("served orders is missing orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("served orders has extra orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 5, 6, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has extra orders") {
        const vector<int> takeOutOrders {1, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has unserved orders") {
        const vector<int> takeOutOrders {55, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8, 9};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("order numbers are not sequential") {
        const vector<int> takeOutOrders = {27, 12, 18};
        const vector<int> dineInOrders = {55, 31, 8};
        const vector<int> servedOrders = {55, 31, 8, 27, 12, 18};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}


















// tests

const lest::test tests[] = {
    {CASE("both registers have same number of orders") {
        const vector<int> takeOutOrders {1, 4, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 4, 5, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("registers have different lengths") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register is empty") {
        const vector<int> takeOutOrders;
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {2, 3, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("served orders is missing orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("served orders has extra orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 5, 6, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has extra orders") {
        const vector<int> takeOutOrders {1, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has unserved orders") {
        const vector<int> takeOutOrders {55, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8, 9};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("order numbers are not sequential") {
        const vector<int> takeOutOrders = {27, 12, 18};
        const vector<int> dineInOrders = {55, 31, 8};
        const vector<int> servedOrders = {55, 31, 8, 27, 12, 18};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}