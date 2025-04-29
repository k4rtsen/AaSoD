#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

ostream &operator<<(ostream &s, const vector<long long> &v)
{
    for (auto &val : v)
        s << val << " ";

    return s;
}

template <class T>
vector<long long> prefix(const vector<T> &arr)
{
    vector<long long> prefix{0};
    for (int i = 0; i < arr.size(); i++)
    {
        prefix.push_back(prefix[i] + arr[i]);
    }
    return prefix;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream ifs{"D:\\karen\\dev\\cpp\\test.txt"};
    int n{0};
    vector<long long> arr;
    if (ifs.is_open())
    {
        ifs >> n;
        forn(_, n)
        {
            int x{0};
            ifs >> x;
            arr.push_back(x);
        }

        int q{0}, l{0}, r{0}, d{0};
        ifs >> q;
        vector<long long> arrCopy{arr};
        vector<long long> seq(n, 0);
        long long count{0};

        clock_t start = clock();
        forn(i, q)
        {
            if (count % 1000000 == 0)
                cout << "c: " << count << '\n';
            count++;

            ifs >> l >> r >> d;
            l--; // [l;r)
            seq[l] += d;
            if (r < n)
                seq[r] -= (r - l + 1) * d;
            if ((r + 1) < n)
                seq[r + 1] += (r - l) * d;

            for (int k = 1, j = l; j < r; k++, j++)
            {
                if (k % 1000000 == 0)
                    cout << "k: " << k << '\n';
                arrCopy[j] += k * d;
            }
        }

        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;

        vector<long long> p = prefix(prefix(seq));

        // for (int i = 0; i < n; i++)
        // {
        //     cout << (long long)arr[i] + p[i + 2] << " ";
        // }
        // cout << arrCopy << endl;

        p.erase(p.begin());
        p.erase(p.begin());

        for (int i = 0; i < n; i++)
            p[i] += arr[i];

        for (int i = 0; i < n; i++)
            if (arrCopy[i] != p[i])
                cout << i << ": " << arrCopy[i] << " | " << p[i] << endl;

        printf("The time: %f seconds\n", seconds);
    }
    else
        cout << "Error!" << endl;

    return 0;
}
