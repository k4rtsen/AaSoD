/**
 * @file B_sumOnCub.cpp
 * task : Дан двумерный массив a. Поступает q запросов поиска суммы на прямоугольнике, где [lx,ly] - это левая верхняя координата, а [rx,ry] - это нижняя правая координата. Вам необходимо на них отвечать.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define forn(i, s, n) for (size_t i = s; i < static_cast<size_t>(n); i++)

ostream &operator<<(ostream &s, const vector<long long> &v)
{
    for (auto &val : v)
        s << val << " ";

    return s;
}

ostream &operator<<(ostream &s, const vector<vector<long long>> &v)
{
    for (auto &arr : v)
        s << "{ " << arr << "}" << endl;

    return s;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n{0}, m{0};
    ifstream ifs{"D:\\karen\\dev\\cpp\\test.txt"};
    if (ifs.is_open())
    {
        ifs >> n >> m;
        n++;
        m++;
    }
    else
    {
        cout << "Error!" << endl;
    }

    vector<vector<long long>> prefixCub(n, vector<long long>(m, 0));
    if (ifs.is_open())
        forn(i, 1, n)
        {
            forn(j, 1, m)
            {
                int x{0};
                ifs >> x;
                prefixCub[i][j] = x + prefixCub[i - 1][j] + prefixCub[i][j - 1] - prefixCub[i - 1][j - 1];
            }
        }

    // cout << prefixCub;

    int q{0}, lx{0}, ly{0}, rx{0}, ry{0};
    if (ifs.is_open())
    {
        ifs >> q;
        forn(i, 0, q)
        {
            ifs >> lx >> ly >> rx >> ry;
            long long res = prefixCub[rx][ry] - prefixCub[rx][ly - 1] - prefixCub[lx - 1][ry] + prefixCub[lx - 1][ly - 1];
            cout << res << "\n";
        }
    }

    return 0;
}
