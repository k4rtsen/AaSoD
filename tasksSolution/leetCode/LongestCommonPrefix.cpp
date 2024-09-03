#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

size_t minStringSize(vector<string> &strs)
{
    size_t result{SIZE_MAX};
    for (auto &val : strs)
    {
        if (val.size() < result)
            result = val.size();
    }

    return result;
}

 /**
  * @brief brute force
  * 
  * @param strs 
  * @return string 
  */
string longestCommonPrefix(vector<string> &strs)
{
    size_t n = minStringSize(strs);
    if (n < 1)
        return "";

    size_t index {0};
    for(size_t i = 0; i < n; i++)
    {
        bool flag{true};
        for(auto &val : strs)
        {
            if (strs[0][i] != val[i])
                flag = false;
        }
        if (flag)
            index = i + 1;
        else
            break;
    }
    return strs[0].substr(0, index);
}

int main(int argc, char const *argv[])
{
    vector<string> words{"c"};
    cout << longestCommonPrefix(words) << endl;
    return 0;
}
