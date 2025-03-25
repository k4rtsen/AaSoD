#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

bool isCovered(vector<vector<int>> &ranges, int left, int right)
{
    constexpr int N{52}; // по условию задачи
    int cover[N] = {0};

    for (auto arr : ranges)
    {
        cover[arr[0]]++;
        cover[arr[1] + 1]--;
    }

    int sum{0};
    for (int i = 1; i <= right; i++) // отсчет обязательно с 1
    {
        sum += cover[i];
        if (!sum && i >= left)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr{{50, 50}};
    cout << isCovered(arr, 50, 50) << endl;

    return 0;
}
