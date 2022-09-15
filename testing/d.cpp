#include <bits/stdc++.h> 
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// generate a random line : L < R
// 0 <= L & R <= 1

int main(int argc, char const *argv[])
{
    clock_t start = clock();

    {
        const int n = 100000;
        double sum = 0;

        forn(i, n){
            double L, R;
            do
            {
                L = 1. * rand() / RAND_MAX;
                R = 1. * rand() / RAND_MAX;
            } while (L > R);// || R - L < 0.5);

            // L = 1. * rand() / RAND_MAX;
            // R = 1. * rand() / RAND_MAX;
            sum += R - L;
        }

        printf("%.5f\n", sum / n); // mat ozhidanie
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}
