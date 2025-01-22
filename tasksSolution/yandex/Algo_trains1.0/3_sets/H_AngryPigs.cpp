#include <iostream> 
#include <set>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char const *argv[])
{
    int n{0};
    cin >> n;
    set<int> x;

    forn(_, n)
    {
        int temp{0};
        cin >> temp;
        x.insert(temp);
        cin >> temp;
    }

    cout << x.size();

    return 0;
}
