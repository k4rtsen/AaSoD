#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

vector<int> runningSum(const vector<int> &nums)
{
    vector<int> res(nums.size());
    res[0] = nums[0];
    for (size_t i = 1; i < nums.size(); i++)
    {
        res[i] = res[i - 1] + nums[i];
    }

    return res;
}

vector<int> leftRightDifference(const vector<int> &nums)
{
    const int N{static_cast<int>(nums.size()) - 1};
    vector<int> prefixSum = runningSum(nums), result(N + 1);

    result[0] = prefixSum[N] - prefixSum[0];
    result[N] = prefixSum[N] - nums[N];

    for (int i = 1; i < N; i++)
    {
        int left = prefixSum[i - 1];
        int right = prefixSum[N] - prefixSum[i];
        result[i] = abs(left - right);
    }

    return result;
}

// more simple solution
vector<int> leftRightDifference2(const vector<int> &nums)
{
    vector<int> result;
    int rSum{0}, lSum{0};
    for (int i = 0; i < nums.size(); i++)
    {
        rSum += nums[i];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        rSum -= nums[i];
        result.push_back(abs(lSum - rSum));
        lSum += nums[i];
    }

    return result;
}

ostream &operator<<(ostream &s, const vector<int> &v)
{
    for (auto &val : v)
        s << val << " ";

    return s;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{3, 9, 6, 2, 5};
    cout << leftRightDifference2(arr) << endl;

    return 0;
}
