#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int Partition(vector<int> &values, int l, int r)
{
    int x = values[r];
    int less = l;

    for (int i = l; i < r; ++i)
    {
        if (values[i] <= x)
        {
            swap(values[i], values[less]);
            ++less;
        }
    }
    swap(values[less], values[r]);
    return less;
}

void QuickSortImpl(vector<int> &values, int l, int r)
{
    if (l < r)
    {
        int q = Partition(values, l, r);
        QuickSortImpl(values, l, q - 1);
        QuickSortImpl(values, q + 1, r);
    }
}

void QuickSort(vector<int> &values)
{
    if (!values.empty())
    {
        QuickSortImpl(values, 0, values.size() - 1);
    }
}

int Partition(int *arr, int l, int r)
{
    int x = arr[r];
    int less = l;

    for (int i = l; i < r; ++i)
    {
        if (arr[i] <= x)
        {
            swap(arr[i], arr[less]);
            ++less;
        }
    }
    swap(arr[less], arr[r]);
    return less;
}

void QuickSortImpl(int *arr, int l, int r)
{
    if (l < r)
    {
        int q = Partition(arr, l, r);
        QuickSortImpl(arr, l, q - 1);
        QuickSortImpl(arr, q + 1, r);
    }
}

clock_t QuickSort(int *arr, const size_t size)
{
    clock_t start = clock();

    QuickSortImpl(arr, 0, size);

    if (size >= 1024)
        return clock() - start;
    else
        return -1;
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

bool checkSorting(int *arr, const size_t size)
{
    forn(i, size - 1) if (arr[i] > arr[i + 1]) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    const size_t N = 1024 * 1024;
    // vector implementation
    // vector<int> v(N);
    // scatterValues(v);
    // QuickSort(v);

    // array implementation
    int *arr = new int[N];
    forn(i, N)
    {
        arr[i] = i;
    }
    random_shuffle(arr, arr + N);
    cout << "Time: " << QuickSort(arr, N) << endl;
    checkSorting(arr, N) ? cout << "Done!" << endl : cout << "Wrong!" << endl;
    // print_array(arr, N);

    return 0;
}
