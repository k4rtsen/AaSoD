#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printSet(const set<string> &vec)
{
    for (auto &val : vec)
        cout << val << endl;
}

/**
 * @brief deletes in s1 that are not common elements with s2
 *
 * @param s1 set of string
 * @param s2 set of string
 */
void intersection(set<string> &s1, set<string> &s2)
{
}

int main(int argc, char const *argv[])
{
    int n{0}; // count of students

    set<string> allLngs, commonLngs;
    ifstream in("input.txt");
    if (in.is_open())
    {
        in >> n;
        while (!in.eof()) // or we can set loop for in range [0, n)
        {
            int m{0}; // count of language
            forn(_, m)
            {
                string lng{}; // language
                allLngs.insert(lng);
            }
        }
    }
    in.close();

    return 0;
}
