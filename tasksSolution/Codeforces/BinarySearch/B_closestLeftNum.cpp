#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

typedef vector<int>::iterator int_iter;
// if we return int_iter, we dont check the existence of the element.
// but we can return the int -1 value if the element doesnt exist.
int_iter BS(int_iter start, int_iter end, int searchItem);

int main(int argc, char const *argv[])
{
    int n{0}, k{0};
    cin >> n >> k;
    vector<int> arr;

    forn(_, n)
    {
        int x{0};
        cin >> x;
        arr.push_back(x);
    }

    forn(_, k)
    {
        int x{0};
        cin >> x;

        cout << BS(arr.begin(), arr.end(), x) - arr.begin() << endl;
    }

    return 0;
}

int_iter BS(int_iter start, int_iter end, int searchItem)
{
    if (end == start)
        return start;

    int_iter mid = start + (end - start) / 2;

    if (*mid > searchItem)
        return BS(start, mid, searchItem); // (mid, end] or [mid + 1, end]
    else
        return BS(++mid, end, searchItem); // [start, mid) or [start, mid - 1]
}
