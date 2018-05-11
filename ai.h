#ifndef AI_H
#define AI_H

#include <list.h>
using namespace std;

void randomship(int x, int y, int **D, List *list, int S[4], int len);

void makeboard(int x, int y, int **A, List *list, int S[4]);

void aishot(int x,int y,int **A, bool **AS, List *list,int &score);

int randomshot(int x,int y,int **A, bool **AS, List *list,int &score);

void hunting(int x, int y, int X, int Y, bool **AS);

int stackshot(int x, int y, int **A, bool **AS, List *list,int &score);

#endif // AI_H
