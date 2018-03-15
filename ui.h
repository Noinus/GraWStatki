#ifndef UI_H
#define UI_H

#endif // UI_H

#include <iostream>
#include <fstream>
using namespace std;

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
