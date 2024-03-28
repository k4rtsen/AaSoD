#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

// returns ceil log2
unsigned short logNbase2(unsigned long long num)
{
    unsigned short lgN{0};
    bool flag{false};
    for (; num > 1; lgN++, num /= 2)
    {
        if (num % 2 != 0)
            flag = true;
    }
    return flag ? lgN + 1 : lgN;
}

// returns ceil log10
unsigned short logNbase10(unsigned long long num)
{
    unsigned short lgN{0};
    bool flag{false};
    for (; num > 9; lgN++, num /= 10)
        if (num % 10 != 0)
            flag = true;
    return flag || (num > 1) ? lgN + 1 : lgN;
}

// returns count of digits in number
unsigned short digitCount(unsigned long long number)
{
    return floor(log10(number)) + 1;
}

// returns the highest digit of the number
unsigned short hiDigit(unsigned long long number)
{
    double k = log10(number);
    k = k - floor(k);
    return pow(10, k);
}

// returns approx n!
unsigned long long factorial(unsigned short n)
{
    return sqrt(2 * M_PI * n) * pow(n / M_E, n);
}

// returns ln(n!)
unsigned long long sterling(unsigned int n)
{
    return n * log(n) - n + sqrt(log(2 * M_PI * n));
}

// returns digits in n!
unsigned long long digits_in_factN(unsigned int n)
{
    return ceil(sterling(n) / log(10)) + 1;
}

// returns the number of bits out of n
unsigned long long count_of_bits(unsigned int num)
{
    return logNbase2(num + 1);
}

// returns approx H(n)
double harmonic_nums(unsigned int n)
{
    double y = 0.57721;
    return log(n) + y + 1/(12*n);
}

const int N = 10e5; // million

int main(int argc, char const *argv[])
{
    srand(time(0));
    rand();
    int n = 255; //rand() % N;
    cout << "n : " << n
         << "\nlogN base 2:\t" << logNbase2(n)
         << "\ncount of digit:\t" << digitCount(n)
         << "\nhight digit:\t" << hiDigit(n)
         << "\ncount of bits:\t" << count_of_bits(n)
         << "\nDigits in fact of n:\t" << digits_in_factN(n) << endl;

    return 0;
}
