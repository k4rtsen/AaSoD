#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

ostream &operator<<(ostream &s, const vector<int> &v)
{
    for (auto &val : v)
        s << val << " ";

    return s;
}

vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
{
    const int N{static_cast<int>(nums.size())};
    int prefixSum[N];
    prefixSum[0] = nums[0];
    for (int i = 1; i < N; i++)
    {
        prefixSum[i] = 0;
        prefixSum[i] ^= prefixSum[i - 1] ^ nums[i];
    }
    int otvet = (1 << maximumBit) - 1;

    vector<int> res(N);
    for (int i = 0, j = N - 1; i < N, j >= 0; i++, j--)
    {
        res[i] = prefixSum[j] ^ otvet;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{0, 1, 2, 2, 5, 7};
    cout << getMaximumXor(arr, 3) << endl;

    return 0;
}
