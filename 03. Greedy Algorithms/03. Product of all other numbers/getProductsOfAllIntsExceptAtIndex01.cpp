#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& v)
{
    int n = v.size();
    
    if ( n < 2 ) {
        throw ("Not enough numbers");
    }
    
    int temp = 1;
    vector<int> x(n,1);

    for ( int i = n-2; i > -1; i-- ) {
        x[i] = x[i+1]*v[i+1];
    }    
    
    for ( int i = 0; i < n; i++ ) {
        x[i] *= temp;
        temp *= v[i];
    }

    return x;
}


















// tests

const lest::test tests[] = {
    {CASE("small vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({1, 2, 3});
        const auto expected = vector<int> {6, 3, 2};
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({8, 2, 4, 3, 1, 5});
        const auto expected = vector<int> {120, 480, 240, 320, 960, 192};
        EXPECT(actual == expected);
    }},

    {CASE("vector has one zero") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({6, 2, 0, 3});
        const auto expected = vector<int> {0, 0, 36, 0};
        EXPECT(actual == expected);
    }},

    {CASE("vector has two zeros") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({4, 0, 9, 1, 0});
        const auto expected = vector<int> {0, 0, 0, 0, 0};
        EXPECT(actual == expected);
    }},

    {CASE("one negative number") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-3, 8, 4});
        const auto expected = vector<int> {32, -12, -24};
        EXPECT(actual == expected);
    }},

    {CASE("all negative numbers") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-7, -1, -4, -2});
        const auto expected = vector<int> {-8, -56, -14, -28};
        EXPECT(actual == expected);
    }},

    {CASE("error with empty vector") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({}));
    }},

    {CASE("error with one number") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}