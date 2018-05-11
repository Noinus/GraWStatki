#ifndef LIST_H
#define LIST_H

#include <ship.h>

struct List
{
    Ship ship;
    List *n;
};

List *createList();

int add(List *list, Ship ship);

void clearList(List *list);

#endif // LIST_H
