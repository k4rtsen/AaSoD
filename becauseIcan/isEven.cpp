#include <iostream>
#include <cmath>
#include <assert.h>
#include <random>

bool isEven(int value)
{
    const short bits = 8;
    value = value << sizeof(value) * bits - 1;
    value = value >> sizeof(value) * bits - 1;
    return !(static_cast<bool>(value));
}
const int ITERATIONS = 1e7;

int main(int argc, char const *argv[])
{
    double sum = 0;

    for (int i = 0; i < ITERATIONS; i++)
        sum += rand() % 1000000;

    std::cout << "Average value: " << sum / ITERATIONS << '\n';
}
