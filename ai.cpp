#ifndef AI_H
#define AI_H

#endif // AI_H
#include <ai.h>
#include <ui.h>
#include <core.h>
#include <list.h>

void randomship(int x, int y, int **D,List *list, int S[4], int len)
{
    Ship ship;
    int number = 1;
    bool heh=1;
    do{
        char param;
        if(rand()%2==1)
            param='H';
        else
            param='V';
        int xs = rand()%x+1;
        int ys = rand()%y+1;
        int ls = len;

        cout <<"debug input:"<< param << " " << xs << " " << ys << " " << ls << endl;
        cout <<"shipssssss:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;

            if(param!='H' && param!='V')
            {heh=1; continue;}
            if(xs<1 || xs>x+1)
            {heh=1; continue;}
            if(ys<1 || ys>y+1)
            {heh=1; continue;}
            if(ls<0 || ls>4)
            {heh=1; continue;}

        ship={number,ls,param,xs,ys,ls};

        heh=sanitycheck(x,y,D,S,ship);

        //if(heh)
        //    cout << "Error! Cannot insert ship " << param << x << y << l << endl;

        if(S[len-1]<1)
            return;

    }while(!heh);

    insertship(D,S,list,ship,number);
}

void makeboard(int x, int y, int **A, List *list, int S[4])
{
    int i=4;

    do
    {
        randomship(x,y,A,list,S,i);
        //cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
        //print(x,y,A,B,AS,BS);
        if(S[0]<1 && S[1]<1 && S[2]<1 && S[3]<1)
            break;
        if(S[i-1]<1)
            i--;
        if(i<=0)
            break;

    }while(true);
}


