#ifndef UI_H
#define UI_H


#include <ui.h>
#include <ai.h>
#include <core.h>
#include <list.h>

using namespace std;




void print(int x, int y, int **A, int **B, bool **AS, bool **BS)
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
                if(BS[i][j]==1)
                    cout << " *";
                else
                    cout << "  ";
            }
            else
            {
                if(BS[i][j]==0)
                    cout <<" #";
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
            if(AS[i][j]==0)
                    cout <<"  ";
            else
            {
                if(B[i][j]>0)
                    cout <<" X";
                else
                    cout <<" *";
            }
        }
        cout << endl;
    }
}

void checkpassword(string pass)
{
    string password;
    do{
        cin >> password;
        if(password!=pass)
            cout << "Wrong password! Try again!\n";
    }while(password!=pass);
}

void insert(int x, int y, int **D, List *list, int S[4])
{
    int number = 1;
    Ship ship;
    bool heh=1;
    do{
        cout << "Remaining ships:\n";
        cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
        cout << "enter new ship:" << endl;

        char param;
        char xsr;
        int ys;
        int ls;

        cin >> param >> xsr >> ys >> ls;
        int xs=xsr-64;

        cout <<"debug input:"<< param << " " << xs << " " << ys << " " << ls << endl;

            if(param!='H' && param!='V')
            {cout << "Wrong input! Try again\n";heh=1; continue;}
            if(xs<1 || xs>x+1)
            {cout << "Wrong input! Try again\n";heh=1; continue;}
            if(ys<1 || ys>y+1)
            {cout << "Wrong input! Try again\n";heh=1; continue;}
            if(ls<0 || ls>4)
            {cout << "Wrong input! Try again\n";heh=1; continue;}

        ship={number,ls,param,xs,ys,ls};

        heh=sanitycheck(x,y,D,S,ship);
        if(!heh)
            cout << "You cannot place ship here! Try again\n";
    }while(!heh);
    insertship(D,S,list,ship,number);

    cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
}

void userinsert(int x, int y,int **A, int **B, bool **AS, bool **BS, List *list, int S[4])
{
    while(true)
    {
        char choice;
        cout << "Do you want to insert your ships manually, or randomly [m/r]?";
        cin >> choice;
        if(choice=='r')
        {
            makeboard(x,y,A,list,S);
            return;
        }
        else if(choice=='m')
        {
            do
            {
                insert(x,y,A,list,S);
                system("clear");
                print(x,y,A,B,AS,BS);
                if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0)
                    break;
            }while(true);
            return;
        }
    }
}

void randomboard(int **T)
{
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            T[i][y]=rand()&2;
}

void outline(Ship ship, bool **AS)
{
    if(ship.p=='H')
    {
        for(int i=ship.x;i<ship.x+ship.l;i++)
            AS[ship.y-1][i]=1;
        for(int i=ship.x-1;i<ship.x+ship.l+1;i++)
            AS[ship.y][i]=1;
        for(int i=ship.x;i<ship.x+ship.l;i++)
            AS[ship.y+1][i]=1;
    }
    else
    {
        for(int i=ship.y;i<ship.y+ship.l;i++)
            AS[i][ship.x-1]=1;
        for(int i=ship.y-1;i<ship.y+ship.l+1;i++)
            AS[i][ship.x]=1;
        for(int i=ship.y;i<ship.y+ship.l;i++)
            AS[i][ship.x+1]=1;
    }
}

bool checksunk(List *list, bool **AS, int number)
{
    while(list)
    {
        if(list->ship.number==number)
        {
            list->ship.hp--;
            if(list->ship.hp<1)
            {
                outline(list->ship, AS);
                return 1;
            }
            else
                return 0;
        }
        list = list->n;
    }
}

int shot(int x,int y,int **A, bool **AS, List *list,int &score)
{
    int X,Y;
    do{
        cout << "Choose place to shoot at:" << endl;
        char ddd;
        cin >> ddd >> X;
        Y=ddd-64;

            if(X<0 || X>x)
            {cout << "Wrong input! Try again\n"; continue;}
            if(Y<0 || Y>y)
            {cout << "Wrong input! Try again\n"; continue;}

            if(AS[X][Y]==1)
            {cout << "You have already shot there! Try other place\n"; continue;}
            else
            {AS[X][Y]=1;break;}

    }while(true);
    if(A[X][Y]!=0)
    {
        score++;
        if(checksunk(list,AS,A[X][Y]))
            return 2;
        else
            return 1;
    }
    else
        return 0;
}


void endgame(int x, int y,int **A, int **B, bool turn)
{
    system("clear");
    if(turn)
    {
        cout << "Player B wins!"<< endl;
    }
    else
    {
        cout << "Player A wins!"<< endl;
    }
    cout << "     Player A              Player B\n";
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
                cout << "  ";
            else
                cout <<" #";
        }
        cout << "     ";
        cout << i;
        if(i<10)
            cout << " ";
        for(int j=1;j<x+1;j++)
        {
            if(B[i][j]==0)
                cout << "  ";
            else
                cout <<" #";
        }
        cout << endl;
    }
}

#endif // UI_H
