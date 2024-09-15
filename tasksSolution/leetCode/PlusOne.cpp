#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr)
{
    cout << "{ ";
    for (auto &val : arr)
        cout << val << "; ";
    cout << "}" << endl;
}

vector<int> plusOne(vector<int> &digits)
{
    int k = digits.size() - 1;
    while (k >= 0)
    {
        if (digits[k] + 1 == 10)
        {
            digits[k] = 0;
            k--;
        }
        else
        {
            digits[k] += 1;
            return digits;
        }
    }

    vector<int> arr(digits.size() + 1);
    if (k < 0)
    {
        arr[0] = 1;
    }
    for (size_t i = 1; i < arr.size(); i++)
    {
        arr[i] = digits[i - 1];
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    vector<int> arr{9, 8, 9};
    printVector(plusOne(arr));
    return 0;
}
