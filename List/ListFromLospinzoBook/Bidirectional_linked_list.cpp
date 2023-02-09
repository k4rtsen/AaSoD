#include <cstdio>
using namespace std;

struct Element
{
    char prefix[2];
    short operating_number;
    Element *next;
    Element *last;

    void insert_after(Element *new_element)
    {
        new_element->next = this->next;
        new_element->last = this;
        this->next = new_element;
    }

    void insert_before(Element *new_element) {
        if (this->last != NULL)
            new_element->last = this->last;
        this->last = new_element;
        new_element->next = this;
    }
};

int main(int argc, char const *argv[])
{
    Element clone1{{'T', 'K'}, 69}, clone2{{'F', 'N'}, 256}, clone3{{'Z', 'Z'}, 77};
    clone1.insert_after(&clone2);
    clone3.insert_before(&clone2);

    // going through the list
    for (Element *point = &clone1; point; point = point->next)
    {
        printf("Clone %c%c-%d\n",
               point->prefix[0],
               point->prefix[1],
               point->operating_number);
    }
    printf("Get back\n");
    for (Element *point = &clone3; point; point = point->last)
    {
        printf("Clone %c%c-%d\n",
               point->prefix[0],
               point->prefix[1],
               point->operating_number);
    }

    return 0;
}
