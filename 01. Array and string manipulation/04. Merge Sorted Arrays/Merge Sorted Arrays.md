# Merge Sorted Arrays

**In order to win the prize for most cookies sold, my friend Alice and I are going to merge our Girl Scout Cookies orders and enter as one unit.**

Each order is represented by an "order id" (an integer).

We have our lists of orders sorted numerically already, in vectors. Write a function to merge our vectors of orders into one sorted vector.

For example:

```cpp
const vector<int> myVector {3, 4, 6, 10, 11, 15};
const vector<int> alicesVector {1, 5, 8, 12, 14, 19};

vector<int> mergedVector = mergeVectors(myVector, alicesVector);

cout << "[";
for (size_t i = 0; i < mergedVector.size(); ++i) {
    if (i > 0) {
        cout << ", ";
    }
    cout << mergedVector[i];
}
cout << "]" << endl;
// prints [1, 3, 4, 5, 6, 8, 10, 11, 12, 14, 15, 19]
```

