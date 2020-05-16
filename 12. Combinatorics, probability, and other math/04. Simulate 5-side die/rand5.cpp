#include <iostream>
#include <random>

using namespace std;

int rand7()
{
    static random_device rd;
    static mt19937 g(rd());
    static uniform_int_distribution<int> d(1, 7);
    return d(g);
}

int rand5()
{
    int result = rand7();
    if (result <= 5) {
        return result;
    }
    else {
        return rand5();
    }
}

int main()
{
    for (int i = 0; i < 10; ++i) {
        cout << rand5() << ' ';
    }
    cout << endl;

    return 0;
}