#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> my_z_function(string str)
{
    int n = str.size();
    vector<int> z(n, 0);
    int l{0}, r{0};

    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);

        for (; z[i] + i < n && str[z[i]] == str[i + z[i]]; z[i]++)
            ;

        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

vector<int> slow_z_function(string s)
{
    int n = (int)s.size();
    vector<int> z(n, 0); // z[0] считается не определенным
    for (int i = 1; i < n; i++)
        // если мы не вышли за границу и следующие символы совпадают
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
    return z;
}

vector<int> z_function(string str)
{
    int n = (int)str.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        // если мы уже видели этот символ
        if (i <= r)
            // то мы можем попробовать его инициализировать z[i - l],
            // но не дальше правой границы: там мы уже ничего не знаем
            z[i] = min(r - i + 1, z[i - l]);
        // дальше каждое успешное увеличение z[i] сдвинет z-блок на единицу
        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            z[i]++;
        // проверим, правее ли мы текущего z-блока
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

class HashStr
{
private:
    const long long x_ = 257, p = 1000000007;
    long long *h, *x, n;

public:
    // высчитывает хэш строки
    HashStr(string str)
    {
        n = str.size();
        h = new long long[n + 1]; // hashes for string
        x = new long long[n + 1];
        h[0] = 0;
        x[0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            h[i] = (h[i - 1] * x_ + int(str[i - 1])) % p;
            x[i] = (x[i - 1] * x_) % p;
        }
    }

    ~HashStr()
    {
        delete[] h;
        delete[] x;
    }

    // Считает равны ли хэши подстрок
    bool Is_substrs_equal(int len, int from1, int from2)
    {
        if (len + from1 > n || len + from2 > n)
        {
            cout << "Error: Range out!" << endl;
            return false;
        }
        // if (len > 0)
        //     cout << "Error : Len is not positive!" << endl;
        return (h[from1 + len] + h[from2] * x[len]) % p == (h[from2 + len] + h[from1] * x[len]) % p;
    }
};

int FindZBinSearch(HashStr &hash, const int len, const int pos, const int last_good_res = 0, const int last_bad_res = 0)
{
    constexpr int StartPosition = 0; // начальная позиция префикса всегда 0
    if (len == 0)
        return 0;

    // сравнение строк
    if (!hash.Is_substrs_equal(len, StartPosition, pos))
    {
        // если не равны строки
        int mid = last_good_res > 0 ? last_good_res + (len - last_good_res) / 2 : len / 2; // и у нас еще нет хорошего результата, то длину делим пополам
                                                                                           // если есть хороший результат, мы берем позицию между хорошим результатом и нынешней длиной
        return FindZBinSearch(hash, mid, pos, last_good_res, len);                         // рекурсивно ищем дальше, меняя только длину подстрок и плохой результат
    }
    else
    {
        // если же подстроки равны
        if (last_bad_res == 0) // и нам повезло и сразу целиком они равны, то просто пишем целиком длину
            return len;
        if (last_bad_res - len == 1) // нам не повезло, но разница между хорошей и плохой строкой в 1 символ, то нынешняя длина - это наш результат
            return len;

        int mid = len + (last_bad_res - len) / 2;                 // если же вообще не повезло, то находим середину между последним плохим результатом и нынешней длиной
        return FindZBinSearch(hash, mid, pos, len, last_bad_res); // снова делем тоже самое но уже длина строк проверяется между длиной и плохим результатом, а хороший результат - это нынешняя длина
    }

    return -1;
}

int FindZ(HashStr &hash, int len, int position)
{
    // unsigned int len = str.size() - position; // максимальная длина от данной позиции и до конца строки
    return FindZBinSearch(hash, len, position);
}

vector<int> z_function_per_log(string str)
{
    int n = str.size();
    vector<int> res(n, 0);

    HashStr hash(str); // вычисляем хэши

    for (int i = 1; i < n; i++)
    {
        res[i] = FindZ(hash, str.size() - i, i);
    }

    return res;
}

void printVector(vector<int> arr)
{
    for (auto &val : arr)
        cout << val << " ";
}

int main(int argc, char const *argv[])
{
    string str{};
    cin >> str;

    // ifstream in("01");
    // if (in.is_open())
    //     in >> str;
    // else
    //     cout << "Error!" << endl;
    // in.close();

    printVector(z_function_per_log(str));
    
    return 0;
}
