#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

void MergeSortImpl(vector<int> &values, vector<int> &buffer, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSortImpl(values, buffer, l, m);
        MergeSortImpl(values, buffer, m + 1, r);

        int k = l;
        for (int i = l, j = m + 1; i <= m || j <= r;)
        {
            if (j > r || (i <= m && values[i] < values[j]))
            {
                buffer[k] = values[i];
                ++i;
            }
            else
            {
                buffer[k] = values[j];
                ++j;
            }
            ++k;
        }
        for (int i = l; i <= r; ++i)
        {
            values[i] = buffer[i];
        }
    }
}

void MergeSort(vector<int> &values)
{
    if (!values.empty())
    {
        vector<int> buffer(values.size());
        MergeSortImpl(values, buffer, 0, values.size() - 1);
    }
}

void MergeSortImpl(int *values, int *buffer, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSortImpl(values, buffer, l, m);
        MergeSortImpl(values, buffer, m + 1, r);

        int k = l;
        for (int i = l, j = m + 1; i <= m || j <= r;)
        {
            if (j > r || (i <= m && values[i] < values[j]))
            {
                buffer[k] = values[i];
                ++i;
            }
            else
            {
                buffer[k] = values[j];
                ++j;
            }
            ++k;
        }
        for (int i = l; i <= r; ++i)
        {
            values[i] = buffer[i];
        }
    }
}

void MergeSort(int *values, const size_t size)
{
        int* buffer = new int[size];
        MergeSortImpl(values, buffer, 0, size - 1);
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
    MergeSort(v);
    print_array(v);

    // array implementation
    int *arr = new int[N];
    forn(i, N)
    {
        arr[i] = i;
    }
    random_shuffle(arr, arr + N);
    print_array(arr, N);
    MergeSort(arr, N);
    print_array(arr, N);

    return 0;
}
