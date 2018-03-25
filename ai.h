#ifndef AI_H
#define AI_H

#endif // AI_H

#include <iomanip>
#include <time.h>
#include <ui.h>

void randomship(bool D[8][8],bool t, int S[4])
{

    ship Ship;
    bool heh=1;
    do{
        char param;
        if(rand()%2==1)
            param='H';
        else
            param='V';
        int x = rand()%8;
        int y = rand()%8;
        int l = rand()%4+1;

        cout <<"debug input:"<< param << " " << x << " " << y << " " << l << endl;

            if(param!='H' && param!='V')
            {heh=1; continue;}
            if(x<0 || x>8)
            {heh=1; continue;}
            if(y<0 || y>8)
            {heh=1; continue;}
            if(l<0 || l>4)
            {heh=1; continue;}

        Ship={param,x,y,l};

        heh=sanitycheck(t,D,S,Ship);
    }while(!heh);
    insertship(D,S,Ship);
}

void makeboard(bool A[8][8],bool B[8][8],bool AS[8][8],bool BS[8][8],bool t, int S[4])
{
    do
    {
        randomship(A,t,S);
        cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
        print(A,B,AS,BS);
        if(S[0]==0 && S[1]==0 && S[2]==0 && S[3]==0)
            break;
    }while(true);
}
