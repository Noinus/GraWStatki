#ifndef AI_H
#define AI_H

#endif // AI_H
#include <ai.h>
#include <ui.h>

void randomship(int D[8][8],bool t, int S[4], int len)
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
        int l = len;

        //cout <<"debug input:"<< param << " " << x << " " << y << " " << l << endl;
        //cout <<"shipssssss:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;

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

        //if(heh)
        //    cout << "Error! Cannot insert ship " << param << x << y << l << endl;

        if(S[len-1]<1)
            return;

    }while(!heh);

    insertship(D,S,Ship);
}

void makeboard(int A[][8], bool t, int S[4])
{
    int i=4;

    do
    {
        randomship(A,t,S,i);
        //cout <<"ships:"<< S[0] << " " << S[1] << " " << S[2] << " " << S[3] << endl;
        //print(A,B,AS,BS);
        if(S[0]<1 && S[1]<1 && S[2]<1 && S[3]<1)
            break;
        if(S[i-1]<1)
            i--;
        if(i<=0)
            break;

    }while(true);
}


