#include <iostream>
#include <vector>
#include <algorithm>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class CakeType
{
public:
    const unsigned int weight_;
    const unsigned int value_;

    CakeType(unsigned int weight = 0, unsigned int value = 0) :
        weight_(weight),
        value_(value)
    {
    }
};

unsigned long long maxDuffelBagValue(const vector<CakeType>& cakeTypes,
                                     unsigned int weightCapacity)
{
    vector<unsigned long long> maxValuesAtCapacities(weightCapacity + 1);

    for (unsigned int currentCapacity = 0; currentCapacity <= weightCapacity; ++currentCapacity) {
        unsigned long long currentMaxValue = 0;

        for (const CakeType& cakeType : cakeTypes) {
            if (cakeType.weight_ == 0 && cakeType.value_ != 0) {
                throw range_error("Range error");
            }
            if (cakeType.weight_ <= currentCapacity) {
                unsigned long long maxValueUsingCake = cakeType.value_
                        + maxValuesAtCapacities[currentCapacity - cakeType.weight_];
                currentMaxValue = max(maxValueUsingCake, currentMaxValue);
            }
        }
        maxValuesAtCapacities[currentCapacity] = currentMaxValue;
    }
    return maxValuesAtCapacities[weightCapacity];
}


















// tests

const lest::test tests[] = {
    {CASE("one cake") {
        const vector<CakeType> cakeTypes { CakeType(2, 1) };
        const auto weightCapacity = 9U;
        const auto expected = 4ULL;
        const auto actual = maxDuffelBagValue(cakeTypes, weightCapacity);
        EXPECT(actual == expected);
    }},
    {CASE("two cakes") {
        const vector<CakeType> cakeTypes { CakeType(4, 4), CakeType(5, 5) };
        const auto weightCapacity = 9U;
        const auto expected = 9ULL;
        const auto actual = maxDuffelBagValue(cakeTypes, weightCapacity);
        EXPECT(actual == expected);
    }},
    {CASE("only take less valuable cake") {
        const vector<CakeType> cakeTypes { CakeType(4, 4), CakeType(5, 5) };
        const auto weightCapacity = 12U;
        const auto expected = 12ULL;
        const auto actual = maxDuffelBagValue(cakeTypes, weightCapacity);
        EXPECT(actual == expected);
    }},
    {CASE("lots of cakes") {
        const vector<CakeType> cakeTypes {
            CakeType(2, 3), CakeType(3, 6), CakeType(5, 1),
            CakeType(6, 1), CakeType(7, 1), CakeType(8, 1)
        };
        const auto weightCapacity = 7U;
        const auto expected = 12ULL;
        const auto actual = maxDuffelBagValue(cakeTypes, weightCapacity);
        EXPECT(actual == expected);
    }},
    {CASE("value to weight ratio is not optimal") {
        const vector<CakeType> cakeTypes { CakeType(51, 52), CakeType(50, 50) };
        const auto weightCapacity = 100U;
        const auto expected = 100ULL;
        const auto actual = maxDuffelBagValue(cakeTypes, weightCapacity);
        EXPECT(actual == expected);
    }},
    {CASE("zero capacity") {
        const vector<CakeType> cakeTypes { CakeType(1, 2) };
        const auto weightCapacity = 0U;
        const auto expected = 0ULL;
        const auto actual = maxDuffelBagValue(cakeTypes, weightCapacity);
        EXPECT(actual == expected);
    }},
    {CASE("cake with zero value and weight") {
        const vector<CakeType> cakeTypes { CakeType(0, 0), CakeType(2, 1) };
        const auto weightCapacity = 7U;
        const auto expected = 3ULL;
        const auto actual = maxDuffelBagValue(cakeTypes, weightCapacity);
        EXPECT(actual == expected);
    }},
    {CASE("cake with non-zero value and zero weight") {
        const vector<CakeType> cakeTypes { CakeType(0, 5) };
        const auto weightCapacity = 5U;
        EXPECT_THROWS(maxDuffelBagValue(cakeTypes, weightCapacity));
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}