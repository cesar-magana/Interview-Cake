#include <iostream>
#include <string>
#include <unordered_set>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

  unordered_set<string> getPermutations(const string& inputString)
{
    unordered_set<string> permutations;

    // base case
    if (inputString.length() <= 1) {
        permutations.insert(inputString);
        return permutations;
    }

    string allCharsExceptLast = inputString.substr(0, inputString.length() - 1);
    char lastChar = inputString[inputString.length() - 1];

    // recursive call: get all possible permutations for all chars except last
    const auto permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

    // put the last char in all possible positions for each of the above permutations
    for (const string& permutationOfAllCharsExceptLast : permutationsOfAllCharsExceptLast) {
        for (size_t position = 0; position <= allCharsExceptLast.length(); ++position) {
            string permutation = permutationOfAllCharsExceptLast.substr(0, position)
                    + lastChar + permutationOfAllCharsExceptLast.substr(position);
            permutations.insert(permutation);
        }
    }

    return permutations;
}


















// tests

const lest::test tests[] = {
    {CASE("empty string") {
        const unordered_set<string> expected {""};
        auto actual = getPermutations("");
        EXPECT(actual == expected);
    }},
    {CASE("one character string") {
        const unordered_set<string> expected {"a"};
        auto actual = getPermutations("a");
        EXPECT(actual == expected);
    }},
    {CASE("two character string") {
        const unordered_set<string> expected {"ab", "ba"};
        auto actual = getPermutations("ab");
        EXPECT(actual == expected);
    }},
    {CASE("three character string") {
        const unordered_set<string> expected {"abc", "acb", "bac", "bca", "cab", "cba"};
        auto actual = getPermutations("abc");
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}