#ifndef DEBUG_H
#define DEBUG_H

#include <list.h>

void debugprint(int x, int y, int **A, int **B, bool **AS, bool **BS)
{
    cout << "  ";
    char d='A';
    for(int i=1;i<x+1;i++)
    {cout <<" "<<d;d++;}
    cout << "       ";
    d='A';
    for(int i=1;i<x+1;i++)
    {cout <<" "<<d;d++;}
    cout << endl;

    for(int i=1;i<y+1;i++)
    {
        cout << i;
        if(i<10)
            cout << " ";
        for(int j=1;j<x+1;j++)
        {
            if(A[i][j]==0)
            {
                if(BS[i-1][j-1]==1)
                    cout << " *";
                else
                    cout << "  ";
            }
            else
            {
                if(BS[i-1][j-1]==0)
                    cout <<" " << A[i][j];
                else
                    cout <<" X";
            }
        }
        cout << "     ";
        cout << i;
        if(i<10)
            cout << " ";
        for(int j=1;j<x+1;j++)
        {
            if(AS[i-1][j-1]==0)
            {
                if(B[i][j]==0)
                    cout <<"  ";
                else
                    cout <<" " << B[i][j];
            }
            else
            {
                if(B[i][j]==1)
                    cout <<" X";
                else
                    cout <<" *";
            }
        }
        cout << endl;
    }
}

void printList(List *list)
{
    while(list!=0)
    {
        cout << list->ship.p << " " << list->ship.x << " " << list->ship.y << " " << list->ship.l << "   " << list->ship.number << " " << list->ship.hp << endl;
        list = list->n;
    }
}

#endif // DEBUG_H
