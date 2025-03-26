#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

ostream &operator<<(ostream &s, const vector<int> &v)
{
    for (auto &val : v)
        s << val << " ";

    return s;
}

ostream &operator<<(ostream &s, const vector<vector<int>> &v)
{
    for (auto &arr : v)
        s << "{ " << arr << "}" << endl;

    return s;
}

vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
{
    const int n{static_cast<int>(mat.size())};
    const int m{static_cast<int>(mat[0].size())};

    vector<vector<int>> pmx(n, vector<int>(m, 0));

    // заполнение префиксов целиков
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pmx[i][j] += mat[i][j];
            bool jNotNeg{(j - 1) >= 0}, iNotNeg{(i - 1) >= 0};
            if (jNotNeg)
                pmx[i][j] += pmx[i][j - 1];
            if (iNotNeg)
                pmx[i][j] += pmx[i - 1][j];
            if (jNotNeg && iNotNeg)
                pmx[i][j] -= pmx[i - 1][j - 1];
        }
    }

    vector<vector<int>> result(n, vector<int>(m, 0));
    // заполнение сумм
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int r_max = ((i + k) >= n) ? n - 1 : i + k;
            int c_max = ((j + k) >= m) ? m - 1 : j + k;

            result[i][j] += pmx[r_max][c_max];

            bool jMoreZero{(j - k) > 0}, iMoreZero{(i - k) > 0};
            if (jMoreZero)
                result[i][j] -= pmx[r_max][j - k - 1];

            if (iMoreZero)
                result[i][j] -= pmx[i - k - 1][c_max];

            if (jMoreZero && iMoreZero)
                result[i][j] += pmx[i - k - 1][j - k - 1];
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << matrixBlockSum(matrix, 1);
    return 0;
}
