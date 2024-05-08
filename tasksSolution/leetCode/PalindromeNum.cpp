#include <iostream>
#include <math.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// returns count of digits in number
unsigned short digitCount(int number)
{
    return floor(log10(number)) + 1;
}

// returns the highest digit of the number
unsigned short hiDigit(int number)
{
    double k = log10(number);
    k -= floor(k);
    return pow(10, k);
}

bool isPalindrome1(int num)
{
    if (num < 0)
        return false;

    unsigned digCount = digitCount(num);
    for (int i = 0; i < digCount / 2; i++)
    {
        unsigned low = num % 10;
        unsigned hi = hiDigit(num);
        if (hi != low)
            return false;
        num -= hi * pow(10, digitCount(num) - 1);
        num -= low;
        num /= 10;
    }
    return true;
}

bool isPalindrome(int num)
{
    if (num < 0)
        return false;

    int temp = num;
    int pal = 0;

    while (temp != 0)
    {
        short digit = temp % 10;
        pal = pal * 10 + digit;
        temp /= 10;
    }

    return (pal == num);
}

// the fastest algorithm
bool isPalindromeFast(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
    {
        return false;
    }

    int reversed = 0;
    while (x > reversed)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return (x == reversed) || (x == reversed / 10);
}

int main(int argc, char const *argv[])
{
    unsigned num{0};
    cin >> num;
    isPalindromeFast(num) ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}
