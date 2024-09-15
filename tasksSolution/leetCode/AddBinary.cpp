#include <iostream>
// #include <algorithm>
// #include <cmath>
using namespace std;

string addBinary(string a, string b)
{
    const char one = '1';
    const char zero = '0';
    string more{}, less{};
    if (a.size() > b.size())
    {
        more = a;
        less = b;
    }
    else
    {
        less = a;
        more = b;
    }

    int k = less.size() - 1;
    string str;
    bool flag{false};

    while (k >= 0)
    {
        int dif = more.size() - less.size() + k;
        if (flag)
        {
            if (more[dif] == one && less[k] == one)
            {
                str = one + str;
            }
            else
            {
                if (more[dif] == one || less[k] == one)
                {
                    str = zero + str;
                }
                else
                {
                    str = one + str;
                    flag = false;
                }
            }
        }
        else
        {
            if (more[dif] == one && less[k] == one)
            {
                str = zero + str;
                flag = true;
            }
            else
            {
                if (more[dif] == one || less[k] == one)
                {
                    str = one + str;
                }
                else
                {
                    str = zero + str;
                }
            }
        }

        k--;
    }

    int dif = more.size() - less.size() - 1;
    while (dif >= 0)
    {
        if (flag)
        {
            if (more[dif] == one)
                str = zero + str;
            else
            {
                str = one + str;
                flag = false;
            }
        }
        else
        {
            str = more[dif] + str;
        }
        dif--;
    }

    if (flag)
        str = one + str;
    
    return str;
}

int main(int argc, char const *argv[])
{
    string a{"100"};
    string b{"110010"};
    string c = addBinary(a, b);
    cout << c;
    return 0;
}
