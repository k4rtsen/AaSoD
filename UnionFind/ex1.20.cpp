// TO-DO
#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

static const int N = 10;

void printArray(int *arr, int size)
{
    cout << "{ ";
    forn(i, size)
    {
        cout << arr[i] << "; ";
    }
    cout << "}" << endl;
}

int main()
{
    // init vars
    int p{}, q{};
    int count = 0;
    
    // id[i] show to which element attached i
    int id[N]; // links
    // id sz[i] show how many elements attached to element i
    int sz[N]; // tree hight
    forn(i, N)
    {
        id[i] = i;
        sz[i] = 0; // attach self
    }

    // algorithm
    while (cin >> p >> q && count < N - 1)
    {
        if (p == q)
            break;
        int i, j;

        // find roots with compressing find path
        for (i = p; i != id[i]; i = id[i])
            ;

        // the same
        for (j = q; j != id[j]; j = id[j])
            ;

        // if elements no attached before
        if (i != j)
        {
            // compare sizes
            if (sz[i] < sz[j])
            {
                // attach small tree to big
                id[i] = j;
            }
            else
            {
                // the same
                id[j] = i;
                if (sz[i] == sz[j])
                    sz[i]++;
            }
        }
        else
        {
            cout << "Already merged" << endl;
            continue;
        }

        // if count == N-1 mean that all elements connected
        ++count;
        cout << "Union : " << p << " and " << q << endl;

        printArray(id, N);
        printArray(sz, N);
    }
}
