#include <iostream>
#include <string>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

size_t getClosingParen(const string& sentence, size_t openingParenIndex)
{
    // find the position of the matching closing parenthesis
    stack<char> stk;
    size_t i = 0;
    size_t n = sentence.length();
    
    for ( i = 0; i < n; i++ ) {
        if ( sentence[ i ] == '(' ) {
            stk.push( i );
        }
        if ( sentence[ i ] == ')' ) {
            size_t index = stk.top();
            stk.pop();
            if ( index == openingParenIndex )
                break;
        }
    }
    if ( i == n ) {
        throw invalid_argument("Not matching closer");
    }

    return i;
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