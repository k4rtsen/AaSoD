#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

static const int N = 1e4;

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
    clock_t start = clock();
    srand(time(NULL));
    // init vars
    int p, q;
    int count = 0;
    int number_of_edges = 0;
    // id[i] show to which element attached i
    int id[N]; // links
    // id sz[i] show how many elements attached to element i
    vector<int> sz(N); // tree size
    forn(i, N)
    {
        id[i] = i;
        sz[i] = 0; // attach self
    }

    // algorithm
    while (count < N - 1)
    {
        ++number_of_edges;
        p = rand() % N;
        q = rand() % N;

        int i, j;

        // find roots with compressing find path
        for (i = p; i != id[i]; i = id[i])
        {
            if (id[i] != id[id[i]])
                --sz[id[i]];   // calculate size
            id[i] = id[id[i]]; // if the root of the element also has a root, then the lower element is union with the root of its root
        }
        // the same
        for (j = q; j != id[j]; j = id[j])
        {
            if (id[j] != id[id[j]])
                --sz[id[j]];
            id[j] = id[id[j]];
        }

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
            // cout << "Already merged" << endl;
            continue;
        }

        // count++ and if count == N-1 mean that all elements connected
        ++count;
        // cout << "Union : " << p << " and " << q << endl;
    }
    // printArray(id, N);
    // printArray(sz, N);
    cout << "Max hight : " << *max_element(sz.begin(), sz.end()) << endl;
    cout << number_of_edges << endl;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
}
