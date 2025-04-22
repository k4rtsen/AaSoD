/**
 * @file C_sumOn5D.cpp
 * task : Дан пятимерный массив a. Поступают запросы поиска суммы на гиперпрямоугольнике. Вам необходимо на них отвечать.
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
        s << "{ " << arr << "}\n";

    return s;
}
ostream &operator<<(ostream &s, const vector<vector<vector<long long>>> &v)
{
    for (auto &arr : v)
        s << arr;
    s << '\n';

    return s;
}
ostream &operator<<(ostream &s, const vector<vector<vector<vector<long long>>>> &v)
{
    for (auto &arr : v)
        s << arr;
    s << '\n';

    return s;
}
ostream &operator<<(ostream &s, const vector<vector<vector<vector<vector<long long>>>>> &v)
{
    for (auto &arr : v)
        s << arr;
    s << '\n';

    return s;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n1{0}, n2{0}, n3{0}, n4{0}, n5{0};
    ifstream ifs{"D:\\karen\\dev\\cpp\\test.txt"};
    if (ifs.is_open())
    {
        ifs >> n1 >> n2 >> n3 >> n4 >> n5;
        n1++;
        n2++;
        n3++;
        n4++;
        n5++;
    }
    else
    {
        cout << "Error!" << endl;
    }

    vector<vector<vector<vector<vector<long long>>>>> prefixSum(n1, vector<vector<vector<vector<long long>>>>(n2, vector<vector<vector<long long>>>(n3, vector<vector<long long>>(n4, vector<long long>(n5, 0)))));

    forn(a, 0, n1)
    {
        forn(b, 0, n2)
        {
            forn(c, 0, n3)
            {
                forn(d, 0, n4)
                {
                    forn(e, 0, n5)
                    {
                        int x{0};
                        ifs >> x;
                        prefixSum[a + 1][b + 1][c + 1][d + 1][e + 1] =
                            prefixSum[a + 1][b + 1][c + 1][d + 1][e] +
                            prefixSum[a + 1][b + 1][c + 1][d][e + 1] +
                            prefixSum[a + 1][b + 1][c][d + 1][e + 1] +
                            prefixSum[a + 1][b][c + 1][d + 1][e + 1] +
                            prefixSum[a][b + 1][c + 1][d + 1][e + 1] -
                            prefixSum[a + 1][b][c][d][e] -
                            prefixSum[a][b + 1][c][d][e] -
                            prefixSum[a][b][c + 1][d][e] -
                            prefixSum[a][b][c][d + 1][e] -
                            prefixSum[a][b][c][d][e + 1] +
                            prefixSum[a][b][c][d][e] + x;   
                    }
                }
            }
        }
    }

    cout << prefixSum;

    return 0;
}
