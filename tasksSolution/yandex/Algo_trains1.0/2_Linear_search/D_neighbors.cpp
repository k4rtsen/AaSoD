#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int temp{0}, count{0};
    while(cin >> temp)
        arr.push_back(temp);

    for (int i = 1; i < arr.size() - 1; i++)
    {
        if(arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            count++;
        }
    }
    cout << count;

    return 0;
}
