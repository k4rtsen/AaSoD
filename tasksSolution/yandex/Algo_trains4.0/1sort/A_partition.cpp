#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int Partition(int *array, int size, int num)
{
    int left{0}, right{size - 1};

    while (left - right < 1)
    {
        if (array[left] >= num && array[right] < num)
        {
            array[left] = array[left] ^ array[right];
            array[right] = array[left] ^ array[right];
            array[left] = array[left] ^ array[right];
            left++;
            right--;
            continue;
        }
        if (array[left] < num)
            left++;
        if (array[right] >= num)
            right--;
    }
    return left;
}

int main(int argc, char const *argv[])
{
    int n{0}, num{0};
    cin >> n;
    int *arr = new int[n];
    forn(i, n)
    {
        cin >> arr[i];
    }
    cin >> num;

    if (n == 0)
        cout << 0 << endl
             << 0 << endl;
    else
    {
        int x = Partition(arr, n, num);
        cout << x << endl
             << n - x << endl;
    }
    return 0;
}
