#include <bits/stdc++.h> 
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// a[]
// b[]
// sum a[i]*b[i] ---> min
// a : inc
// b : dec || inc

int main(int argc, char const *argv[])
{
    int n = 10;

    for(int t = 1;;t++) {
        if (t % 1000 == 0){
            printf("t = %d\n", t);
            fflush(stdout);
        }

        int a[n], b[n];
        forn(i, n) {
            a[i] = rand() % 10;
            b[i] = rand() % 10;
        }

        sort(a, a+n);
        sort(b, b+n);

        auto f = [&](){
            int sum = 0;
            forn(i, n)
                sum += a[i] * b[i];
            return sum;
        };
        int x = f();
        printf("%d | ",x);

        reverse(b, b+n);
        int y = f();

        printf("%d\n",y);

        random_shuffle(b, b + n);
        assert(f() >= y);
        // do
        // {
        //     assert(f() >= y);
        // } while (next_permutation(b, b+n));
    }
    // END
    printf("Well done!");
    return 0;
}
