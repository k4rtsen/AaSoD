#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

int searchInsert(vector<int> &nums, int target)
{
    int l{0}, r{static_cast<int>(nums.size()) - 1};

    while (l <= r)
    {
        int mid{(r + l) / 2};
        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            if (l == r)
                r = mid - 1;
            else 
                r = mid;

        if (nums[mid] < target)
            l = mid + 1;
    }
    return l;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{1, 3, 5, 6};
    cout << searchInsert(arr, 6) << endl;
    return 0;
}
