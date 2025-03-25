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

// O(N^3)
int countTriplets(vector<int> &arr)
{
    const int N{static_cast<int>(arr.size()) + 1};
    int prefixSum[N];
    prefixSum[0] = 0;
    for (int i = 1; i < N; i++)
    {
        prefixSum[i] = 0;
        prefixSum[i] ^= prefixSum[i - 1] ^ arr[i - 1];
    }

    int count{0};
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int a = prefixSum[i - 1] ^ prefixSum[j - 1];
            for (int k = j; k < N; k++)
            {
                int b = prefixSum[j - 1] ^ prefixSum[k];
                if (a == b)
                    count++;
            }
        }
    }
    return count;
}

// TO-DO: better solution

int main(int argc, char const *argv[])
{
    vector<int> arr{10};
    cout << countTriplets(arr) << endl;

    return 0;
}
