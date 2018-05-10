#ifndef CORE_H
#define CORE_H

#endif // CORE_H
#include <ai.h>
#include <ui.h>
#include <core.h>

void mainloop(int x,int y,int **A, int **B, bool **AS, bool **BS, bool turn, string PassA, string PassB)
{
    int scoreA=0,scoreB=0;
    while(true)
    {
        if(turn==1)
        {
            system("clear");
            cout << "Player B\nPassword:\n";
            checkpassword(PassB);
            system("clear");
            cout << "Turn of player B\n";
            print(x,y,B,A,BS,AS);
            shot(x,y,A,BS,scoreB);
            system("clear");
            cout << "Turn of player B\n";
            print(x,y,B,A,BS,AS);
            if(scoreB>=20)
                break;
            turn=0;
            cout << "Press enter to continue\n";
            system("read");
        }
        else
        {
            system("clear");
            cout << "Player A\nPassword:\n";
            checkpassword(PassA);
            system("clear");
            cout << "Turn of player A\n";
            print(x,y,A,B,AS,BS);
            shot(x,y,B,AS,scoreA);
            system("clear");
            cout << "Turn of player A\n";
            print(x,y,A,B,AS,BS);
            if(scoreA>=20)
                break;
            turn=1;
            cout << "Press enter to continue\n";
            system("read");
        }
    }
    endgame(A,B,turn, scoreA, scoreB);
    return;
}

void maketab(int **&A, int x, int y)
{
    for (int i = 0; i<y+2; i++)
        A[i] = new int [x+2];
}

void makebooltab(bool **&A, int x, int y)
{
    for (int i = 0; i<y; i++)
        A[i] = new bool [x];
}

void deletetab(int **&A, int x)
{
    for (int i = 0; i<x+2; i++)
       delete [] A[i];
}

void deletebooltab(bool **&A, int x)
{
    for (int i = 0; i<x; i++)
       delete [] A[i];
}

bool sanitycheck(int x, int y, int **A, int S[4], ship Ship)
{
    if(S[Ship.l-1]<1)
        return 0;
    if(Ship.x<0)
        return 0;

    if(Ship.p=='H')
    {
        if(Ship.x+Ship.l>x)
            return 0;
        for(int i=Ship.x;i<Ship.x+Ship.l;i++)
        {
            if(A[Ship.y][i]>=1 || A[Ship.y-1][i]>=1 || A[Ship.y][i-1]>=1 || A[Ship.y+1][i]>=1 || A[Ship.y][i+1]>=1)
                return 0;
        }
        return 1;
    }
    else if(Ship.p=='V')
    {
        if(Ship.y+Ship.l>y)
            return 0;
        for(int i=Ship.y;i<Ship.y+Ship.l;i++)
        {
            if(A[i][Ship.x]>=1 || A[i-1][Ship.x]>=1 || A[i][Ship.x-1]>=1 || A[i+1][Ship.x]>=1 || A[i][Ship.x+1]>=1)
                return 0;
        }
        return 1;
    }
    return 0;
}
