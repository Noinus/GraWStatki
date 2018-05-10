#ifndef CORE_H
#define CORE_H

#endif // CORE_H

void mainloop(int x, int y, int **A, int **B, bool **AS, bool **BS, bool turn, string PassA, string PassB);

void maketab(int **&A, int x, int y);

void makebooltab(bool **&A, int x, int y);

void deletetab(int **&A, int x);

void deletebooltab(bool **&A, int x);

bool sanitycheck(int x, int y, int **A, int S[4], ship Ship);
