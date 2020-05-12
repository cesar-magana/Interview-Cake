#include <iostream>
#include <random>
#include <vector>

using namespace std;

size_t getRandom(size_t floor, size_t ceiling)
{
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    double value = distribution(generator);
    return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}

void shuffle(vector<int>& v)
{
    int random;
    // shuffle the input in place
    for ( int i = v.size()-1; i > 0; i--) {
        random = getRandom( 0, i + 1 );
        swap( v[ i ], v[ random ] );
    }

}

void printVector(const char* title, const vector<int>& theVector)
{
    cout << title << ": [";
    bool isFirst = true;
    for (int value: theVector) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << ", ";
        }
        cout << value;
    }
    cout << ']' << endl;
}

int main(int argc, char** argv)
{
    const vector<int> initial {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> shuffled(initial);
    shuffle(shuffled);
    printVector("initial vector", initial);
    printVector("shuffled vector", shuffled);
    return 0;
}