#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

const string CONSTANT = "CONSTANT";                   // =
const string ASCENDING = "ASCENDING";                 // <
const string WEAKLY_ASCENDING = "WEAKLY ASCENDING";   // =<
const string DESCENDING = "DESCENDING";               // >
const string WEAKLY_DESCENDING = "WEAKLY DESCENDING"; // >=
const string RANDOM = "RANDOM";                       // <=>

string definition(bool equal, bool more, bool less)
{
    if (equal && more && less)
        return RANDOM;

    if (equal && more)
        return WEAKLY_DESCENDING;

    if (equal && less)
        return WEAKLY_ASCENDING;

    if (less)
        return ASCENDING;

    if (more)
        return DESCENDING;

    if (equal)
        return CONSTANT;

    return string();
}

main(int argc, char const *argv[])
{
    vector<int> seq;
    int value{0};
    while (cin >> value && value != -2000000000)
    {
        seq.push_back(value);
    }

    bool equal{false}, more{false}, less{false};
    forn(i, seq.size() - 1)
    {
        if (seq[i] == seq[i + 1])
            equal = true;

        if (seq[i] > seq[i + 1])
            more = true;

        if (seq[i] < seq[i + 1])
            less = true;
    }

    cout << definition(equal, more, less);

    return 0;
}
