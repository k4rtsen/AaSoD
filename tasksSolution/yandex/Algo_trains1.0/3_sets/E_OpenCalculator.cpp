#include <iostream>
#include <fstream>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    set<char> buttons, number;
    string str{};
    ifstream in("input.txt");
    if (in.is_open())
    {
        char ch;
        while(!in.eof() && in.peek() != '\n'){
            in >> ch;
            buttons.insert(ch);
        }

        in >> str;
    }
    else
        cout << "Error!" << endl;
    in.close();

    for (auto &val : str)
    {
        number.insert(val);
    }

    int count{0};
    for (auto& val : number)
    {
        if (!buttons.count(val))
            count++;
    }
    
    cout << count;

    return 0;
}
