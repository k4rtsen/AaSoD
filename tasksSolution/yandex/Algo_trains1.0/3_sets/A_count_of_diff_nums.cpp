#include <iostream>
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    set<int> s;
    int n;
    while(cin >> n){
        s.insert(n);
    }

    cout << s.size() << endl;

    return 0;
}