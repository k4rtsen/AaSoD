#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> s1;
    set<int> s2;
    vector<set<int>> listOfSets = {s1, s2};

    string str;
    ifstream in("input.txt");
    if (in.is_open())
    {
        for (auto &val : listOfSets)
        {
            int n;
            while (!in.eof() && in.peek() != '\n')
            {
                in >> n;
                val.insert(n);
            }
            in.get();
        }
    }
    in.close();

    vector<int> result;
    set_intersection(listOfSets[0].begin(), listOfSets[0].end(), listOfSets[1].begin(), listOfSets[1].end(), back_inserter(result));
    
    ofstream out;
    out.open("output.txt");
    if (out.is_open())
        for (auto &val : result)
            out << val << " ";
    out.close();

    return 0;
}
