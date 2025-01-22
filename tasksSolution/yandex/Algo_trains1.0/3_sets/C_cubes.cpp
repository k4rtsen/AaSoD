#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

void printSet(set<int> &arr)
{
    for (auto &val : arr)
        cout << val << endl;
}

void printVector(vector<int> &arr)
{
    for (auto &val : arr)
        cout << val << " ";
}

void difference(set<int> &s1, vector<int> &s2)
{
    for (auto &val : s2)
    {
        if (s1.count(val))
            s1.erase(val);
    }
}

int main(int argc, char const *argv[])
{
    int n{0}, m{0};
    set<int> anna, borya;
    ifstream in("input.txt");
    in >> n >> m;
    if (in.is_open())
    {
        forn(_, n)
        {
            int temp;
            in >> temp;
            anna.insert(temp);
        }
        forn(_, m)
        {
            int temp;
            in >> temp;
            borya.insert(temp);
        }
    }
    in.close();

    // количество и пересечение множеств Ани и Бори
    vector<int> commonElements;
    set_intersection(anna.begin(), anna.end(), borya.begin(), borya.end(), back_inserter(commonElements));
    cout << commonElements.size() << endl;
    printVector(commonElements);
    cout << endl;

    // количество и разность сетов с общим сетов
    difference(anna, commonElements);
    cout << anna.size() << endl;
    printSet(anna);

    difference(borya, commonElements);
    cout << borya.size() << endl;
    printSet(borya);

    return 0;
}
