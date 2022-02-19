// The task:
// -------------------
// You are given an unordered array of natural numbers from 1 to n.
// One number was removed from this array and the size of the array was reduced to (n-1).
// Find the missing element with minimal(!!!) time and memory costs.
// Example: n = 6, array [3, 5, 2, 6, 1], missing element = 4. Answer can be specified as a function body
// -------------------
// Solution:
// time: O(n)
// memory: O(1)

#include <iostream>
#include <ctime>

using namespace std;

void print(int*, int); // show array

int MissedNum(int*, int); // minimized (optimized) missing number search algorithm

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();

    // initialization...
    cout << "Please, enter the n of array...\t";
    int n;
    cin >> n;
    int* arr = new int[n];

    // fill array with nums from 1 to n, then shuffle array items and delete one random number
    for (int i = 0; i < n; i++)
        arr[i] = i + 1; // filling
    print(arr, n);
    //---

    for (int i = 0; i < n; i++)
        swap(arr[i], arr[rand() % n]); // shuffling
    print(arr, n);
    //---
    
    // delete a random numder of array
    int *mis_num_arr = new int[n - 1];
    for (int i = 0; i < n - 1; i++)
        mis_num_arr[i] = arr[i];
    print(mis_num_arr, n - 1);
    //---

    cout << "The missed nimber is: " << MissedNum(mis_num_arr, n) << endl;

    // don't forget clear trash
    delete[] arr;
    delete[] mis_num_arr;
    return 0;
}

void print(int* arr, int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "; ";
    cout << "}\n";
}

int MissedNum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size - 1; i++)
        sum += arr[i];
    // сумма всех элементов предыдущего и данного массива отличается ровно на пропущенное число
    // чтобы найти данное число, необходимо сумму элементов целого массива (узнаем из размера переданного в функцию) и сумму элементов массива с удаленным элементом
    // после чего, узнать их разницу
    return (size * (size + 1) / 2) - sum;
}
