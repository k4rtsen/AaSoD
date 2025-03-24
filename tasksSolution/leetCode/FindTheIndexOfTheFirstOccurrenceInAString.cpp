#include <iostream>
using namespace std;

class Hash
{
private:
    const short x_ = 257;
    const long long p = 1'000'000'007; // модуль
    size_t size;
    long long *h, *x;

    bool CompareStrings(long long, long long, long long);
    long long getFullHash() const { return h[size]; }

public:
    Hash(string str);
    size_t len() const { return this->size; }
    int firstOccurrence(Hash);
};

int strStr(string haystack, string needle)
{
    if (needle.size() > haystack.size())
        return -1;

    Hash h1{haystack};
    Hash h2{needle};
    return h1.firstOccurrence(h2);
}

int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << strStr(s1, s2);
    return 0;
}

Hash::Hash(string str) : size{str.length()}
{
    h = new long long[size + 1]; // hashes for string
    x = new long long[size + 1];
    h[0] = 0;
    x[0] = 1;

    for (size_t i = 1; i < size + 1; i++)
    {
        h[i] = (h[i - 1] * x_ + int(str[i - 1])) % p;
        x[i] = (x[i - 1] * x_) % p;
    }
}

bool Hash::CompareStrings(long long index, long long strHash, long long length)
{
    return h[index + length] /* + 0 */ == (strHash + h[index] * x[length]) % p;
}

int Hash::firstOccurrence(Hash word)
{
    for (int i = 0; i < this->len() - word.len() + 1; i++)
    {
        if (this->CompareStrings(i, word.getFullHash(), word.len()))
        {
            return i;
        }
    }
    return -1;
}
