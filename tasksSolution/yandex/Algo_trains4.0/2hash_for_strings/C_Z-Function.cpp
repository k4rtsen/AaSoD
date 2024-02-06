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

    printVector(z_function(str));

    return 0;
}
