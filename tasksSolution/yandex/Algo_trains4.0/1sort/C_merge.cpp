#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void merge(int *arr1, int *arr2, int n1, int n2)
{
    int n{n1 + n2};        // размер большего массива
    int i{0}, j{0};        // указатели на меньшие массивы
    int *arr = new int[n]; // выделение памяти
    forn(k, n)
    {
        if (i >= n1)
        {
            arr[k] = arr2[j];
            j++;
            continue;
        }
        if (j >= n2)
        {
            arr[k] = arr1[i];
            i++;
            continue;
        }

        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
    }

    printArray(arr, n);

    delete[] arr;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n1{0};
    cin >> n1;
    int *arr1 = new int[n1];
    forn(i, n1)
    {
        cin >> arr1[i];
    }
    int n2{0};
    cin >> n2;
    int *arr2 = new int[n2];
    forn(i, n2)
    {
        cin >> arr2[i];
    }

    merge(arr1, arr2, n1, n2);
    delete[] arr1;
    delete[] arr2;
    return 0;
}
