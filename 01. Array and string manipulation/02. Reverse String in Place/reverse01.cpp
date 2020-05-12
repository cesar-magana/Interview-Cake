#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverse(string& str)
{
    // reverse the input string in place
    int n = str.length();
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]);
}