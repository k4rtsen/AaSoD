#include <iostream>
#include <map>
#include <stack>
using namespace std;

bool isValid(string s)
{
    map<char, char> brackets{
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}};

    stack<char> open_bracket;
    for (char ch : s)
    {
        // Если открывающаяся скобка
        if (brackets.count(ch))
        {
            // Кидаем ее в стек
            open_bracket.push(ch);
        }
        // Если закрывающаяся скобка
        else
        {
            // и все скобки закрылись, стоит не в ту сторону
            if (open_bracket.empty())
                return false;
            
            // не совпадает с закрывающейся скобкой, или стоит не в ту сторону
            if (brackets[open_bracket.top()] != ch)
                return false;

            // одна скобка закрылась
            open_bracket.pop();
        }
    }

    // если остались незакрытые скобки
    if (!open_bracket.empty())
        return false;

    // в любых других случаях - валидация пройдена
    return true;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    if (isValid(s))
        cout << "valid" << endl;
    else
        cout << "NO valid" << endl;

    return 0;
}
