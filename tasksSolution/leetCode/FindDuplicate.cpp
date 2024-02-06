#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int findDuplicate(vector<int> &nums)
{
    for (; nums[0] != nums[nums[0]]; swap(nums[0], nums[nums[0]]))
        ;
    return nums[0];
}

// Marking visited value within the array
// Since all values of the array are between [1…n][1 \dots n][1…n] and the array size is n+1n+1n+1, while scanning the array from left to right, we set the nums[n]\textit{nums}[n]nums[n] to its negative value.
// Time Complexity: O(n)
// Space Complexity: O(1)
int findDuplicate_mark(vector<int> &nums)
{
    int len = nums.size();
    for (int num : nums)
    {
        int idx = abs(num);
        if (nums[idx] < 0)
        {
            return idx;
        }
        nums[idx] = -nums[idx];
    }

    return len;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
int findDuplicate_sort(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = 1; i < len; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return nums[i];
        }
    }

    return len;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int findDuplicate_index_sort(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 0; i < len;)
    {
        int n = nums[i];
        if (n == i + 1)
        {
            i++;
        }
        else if (n == nums[n - 1])
        {
            return n;
        }
        else
        {
            nums[i] = nums[n - 1];
            nums[n - 1] = n;
        }
    }

    return 0;
}

int main()
{
    vector<int> vec{2,2,2,2,2};

    cout << findDuplicate_index_sort(vec) << endl;

    return 0;
}
