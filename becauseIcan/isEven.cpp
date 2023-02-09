#include <iostream>
#include <random>

using namespace std;

bool isEven(int value)
{
    const short bits = 8;
    unsigned short countOfShift = sizeof(value) * bits - 1; // digits before the last bit
    value = value << countOfShift;                          // delete all digits before last bit
    value = value >> countOfShift;                          // return the remaining bit to its place
    return !(static_cast<bool>(value));                // the last bit for even numbers is 0, otherwise
}

bool isEven2(int value)
{
    return value % 2 == 0;
}

const int N = 1e7;

int main(int argc, char const *argv[])
{
    // testing
    srand(time(NULL));
    rand();

    int count = 0;

    // infinity loop if isEven correct
    while (true)
    {
        int i = rand() % N;
        bool even1 = isEven(i);
        bool even2 = isEven2(i);

        if (count % 1000000 == 0)
        {
            cout << "1.\t" << i << " is " << even1 << endl;
            cout << "2.\t" << i << " is " << even2 << endl;
        }
        if (even1 != even2)
            break;
        count++;
    }
}
