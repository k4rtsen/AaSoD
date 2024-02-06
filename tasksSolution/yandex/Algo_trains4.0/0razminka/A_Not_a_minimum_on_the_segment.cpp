#include <iostream>
#include <string>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const string NOTFOUND = "NOT FOUND";

int findMin(int* arr, int begin, int end) {
    int max = INT32_MAX;
    for(int i = begin; i < end + 1; i++) {
        if (arr[i] < max)
            max = arr[i];
    }

    return max;
}

string findNotMin(int* arr, int begin, int end, int min) {
    for (int i = begin; i < end + 1; i++) {
        if (arr[i] > min)
        {
            return to_string(arr[i]);
        }
    }
    return NOTFOUND;
}

int main(int argc, char const *argv[])
{
    int n{}, m{};
    cin >> n >> m;

    int *arr = new int[n];
    forn(i, n) {
        cin >> arr[i];
    }

    while(m > 0) {
        --m;
        int l{}, r{};
        cin >> l >> r;
        cout << findNotMin(arr, l, r, findMin(arr, l, r)) << endl;
    }

    return 0;
}
