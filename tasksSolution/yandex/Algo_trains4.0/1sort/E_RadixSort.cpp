#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define TEN 10

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printArray(string *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        cout << arr[i] << ", ";
    cout << arr[size - 1] << endl;
}

void printBucket(vector<vector<string>> bucket)
{
    forn(i, bucket.size())
    {
        cout << "Bucket " << i << ": ";
        if (bucket[i].empty())
        {
            cout << "empty";
        }
        else
        {
            for (int j = 0; j < bucket[i].size() - 1; j++)
            {
                cout << bucket[i][j] << ", ";
            }
            cout << bucket[i][bucket[i].size() - 1];
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<string>> bucket(TEN, vector<string>());
    int n{0};
    cin >> n;

    string *array{new string[n]};

    forn(i, n)
    {
        cin >> array[i];
    }

    cout << "Initial array:" << endl;
    printArray(array, n);

    size_t phases{array[0].size()};
    size_t last_digit{phases};
    forn(p, phases)
    {
        cout << "**********" << endl;
        cout << "Phase " << p + 1 << endl;

        last_digit--;
        forn(i, n)
        {
            char ch{array[i][last_digit]};
            int bucket_index{atoi(&ch)};
            bucket[bucket_index].push_back(array[i]);
        }

        printBucket(bucket);

        int index = 0;
        for (vector<string> &arr : bucket)
        {
            for (string val : arr)
            {
                array[index] = val;
                index++;
            }
            arr.clear();
        }
    }

    cout << "**********" << endl;
    cout << "Sorted array:" << endl;
    printArray(array, n);

    return 0;
}
