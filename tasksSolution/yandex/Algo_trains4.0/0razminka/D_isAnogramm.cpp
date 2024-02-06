#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    
    // O(NlogN)
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    // можно также сделать подсчетом букв и тогда уже будет занимать время O(N)

    return 0;
}