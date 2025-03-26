#include <iostream>
#include <vector>

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

using namespace std;

ostream &operator<<(ostream &s, const vector<long long> &v)
{
    for (auto &val : v)
        s << val << " ";

    return s;
}

vector<long long> findPrefixScore(vector<int> &nums)
{
    const int n{static_cast<int>(nums.size())};
    vector<long long> conv(n, 0);
    int max{INT_MIN};

    for (int i = 0; i < n; i++)
    {
        if (max < nums[i])
            max = nums[i];

        conv[i] = nums[i] + max;
    }

    for (int i = 1; i < n; i++)
    {
        conv[i] += conv[i - 1];
    }

    return conv;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{1, 1, 2, 4, 8, 16, 32, 64};
    cout << findPrefixScore(arr) << endl;
    return 0;
}
