#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void printVector(vector<int> arr)
{
    cout << "{ ";
    for (auto &val : arr)
        cout << val << "; ";
    cout << "}" << endl;
}

void printVector(vector<bool> arr)
{
    cout << "{ ";
    for (auto val : arr)
        cout << val << "; ";
    cout << "}" << endl;
}

// vector<char> faster than vector<bool>

vector<char> EratosthenesSieve(int n)
{
    vector<char> sieve(n, 't');

    for (int i = 2; i < n; i++)
        if (sieve[i] == 't')
            for (int j = i * 2; j < n / 2; j += i)
                sieve[j] = 'f';

    return sieve;
}

std::vector<char> AtkinSieve(unsigned const limit)
{
    // Предварительное просеивание
    std::vector<char> sieve(limit); // все числа заведомо составные
    // рассматриваются только нечетные числа
    for (unsigned long long x2 = 1ull, dx2 = 3ull; x2 < limit; x2 += dx2, dx2 += 2ull)
        for (unsigned long long y2 = 1ull, dy2 = 3ull, n; y2 < limit; y2 += dy2, dy2 += 2ull)
        {
            // n = 4x² + y²
            n = (x2 << 2ull) + y2;
            if (n <= limit && (n % 12ull == 1ull || n % 12ull == 5ull))
                sieve[n] = 't';
            // n = 3x² + y²
            n -= x2;
            if (n <= limit && n % 12ull == 7ull)
                sieve[n] = 't';
            // n = 3x² - y² (при x > y)
            if (x2 > y2)
            {
                n -= y2 << 1ull;
                if (n <= limit && n % 12ull == 11ull)
                    sieve[n] = 't';
            }
        }
    // Все числа, кратные квадратам, помечаются как составные
    unsigned r = 5u;
    for (unsigned long long r2 = r * r, dr2 = (r << 1ull) + 1ull; r2 < limit; ++r, r2 += dr2, dr2 += 2ull)
        if (sieve[r])
            for (unsigned long long mr2 = r2; mr2 < limit; mr2 += r2)
                sieve[mr2] = false;
    // Числа 2 и 3 — заведомо простые
    if (limit > 2u)
        sieve[2u] = 't';
    if (limit > 3u)
        sieve[3u] = 't';
    return sieve;
}

int main()
{
    constexpr unsigned int N = 10e8;
    clock_t start = clock();

    EratosthenesSieve(N);
    // AtkinSieve(N);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);
    return 0;
}
