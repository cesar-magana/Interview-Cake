### Solution

We swap the first and last characters, then the second and second-to-last characters, and so on until we reach the middle.

```cpp
  void reverse(string& str)
{
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
```



### Complexity

O(n)*O*(*n*) time and O(1)*O*(1) space.