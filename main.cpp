#include <iomanip>
#include <time.h>
#include <ui.h>

using namespace std;

//Game parameters
bool t=0;               //1-ships are allowed to touch  0-ships are not allowed to touch
int Aas[4]={4,3,2,1};   //Number of ships for player A
int Bas[4]={4,3,2,1};   //Number of ships for player B

bool A[8][8];           //table of ships player A
bool B[8][8];           //table of ships player B
bool AS[8][8];          //table of shots player A
bool BS[8][8];          //table of shots player B



bool insertship(bool D[8][8], int S[4])
{
    cout << "enter new ship:" << endl;
    string R;
    cin >> R;
    char param = R[0];
    int x = R[1]-65;
    int y = R[2]-49;
    int l = R[3]-48;

    cout <<"debug input:"<< param << " " << x << " " << y << " " << l << endl;
    if(S[l-1]==0)
        return 1;
    if(x<0)
        return 1;

    if(param=='H')
    {
        if(x+l>8)
            return 1;
        for(int i=x;i<x+l;i++)
            D[y][i]=1;
        S[l-1]--;
        return 0;
    }
    else if(param=='V')
    {
        if(y+l>8)
            return 1;
        for(int i=y;i<y+l;i++)
            D[i][x]=1;
        S[l-1]--;
        return 0;
    }
    return 1;
}

void insert(bool D[8][8], int S[4])
{
    bool heh=1;
    do{
    heh=insertship(D,S);
    if(heh)
        cout << "Wrong input! Try again\n";
    }while(heh);
    cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
}

void randomboard(bool T[][8])
{
    for(int i=0;i<8;i++)
        for(int y=0;y<8;y++)
            T[i][y]=rand()&2;
}

int main()
{
    srand(time(NULL));
    cout << "time to insert!" << endl;
    insert(A, Aas);
    //randomboard(A);
    randomboard(B);
    randomboard(AS);
    randomboard(BS);
    print(A,B,AS,BS);
    return 0;
}
