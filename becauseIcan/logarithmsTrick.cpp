#include <math.h>
#include <iostream>

// count of digits in number without loop
ushort digitCount(long number) {
    return floor(log10(number)) + 1;
}

// the highest digit of the number
ushort hiDigit(long number) {
    double k = log10(number);
    k = k - floor(k);
    return pow(10, k);
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int n = rand() % 100;
    std::cout << "n : " << n
        << "\ncount of digit: " << digitCount(n) 
        << "\nHight digit: " << hiDigit(n) << std::endl;
    return 0;
}
