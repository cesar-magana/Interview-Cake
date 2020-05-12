#include <iostream>
#include <string>
#include <unordered_set>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void getPermutations(string prefix, const string& inputString, unordered_set<string>& permutations ) {
    
    size_t n = inputString.length();
    if ( n == 0 ) {
        permutations.insert( prefix );
    }
    else {
        for ( size_t i = 0; i < n; i++ ) {
            getPermutations( prefix + inputString[i], inputString.substr( 0, i ) + inputString.substr( i+1, n ), permutations );        
        }
    }
}


unordered_set<string> getPermutations(const string& inputString)
{
    // generate all permutations of the input string
    unordered_set<string> permutations; 
    getPermutations("", inputString, permutations);
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