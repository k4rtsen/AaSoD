#include <iostream>
using namespace std;

#define YES "yes"
#define NO "no"

int main(int argc, char const *argv[])
{
    int a{0}, b{0}, n{0};
    cin >> a >> b >> n;
    if (b == 0 && a > 0){
        cout << YES << endl;
        return 0;
    }
    int count2 = b%n == 0? b/n : b/n + 1;
    if (a > count2){
        cout << YES << endl;
    }
    else
        cout << NO << endl;

    return 0;
}
