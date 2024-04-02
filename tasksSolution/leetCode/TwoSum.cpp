#include <iostream> 
#include <vector>
#include <map>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printVector(vector<int> arr) {
    cout << "{ ";
    for (auto &val : arr)
        cout << val << "; ";
    cout << "}" << endl;
}

void printMap(map<int, int> map)
{
    cout << "Map = {" << endl;
    for(const auto& [key, val] : map)
    {
        cout << "\t" << key << " = " << val << endl;
    }
    cout << "}" << endl;
}

vector<int> TwoSum(vector<int> &nums, int target)
{
    map<int, int> map;
    vector<int> result;

    forn(i, nums.size())
    {
        map[nums[i]] = i;
    }

    forn(i, nums.size())
    {
        int num = target - nums[i];
        if (map.contains(num) && map[num] != i)
        {
            result.push_back(i);
            result.push_back(map[num]);
            break;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {0, 0, 0, 1, 2, 3, 3};
    printVector(TwoSum(vec, 6));

    return 0;
}
