#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    long long x1{0}, y1{0}, x2{0}, y2{0};
    cin >> x1 >> y1 >> x2 >> y2;

    // длина 1 и 2 отрезков
    double len1{0}, len2{0}, len{0};
    len1 = sqrt((x1 * x1) + (y1 * y1));
    len2 = sqrt((x2 * x2) + (y2 * y2));

    // углы 1 и 2 отрезков
    double alpha{0}, beta{0}, arc_len{0};
    alpha = atan2(y1, x1);
    beta = atan2(y2, x2);

    // длина дуги с меньшим радиусом
    if (len1 < len2)
        arc_len = abs(alpha - beta) * len1;
    else
        arc_len = abs(alpha - beta) * len2;

    // общая длина по дуге и по прямым или через центр
    len = abs(len1 - len2) + arc_len < len1 + len2 ? abs(len1 - len2) + arc_len : len1 + len2;
    cout.setf(ios::fixed);  // вывод в фиксированном формате 
    cout.precision(6);      // вывод до 6 знака после точки, включительно
    cout << len << endl;

    return 0;
}
