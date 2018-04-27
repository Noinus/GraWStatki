#ifndef UI_H
#define UI_H

#endif // UI_H
#include <ui.h>
#include <ai.h>

using namespace std;

void mainloop(int A[8][8],int B[8][8],bool AS[8][8],bool BS[8][8], bool turn, string PassA, string PassB)
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
            print(B,A,BS,AS);
            shot(A,BS,scoreB);
            system("clear");
            cout << "Turn of player B\n";
            print(B,A,BS,AS);
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
            print(A,B,AS,BS);
            shot(B,AS,scoreA);
            system("clear");
            cout << "Turn of player A\n";
            print(A,B,AS,BS);
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


void print(int A[8][8],int B[8][8],bool AS[8][8],bool BS[8][8])
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

void checkpassword(string pass)
{
    string password;
    do{
        cin >> password;
        if(password!=pass)
            cout << "Wrong password! Try again!\n";
    }while(password!=pass);
}

bool sanitycheck(bool t, int A[8][8],int S[4], ship Ship)
{
    if(S[Ship.l-1]<1)
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
                if(A[Ship.y][i]>=1)
                    return 0;
            }
            else
            {
                if(A[Ship.y][i]>=1 || A[Ship.y-1][i]>=1 || A[Ship.y][i-1]>=1 || A[Ship.y+1][i]>=1 || A[Ship.y][i+1]>=1)
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
                if(A[i][Ship.x]>=1)
                    return 0;
            }
            else
            {
                if(A[i][Ship.x]>=1 || A[i-1][Ship.x]>=1 || A[i][Ship.x-1]>=1 || A[i+1][Ship.x]>=1 || A[i][Ship.x+1]>=1)
                    return 0;
            }
        }
        return 1;
    }
    return 0;
}

void insertship(int D[8][8], int S[4], ship &Ship)
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

void insert(int D[8][8], bool t,int S[4])
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

void userinsert(int A[8][8], int B[8][8], bool AS[8][8], bool BS[8][8], bool t,int S[4])
{
    while(true)
    {
        char choice;
        cout << "Do you want to insert your ships manually, or randomly [m/r]?";
        cin >> choice;
        if(choice=='r')
        {
            makeboard(A,t,S);
            return;
        }
        else if(choice=='m')
        {
            do
            {
                insert(A,t,S);
                system("clear");
                print(A,B,AS,BS);
                if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0)
                    break;
            }while(true);
            return;
        }
    }
}

void randomboard(int T[][8])
{
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            T[i][y]=rand()&2;
}

void shot(int A[8][8], bool AS[8][8], int &score)
{
    int x,y;
    do{
        cout << "Choose place to shoot at:" << endl;
        string R;
        cin >> R;
        y = R[0]-65;
        x = R[1]-49;

            if(x<0 || x>=8)
            {cout << "Wrong input! Try again\n"; continue;}
            if(y<0 || y>=8)
            {cout << "Wrong input! Try again\n"; continue;}

            if(AS[x][y]==1)
            {cout << "You have already shot there! Try other place\n"; continue;}
            else
            {AS[x][y]=1;break;}

    }while(true);
    if(A[x][y]==1)
    {
        score++;
        if(checksunk(A, AS))
            cout << "Hit and sunk!";
        else
            cout << "Hit!";
    }
}

bool checksunk(int A[8][8], bool AS[8][8])
{

}

void endgame(int A[8][8], int B[8][8], bool turn, int scoreA, int scoreB)
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
