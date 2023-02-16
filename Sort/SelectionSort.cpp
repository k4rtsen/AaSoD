#include <iostream>
#include <algorithm> // min_element
#include <random>
#include <vector>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

void SelectionSort(vector<int> &values)
{
    for (auto i = values.begin(); i != values.end(); ++i)
    {
        auto j = min_element(i, values.end());
        swap(*i, *j);
    }
}

void SelectionSort(int *arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        int minElemIndex = i;
        for (size_t j = i + 1; j < size; j++)
            if (arr[minElemIndex] > arr [j])
                minElemIndex = j;
        swap(arr[i], arr[minElemIndex]);
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
    const int N = 20;
    // vector implementation
    vector<int> v(N);
    scatterValues(v);
    print_array(v);
    SelectionSort(v);
    print_array(v);

    // array implementation
    int *arr = new int[N];
    forn(i, N)
    {
        arr[i] = i;
    }
    random_shuffle(arr, arr + N);
    print_array(arr, N);
    SelectionSort(arr, N);
    print_array(arr, N);

    return 0;
}
