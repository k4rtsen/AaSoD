#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

static const int N = 10;

void printArray(int *arr, int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "; ";
    cout << "}\n";
}

int main()
{
    // init vars
    int p, q;
    int id[N];
    forn(i, N)
        id[i] = i;

    // self algorithm
    while (cin >> p >> q)
    {
        if (p == q)
            break;

        if (id[p] == id[q])
        {
            cout << p << " and " << q << " are already merged" << endl;
            continue;
        }

        int temp = id[q];
        forn(i, N) if (id[i] == temp)
            id[i] = id[p];

        cout << "Union : " << p << " and " << q << endl;
        printArray(id, N);
    }
}
