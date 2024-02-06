#include <iostream>
#include <ctime>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int Partition(int *array, int left, int right, int index, int &firstGreatestElem)
{
    // указатели на элементы e = equal, g = great
    int e{left}, g{left};

    // опорный элемент
    int sup_elem = array[index];

    // 1. Если меньше опорного
    // 2. Если равен опорному
    // 3. Если больше опорного
    for (int i = left; i < right; i++)
    {
        // 1.
        if (array[i] < sup_elem)
        {
            int temp = array[i];
            array[i] = array[g];
            array[g] = array[e];
            array[e] = temp;
            e++;
            g++;
            continue;
        }
        // 2.
        if (array[i] == sup_elem)
        {
            int temp = array[i];
            array[i] = array[g];
            array[g] = temp;
            g++;
            continue;
        }
        // 3.
        // просто двигаем индекс еще не просмотренных элементов
        // элементы больше всегда остаются справа, поэтому не трогаем их
    }
    firstGreatestElem = g;
    // возвращаем индекс эл-та, слева от которого все строго меньше опорного
    return e;
}

void quick_sort(int *array, int l, int r)
{
    if (r > l)
    {
        srand(time(NULL));

        // выбор числа относительно которого массив будет делиться
        // рандомизирован
        int rand_index = l + rand() % (r - l); // [l, r)
        // вплоть до элемента g все эл-ты не превышают опорный, собственно с него и стоит начать делать Partition второй части
        int g{0};
        // разделение и упорядочивание элементов относительно некоторого числа
        int p = Partition(array, l, r, rand_index, g); // слева от p все меньше опорного эл-та
        quick_sort(array, l, p);
        quick_sort(array, g, r);
    }
}

void sort(int *array, int size)
{
    quick_sort(array, 0, size);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n{0};
    cin >> n;
    int *arr = new int[n];
    forn(i, n)
    {
        cin >> arr[i];
    }

    sort(arr, n);
    printArray(arr, n);

    return 0;
}
