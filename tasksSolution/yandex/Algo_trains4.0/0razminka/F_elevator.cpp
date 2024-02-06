#include <iostream>
#include <fstream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int capacity{0}, n{0};
    unsigned long long time{0};

    // cin >> capacity >> n;
    // long long *office = new long long[n];
    // forn(i, n)
    // {
    //     cin >> office[i];
    // }

    ifstream in("16"); // окрываем файл для чтения
    in >> capacity >> n;

    unsigned long long *office = new unsigned long long[n];

    if (in.is_open())
    {
        int i = 0;
        while (!in.eof())
        {
            in >> office[i];
            i++;
        }
    }

    in.close(); // закрываем файл

    int inside{0};
    for (int i = n - 1; i >= 0; i--)
    {
        if (office[i] + inside == 0)
            continue;

        int remains = (office[i] + inside) % capacity;

        if (office[i] + inside < capacity)
        {
            if (inside > 0)
                time++; // опуститься вниз на этаж если находится выше i
            else
                time += (unsigned long long)(i + 1); // подняться с 0 до определенного этажа
            inside += office[i]; // подбираем бедолаг
            continue;
        }

        // если не полный лифт опускается, то берем пассажиров и опускаем вниз
        if (inside > 0)
        {
            office[i] -= capacity - inside; // забрать из офиса столько людей, сколько пустых мест
            time++; // опуститься вниз на 1
            time += (unsigned long long)(i + 1); // опустить полный лифт до 0
            inside = 0; // высадить всех из лифта
        }

        // едем за оставшимися
        time += (unsigned long long)(((office[i] - remains) / capacity) * ((i + 1) * 2));
        if (remains > 0)
            time += (unsigned long long)(i + 1); // подняться, чтобы забрать челика
        inside = remains;
    }

    // если кто-то остался внутри и мы на 1 этаже, то нужно опуститься на 0 этаж
    if (inside > 0)
        time++;
    cout << time << endl;

    return 0;
}
