#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define forn(i, n) for (int i = 0; i < static_cast<int>(n); i++)

struct Point
{
    int x;
    int y;

    Point(int x, int y) : x{x}, y{y}
    {
    }

    bool operator< (const Point &p2) const noexcept
    {
        if (this->x < p2.x)
            return true;
        if (this->y < p2.y)
            return true;
        return false;
    }
};

inline bool operator==(const Point &p1, const Point &p2)
{
    if ((p1.x == p2.x) && (p1.y == p2.y))
        return true;
    return false;
}

void printVector(vector<Point> &arr)
{
    for (Point &point : arr)
    {
        cout << "{" << point.x << ", " << point.y << "}" << endl;
    }
}

void printSet(set<Point> &arr)
{
    for (Point point : arr)
    {
        cout << "{" << point.x << ", " << point.y << "}" << endl;
    }
}

Point findClosest(set<Point> &s1, Point &cur)
{
    Point min{*s1.begin()};
    for (auto &point : s1)
    {
        if (abs(cur.x - point.x) + abs(cur.y - point.y))
            min = point;
    }
    return min;
}

template <typename T>
set<T> intersection(set<T> &s1, set<T> &s2)
{
    set<T> result;
    for (auto &val : s1)
    {
        if (s2.count(val))
            result.insert(val);
    }
    return result;
}

/**
 * @brief каждую минуту челик мог остаться или переместиться куда-то, поэтому позвращаем все точки, в которые мог бы челик переместиться
 *
 * @param point точка из которой он мог куда-то уйти
 * @param range максимальный диапазон, куда бы мог уйти
 * @return set<Point> все точки, в которые мог бы челик переместиться
 */
set<Point> Rhomb(Point point, int range)
{
    set<Point> result;

    // добавляем все точки внутреннего квадрата
    forn(i, range)
    {
        forn(j, range)
        {
            result.insert({point.x + i, point.y + j});
            result.insert({point.x + i, point.y - j});
            result.insert({point.x - i, point.y + j});
            result.insert({point.x - i, point.y - j});
        }
    }

    // добавляем крайние осевые точки, чтобы получился ромб
    result.insert({point.x, point.y + range});
    result.insert({point.x, point.y - range});
    result.insert({point.x + range, point.y});
    result.insert({point.x - range, point.y});

    return result;
}

int main(int argc, char const *argv[])
{
    int t{0}, d{0}, n{0};
    vector<Point> coord = {{0, 0}};
    cin >> t >> d >> n;
    forn(_, n)
    {
        int x{0}, y{0};
        cin >> x >> y;
        coord.push_back({x, y});
    }
    // printVector(coord);

    set<Point> whereCouldGone, whereCouldStay;
    set<Point> commonPoints;
    Point closest(coord[0]);

    for (int i = 1; i < coord.size(); i++)
    {
        Point cur{coord[i]};
        if (!commonPoints.empty())
        {
            closest = findClosest(commonPoints, cur);
        }

        whereCouldGone = Rhomb(closest, t);
        whereCouldStay = Rhomb(cur, d);
        commonPoints.clear();
        // set_intersection(whereCouldGone.begin(),
                        //  whereCouldGone.end(),
                        //  whereCouldStay.begin(),
                        //  whereCouldStay.end(),
                        //  back_inserter(commonPoints));
        commonPoints = intersection(whereCouldGone, whereCouldStay);
    }

    printSet(commonPoints);

    return 0;
}
