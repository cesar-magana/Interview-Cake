#include <iostream>
#include <random>

using namespace std;

int rand5()
{
    static random_device rd;
    static mt19937 g(rd());
    static uniform_int_distribution<int> d(1, 5);
    return d(g);
}

  int rand7()
{
    while (true) {
        // do our die rolls
        int roll1 = rand5();
        int roll2 = rand5();

        int outcomeNumber = (roll1 - 1) * 5 + (roll2 - 1) + 1;

        if (outcomeNumber > 21) {
            continue;
        }

        return outcomeNumber % 7 + 1;
    }
}

int main()
{
    for (int i = 0; i < 14; ++i) {
        cout << rand7() << ' ';
    }
    cout << endl;

    return 0;
}