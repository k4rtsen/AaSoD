#include <iostream>
#include <cmath>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

const string SW = "SW";
const string S = "S";
const string SE = "SE";
const string E = "E";
const string NE = "NE";
const string N = "N";
const string NW = "NW";
const string W = "W";

struct Dot
{
    float x{0};
    float y{0};

    Dot(float x, float y) : x{x}, y{y}
    {
    }
};

Dot middle(Dot a, Dot b)
{
    Dot result((b.x + a.x) / 2, (b.y + a.y) / 2);
    return result;
}

float distance(Dot a, Dot b)
{
    float w = b.x - a.x;
    float h = b.y - a.y;
    return sqrt(w * w + h * h);
}

int main(int argc, char const *argv[])
{
    float x1{0}, y1{0}, x2{0}, y2{0}, x{0}, y{0};
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    Dot d(x, y);
    Dot d1(x1, y1);
    Dot d2(x2, y1);
    Dot d3(x2, y2);
    Dot d4(x1, y2);
    Dot d12 = middle(d1, d2);
    Dot d23 = middle(d2, d3);
    Dot d34 = middle(d3, d4);
    Dot d41 = middle(d4, d1);

    string result{SW};
    float dist{distance(d, d1)};

    if (dist > distance(d, d12))
    {
        dist = distance(d, d12);
        result = S;
    }
    if (dist > distance(d, d2))
    {
        dist = distance(d, d2);
        result = SE;
    }
    if (dist > distance(d, d23))
    {
        dist = distance(d, d23);
        result = E;
    }
    if (dist > distance(d, d3))
    {
        dist = distance(d, d3);
        result = NE;
    }
    if (dist > distance(d, d34))
    {
        dist = distance(d, d34);
        result = N;
    }
    if (dist > distance(d, d4))
    {
        dist = distance(d, d4);
        result = NW;
    }
    if (dist > distance(d, d41))
    {
        dist = distance(d, d41);
        result = W;
    }

    cout << result;

    return 0;
}
