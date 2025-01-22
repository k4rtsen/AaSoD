#include <iostream>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] >= 0 ? cout << arr[i] << " " : cout << '*' << " ";
}

void printDoubleArray(int **arr, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        printArray(arr[i], columns);
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    // выделение и инициализация массива и количества мин
    int n{0}, m{0}, mine_count{0};
    cin >> n >> m >> mine_count;
    int **field{new int *[n] {}};
    forn(i, n)
    {
        field[i] = new int[m]{};
    }
    forn(i, n)
    {
        forn(j, m)
        {
            field[i][j] = 0;
        }
    }

    // расстановка бомб и цифр
    forn(_, mine_count)
    {
        int x{0}, y{0};
        cin >> x >> y;
        --x;
        --y;

        field[x][y] = -1;
        for(int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if ((i >= 0 && i < n && j >= 0 && j < m))
                {
                    if (field[i][j] != -1)
                        field[i][j]++;
                }
            }
        }
    }

    // вывод поля
    printDoubleArray(field, n, m);

    // удаление массива
    forn(i, n)
    {
        delete[] field[i];
    }
    delete[] field;

    return 0;
}
