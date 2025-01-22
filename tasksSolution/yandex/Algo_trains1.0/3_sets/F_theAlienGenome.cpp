#include <iostream>
#include <fstream>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    string gen1{}, gen2{};
    ifstream in("input.txt");
    if (in.is_open())
    {
        in >> gen1;
        in >> gen2;
    }
    in.close();

    set<string> g2;
    for (size_t i = 0; i < gen2.size() - 1; i++)
    {
        string temp {""};
        temp += gen2[i];
        temp += gen2[i + 1];
        g2.insert(temp);
    }

    int count{0};
    for (string::iterator first{gen1.begin()}, last{gen1.end()}; first != last;)
    {
        string temp {""};
        temp += *first;
        temp += *++first;
        if (g2.count(temp))
            count++;
    }

    cout << count;

    return 0;
}
