#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

void GnomeSort(vector<int> &values)
{
    int index = 0;
    while (index < values.size())
    {
        if (index == 0)
            index++;
        if (values[index] >= values[index - 1])
            index++;
        else
        {
            swap(values[index], values[index - 1]);
            index--;
        }
    }
}

void GnomeSort(int *arr, const size_t size)
{
    int index = 0;
    while (index < size)
    {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else
        {
            swap(arr[index], arr[index - 1]);
            index--;
        }
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
    GnomeSort(v);
    print_array(v);

    // array implementation
    int *arr = new int[N];
    forn(i, N)
    {
        arr[i] = i - N / 2;
    }
    random_shuffle(arr, arr + N);
    print_array(arr, N);
    GnomeSort(arr, N);
    print_array(arr, N);

    return 0;
}
