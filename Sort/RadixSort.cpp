#include <iostream>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int digit(int n, int k, int N, int M)
{
    return (n >> (N * k) & (M - 1));
}

void _radixsort(int *l, int *r, int N)
{
    int k = (32 + N - 1) / N; // 4
    int M = 1 << N; // 256
    int sz = r - l; // size of arr
    int *b = new int[sz]; // b[size]
    int *c = new int[M]; // c[256]
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < M; j++)
            c[j] = 0; // fill arr by 0

        for (int *j = l; j < r; j++)
            c[digit(*j, i, N, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }
    delete[] b;
    delete[] c;
}

/// @brief sorting array
/// @param arr left element of array
/// @param arrN right element of array
clock_t LSD(int *leftElem, int *rightElem)
{
    clock_t start = clock();

    _radixsort(leftElem, rightElem, 8);

    return clock() - start;
}

void print_array(int *arr, const size_t size)
{
    forn(i, size)
    {
        cout << arr[i] << "; ";
    }
    cout << endl;
}

bool checkSorting(int *arr, const size_t size)
{
    forn(i, size - 1) if (arr[i] > arr[i + 1]) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    const size_t N = 10;
    // array implementation
    int *arr = new int[N];
    forn(i, N)
    {
        arr[i] = i;
    }
    random_shuffle(arr, arr + N);
    // print_array(arr, N);

    cout << "Time: " << LSD(arr, arr + N) << endl;
    checkSorting(arr, N) ? cout << "Done!" << endl : cout << "Wrong!" << endl;

    // print_array(arr, N);

    return 0;
}
