
#include <list.h>

List *createList()
{
    List *list = new List;
    list->head = 0;
    list->n = 0;

    return list;
}

void add(List *list, Ship ship)
{
    if(list==0) return;

    if(list->n!=0)
    {
        list->n = addAfter(list->n, ship);
    } else
    {
        list->head = addAfter(list->head, ship);
        list->n = list->head;
    }
}

lShip *ShipTolShip(Ship ship, lShip *n)
{
    lShip *lship = new lShip;
    lship->ship = ship;
    lship->n = n;
    return lship;
}

void clearList(lShip *adr)
{
    if(adr!=0)
    {
        clearList(adr->n);
        delete adr;
    }
}

lShip * addAfter(lShip *adr, Ship ship)
{
    lShip *tmp;
    tmp = ShipTolShip(ship, 0);

    if(adr!=0)
    {
        tmp->n = adr->n;
        adr->n = tmp;
    }

    return tmp;
}

