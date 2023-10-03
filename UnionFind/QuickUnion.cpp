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
    int id[N];
    forn(i, N)
        id[i] = i;

    // self algorithm
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
            // union
            id[j] = i;
        else
        {
            cout << "Already merged" << endl;
            continue;
        }

        cout << "Union : " << p << " (root is " << i << ") and " << q << " (root is " << j << ")" << endl;
        printArray(id, N);
    }
}
