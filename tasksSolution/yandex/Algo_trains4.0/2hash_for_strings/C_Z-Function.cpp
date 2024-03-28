#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> my_z_function(string str)
{
    int n = str.size();
    vector<int> z(n, 0);
    int l{0}, r{0};

    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);

        for (; z[i] + i < n && str[z[i]] == str[i + z[i]]; z[i]++)
            ;

        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

vector<int> slow_z_function(string s)
{
    int n = (int)s.size();
    vector<int> z(n, 0); // z[0] считается не определенным
    for (int i = 1; i < n; i++)
        // если мы не вышли за границу и следующие символы совпадают
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
    return z;
}

vector<int> z_function(string str)
{
    int n = (int)str.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        // если мы уже видели этот символ
        if (i <= r)
            // то мы можем попробовать его инициализировать z[i - l],
            // но не дальше правой границы: там мы уже ничего не знаем
            z[i] = min(r - i + 1, z[i - l]);
        // дальше каждое успешное увеличение z[i] сдвинет z-блок на единицу
        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            z[i]++;
        // проверим, правее ли мы текущего z-блока
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

class HashStr
{
private:
    const long long x_ = 257, p = 1000000007;
    long long *h, *x, n;

public:
    // высчитывает хэш строки
    HashStr(string str)
    {
        n = str.size();
        h = new long long[n + 1]; // hashes for string
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
        if (len + from1 > n || len + from2 > n)
        {
            cout << "Error: Range out!" << endl;
            return false;
        }
        return (h[from1 + len] + h[from2] * x[len]) % p == (h[from2 + len] + h[from1] * x[len]) % p;
    }
};

int equal_longest_str_BS(HashStr *hash, int left, int right, int limit)
{
    if (right - left <= 1)
        return hash->Is_substrs_equal(right - left, 0, left) ? 1 : 0;

    int mid = (right + left) / 2;
    if (!hash->Is_substrs_equal(right - left, 0, left))
    {
        equal_longest_str_BS(hash, left, mid, limit);
    }
    else
    {
        int mid2 = (limit - right) / 2;
        equal_longest_str_BS(hash, left, mid2, limit);
    }
    return right - left;
}

vector<int> z_function_per_log(string str)
{
    int n = str.size();
    vector<int> res(n, 0);

    HashStr hash(str);
    for (int i = 1; i < n; i++)
    {
        res[i] = equal_longest_str_BS(&hash, i, n, n);
    }

    return res;
}

void printVector(vector<int> arr)
{
    for (auto &val : arr)
        cout << val << " ";
}

int main(int argc, char const *argv[])
{
    string str{};
    cin >> str;
    // ifstream in("test");
    // if (in.is_open())
    //     in >> str;
    // else
    //     cout << "Error!" << endl;

    // in.close();

    printVector(z_function_per_log(str));

    return 0;
}
