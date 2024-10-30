// new solution O(N)
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int size{0};
    cin >> size;

    int val{0};
    vector<long long> arr;
    while (cin >> val)
    {
        arr.push_back(val);
    }

    int left{0}, count{0};
    int right{size - 1};

    while (left < right)
    {
        if (arr[left] == arr[right])
        {
            right--;
            count++;
        }
        else
        {
            right = size - 1;
            if (count)
            {
                count = 0;
                continue;
            }
            count = 0;
        }

        left++;
    }

    val = arr.size() - count * 2;
    if (!count)
        val--;
    if (count && left == right)
        val--;
        
    cout << val << endl;
    for (int i = val - 1; i >= 0; i--)
        cout << arr[i] << " ";

    return 0;
}
