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
    int p, q;

    // id[i] show to which element attached i
    int id[N]; // links
    // id sz[i] show how many elements attached to element i
    int sz[N]; // tree size
    forn(i, N)
    {
        id[i] = i;
        sz[i] = 1; // attach self
    }

    // algorithm
    while (cin >> p >> q)
    {
        if (p == q)
            break;
        int i, j;

        // find roots with compressing find path
        for (i = p; i != id[i]; i = id[i])
        {
            if (id[i] != id[id[i]])
                sz[id[i]] -= sz[i]; // calculate size
            id[i] = id[id[i]]; // if the root of the element also has a root, then the lower element is union with the root of its root
        }
        printf("Root %d is %d (size : %d)\n", p, i, sz[i]);
        // the same
        for (j = q; j != id[j]; j = id[j])
        {
            if (id[j] != id[id[j]])
                sz[id[j]] -= sz[j];
            id[j] = id[id[j]];
        }
        printf("Root %d is %d (size : %d)\n", q, j, sz[j]);

        // if elements no attached before
        if (i != j)
        {
            // compare sizes
            if (sz[i] < sz[j])
            {
                // attach small tree to big
                id[i] = j;
                // added elements from small tree
                sz[j] += sz[i];
            }
            else
            {
                // the same
                id[j] = i;
                sz[i] += sz[j];
            }
        }
        else
        {
            cout << "Already merged" << endl;
            continue;
        }

        // count++ and if count == N-1 mean that all elements connected
        cout << "Union : " << p << " and " << q << endl;

        printArray(id, N);
        printArray(sz, N);
    }
}
