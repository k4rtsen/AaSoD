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
        return gcd(a % b, b);
    else
        return gcd(a, b % a);
    return -1;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << "; " << lcm(a, b) << std::endl;
    return 0;
}
