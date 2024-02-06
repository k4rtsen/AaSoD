#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printVector(vector<int> arr)
{
    cout << "{ ";
    for (auto &val : arr)
        cout << val << "; ";
    cout << "}" << endl;
}

vector<int> slow_prefix_function(string s)
{
    int n = (int)s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++)
        for (int len = 1; len <= i; len++)
            // если префикс длины len равен суффиксу длины len
            if (s.substr(0, len) == s.substr(i - len + 1, len))
                p[i] = len;
    return p;
}

vector<int> prefix_function(string s)
{
    int n = (int)s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++)
    {
        // префикс функция точно не больше этого значения + 1
        int cur = p[i - 1];
        // уменьшаем cur значение, пока новый символ не сматчится
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];
        // здесь либо s[i] == s[cur], либо cur == 0
        if (s[i] == s[cur])
            p[i] = cur + 1;
    }
    return p;
}

vector<int> my_prefix_function(string str)
{
    int n = str.size();
    vector<int> p(n, 0);
    int j{0};
    for (int i = 1; i < n; i++)
    {
        int cur{p[i - 1]};

        for (; str[i] != str[cur] && cur > 0; cur = p[cur - 1])
            ;

        if (str[i] == str[cur])
            p[i] = cur + 1;
    }
    return p;
}

vector<int> Z_func_from_prefix(vector<int> p)
{
    int n = p.size(),
        point{0};
    vector<int> z(n, 0);

    return z;
}

vector<int> prefix_func_from_Z(vector<int> z)
{
    vector<int> p(z.size(), 0);
    int n = z.size();

    for (int i = 1; i < n; i++)
    {
        for (int j = z[i] - 1; j >= 0; j--)
        {
            if (p[i + j] > 0)
                break;
            else
                p[i + j] = j + 1;
        }
    }
    return p;
}

int main()
{
    string str{};

    ifstream in("01");
    if (in.is_open())
        in >> str;
    else
        cout << "Error!" << endl;

    in.close();

    printVector(prefix_function(str));

    //----------------------------------------

    // vector<int> arr;
    // int k{0};
    // ifstream in("01");
    // if (in.is_open())
    //     while (!in.eof())
    //     {
    //         in >> k;
    //         arr.push_back(k);
    //     }
    // else
    //     cout << "Error!" << endl;

    // in.close();

    // printVector(prefix_func_from_Z(arr));

    //----------------------------------------

    

    return 0;
}
