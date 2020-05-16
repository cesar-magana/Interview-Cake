#include <iostream>
#include <string>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

size_t getClosingParen(const string& sentence, size_t openingParenIndex)
{
    // find the position of the matching closing parenthesis
    int openPar = 0;
    
    for ( size_t i = openingParenIndex; i < sentence.length(); i++ ) {
        char c = sentence[ i ];
        if ( c == '(' ) {
            openPar++;
        }
        if ( c == ')' ) {
            if ( openPar == 0 ) {
                return i-1;                
            }
            else {
                openPar--;                
            }
        }
    }
    throw invalid_argument("Not matching closer");
}


















// tests

const lest::test tests[] = {
    {CASE("All openers then closers") {
        const size_t expected = 7;
        const size_t actual = getClosingParen("((((()))))", 2);
        EXPECT(actual == expected);
    }},
    {CASE("mixed openers and closers") {
        const size_t expected = 10;
        const size_t actual = getClosingParen("()()((()()))", 5);
        EXPECT(actual == expected);
    }},
    {CASE("no matching closer") {
        EXPECT_THROWS(getClosingParen("()(()", 2));
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}