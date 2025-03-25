#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int sum{0};
    int maxDiff{0};
    for (int i = 0; i < gain.size(); i++)
    {
        sum += gain[i];
        if (sum > maxDiff)
            maxDiff = sum;
    }
    return maxDiff;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{-4, -3, -2, -1, 4, 3, 2};
    cout << largestAltitude(arr) << endl;
    return 0;
}
