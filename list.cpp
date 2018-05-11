#include <list.h>

using namespace std;

List *createList()
{
    List *list = nullptr;
    list = new List;

    return list;
}

int add(List *list, Ship ship)
{
    int i=1;
    List *p, *e;
    e = new List;
    e->n = 0;
    e->ship = ship;
    p = list;
    if(p)
    {
        while(p->n)
        {
            p = p->n;
            i++;
        }
        p->n = e;
        e->ship.number=i;
    }
    else list = e;
    return i;
}

void clearList(List *list)
{
    while(list)
    {
        List *p = list;
        list = list->n;
        delete p;
    }
}
