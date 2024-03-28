#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef int Number;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

Number randNum()
{
    return rand();
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int N = randNum();
    double m1{0}, m2{0};

    forn(i, N){
        // each time we use a random number, so we simulate a list of random numbers
        Number x = randNum();
        // calc the arithmetic average of previous list
        m1 += ((double)x)/N;
        // calc 1/N*Sum(x^2) for a next formula (standard deviation)
        m2 += ((double)x * x)/N;
    }

    std::cout << "Avg\t" << m1 << endl; 
    std::cout << "Std. dev\t" << sqrt(m2 - m1*m1) << endl; // Std dev = Sqrt(Sum(x - Avg)^2)

    return 0;
}
