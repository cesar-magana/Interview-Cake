#include <iostream>
#include <string>
#include <unordered_set>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome
    unordered_set<char> unpaired;
    
    for ( char c : str ) {
        if ( unpaired.find(c) != unpaired.end() ) {
            unpaired.erase(c);
        } else {
            unpaired.insert(c);
        }
    }

    return unpaired.size() < 2;
}


















// tests

const lest::test tests[] = {
    {CASE("permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcbcd");
        EXPECT(result == true);
    }},
    {CASE("permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabccbdd");
        EXPECT(result == true);
    }},
    {CASE("no permutation with odd number of chars") {
        const auto result = hasPalindromePermutation("aabcd");
        EXPECT(result == false);
    }},
    {CASE("no permutation with even number of chars") {
        const auto result = hasPalindromePermutation("aabbcd");
        EXPECT(result == false);
    }},
    {CASE("empty string") {
        const auto result = hasPalindromePermutation("");
        EXPECT(result == true);
    }},
    {CASE("one character string") {
        const auto result = hasPalindromePermutation("a");
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}