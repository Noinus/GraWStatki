#ifndef UI_H
#define UI_H

#endif // UI_H

#include <iostream>
#include <fstream>

using namespace std;

struct ship{
    char p;
    int x;
    int y;
    int l;
};

void print(int x, int y, int **A, int **B, bool **AS, bool **BS);

void checkpassword(string pass);

void insertship(int **D, int S[4], ship &Ship);

void insert(int **D, int S[4]);

void userinsert(int x, int y, int **A, int **B, bool **AS, bool **BS, int S[4]);

void randomboard(int **T);

void shot(int x, int y, int **A, bool **AS, int &score);

bool checksunk(int **A, bool **AS);

void endgame(int **A, int **B, bool turn, int scoreA, int scoreB);
