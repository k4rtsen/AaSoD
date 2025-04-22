/**
 * @file D_addOnSegments.cpp
 * Дан массив a. Поступают запросы прибавления константы на отрезках [l,r] этого массива. В конце нужно вывести получившийся массив.
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n{0};
    cin >> n;

    vector<int> arr;
    forn(i, n)
    {
        int x{0};
        cin >> x;
        arr.push_back(x);
    }

    long long *seq {new long long[n]{}};
    int q{0};
    cin >> q;
    forn(i, q)
    {
        int l{0}, r{0}, d{0};
        cin >> l >> r >> d;
        seq[l - 1] += d;
        if (r < n)
            seq[r] -= d;
    }

    long long *prefix{ new long long[n + 1]{}};
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + seq[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << (long long)arr[i] + prefix[i + 1] << " ";
    }

    return 0;
}
