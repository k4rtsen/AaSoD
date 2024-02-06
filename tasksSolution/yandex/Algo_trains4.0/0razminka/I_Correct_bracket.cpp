#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

#define YES "yes"
#define NO "no"

int main(int argc, char const *argv[])
{
    string str{};
    cin >> str;

    if (str.empty())
    {
        cout << YES << endl;
        return 0;
    }

    map<char, char> brackets{
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}};

    stack<char> open_bracket;
    for (char ch : str)
    {
        if (brackets.count(ch))
            open_bracket.push(ch);
        else
        {
            if (!open_bracket.empty())
                if (brackets[open_bracket.top()] == ch)
                {
                    open_bracket.pop();
                    continue;
                }
            cout << NO << endl;
            return 0;
        }
    }

    if (open_bracket.empty())
        cout << YES << endl;
    else
        cout << NO << endl;
    return 0;
}
