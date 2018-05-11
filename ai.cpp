#ifndef AI_H
#define AI_H

#include <ai.h>
#include <ui.h>
#include <core.h>
#include <list.h>
#include <stack>

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

        //cout <<"debug input:"<< param << " " << xs << " " << ys << " " << ls << endl;
        //cout <<"shipssssss:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;

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



struct coord{
    int x;
    int y;
};

stack <coord> next_move;

void stackwipe()
{
    while(next_move.empty()==false)
    {
        next_move.pop();
    }
}

void hunting(int x, int y,int X, int Y, bool **AS)
{
    coord c;
    if(AS[Y-1][X]==0 && Y-1>0)
    {
        c={X,Y-1};
        //cout << "Pushing on stack" << " x = " << c.x << "  y = " << c.y << endl;
        next_move.push(c);
    }
    if(AS[Y][X-1]==0 && X-1>0)
    {
        c={X-1,Y};
        //cout << "Pushing on stack" << " x = " << c.x << "  y = " << c.y << endl;
        next_move.push(c);
    }
    if(AS[Y+1][X]==0 && Y+1<=y)
    {
        c={X,Y+1};
        //cout << "Pushing on stack" << " x = " << c.x << "  y = " << c.y << endl;
        next_move.push(c);
    }
    if(AS[Y][X+1]==0 && X+1<=x)
    {
        c={X+1,Y};
        //cout << "Pushing on stack" << " x = " << c.x << "  y = " << c.y << endl;
        next_move.push(c);
    }
}

int stackshot(int x, int y, int **A, bool **AS, List *list,int &score)
{
    coord c=next_move.top();
    next_move.pop();
    AS[c.y][c.x]=1;
    if(A[c.y][c.x]!=0)
    {
        score++;
        if(checksunk(list,AS,A[c.y][c.x]))
        {
            stackwipe();
            return 2;
        }
        else
        {
            hunting(x,y,c.x,c.y,AS);
            return 1;
        }
    }
    else
        return 0;
}

int randomshot(int x,int y,int **A, bool **AS, List *list,int &score)
{
    int X,Y;
    do{
        X=rand()%x+1;
        Y=rand()%y+1;

            if(AS[Y][X]==1)
                continue;
            else
            {AS[Y][X]=1;break;}

    }while(true);
    if(A[Y][X]!=0)
    {
        score++;
        if(checksunk(list,AS,A[Y][X]))
        {
            stackwipe();
            return 2;
        }
        else
        {
            hunting(x,y,X,Y,AS);
            return 1;
        }
    }
    else
        return 0;
}



void aishot(int x,int y,int **A, bool **AS, List *list,int &score)
{
    if(next_move.empty())
    {
        //cout << "performing random shot\n";
        randomshot(x,y,A,AS,list,score);
    }
    else
    {
        //cout << "performing stack shot\n";
        //coord c=next_move.top();
        //cout << "x = " << c.x << "  y = " << c.y << endl;
        stackshot(x,y,A,AS,list,score);
    }
}


#endif // AI_H
