/**
 * Gra w Statki
 * Autor: Kamil Turko
 *
 * Uwagi: Program testowany na systemie Fedora 27, nietestowany na systemach Windows
 * https://github.com/Noinus/GraWStatki.git
**/
#include <ai.h>
#include <ui.h>

//Game parameters
bool ai=0;              //1-human vs machine  0-human vs human
bool t=0;               //1-ships are allowed to touch  0-ships are not allowed to touch
int Aas[4]={4,3,2,1};   //Number of ships for player A
int Bas[4]={4,3,2,1};   //Number of ships for player B

int A[8][8];           //table of ships player A
int B[8][8];           //table of ships player B
bool AS[8][8];          //table of shots player A
bool BS[8][8];          //table of shots player B

string PassA;           //Password of Player A
string PassB;           //Password of Player B

bool turn=0;            //0 - player A,   1 - player B

int main()
{
    srand(time(NULL));
    cout<<"Set password for Player A: ";
    cin >> PassA;
    system("clear");
    if(ai==0)
    {
        cout<<"Set password for Player B: ";
        cin >> PassB;
        system("clear");
    }
    print(A,B,AS,BS);

    cout << "Time for player A to insert!" << endl;
    userinsert(A,B,AS,BS,t,Aas);

    system("clear");

    makeboard(B,t,Bas);

    mainloop(A,B,AS,BS,turn,PassA,PassB);

    return 0;
}
