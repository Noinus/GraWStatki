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
void mainloop(int A[8][8],int B[8][8],bool AS[8][8],bool BS[8][8], bool turn, string PassA, string PassB);

void print(int A[8][8],int B[8][8],bool AS[8][8],bool BS[8][8]);

void checkpassword(string pass);

bool sanitycheck(bool t, int A[8][8],int S[4], ship Ship);

void insertship(int D[8][8], int S[4], ship &Ship);

void insert(int D[8][8], bool t,int S[4]);

void userinsert(int A[8][8], int B[8][8], bool AS[8][8], bool BS[8][8], bool t,int S[4]);

void randomboard(int T[][8]);

void shot(int A[8][8], bool AS[8][8], int &score);

bool checksunk(int A[8][8], bool AS[8][8]);

void endgame(int A[8][8], int B[8][8], bool turn, int scoreA, int scoreB);
