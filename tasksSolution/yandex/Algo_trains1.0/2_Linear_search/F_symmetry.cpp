// написать через префиксы
#include <iostream>
#include <vector>
using namespace std;

class HashStr
{
private:
    int _x{257}, p{1'000'000'007};
    vector<long long> hash;
    vector<long long> reverse_hash;
    vector<long long> x;

public:
    HashStr(vector<long long>);
    bool isEqual(int, int);
};

HashStr::HashStr(vector<long long> arr)
{
    hash.push_back(0);
    reverse_hash.push_back(0);
    x.push_back(1);

    for (int i = 0; i < arr.size(); i++)
    {
        hash.push_back((hash[i] * x[i] + arr[i]) % p);
        reverse_hash.push_back((reverse_hash[i] * x[i] + arr[arr.size() - i - 1]) % p);
        x.push_back((x[i] * _x) % p);
    }
}

bool HashStr::isEqual(int len, int from)
{
    long long left{0};
    long long right{0};
    left = hash[len + from];
    right = (reverse_hash[len] + hash[from] * x[len]) % p;

    return left == right;
}

int main(int argc, char const *argv[])
{
    int count{0};
    cin >> count;

    int val{0};
    vector<long long> arr;
    while (cin >> val)
    {
        arr.push_back(val);
    }

    int m{0};
    HashStr hash(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        if (hash.isEqual(arr.size() - i, i))
        {
            m = i;
            break;
        }
    }

    cout << m << endl;
    for (; m > 0; --m)
    {
        cout << arr[m] << " ";
    }

    return 0;
}
