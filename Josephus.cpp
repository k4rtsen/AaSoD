#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct node
{
    int item;
    node *next;

    node(int i, node *next) : item{i}, next{next}
    {
    }
};

typedef node *link;

unsigned Josephus(unsigned n, unsigned m)
{
    // init stack
    link head = new node(0, nullptr);
    link temp = new node(1, nullptr);
    head->next = temp;

    for (size_t i = 2; i < n; i++)
    {
        link n = new node(i, nullptr);
        temp->next = n;
        temp = n;
    }

    // here temp point on the last node
    temp->next = head; // loop

    // finding the suvirval
    while (temp->next != temp)
    {
        // steps
        forn(i, m - 1)
        {
            temp = temp->next;
        }

        // deleting
        link dead = temp->next;
        temp->next = temp->next->next;
        delete dead;
    }

    int result = temp->item;

    // for(link l = head; l->next != l && l->next != nullptr; l = l->next)
    //     cout << l->item << " ";
    // cout << endl;

    // I don't fucking care about memory cleanup))

    return result + 1;
}

int main(int argc, char const *argv[])
{
    constexpr int N = 10e6;
    constexpr int M = 3;

    clock_t start = clock();

    cout << Josephus(N, M) << endl;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

    return 0;
}
