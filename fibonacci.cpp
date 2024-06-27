#include <cassert>
#include <iostream>

using namespace std;

class Fibonacci
{
public:
    static int get(int n)
    {
        assert(n >= 0);
        // put your code here
        int *arr = new int[n];
        arr[0] = 0;
        arr[1] = 1;
        for (size_t i = 2; i < n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        n = arr[n - 1];
        return n;
    }

    static int get_last_digit(int n)
    {
        assert(n >= 1);
        // put your code here
        const short ten = 10;
        if (n <= 10)
            return get(n) % ten;
        else
        {
            int a = get(ten - 1) % ten;
            int b = get(ten) % ten;
            int c = (a + b) % ten;
            for (int i = ten; i < n; i++)
            {
                c = (a + b) % ten;
                a = b;
                b = c;
            }
            n = c;
        }
        return n;
    }

    static int get_remainder(long long n, int m)
    {
        assert(n >= 1);
        assert(m >= 2);
        // put your code here
        return n % m;
    }
};

int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << Fibonacci::get(n) << endl;
    cout << Fibonacci::get_last_digit(n) << endl;
    return 0;
}
