#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void merge_sort(int *array,  int *buffer, int l, int r)
{
   if (r <= l) return;

    int m = (r + l) / 2;
    merge_sort(array, buffer, l, m);
    merge_sort(array, buffer, m + 1, r);

    int i{l}, j{m + 1};
    for (int k = l; k <= r; k++)
    {
        // закончился левый массив, переносим правый
        if (i > m)
        {
            buffer[k] = array[j];
            j++;
            continue;
        }
        // закончился правый массив, переносим левый
        if (j > r)
        {
            buffer[k] = array[i];
            i++;
            continue;
        }

        // сравниваем поэлементно массивы
        // записываем меньший и передвигаем индекс, чей элемент мы взяли
        if (array[i] < array[j])
        {
            buffer[k] = array[i];
            i++;
        }
        else
        {
            buffer[k] = array[j];
            j++;
        }
    }
    // запоминаем состояние отсортированных частей
    for (int k = l; k <= r; k++)
    {
        array[k] = buffer[k];
    }
}

void merge_sort(int *arr, const size_t size)
{
    int *buffer = new int[size];
    merge_sort(arr, buffer, 0, size - 1);

    delete[] buffer;
}

int main(int argc, char const *argv[])
{
    int n{0};
    cin >> n;

    int *array = new int[n];

    forn(i, n)
    {
        cin >> array[i];
    }

    merge_sort(array, n);
    printArray(array, n);

    delete[] array;
    return 0;
}
