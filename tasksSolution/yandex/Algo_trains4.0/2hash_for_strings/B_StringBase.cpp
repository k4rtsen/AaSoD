#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

class HashStr
{
private:
    const long long x_ = 257, p = 1000000007;
    long long *h, *x;

public:
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

    bool Is_substrs_equal(int len, int from1, int from2)
    {
        return (h[from1 + len] + h[from2] * x[len]) % p == (h[from2 + len] + h[from1] * x[len]) % p;
    }
};

int main(int argc, char const *argv[])
{
    string str{0};
    ifstream in("01");
    if (in.is_open())
        in >> str;
    else
        cout << "Error!" << endl;

    int n = str.size();
    int result{0};
    HashStr hstr(str);
    for (int i = 0; i < n; i++)
    {
        if (hstr.Is_substrs_equal(i, 0, n - i))
            result = n - i;
    }
    in.close();
    cout << result << endl;
    return 0;
}
