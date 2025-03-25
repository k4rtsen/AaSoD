#include <iostream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

int numberOfPoints(vector<vector<int>> &nums)
{
    constexpr int N{102};
    int places[N];
    forn(i, N)
        places[i] = 0;

    for (vector<int> arr : nums)
    {
        int start = arr[0];
        int end = arr[1];

        places[start] += 1;
        places[end + 1] -= 1;
    }

    int sum{0}, count{0};
    forn(i, N)
    {
        sum += places[i];
        if (sum > 0)
            count++;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> nums{{28,88},{9,88},{52,100},{4,86},{26,70},{43,81},{66,94},{15,74},{10,15},{17,54},{65,73},{70,100},{4,61},{78,93},{78,95},{42,59},{99,100},{78,97},{39,72},{2,83},{23,54},{14,94},{50,59},{43,56},{50,80},{57,75},{59,75},{50,59},{83,85},{82,99},{38,75},{49,51},{17,27},{69,96},{1,13},{1,84},{14,68},{23,36},{7,41},{72,80},{2,4},{17,53},{54,82},{10,83}};
    cout << numberOfPoints(nums) << endl;
    return 0;
}
