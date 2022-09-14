#include <bits/stdc++.h> 
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void print_array(int* arr, int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "; ";
    cout << "}\n";
}

int BubbleSort(int* values, int size) 
{
    int iter = 0;
    for (size_t i = 0; i < size - 1; ++i)
    {
        bool flag = false;
        ++iter;
        for (size_t j = 0; j < size - 1; ++j) // we don't check the last items already sorted, for this reason condition is j < (size - i) - 1
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

int main(int argc, char const *argv[])
{
    // INIT ARRAY
    const int n = 10;
    int* arr = new int[n];
    forn(i, n){
        arr[i] = i;
    }

    int min = INT_MAX, max = 0, iter = 0;
    sort(arr, arr + n);

    auto RightSorting = [](int* arr, int n){
        forn(i, n-1)
            if(arr[i] > arr[i+1])
                return false;
        return true;
    };
        
    // testing combinations, best and worst time
    // be careful, here is n! combinations
    // USE ONLY SMALL n
/*
    do
    {
        printf("Iteration %d: ", ++iter);
        print_array(arr, n);
        int arr1[n] {};
        forn(i, n){
            arr1[i] = arr[i];
        }
        // sorting name
        int i = BubbleSort(arr1, n);
        // check right sorting
        assert(RightSorting(arr1, n));

        bool change = i < min? true : false;
        if (change) min = i;
        change = i > max? true : false;
        if (change) max = i;
    } while (next_permutation(arr, arr + n));
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
*/

    // testing sort
    for(int i = 0; ; i++) {
        if (i % 10 == 0) {
            printf("Iteration %d\n", i);
            fflush(stdout);
        }
        
        random_shuffle(arr, arr + n);
        // sorting name
        BubbleSort(arr, n);
        // check right sorting
        assert(RightSorting(arr, n));
    }

    return 0;
}
