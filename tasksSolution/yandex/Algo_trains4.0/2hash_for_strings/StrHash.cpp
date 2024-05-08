#include <iostream>
#include <fstream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

class HashStr
{
private:
    const long long x_ = 257, p = 1000000007;
    long long *h, *x, *rh, n;

public:
    // высчитывает хэш строки
    HashStr(string str)
    {
        n = str.size();
        h = new long long[n + 1]; // hashes for string
        rh = new long long[n + 1]; // hashes for revers string
        x = new long long[n + 1];
        h[0] = 0;
        rh[0] = 0;
        x[0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            h[i] = (h[i - 1] * x_ + int(str[i - 1])) % p;
            rh[i] = (rh[i - 1] * x_ + int(str[n - i])) % p;
            x[i] = (x[i - 1] * x_) % p;
        }
    }

    ~HashStr()
    {
        delete[] h;
        delete[] rh;
        delete[] x;
    }

    // Считает равны ли хэши подстрок
    bool Is_substrs_equal(int len, int from1, int from2)
    {
        if (len + from1 > n || len + from2 > n)
        {
            throw invalid_argument("Error : Out of range...");
            return false;
        }
        if (len <= 0)
        {
            throw invalid_argument("Error : Length can't be a negative!");
            return false;
        }
        return (h[from1 + len] + h[from2] * x[len]) % p == (h[from2 + len] + h[from1] * x[len]) % p;
    }
};

int main()
{
    string str{};
    ifstream in("test");
    if (in.is_open())
        in >> str;
    else
        cout << "Error!" << endl;

    in.close();

    return 0;
}
