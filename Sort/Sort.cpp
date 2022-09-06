#include <iostream>

using namespace std;

int main();

void print(int*, int); // show array

void SetRandomValuesOfArray(int*, int); // mix array

/* Bubble sort 
* the best case - O(n)
* the middle case - O(n^2)
* the worst case - O(n^2)
* memory cost - O(1)
*/ 
void BubbleSort(int*, int);

/* Shaker sort 
* the best case - O(n)
* the middle case - O(n^2)
* the worst case - O(n^2)
* memory cost - O(1)
*/ 
void ShakerSort(int*, int);

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    // init
    cout << "Please, enter the n of array...\t";
    int n;
    cin >> n;
    int* arr = new int[n];
    
    SetRandomValuesOfArray(arr, n);
    print(arr, n);

    // Sorting...
    ShakerSort(arr, n);
    print(arr, n);

    // --- END --- 
    delete[] arr;
    system("pause");
}

void print(int* arr, int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "; ";
    cout << "}\n";
}

void SetRandomValuesOfArray(int* arr, int size)
{
    // fill array with random nums from 1 to size
    for (int i = 0; i < size; i++)
        arr[i] = rand() % size;
}

void BubbleSort(int* values, int size) 
{
    for (size_t i = 0; i < size - 1; ++i) 
    {
        for (size_t j = 0; j < (size - i) - 1; ++j) 
        {
            if (values[j + 1] < values[j]) 
            {
                swap(values[j], values[j + 1]);
            }
        }
    }
}

void ShakerSort(int* values, int size)
{
    int left = 0, right = size;
    while (left < right) 
    {
        for(size_t i = left; i < right - 1; i++)
        {
            if (values[i] > values[i + 1])
                swap(values[i], values[i + 1]);
        }
        --right;

        for (size_t j = right; j > left; j--)
        {
            if (values[j] < values[j - 1])
                swap(values[j], values[j - 1]);
        }
        ++left;
    }
}
