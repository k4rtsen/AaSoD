#include <iostream>
#include <fstream>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printSet(const set<string> &vec)
{
    for (auto &val : vec)
        cout << val << endl;
}

template <typename T>
set<T> intersection(set<T> &s1, set<T> &s2)
{
    set<T> result;
    for (auto &val : s1)
    {
        if (s2.count(val))
            result.insert(val);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    set<string> allLngs, commonLngs;
    ifstream in("input.txt");
    if (in.is_open())
    {
        int n{0}; // count of students
        in >> n;
        forn(_, n)
        {
            set<string> currLngs;
            int m{0}; // count of language
            in >> m;
            forn(_, m)
            {
                string lng{}; // language
                in >> lng;
                allLngs.insert(lng);
                currLngs.insert(lng);
            }

            if (_ == 0)
                commonLngs = currLngs;
            else
                commonLngs = intersection(commonLngs, currLngs);
        }
    }
    in.close();

    cout << commonLngs.size() << endl;
    printSet(commonLngs);
    cout << allLngs.size() << endl;
    printSet(allLngs);

    return 0;
}
