#ifndef CORE_H
#define CORE_H


#include <ai.h>
#include <ui.h>
#include <core.h>
#include <list.h>
#include <debug.h>
#include <fstream>

bool debug = 0;

void startscreen(int &x,int &y, int &type, int *&S, bool &ai, bool &safegame)
{
    string choice, param;
    int fleetpower = 0;
    for(int i=0;i<type;i++)
        fleetpower+=S[i]*(i+1);

    do{
        system("clear");
        cout << "Welcome to Battleships!\n";
        cout << "current settings are:\n";
        cout << "1. X = " << x << endl;
        cout << "2. Y = " << y << endl;
        cout << "3. Number o types = " << type << endl;
            for(int i=0;i<type;i++)
                cout << "  Size " << i+1 << ": " << S[i] << endl;
        cout << "4. AI = " << (ai ? "Enabled" : "Disabled") << endl;
        cout << "5. Passwords = " << (safegame ? "Enabled" : "Disabled") << endl << endl;

        cout << "Type CHANGE number to change desired parameter (ex. CHANGE 1 will the x dimension of the board\n";
        cout << "SAVE file_name to save settings to file\n";
        cout << "LOAD file_name to load settings from file\n";
        cout << "OK to begin game with current settings\n";

        cin >> choice >> param;

        if(choice=="CHANGE")
        {
            if(param=="1")
            {
                do{
                    cout << "Type in new value of x: ";
                    cin >> x;
                    if(fleetpower > x*y/3)
                        cout << "You cannot fit that many ships on that area!!\n";
                }while(fleetpower > x*y/3);
            }
            else if(param=="2")
            {
                do{
                    cout << "Type in new value of y: ";
                    cin >> y;
                    if(fleetpower > x*y/3)
                        cout << "You cannot fit that many ships on that area!!\n";
                }while(fleetpower > x*y/3);
            }
            else if(param=="3")
            {
                int q;
                do
                {
                    cout << "Type in new number of ship types: ";
                    cin >> q;
                    if(q>x && q>y)
                        cout << "Longest ship cannot be longer than board!\n";
                }while(q>x && q>y);
                type = q;
                S = new int[type];

                do{
                    fleetpower =0;
                    for(int i=0;i<type;i++)
                    {
                        cout << "Numbers of ships in size " << i+1 << ": ";
                        cin >> S[i];
                        fleetpower+=S[i]*(i+1);
                    }
                    if(fleetpower > x*y/3)
                        cout << "There is too many ships!\n";
                }while(fleetpower > x*y/3);
            }
            else if(param=="4")
            {
                cout << "Type 1 to enable AI or 0 to disable it: ";
                cin >> ai;
            }
            else if(param=="5")
            {
                cout << "Type 1 to enable passwords or 0 to disable it: ";
                cin >> safegame;
            }
            else
                cout << "Wrong parameter!\n";
        }

        else if(choice=="LOAD")
        {
            ifstream plik;
            plik.open(param.c_str());
            if(plik.good())
            {
                string R;
                plik >> R;
                if(R!="Battleships_Settings_File")
                {cout << "Bad file!\n"; continue;}
                plik >> x >> y;
                plik >> type;
                for(int i=0;i<type;i++)
                    plik >> S[i];
                plik >> ai >> safegame;
                plik.close();
            }
            else
                cout << "Cannot reach file!\n";
        }
        else if(choice=="SAVE")
        {
            ofstream plik;
            plik.open(param.c_str());
            if(plik.good())
            {
                plik << "Battleships_Settings_File" << endl;
                plik << x << " " << y << endl;
                plik << type << " ";
                for(int i=0;i<type;i++)
                    plik << S[i] << " ";
                plik << endl;
                plik << ai << " " << safegame << endl;
                plik.close();
            }
        }
        else
        {
            cout << "Wrong input!\n";
        }
    }while(choice!="OK");
}


void mainloop(int x,int y,int **A, int **B, bool **AS, bool **BS, List *listA, List *listB, bool ai, bool turn, bool safegame, string PassA, string PassB,int scoreToWin)
{
    int scoreA=0,scoreB=0,d;
    while(true)
    {
        if(turn) // Turn of Player B
        {
            if(ai)
            {
                aishot(x,y,A,BS,listA,scoreB);
                if(scoreB>=scoreToWin)
                    break;
                turn=0;
                //cout << "Press enter to continue\n";
                //system("read");
            }
            else
            {
                system("clear");
                if(safegame)
                {
                    cout << "Player B\nPassword:\n";
                    checkpassword(PassB);
                }
                system("clear");
                cout << "Turn of player B\n";
                print(x,y,B,A,BS,AS);
                if(debug)
                {
                    cout << endl << endl;
                    debugprint(x,y,B,A,BS,AS);
                }
                d = shot(x,y,A,BS,listA,scoreB);
                system("clear");
                cout << "Turn of player B\n";
                print(x,y,B,A,BS,AS);
                switch (d) {
                case 1:
                    cout << "Hit!\n";
                    break;
                case 2:
                    cout << "Hit and sunk!\n";
                    break;
                default:
                    cout << "Miss!\n";
                    break;
                }
                if(debug)
                {
                    cout << endl << endl;
                    debugprint(x,y,B,A,BS,AS);
                    printList(listA);
                }
                if(scoreB>=scoreToWin)
                    break;
                turn=0;
                cout << "Press enter to continue\n";
                system("read");
            }
        }
        else  // Turn of Player A
        {
            system("clear");
            if(safegame)
            {
                cout << "Player A\nPassword:\n";
                checkpassword(PassA);
            }
            system("clear");
            cout << "Turn of player A\n";
            print(x,y,A,B,AS,BS);
            if(debug)
            {
                cout << endl << endl;
                debugprint(x,y,A,B,AS,BS);
            }
            d = shot(x,y,B,AS,listB,scoreA);
            system("clear");
            cout << "Turn of player A\n";
            print(x,y,A,B,AS,BS);
            switch (d) {
            case 1:
                cout << "Hit!\n";
                break;
            case 2:
                cout << "Hit and sunk!\n";
                break;
            default:
                cout << "Miss!\n";
                break;
            }
            if(debug)
            {
                cout << endl << endl;
                debugprint(x,y,A,B,AS,BS);
                printList(listB);
            }
            if(scoreA>=scoreToWin)
                break;
            turn=1;
            cout << "Press enter to continue\n";
            system("read");
        }
    }
    endgame(x,y,A,B,turn);
    return;
}

void maketab(int **&A, int x, int y)
{
    for (int i = 0; i<y+2; i++)
        A[i] = new int [x+2];
}

void makebooltab(bool **&A, int x, int y)
{
    for (int i = 0; i<y+2; i++)
        A[i] = new bool [x+2];
}

void deletetab(int **&A, int x)
{
    for (int i = 0; i<x+2; i++)
       delete [] A[i];
}

void deletebooltab(bool **&A, int x)
{
    for (int i = 0; i<x+2; i++)
       delete [] A[i];
}

void insertship(int **D, int *S, List *list, Ship &ship, int number)
{
    cout << "adding ship to list\n";
    number=add(list,ship);
    if(ship.p=='H')
    {
        for(int i=ship.x;i<ship.x+ship.l;i++)
            D[ship.y][i]=number;
        S[ship.l-1]--;
        return;
    }
    else if(ship.p=='V')
    {
        for(int i=ship.y;i<ship.y+ship.l;i++)
            D[i][ship.x]=number;
        S[ship.l-1]--;
        return;
    }
    return;
}

bool sanitycheck(int x, int y, int **A, int *S, Ship ship)
{
    if(S[ship.l-1]<1)
        return 0;
    if(ship.x<0)
        return 0;

    if(ship.p=='H')
    {
        if(ship.x+ship.l>x)
            return 0;
        for(int i=ship.x;i<ship.x+ship.l;i++)
        {
            if(A[ship.y][i]>=1 || A[ship.y-1][i]>=1 || A[ship.y][i-1]>=1 || A[ship.y+1][i]>=1 || A[ship.y][i+1]>=1)
                return 0;
        }
        return 1;
    }
    else if(ship.p=='V')
    {
        if(ship.y+ship.l>y)
            return 0;
        for(int i=ship.y;i<ship.y+ship.l;i++)
        {
            if(A[i][ship.x]>=1 || A[i-1][ship.x]>=1 || A[i][ship.x-1]>=1 || A[i+1][ship.x]>=1 || A[i][ship.x+1]>=1)
                return 0;
        }
        return 1;
    }
    return 0;
}

#endif // CORE_H
