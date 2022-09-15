#define _GLIBCXX_DEBUG // Before include files

#include <bits/stdc++.h> 
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    clock_t start = clock();

    const int n = 100;
    int a[n];

    for (auto &&i : a)
        i = rand() % n;

    auto f = [](int i, int j){
        return i >= j; //=>Error
        // return i > j; //=>Right
    };

    sort(a, a + n, f);

    forn(i, n - 1){
        assert(f(a[i], a[i+1]));
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}
