#include <math.h>
#include <iostream>

// count of digits in number without loop
unsigned short digitCount(long number) {
    return floor(log10(number)) + 1;
}

// the highest digit of the number
unsigned short hiDigit(long number) {
    double k = log10(number);
    k = k - floor(k);
    return pow(10, k);
}

const int N = 1e7;

int main(int argc, char const *argv[])
{
    srand(time(0));
    rand();
    int n = rand() % N;
    std::cout << "n : " << n
        << "\ncount of digit: " << digitCount(n) 
        << "\nHight digit: " << hiDigit(n) << std::endl;
    return 0;
}
