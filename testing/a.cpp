#include <bits/stdc++.h> 
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// N = a^2 + b^2 + c^2 + ... + n^2

int main(int argc, char const *argv[])
{
    const int N = 1e5;
    vector<int> f(N, 1e9);
    f[0] = 0;
    for (int n = 1; n < N; n++)
    {
        for (int x = 0; x*x <= n; x++)
        {
            f[n] = min(f[n], 1 + f[n - x * x]);
        }
    }

    for (int n = 0; n < N; n++)
    {
        assert(f[n] <=4 );
        // printf("%d : %d\n", n, f[n]);
    }

    printf("well done!");
    return 0;
}
