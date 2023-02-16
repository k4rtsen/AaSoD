#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

void InsertionSort(vector<int> &values)
{
    for (size_t i = 1; i < values.size(); ++i)
    {
        int x = values[i];
        for (size_t j = i; j > 0 && values[j - 1] > x; j--)
            swap(values[j - 1], values[j]);
    }
}

void InsertionSort(int *arr, const size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        int x = arr[i];
        for (size_t j = i; j > 0 && arr[j - 1] > x; j--)
            swap(arr[j - 1], arr[j]);
    }
}

void scatterValues(vector<int> &values)
{
    forn(i, values.size())
        values[i] = i;
    auto rng = default_random_engine{};
    shuffle(begin(values), end(values), rng);
}

void print_array(vector<int> values)
{
    for (auto val : values)
        cout << val << "; ";
    cout << endl;
}

void print_array(int *arr, const size_t size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "; ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    const size_t N = 20;

    // vector implementation
    vector<int> v(N);
    scatterValues(v);
    print_array(v);
    InsertionSort(v);
    print_array(v);

    // array implementation
    int *arr = new int[N];
    forn(i, N)
    {
        arr[i] = i;
    }
    random_shuffle(arr, arr + N);
    print_array(arr, N);
    InsertionSort(arr, N);
    print_array(arr, N);

    return 0;
}
