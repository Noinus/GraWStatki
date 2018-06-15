/**
 * Gra w Statki
 * Autor: Kamil Turko
 *
 * Uwagi: Program testowany na systemie Fedora 27, nietestowany na systemach Windows
 * https://github.com/Noinus/GraWStatki.git
**/
#include <ai.h>
#include <ui.h>
#include <core.h>
#include <list.h>

//Game parameters
bool ai=1;              //1-human vs machine  0-human vs human
bool safegame=0;        //1-require password before turn

int x=8, y=8;           //size of the board
int type=4;             //number of ship types

int ** A = new int * [y+2];     //board of player A ships
int ** B = new int * [y+2];     //board of player B ships
bool ** AS = new bool * [y+2];  //board of player A shots
bool ** BS = new bool * [y+2];  //board of player B shots
int *S = new int[type];         //ships to be inserted

int scoreToWin = 0;             //sum of all ships hit points

string PassA;           //Password of Player A
string PassB;           //Password of Player B

bool turn=0;            //0 - player A,   1 - player B

int main()
{
    S[0]=4;S[1]=3;S[2]=2;S[3]=1; //default settings

    startscreen(x,y,type,S,ai,safegame);

    int *SB = new int[type];

    for(int i=0;i<type;i++)
    {
        SB[i]=S[i];
        scoreToWin+=S[i]*(i+1);
    }

    maketab(A,x,y);
    maketab(B,x,y);
    makebooltab(AS,x,y);
    makebooltab(BS,x,y);
    srand(time(NULL));

    List *listA;
    List *listB;
    listA = createList();
    listB = createList();

    if(safegame)
    {
        cout<<"Set password for Player A: ";
        cin >> PassA;
        system("clear");
        if(ai==0)
        {
            cout<<"Set password for Player B: ";
            cin >> PassB;
            system("clear");
        }
    }

    print(x,y,A,B,AS,BS);

    system("clear");
    cout << "Time for player A to insert!" << endl;
    userinsert(x,y,A,B,AS,BS,listA,S,type);

    system("clear");

    makeboard(x,y,B,listB,SB,type);

    mainloop(x,y,A,B,AS,BS,listA,listB,ai,turn,safegame,PassA,PassB,scoreToWin);

    delete [] S;
    deletetab(A,x);
    deletetab(B,x);
    deletebooltab(AS,x);
    deletebooltab(BS,x);
    clearList(listA);
    clearList(listB);
    return 0;
}
