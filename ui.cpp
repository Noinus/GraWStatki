#ifndef UI_H
#define UI_H

#endif // UI_H
#include <ui.h>
#include <ai.h>
#include <core.h>

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
                if(BS[i-1][j-1]==1)
                    cout << " *";
                else
                    cout << "  ";
            }
            else
            {
                if(BS[i-1][j-1]==0)
                    cout <<" #";
                else
                    cout <<" X";
            }
        }
        cout << "     ";
        cout << i;
        for(int j=1;j<x+1;j++)
        {
            if(AS[i-1][j-1]==0)
                    cout <<"  ";
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

void checkpassword(string pass)
{
    string password;
    do{
        cin >> password;
        if(password!=pass)
            cout << "Wrong password! Try again!\n";
    }while(password!=pass);
}

void insertship(int **D, int S[4], ship &Ship)
{
    if(Ship.p=='H')
    {
        for(int i=Ship.x;i<Ship.x+Ship.l;i++)
            D[Ship.y][i]=Ship.l;
        S[Ship.l-1]--;
        return;
    }
    else if(Ship.p=='V')
    {
        for(int i=Ship.y;i<Ship.y+Ship.l;i++)
            D[i][Ship.x]=Ship.l;
        S[Ship.l-1]--;
        return;
    }
    return;
}

void insert(int **D, int S[4])
{
    ship Ship;
    bool heh=1;
    do{
        cout << "Remaining ships:\n";
        cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
        cout << "enter new ship:" << endl;
        string R;
        cin >> R;
        char param = R[0];
        int x = R[1]-65;
        int y = R[2]-49;
        int l = R[3]-48;

        cout <<"debug input:"<< param << " " << x << " " << y << " " << l << endl;

            if(param!='H' && param!='V')
            {cout << "Wrong input! Try again\n";heh=1; continue;}
            if(x<0 || x>8)
            {cout << "Wrong input! Try again\n";heh=1; continue;}
            if(y<0 || y>8)
            {cout << "Wrong input! Try again\n";heh=1; continue;}
            if(l<0 || l>4)
            {cout << "Wrong input! Try again\n";heh=1; continue;}

        Ship={param,x,y,l};

        heh=sanitycheck(x,y,D,S,Ship);
        if(!heh)
            cout << "You cannot place ship here! Try again\n";
    }while(!heh);
    insertship(D,S,Ship);

    cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
}

void userinsert(int x, int y,int **A, int **B, bool **AS, bool **BS, int S[4])
{
    while(true)
    {
        char choice;
        cout << "Do you want to insert your ships manually, or randomly [m/r]?";
        cin >> choice;
        if(choice=='r')
        {
            makeboard(x,y,A,S);
            return;
        }
        else if(choice=='m')
        {
            do
            {
                insert(A,S);
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

void shot(int x,int y,int **A, bool **AS, int &score)
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

            if(AS[X-1][Y-1]==1)
            {cout << "You have already shot there! Try other place\n"; continue;}
            else
            {AS[X-1][Y-1]=1;break;}

    }while(true);
    if(A[X][Y]==1)
    {
        score++;
        if(checksunk(A, AS))
            cout << "Hit and sunk!";
        else
            cout << "Hit!";
    }
}

bool checksunk(int **A, bool **AS)
{

}

void endgame(int **A, int **B, bool turn, int scoreA, int scoreB)
{
    system("clear");
    if(turn)
    {
        cout << "Player B wins!\n";
    }
    else
    {
        cout << "Player A wins!\n";
    }
    cout << "     Player A              Player B\n";
    cout << " ";
    char d='A';
    for(int i=0;i<8;i++)
    {cout <<" "<<d;d++;}
    cout << "      ";
    d='A';
    for(int i=0;i<8;i++)
    {cout <<" "<<d;d++;}
    cout << endl;

    for(int i=0;i<8;i++)
    {
        cout << i+1;
        for(int y=0;y<8;y++)
        {
            if(A[i][y]==0)
                cout << "  ";
            else
                cout <<" #";
        }
        cout << "     ";
        cout << i+1;
        for(int y=0;y<8;y++)
        {
            if(B[i][y]==0)
                cout << "  ";
            else
                cout <<" #";
        }
        cout << endl;
    }
}
