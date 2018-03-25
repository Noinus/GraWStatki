#include <ai.h>

//Game parameters
bool t=0;               //1-ships are allowed to touch  0-ships are not allowed to touch
int Aas[4]={4,3,2,1};   //Number of ships for player A
int Bas[4]={4,3,2,1};   //Number of ships for player B

bool A[8][8];           //table of ships player A
bool B[8][8];           //table of ships player B
bool AS[8][8];          //table of shots player A
bool BS[8][8];          //table of shots player B

int main()
{
    srand(time(NULL));
    print(A,B,AS,BS);
    /*
    cout << "time to insert!" << endl;
    do
    {
        insert(A,t,Aas);
        print(A,B,AS,BS);
        if(Aas[0]==0 && Aas[1]==0 && Aas[2]==0 && Aas[3]==0)
            break;
    }while(true);
    */
    //randomboard(A);
    makeboard(A,B,AS,BS,t,Bas);
    //randomboard(B);
    //randomboard(AS);
    //randomboard(BS);
    print(A,B,AS,BS);
    return 0;
}
