#include <iostream>
#include <string>
#include <stack>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverseWords(string& message)
{
    // decode the message by reversing the words
    if ( message.empty() ) {
        return;
    }
        
    reverse(message.begin(), message.end());
    int index = 0;
    stack<char> stk;

    cout << message << endl;
    message[0] = 'A';

    for ( char c : message ) {
        if ( c != ' ' ) 
            stk.push( c );
        else {
            while ( !stk.empty() ) {
                message[ index++ ] = stk.top();
                stk.pop();
            }
            message[ index++ ] = ' ';
        }
    }
    cout << message << endl;
}


















// tests

const lest::test tests[] = {
    {CASE("one word") {
        const string expected = "vault";
        string actual = "vault";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("two words") {
        const string expected = "cake thief";
        string actual = "thief cake";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("three words") {
        const string expected = "get another one";
        string actual = "one another get";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("multiple words same length") {
        const string expected = "the cat ate the rat";
        string actual = "rat the ate cat the";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("multiple words different lengths") {
        const string expected = "chocolate bundt cake is yummy";
        string actual = "yummy is cake bundt chocolate";
        reverseWords(actual);
        EXPECT(actual == expected);
    }},
    {CASE("empty string") {
        const string expected;
        string actual;
        reverseWords(actual);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}