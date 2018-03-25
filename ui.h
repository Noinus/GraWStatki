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

void print(bool A[8][8],bool B[8][8],bool AS[8][8],bool BS[8][8])
{
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
            {
                if(BS[i][y]==1)
                    cout << " *";
                else
                    cout << "  ";
            }
            else
            {
                if(BS[i][y]==0)
                    cout <<" #";
                else
                    cout <<" X";
            }
        }
        cout << "     ";
        cout << i+1;
        for(int y=0;y<8;y++)
        {
            if(AS[i][y]==0)
                    cout <<"  ";
            else
            {
                if(B[i][y]==1)
                    cout <<" X";
                else
                    cout <<" *";
            }
        }
        cout << endl;
    }
}

bool sanitycheck(bool t, bool A[8][8],int S[4], ship Ship)
{
    if(S[Ship.l-1]==0)
        return 0;
    if(Ship.x<0)
        return 0;

    if(Ship.p=='H')
    {
        if(Ship.x+Ship.l>8)
            return 0;
        for(int i=Ship.x;i<Ship.x+Ship.l;i++)
        {
            if(t)
            {
                if(A[Ship.y][i]==1)
                    return 0;
            }
            else
            {
                if(A[Ship.y][i]==1 || A[Ship.y-1][i]==1 || A[Ship.y][i-1]==1 || A[Ship.y+1][i]==1 || A[Ship.y][i+1]==1)
                    return 0;
            }
        }
        return 1;
    }
    else if(Ship.p=='V')
    {
        if(Ship.y+Ship.l>8)
            return 0;
        for(int i=Ship.y;i<Ship.y+Ship.l;i++)
        {
            if(t)
            {
                if(A[i][Ship.x]==1)
                    return 0;
            }
            else
            {
                if(A[i][Ship.x]==1 || A[i-1][Ship.x]==1  || A[i][Ship.x-1]==1 || A[i+1][Ship.x]==1  || A[i][Ship.x+1]==1 ==1)
                    return 0;
            }
        }
        return 1;
    }
    return 0;
}

void insertship(bool D[8][8], int S[4], ship &Ship)
{
    if(Ship.p=='H')
    {
        for(int i=Ship.x;i<Ship.x+Ship.l;i++)
            D[Ship.y][i]=1;
        S[Ship.l-1]--;
        return;
    }
    else if(Ship.p=='V')
    {
        for(int i=Ship.y;i<Ship.y+Ship.l;i++)
            D[i][Ship.x]=1;
        S[Ship.l-1]--;
        return;
    }
    return;
}

void insert(bool D[8][8], bool t,int S[4])
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

        heh=sanitycheck(t,D,S,Ship);
        if(!heh)
            cout << "You cannot place ship here! Try again\n";
    }while(!heh);
    insertship(D,S,Ship);

    cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
}

void randomboard(bool T[][8])
{
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            T[i][y]=rand()&2;
}

/*
void load(string nazwa_pliku,bool A[8][8],bool B[8][8],bool AS[8][8],bool BS[8][8])
{
    ofstream plik(nazwa_pliku.c_str());
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik >> A[i][y];
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik >> B[i][y];
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik >> AS[i][y];
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik >> BS[i][y];
}
void save(string nazwa_pliku,bool A[8][8],bool B[8][8],bool AS[8][8],bool BS[8][8])
{
    ifstream plik(nazwa_pliku.c_str());
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik << A[i][y] << " ";
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik << B[i][y] << " ";
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik << AS[i][y] << " ";
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            plik << BS[i][y] << " ";
}
*/
