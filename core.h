#ifndef CORE_H
#define CORE_H

#endif // CORE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ship.h>

void mainloop(int x, int y, int **A, int **B, bool **AS, bool **BS, List *listA, List *listB, bool turn, string PassA, string PassB);

void maketab(int **&A, int x, int y);

void makebooltab(bool **&A, int x, int y);

void deletetab(int **&A, int x);

void deletebooltab(bool **&A, int x);

void insertship(int **D, int S[4], List *list, Ship &ship, int number);

bool sanitycheck(int x, int y, int **A, int S[4], Ship ship);

