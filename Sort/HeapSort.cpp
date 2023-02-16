#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

void HeapSort(vector<int> &values)
{
    make_heap(values.begin(), values.end());
    for (auto i = values.end(); i != values.begin(); --i)
    {
        pop_heap(values.begin(), i);
    }
}

void random_shuffle(vector<int> &values)
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

int main(int argc, char const *argv[])
{
    const int N = 20;
    vector<int> v(N);
    random_shuffle(v);
    print_array(v);
    HeapSort(v);
    print_array(v);
    return 0;
}
