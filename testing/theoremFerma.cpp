#include <bits/stdc++.h> 
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// x^n + y^n != z^n | n >= 3; x, y, z > 0

int main(int argc, char const *argv[])
{
    const int n = 1e8;
    clock_t start = clock();  

    // optimized version 
    // if y and z would start with 1, the algorithm would be slower
    for (int x = 1; x * x * x <= n; x++)
        for (int y = x; y * y * y <= n; y++)
            for (int z = y; z * z * z <= n; z++)
                assert(x*x*x + y*y*y != z*z*z);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

    return 0;
}
