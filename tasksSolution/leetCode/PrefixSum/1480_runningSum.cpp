#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    for (size_t i = 1; i < nums.size(); i++)
    {
        nums[i] += nums[i - 1];
    }

    return nums;
}

ostream &operator<<(ostream &s, const vector<int> &v)
{
    for (auto &val : v)
        s << val << " ";

    return s;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{3, 1, 2, 10, 1};
    cout << runningSum(nums) << endl;

    return 0;
}
