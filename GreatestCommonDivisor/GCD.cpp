#include <cassert>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a >= b)
        gcd(a % b, b);
    if (b >= a)
        gcd(a, b % a);
    return -1;
}

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}