#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverse(string& str)
{
    // reverse the input string in place
    if (str.empty()) {
        return;
    }

    size_t leftIndex = 0;
    size_t rightIndex = str.length() - 1;

    while (leftIndex < rightIndex) {
        // swap characters
        swap(str[leftIndex], str[rightIndex]);

        // move towards middle
        ++leftIndex;
        --rightIndex;
    }
}