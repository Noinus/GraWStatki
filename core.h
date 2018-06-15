#ifndef CORE_H
#define CORE_H



#include <iostream>
#include <fstream>
#include <string>
#include <ship.h>

void startscreen(int &x,int &y, int &type, int *&S, bool &ai, bool &safegame);

void mainloop(int x, int y, int **A, int **B, bool **AS, bool **BS, List *listA, List *listB, bool ai, bool turn, bool safegame, string PassA, string PassB, int scoreToWin);

void maketab(int **&A, int x, int y);

void makebooltab(bool **&A, int x, int y);

void deletetab(int **&A, int x);

void deletebooltab(bool **&A, int x);

void insertship(int **D, int *S, List *list, Ship &ship, int number);

bool sanitycheck(int x, int y, int **A, int *S, Ship ship);

#endif // CORE_H
