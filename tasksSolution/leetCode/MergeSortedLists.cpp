#include <iostream>
using namespace std;

struct node
{
    int item;
    node* next;

    node() : item{0}, next{nullptr}
    {
    }

    node(int i) : item{i}, next{nullptr}
    {
    }

    node(int i, node* n) : item{i}, next{n}
    {
    }
};

node* create_stack(int size)
{
    cout << "Enter list: ";
    int item{0};
    cin >> item;
    node* head = new node(item, nullptr);
    node* temp = head;
    head->next = temp;
    for (size_t i = 1; i < size; i++)
    {
        cin >> item;
        node* n = new node(item, nullptr);
        temp->next = n;
        temp = n;
    }

    return head;
}

node* mergeTwoLists(node* list1, node* list2)
{
    if (list1 == nullptr)
        if (list2 == nullptr)
            return nullptr;
        else
            return list2;
    else
        if (list2 == nullptr)
            return list1;
    
    node *head, *reserve;
    if (list1->item <= list2->item)
    {
        head = list1;
        reserve = list2;
    }
    else
    {
        head = list2;
        reserve = list1;        
    }

    for (node* temp = head; temp != nullptr; temp = temp->next)
    {
        if (reserve == nullptr)
            break;
        if (temp->next == nullptr)
        {
            temp->next = reserve;
            break;
        }
        if (temp->item <= reserve->item && reserve->item < temp->next->item)
        {
            node* t = reserve->next;
            reserve->next = temp->next;
            temp->next = reserve;
            reserve = t;
        }
    }

    return head;
}

int main(int argc, char const *argv[])
{
    constexpr int N{3};
    node* list1 = create_stack(N);
    node* list2 = create_stack(N);

    for (node* temp = list1; temp != nullptr; temp = temp->next)
        cout << temp->item << " ";

    cout << endl;
    for (node* temp = list2; temp != nullptr; temp = temp->next)
        cout << temp->item << " ";

    list1 = mergeTwoLists(list1, list2);

    cout << endl;
    for (node* temp = list1; temp != nullptr; temp = temp->next)
        cout << temp->item << " ";

    return 0;
}
