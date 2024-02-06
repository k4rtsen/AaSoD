#include <iostream>
#include <fstream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define YES "YES"
#define NO "NO"

void printArray(bool *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        string res = arr[i] ? YES : NO;
        cout << res << endl;
    }
}

int main(int argc, char const *argv[])
{
    short t{0};
    unsigned int n{0}, a{0}, b{0};

    cin >> t;
    bool *arr = new bool[t];

    forn(j, t)
    {
        cin >> n >> a >> b;
        for (int i = a; i <= b; i++)
        {
            int remain = n % i;
            // делим группы поровну
            if (remain == 0)
            {
                arr[j] = true;
                break;
            }
            // если не делятся пытаемся из остатка создать еще одну группу
            if (a <= remain && remain <= b)
            {
                arr[j] = true;
                break;
            }
            // если и такой вариант не проходит, то пытаемся распихать оставшихся по группам
            if (remain <= n / i * (b - i))
            {
                arr[j] = true;
                break;
            }
            
            arr[j] = false;
        }
    }

    printArray(arr, t);
    return 0;
}
