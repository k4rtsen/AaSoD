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
        int i = p, j = q;

        // find roots
        while (i != id[i])
            i = id[i];

        while (j != id[j])
            j = id[j];

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

        cout << "Union : " << p << " (root is " << i << ") and " << q << " (root is " << j << ")" << endl;

        printArray(id, N);
        printArray(sz, N);
    }
}
