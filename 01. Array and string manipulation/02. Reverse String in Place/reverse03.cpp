//https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/

#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverse(string& str)
{
    // reverse the input string in place
    reverse(str.begin(), str.end());
}