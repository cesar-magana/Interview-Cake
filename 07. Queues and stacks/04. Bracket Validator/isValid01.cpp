#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

bool isValid(const string& code)
{
    // determine if the input code is valid
    unordered_map<char,char> openersToClosers {
        make_pair('(', ')'),
        make_pair('[', ']'),
        make_pair('{', '}')        
    };
    unordered_set<char> closers {
        ')', ']', '}'
    };   
    stack<char> openersStack;
    for (char c : code) {
            if (openersToClosers.find(c) != openersToClosers.end()) {
                openersStack.push(c);
            }
            else if (closers.find(c) != closers.end()) {
                if (openersStack.empty()) {
                    return false;
                }
                else {
                    char lastUnclosedOpener = openersStack.top();
                    openersStack.pop();
                    if (openersToClosers[lastUnclosedOpener] != c) {
                        return false;
                    }
                }
            }
        }

    return openersStack.empty();    
}


















// tests

const lest::test tests[] = {
    {CASE("valid short code") {
        const auto code = "()";
        const auto result = isValid(code);
        EXPECT(result == true);
    }},
    {CASE("valid longer code") {
        const auto code = "([]{[]})[]{{}()}";
        const auto result = isValid(code);
        EXPECT(result  == true);
    }},
    {CASE("interleaved openers and closers") {
        const auto code = "([)]";
        const auto result = isValid(code);
        EXPECT(result == false);
    }},
    {CASE("mismatched opener and closer") {
        const auto code = "([][]}";
        const auto result = isValid(code);
        EXPECT(result == false);
    }},
    {CASE("missing closer") {
        const auto code = "[[]()";
        const auto result = isValid(code);
        EXPECT(result == false);
    }},
    {CASE("extra closer") {
        const auto code = "[[]]())";
        const auto result = isValid(code);
        EXPECT(result == false);
    }},
    {CASE("empty string") {
        const auto code = "";
        const auto result = isValid(code);
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}