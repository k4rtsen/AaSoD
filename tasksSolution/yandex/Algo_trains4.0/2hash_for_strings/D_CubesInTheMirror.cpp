#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

class HashStr
{
private:
    const long long x_ = 257, p = 1000000007;
    vector<long long> h, x, rh;

public:
    // высчитывает хэш строки
    HashStr(string str)
    {
        int n = str.size();
        h.push_back(0);
        rh.push_back(0);
        x.push_back(1);

        for (int i = 1; i < n + 1; i++)
        {
            h.push_back((h[i - 1] * x_ + int(str[i - 1])) % p);
            rh.push_back((rh[i - 1] * x_ + int(str[n - i])) % p);
            x.push_back((x[i - 1] * x_) % p);
        }
    }

    HashStr(vector<int> arr)
    {
        int n = arr.size();
        h.push_back(0);
        rh.push_back(0);
        x.push_back(1);

        for (int i = 1; i < n + 1; i++)
        {
            h.push_back((h[i - 1] * x_ + int(arr[i - 1])) % p);
            rh.push_back((rh[i - 1] * x_ + int(arr[n - i])) % p);
            x.push_back((x[i - 1] * x_) % p);
        }
    }

    bool ISE_reverse(int len, int point, int rpoint)
    {
        return (h[point + len] + rh[rpoint] * x[len]) % p == (rh[rpoint + len] + h[point] * x[len]) % p;
    }

    // Считает равны ли хэши подстрок
    bool ISE(int len, int from1, int from2)
    {
        return (h[from1 + len] + h[from2] * x[len]) % p == (h[from2 + len] + h[from1] * x[len]) % p;
    }
};

void printVector(vector<int> arr)
{
    for (int val = arr.size() - 1; val >= 0; val--)
        cout << arr[val] << " ";
}

int main()
{
    int size, count;
    vector<int> str;
    // string str{};

    // ifstream in("20");

    // if (in.is_open())
    // {
    //     in >> size >> count;
    //     while (!in.eof())
    //     {
    //         int s{0};
    //         in >> s;
    //         str.push_back(s);
    //     }
    // }
    // else
    //     cout << "Error!" << endl;

    // in.close();

    cin >> size >> count;
    forn(i, size)
    {
        int s{0};
        cin >> s;
        str.push_back(s);
    }

    HashStr h(str);

    int m = size / 2;
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        int size = i + 1;
        if (h.ISE_reverse(size, i + 1, str.size() - size))
            res.push_back(str.size() - i - 1);
    }

    res.insert(res.begin(), str.size());
    printVector(res);

    return 0;
}