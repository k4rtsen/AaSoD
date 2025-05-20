#include <cassert>
#include <iostream>

/**
 * @brief recursive Euclid algorithm
 * 
 * @param m integer, where m > n
 * @param n integer, where n < m
 * @return int greatest common divisor
 */
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

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
