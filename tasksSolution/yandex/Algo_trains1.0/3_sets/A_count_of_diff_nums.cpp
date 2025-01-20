#include <iostream>
#include <fstream>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    set<int> s;
    int n;

    ifstream in("input.txt");
    int count{0};
    int temp{0};
    if (in.is_open())
    {
        while (in >> temp)
        {
            count++;
            s.insert(temp);
        }
    }
    in.close();

    cout << s.size() << endl;

    return 0;
}