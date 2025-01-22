#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    int n{0};
    set<vector<int>> trues;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1{0}, t2{0};
        cin >> t1;
        cin >> t2;
        bool b1{t1 + t2 == n - 1}, b2{t1 >= 0}, b3{t2 >= 0};
        if (b1 && b2 && b3)
            trues.insert({t1, t2});
    }

    cout << trues.size();

    return 0;
}
