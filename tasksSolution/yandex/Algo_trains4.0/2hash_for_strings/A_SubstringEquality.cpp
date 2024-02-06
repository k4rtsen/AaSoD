#include <iostream>
#include <string>
using namespace std;

#define YES "yes"
#define NO "no"

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// сравнение строк за O(N)
class HashStr
{
private:
    const long long x_ = 257, p = 1000000007;
    long long *h, *x;

public:
    // высчитывает хэш строки
    HashStr(string str)
    {
        int n = str.size();
        h = new long long[n + 1];
        x = new long long[n + 1];
        h[0] = 0;
        x[0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            h[i] = (h[i - 1] * x_ + int(str[i - 1])) % p;
            x[i] = (x[i - 1] * x_) % p;
        }
    }

    // Считает равны ли хэши подстрок
    bool Is_substrs_equal(int len, int from1, int from2)
    {
        return (h[from1 + len] + h[from2] * x[len]) % p == (h[from2 + len] + h[from1] * x[len]) % p;
    }
};

void printArray(int *arr, int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "; ";
    cout << "}\n";
}

int main(int argc, char const *argv[])
{
    const long long x_ = 257, p = 1000000007;
    long long *h, *x;

    string str{};
    cin >> str;

    HashStr hstr(str);

    int t{0};
    cin >> t;
    bool *res = new bool[t];
    forn(i, t)
    {
        int len{0}, from1{0}, from2{0};
        cin >> len >> from1 >> from2;

        res[i] = hstr.Is_substrs_equal(len, from1, from2);
    }
    
    forn(i, t)
            res[i]
        ? cout << YES << endl
        : cout << NO << endl;
    return 0;
}
