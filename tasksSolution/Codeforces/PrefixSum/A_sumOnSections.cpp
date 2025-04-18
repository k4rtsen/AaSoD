#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
#define forn(i, s, n) for (size_t i = s; i < static_cast<size_t>(n); i++)
 
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n{0}, q{0}, l{0}, r{0}; // size of array
    vector<int> arr;
 
    cin >> n;
    forn(i, 0, n)
    {
        int x{0};
        cin >> x;
        arr.push_back(x);
    }
 
    long long prefix[arr.size() + 1] = {0};
    for (int i = 1; i < n + 1; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
 
    cin >> q;
    forn(i, 0, q)
    {
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
 
    return 0;
}