#include <iostream> 
#include <fstream>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    string str{};
    set<string> s;
    ifstream in("input.txt");
    while (in)
    {
        in >> str;
        if (str.size() == 0)
            break;
        s.insert(str);
    }
    in.close();

    cout << s.size() << endl;

    return 0;
}
