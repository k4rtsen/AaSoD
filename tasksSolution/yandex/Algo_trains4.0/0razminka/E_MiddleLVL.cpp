#include <iostream>
#include <cmath>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main(int argc, char const *argv[])
{
    int n{0};
    cin >> n;

    int *sRate = new int[n];
    int *sHate = new int[n];
    int totalRight{0}, totalLeft{0};

    forn(i, n)
    {
        cin >> sRate[i];
        totalRight += sRate[i];
        sHate[i] = 0;
    }

    forn(i, n)
    {
        int r = abs(totalRight - (n - i) * sRate[i]);
        int l = abs(totalLeft - i * sRate[i]);
        sHate[i] = r + l;
        totalLeft += sRate[i];
        totalRight -= sRate[i];
    }

    printArray(sHate, n);
    delete[] sHate;
    delete[] sRate;
}
