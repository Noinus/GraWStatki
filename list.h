#ifndef LIST_H
#define LIST_H

#include <ship.h>

struct lShip
{
    Ship ship;
    lShip *n;
};


struct List
{
    lShip *head;
    lShip *n;
};

List *createList();

void add(List *list, Ship ship);

lShip *ShipTolShip(Ship ship, lShip *n);

void clearList(lShip *adr);

lShip * addAfter(lShip *adr, Ship ship);

#endif // LIST_H
