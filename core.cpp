#ifndef CORE_H
#define CORE_H

#endif // CORE_H
#include <ai.h>
#include <ui.h>
#include <core.h>
#include <list.h>
#include <debug.h>



void mainloop(int x,int y,int **A, int **B, bool **AS, bool **BS, List *listA, List *listB, bool turn, string PassA, string PassB)
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
                cout << endl << endl;
                debugprint(x,y,B,A,BS,AS);
            shot(x,y,A,BS,scoreB);
            system("clear");
            cout << "Turn of player B\n";
            print(x,y,B,A,BS,AS);
                cout << endl << endl;
                debugprint(x,y,B,A,BS,AS);
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
                cout << endl << endl;
                debugprint(x,y,A,B,BS,AS);
            shot(x,y,B,AS,scoreA);
            system("clear");
            cout << "Turn of player A\n";
            print(x,y,A,B,AS,BS);
                cout << endl << endl;
                debugprint(x,y,A,B,BS,AS);
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

void insertship(int **D, int S[4], List *list, Ship &ship, int number)
{
    add(list,ship);
    if(ship.p=='H')
    {
        for(int i=ship.x;i<ship.x+ship.l;i++)
            D[ship.y][i]=number;
        S[ship.l-1]--;
        return;
    }
    else if(ship.p=='V')
    {
        for(int i=ship.y;i<ship.y+ship.l;i++)
            D[i][ship.x]=number;
        S[ship.l-1]--;
        return;
    }
    return;
}

bool sanitycheck(int x, int y, int **A, int S[4], Ship ship)
{
    if(S[ship.l-1]<1)
        return 0;
    if(ship.x<0)
        return 0;

    if(ship.p=='H')
    {
        if(ship.x+ship.l>x)
            return 0;
        for(int i=ship.x;i<ship.x+ship.l;i++)
        {
            if(A[ship.y][i]>=1 || A[ship.y-1][i]>=1 || A[ship.y][i-1]>=1 || A[ship.y+1][i]>=1 || A[ship.y][i+1]>=1)
                return 0;
        }
        return 1;
    }
    else if(ship.p=='V')
    {
        if(ship.y+ship.l>y)
            return 0;
        for(int i=ship.y;i<ship.y+ship.l;i++)
        {
            if(A[i][ship.x]>=1 || A[i-1][ship.x]>=1 || A[i][ship.x-1]>=1 || A[i+1][ship.x]>=1 || A[i][ship.x+1]>=1)
                return 0;
        }
        return 1;
    }
    return 0;
}
