#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

int findMiddleIndex(vector<int> &nums)
{
    int left{0}, right{0};
    for (auto val : nums)
        right += val;

    forn(i, nums.size())
    {
        right -= nums[i];
        if (right == left)
            return i;
        left += nums[i];
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{2, 5};
    cout << findMiddleIndex(arr) << endl;

    return 0;
}
