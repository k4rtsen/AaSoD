#include <iostream>
#include <map>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printMap(const map<char, int> &map)
{
    cout << "Map = {" << endl;
    for (const auto &[key, val] : map)
        cout << "	" << key << " = " << val << endl;
    cout << "}" << endl;
}

int romanToInt(string s)
{
    map<char, int> rtoi{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int result{0};

    for (int i = 0; i < s.size(); i++)
    {
        if (rtoi[s[i]] < rtoi[s[i + 1]])
        {
            result += rtoi[s[i + 1]] - rtoi[s[i]];
            ++i;
        }
        else result += rtoi[s[i]];
    }

    return result;
}

int main(int argc, char const *argv[])
{
    cout << romanToInt("MCMXCIV") << endl;

    return 0;
}
