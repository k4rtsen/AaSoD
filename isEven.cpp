#include <iostream>
#include <random>

using namespace std;

bool isEven(int value)
{
    const short bits = 8;
    unsigned short countOfShift = sizeof(value) * bits - 1; // the number of digits before the last one
                                                            // the last bit for even numbers is 0, otherwise 1
    value = value << countOfShift;                          // move the last bit to the very beginning of the sequence and inserting zeros after it
    return !(static_cast<bool>(value));                     // if all bits in sequence is 0, then number is even, otherwise odd
}

// эта хрень работает быстрее :(
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

        if (count % 10000000 == 0)
        {
            cout << "1.\t" << i << " is " << even1 << endl;
            cout << "2.\t" << i << " is " << even2 << endl;
        }
        if (even1 != even2)
            break;
        count++;
    }
}
