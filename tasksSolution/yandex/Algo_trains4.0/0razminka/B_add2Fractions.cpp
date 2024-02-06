#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a >= b)
        return gcd(a % b, b);
    if (b >= a)
        return gcd(a, b % a);
}

int main()
{
    int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 };
    cin >> a >> b >> c >> d;

    int zn = b * d / gcd(b, d);
    int chisl = zn / b * a + zn / d * c;

    cout << chisl / gcd(chisl, zn) << " " << zn / gcd(chisl, zn) << endl;

    return 0;
}
