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
#include <debug.h>

//Game parameters
bool ai=0;              //1-human vs machine  0-human vs human
int Aas[4]={4,3,2,1};   //Number of ships for player A
int Bas[4]={4,3,2,1};   //Number of ships for player B

int x=8, y=8;

int ** A = new int * [y+2];
int ** B = new int * [y+2];
bool ** AS = new bool * [y];
bool ** BS = new bool * [y];

string PassA;           //Password of Player A
string PassB;           //Password of Player B

bool turn=0;            //0 - player A,   1 - player B

int main()
{
    maketab(A,x,y);
    maketab(B,x,y);
    makebooltab(AS,x,y);
    makebooltab(BS,x,y);
    srand(time(NULL));

    List *listA;
    List *listB;
    listA = createList();
    listB = createList();


    cout<<"Set password for Player A: ";
    cin >> PassA;
    system("clear");
    if(ai==0)
    {
        cout<<"Set password for Player B: ";
        cin >> PassB;
        system("clear");
    }

    print(x,y,A,B,AS,BS);

    cout << "Time for player A to insert!" << endl;
    userinsert(x,y,A,B,AS,BS,listA,Aas);

    system("clear");

    printList(listA);

    makeboard(x,y,B,listB,Bas);

    mainloop(x,y,A,B,AS,BS,listA,listB,turn,PassA,PassB);

    deletetab(A,x);
    deletetab(B,x);
    deletebooltab(AS,x);
    deletebooltab(BS,x);
    cout << "unexpected error\n";
    return 0;
}
