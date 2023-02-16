#include <iostream>
#include <algorithm>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void print(int*, int); // show array

void SetRandomValuesOfArray(int*, int); // mix array

/* Bubble sort 
* the best case - O(n)
* the middle case - O(n^2)
* the worst case - O(n^2)
* memory cost - O(1)
*/ 
long long BubbleSort(int*, int);

/* Shaker sort 
* the best case - O(n)
* the middle case - O(n^2)
* the worst case - O(n^2)
* memory cost - O(1)
*/ 
long long ShakerSort(int*, int);

/* Comb sort
* the best case - O(n log n)
* the middle case - O(n^2 / 2^p), where p is count of increments
* the worst case - O(n^2)
* memory cost - O(1)
*/
long long CombSort(int*, int);

int main()
{
    const int n = 10000;
    int* arr = new int[n];
    forn(i, n){
        arr[i] = i;
    }

    random_shuffle(arr, arr + n);
    long long iterBubbleSort = BubbleSort(arr, n);
    random_shuffle(arr, arr + n);
    long long iterShakerSort = ShakerSort(arr, n);
    random_shuffle(arr, arr + n);
    long long iterCombSort = CombSort(arr, n);

    printf("Iterations BubbleSort:\t%llu\nIterations ShakerSort:\t%llu\nIterations CombSort:\t%llu\n", 
            iterBubbleSort,
            iterShakerSort,
            iterCombSort);
    cout << endl;

    // --- END --- 
    delete[] arr;
    return 0;
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

long long BubbleSort(int* values, int size) 
{
    long long iter = 0;
    for (size_t i = 0; i < size - 1; ++i)
    {
        bool flag = false;
        ++iter;
        for (size_t j = 0; j < size - i - 1; ++j) // we don't check the last items already sorted, for this reason condition is j < (size - i) - 1
        {
            ++iter;
            if (values[j + 1] < values[j])
            {
                swap(values[j], values[j + 1]);
                flag = true; 
            }
        }
        // if we do not swap elements, then the array is already sorted
        if (!flag)
            break;
    }
    return iter;
}

long long ShakerSort(int* values, int size)
{
    int left = 0, right = size;
    long long iter = 0;
    while (left < right) // our array is decreases every iteration
    {
        bool flag = false;
        // from left to right
        for (size_t i = left; i < static_cast<unsigned long long>(right) - 1; i++)
        {
            ++iter;
            if (values[i] > values[i + 1]) 
            {
                swap(values[i], values[i + 1]);
                flag = true;
            }
        }
        // the last element already the biggest
        --right;
        // if we do not swap elements, then the array is already sorted
        if (!flag)
            break;

        // from right to left
        for (size_t j = right; j > left; j--)
        {
            ++iter;
            if (values[j] < values[j - 1]) 
            {
                swap(values[j], values[j - 1]);
                flag = true;
            }
        }
        // the first item already the smallest 
        ++left;
        // if we do not swap elements, then the array is already sorted
        if (!flag)
            break;
    }
    return iter;
}

long long CombSort(int* values, int size)
{
    const double factor = 1.247;
    unsigned int step = size / factor;
    long long iter = 0;
    while (step > 1) {
        // preparations
        iter++;
        unsigned int leftBoarder = 0, rightBoarder = leftBoarder + step;
        // bubble turtles
        for (int i = rightBoarder, j = leftBoarder; i < size; i++, j++) {
            iter++;
            if (values[j] > values[i])
                swap(values[i], values[j]);
        }
        step /= factor;
    }
    return iter + BubbleSort(values, size);
}
