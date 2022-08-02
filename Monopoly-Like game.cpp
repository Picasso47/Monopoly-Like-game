#include <iostream>
#include <windows.h>
#include<conio.h>
#include<ctime>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int iDistance = 6, jDistance = 2;           //for dimesions of one box
int pturn = 1;                              //player turn
char Color;
int arraygreen[4] = { 5,16,27,38 };             //array of green box(Snake)
int arrayreward[4] = { 7,18,29,40 };        //array of Light blue(Ladder)
int arrayopprwrd[4] = { 3,14,24,35 };       //array of color Dark pink (Opponenet will have 2 turns)
int arrayownrwrd[4] = { 11,22,32,36 };
int temp1 = 10, temp2 = 10, temp3 = 10, temp4 = 10, swtch1 = 1;
void DrawSquare(int x, int y, char Player1Sym = ' ', char Player2Sym = ' ', char Color = ' ')
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();

    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);

    cout << " _____\n";

    y += 1;
    coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
    cout << "|" << Player1Sym << " " << Color << " " << Player2Sym << "|\n";

    y += 1;
    coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);

    cout << "|_____|\n";

}
void DrawBoard()
{
    char empty = ' ';

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (i == 0 && j == 11)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 8);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'B');
            }
            else if (i == 0 && j == 1 || i == 10 && j == 0 || i == 11 && j == 9 || i == 9 && j == 11)
            {

                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 4);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'R');
            }
            else if (i == 0 && j == 9 || i == 2 && j == 0 || i == 11 && j == 1 || i == 10 && j == 11)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 13);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'M');
            }
            else if (i == 0 && j == 7 || i == 4 && j == 0 || i == 11 && j == 4 || i == 7 && j == 11)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 2);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'G');
            }
            else if (i == 0 && j == 6 || i == 5 && j == 0 || i == 11 && j == 5 || i == 6 && j == 11)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 1);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'D');
            }
            else if (i == 0 && j == 5 || i == 6 && j == 0 || i == 11 && j == 6 || i == 5 && j == 11)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 3);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'L');
            }
            else if (i == 0 && j == 4 || i == 7 && j == 0 || i == 11 && j == 7 || i == 4 && j == 11)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 6);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'Y');
            }
            else if (i == 0 || j == 0 || i == 11 || j == 11)
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 12);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'P');
            }
            else if ((j == 1 || j == 10) && (i == 4 || i == 7)
                || (j == 2 || j == 9) && (i == 3 || i == 8)
                || (j == 3 || j == 8) && (i == 2 || i == 9)
                || (j == 4 || j == 7) && (i == 1 || i == 10))
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 12);
                DrawSquare(i * iDistance, j * jDistance, empty, empty, 'P');
            }
            else
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 15);
                DrawSquare(i * iDistance, j * jDistance);
            }


        }
    }


}
void DrawPlayer1(int& Player1Pos, char Player1Sym)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();

    if (Player1Pos <= 12)
    {
        COORD coord = { (SHORT)1, (SHORT)(12 - Player1Pos) * jDistance + jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player1Sym;
    }
    else if (Player1Pos < 24)
    {
        COORD coord = { (SHORT)(Player1Pos - 12) * iDistance + 1, (SHORT)jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player1Sym;
    }
    else if (Player1Pos <= 34)
    {
        COORD coord = { (SHORT)iDistance * 11 + 1, (SHORT)(Player1Pos - 23) * jDistance + jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player1Sym;
    }
    else
    {


        COORD coord = { (SHORT)(11 - (Player1Pos - 34)) * iDistance + 1, (SHORT)(11 * jDistance) + jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player1Sym;
    }




}
void DrawPlayer2(int& Player2Pos, char Player2Sym)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();

    if (Player2Pos <= 12)
    {
        COORD coord = { (SHORT)5, (SHORT)(12 - Player2Pos) * jDistance + jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player2Sym;
    }
    else if (Player2Pos < 24)
    {
        COORD coord = { (SHORT)(Player2Pos - 12) * iDistance + 5, (SHORT)jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player2Sym;
    }
    else if (Player2Pos <= 34)
    {
        COORD coord = { (SHORT)iDistance * 11 + 5, (SHORT)(Player2Pos - 23) * jDistance + jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player2Sym;
    }
    else
    {


        COORD coord = { (SHORT)(11 - (Player2Pos - 34)) * iDistance + 5, (SHORT)(11 * jDistance) + jDistance / 2 };
        SetConsoleCursorPosition(hOut, coord);
        cout << Player2Sym;
    }
}
void status(int p, int r, int NoofRounds, int& dice, int Player1CurrentPos, int roundnump1, int Player2CurrentPos, int roundnump2)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    r += 2;

    COORD coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "=======(CS-30)===== ";
    
    r += 1;//--------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Dice number : " << dice;
    r += 1;//-------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Player Number turn : " << pturn << endl;
    r += 1;//------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Total Rounds : " << NoofRounds;
    r += 1;//------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Player 1 round number : " << roundnump1;
    r += 1;//------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Player 2 round number : " << roundnump2;
    r += 1;//------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Player One symbol is :" << "*";
    r += 1;//------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Player One symbol is :" << "^";
    r += 1;//------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Position of Player 1:" << Player1CurrentPos;
    r += 1;//------
    coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);
    cout << "Position of Player 2:" << Player2CurrentPos;
}
void dicef(int& dice)
{
    srand(time(NULL));
    dice = rand() % 6 + 1;
    //if (pturn == 1) dice = 6;
    //if (pturn == 2) dice = 4;
}
void pLcheck(int& pturn, int& Player1CurrentPos, int& Player2CurrentPos, int dice, int NoofRounds, int& pwin, int& roundnump1, int& roundnump2, char Player1Sym, char Player2Sym, int p, int r)
{
    for (int v = 0; true; v++)
    {
        //----------------------------for last round/or Noofrounds are 1--------------------------------
        //for pos=>39 hardcoded values are used so it wont cause any trouble
  
        //------------------------------------Player 1--------------------------------------------------
        if (pturn == 1 && roundnump1 == NoofRounds)
        {
            if (Player1CurrentPos < 39)//for pos smaller than 38 a  normal functioning
            {
                Player1CurrentPos = Player1CurrentPos + dice;
                break;
            }
            if (Player1CurrentPos == 39) // 39
            {
                if (dice == 6) { pwin = 1;Player1CurrentPos=1; break; } //if dice is greater than req numb it will turn term to player2---same for all hardcodened below values
                if (dice == 5 || dice == 4 || dice == 3 || dice == 2 || dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 40)//40
            {
                if (dice == 6) { break; }
                if (dice == 5) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 4 || dice == 3 || dice == 2 || dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 41)//41
            {
                if (dice == 5 || dice == 6) { break; }
                if (dice == 4) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 3 || dice == 2 || dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 42)//42
            {
                if (dice == 5 || dice == 4 || dice == 6) { break; }
                if (dice == 3) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 2 || dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 43)//43
            {
                if (dice == 5 || dice == 4 || dice == 6 || dice == 3) { break; }
                if (dice == 2) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 44)//43
            {
                if (dice == 5 || dice == 4 || dice == 3 || dice == 2 || dice == 6) { break; }
                if (dice == 1) { pwin = 1; Player1CurrentPos = 1; break; }
            }

        }

        //------------------------------------Player 2-------------------------------------------------
        if (pturn == 2 && roundnump2 == NoofRounds)
        {
            //for values => 39 hardcoded vaules are used so it wont cause any problem
            if (Player2CurrentPos < 39)//for pos smaller than 38 normal functioning
            {
                Player2CurrentPos = Player2CurrentPos + dice;
                break;
            }
            if (Player2CurrentPos == 39) // 39
            {
                if (dice == 6) { pwin = 1; Player1CurrentPos = 1; break; } //it will turn term to next player 
                if (dice == 5 || dice == 4 || dice == 3 || dice == 2 || dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 40)//40
            {
                if (dice == 6) { break; }
                if (dice == 5) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 4 || dice == 3 || dice == 2 || dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 41)//41
            {
                if (dice == 5 || dice == 6) { break; }
                if (dice == 4) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 3 || dice == 2 || dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 42)//42
            {
                if (dice == 5 || dice == 4 || dice == 6) { break; }
                if (dice == 3) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 2 || dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 43)//43
            {
                if (dice == 5 || dice == 4 || dice == 3 || dice == 6) { break; }
                if (dice == 2) { pwin = 1; Player1CurrentPos = 1; break; }
                if (dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 44)//43
            {
                if (dice == 5 || dice == 4 || dice == 3 || dice == 2 || dice == 6) { break; }
                if (dice == 1) { pwin = 1; Player1CurrentPos = 1; break; }
            }

        }
        
        //----------------------------for middle orderd Rounds-----------------------------------------
       
        //----------------------------------Player 1---------------------------------------------------
        if (pturn == 1 && roundnump1 != NoofRounds)
        {
            //hardcoded values will set the player position to next round starting from ONE and INCREASE ROUND NUMBER by ONE
            if (Player1CurrentPos < 39)//for pos smaller than 38
            {
                Player1CurrentPos = Player1CurrentPos + dice;
                break;
            }
            if (Player1CurrentPos == 39) // 39
            {
                if (dice == 6) { Player1CurrentPos = 1; roundnump1++; break; }//will set pos to next round 
                if (dice == 1) { Player1CurrentPos = 6; roundnump1++; break; }//will set pos to next round 
                if (dice == 5 || dice == 4 || dice == 3 || dice == 2)         //simply move the player pos
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 40)//40
            {
                if (dice == 6) { Player1CurrentPos = 2; roundnump1++; break; }
                if (dice == 5) { Player1CurrentPos = 1; roundnump1++; break; }
                if (dice == 4 || dice == 3 || dice == 2 || dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 41)//41
            {
                if (dice == 5) { Player1CurrentPos = 2; roundnump1++; break; }
                if (dice == 6) { Player1CurrentPos = 3; roundnump1++; break; }
                if (dice == 4) { Player1CurrentPos = 1; roundnump1++; break; }
                if (dice == 3 || dice == 2 || dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 42)//42
            {
                if (dice == 4) { Player1CurrentPos = 2; roundnump1++; break; }
                if (dice == 5) { Player1CurrentPos = 3; roundnump1++; break; }
                if (dice == 6) { Player1CurrentPos = 4; roundnump1++; break; }
                if (dice == 3) { Player1CurrentPos = 1; roundnump1++; break; }
                if (dice == 2 || dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 43)//43
            {
                if (dice == 3) { Player1CurrentPos = 2; roundnump1++; break; }
                if (dice == 4) { Player1CurrentPos = 3; roundnump1++; break; }
                if (dice == 5) { Player1CurrentPos = 4; roundnump1++; break; }
                if (dice == 6) { Player1CurrentPos = 41; break; }//green snake round will rem same
                if (dice == 2) { Player1CurrentPos = 1; roundnump1++; break; }
                if (dice == 1)
                {
                    Player1CurrentPos = Player1CurrentPos + dice;
                    break;
                }
            }
            if (Player1CurrentPos == 44)//43
            {
                if (dice == 2) { Player1CurrentPos = 2; roundnump1++; break; }
                if (dice == 3) { Player1CurrentPos = 3; roundnump1++; break; }
                if (dice == 4) { Player1CurrentPos = 4; roundnump1++; break; }
                if (dice == 5) { Player1CurrentPos = 41; break; }//green snake round will remain same
                if (dice == 6) { Player1CurrentPos = 6; roundnump1++; break; }
                if (dice == 1) { Player1CurrentPos = 1; roundnump1++; break; }
            }
        }

        //----------------------------------Player 2---------------------------------------------------
        if (pturn == 2 && roundnump2 != NoofRounds)
        {
            if (Player2CurrentPos < 39)//for pos smaller than 38
            {
                Player2CurrentPos = Player2CurrentPos + dice;
                break;
            }
            if (Player2CurrentPos == 39) // 39
            {
                if (dice == 6) { Player2CurrentPos = 1; roundnump2++; break; }
                if (dice == 1) { Player2CurrentPos = 6; roundnump2++; break; }
                if (dice == 5 || dice == 4 || dice == 3 || dice == 2)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 40)//40
            {
                if (dice == 6) { Player2CurrentPos = 2; roundnump2++; break; }
                if (dice == 5) { Player2CurrentPos = 1; roundnump2++; break; }
                if (dice == 4 || dice == 3 || dice == 2 || dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 41)//41
            {
                if (dice == 5) { Player2CurrentPos = 2; roundnump2++; break; }
                if (dice == 6) { Player2CurrentPos = 3; roundnump2++; break; }
                if (dice == 4) { Player2CurrentPos = 1; roundnump2++; break; }
                if (dice == 3 || dice == 2 || dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 42)//42
            {
                if (dice == 4) { Player2CurrentPos = 2; roundnump2++; break; }
                if (dice == 5) { Player2CurrentPos = 3; roundnump2++; break; }
                if (dice == 6) { Player2CurrentPos = 4; roundnump2++; break; }
                if (dice == 3) { Player2CurrentPos = 1; roundnump2++; break; }
                if (dice == 2 || dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 43)//43
            {
                if (dice == 3) { Player2CurrentPos = 2; roundnump2++; break; }
                if (dice == 4) { Player2CurrentPos = 3; roundnump2++; break; }
                if (dice == 5) { Player2CurrentPos = 4; roundnump2++; break; }
                if (dice == 6) { Player2CurrentPos = 41; break; }//green snake round remains the same
                if (dice == 2) { Player2CurrentPos = 1; roundnump2++; break; }
                if (dice == 1)
                {
                    Player2CurrentPos = Player2CurrentPos + dice;
                    break;
                }
            }
            if (Player2CurrentPos == 44)//43
            {
                if (dice == 2) { Player2CurrentPos = 2; roundnump2++; break; }
                if (dice == 3) { Player2CurrentPos = 3; roundnump2++; break; }
                if (dice == 4) { Player2CurrentPos = 4; roundnump2++; break; }
                if (dice == 5) { Player2CurrentPos = 41; break; }//green snake round will remain same
                if (dice == 6) { Player2CurrentPos = 6; roundnump2++; roundnump2++; break; }
                if (dice == 1) { Player2CurrentPos = 1; roundnump2++; break; }
            }
        }
    }
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    r += 1;

    COORD coord = { (SHORT)p, (SHORT)r };
    SetConsoleCursorPosition(hOut, coord);

    system("pause");
    system("cls");
    DrawBoard();
    status(p, r, NoofRounds, dice, Player1CurrentPos, roundnump1, Player2CurrentPos, roundnump2);
    DrawPlayer1(Player1CurrentPos, Player1Sym);
    DrawPlayer2(Player2CurrentPos, Player2Sym);

}
void boxcheck(int& Player1CurrentPos, int& Player2CurrentPos, char color, int NoofRounds, int dice, int p, int r, char Player1Sym, char Player2Sym, int& roundnump1, int& pturn, int& roundnump2)
{
    int breaker = 0;  //breaker is initiated as zero resetting value
    for (int y = 0; y < 4; y++)
    {
            //-----------------------------------For green (SNAKE OR MOVING DOWN)------------------------------//
            for (int fr_rnd1 = 1; fr_rnd1 < 4; fr_rnd1++)  
            {
                //for green color round 1  as if in first round the players should move back 4 placecs so value is hardcoded for zeroth index and then for more than 1th it will use fr_rnd1
                //values for round of any player greater than 1 are hardcoded to move back to place 41 along with subtration in their round number
                if (pturn == 1 && Player1CurrentPos == arraygreen[0] && roundnump1 == 1) { Player1CurrentPos = Player1CurrentPos - 4; pturn = 2; breaker = 1; break; }
                if (pturn == 2 && Player2CurrentPos == arraygreen[0] && roundnump2 == 1) { Player2CurrentPos = Player2CurrentPos - 4; pturn = 1; breaker = 1; break; }
                if (pturn == 1 && Player1CurrentPos == arraygreen[0] && roundnump1 > 1) { Player1CurrentPos = 41;roundnump1--; pturn = 2; breaker = 1; break; }
                if (pturn == 2 && Player2CurrentPos == arraygreen[0] && roundnump2 > 1) { Player2CurrentPos = 41;roundnump2--; pturn = 1; breaker = 1; break; }
                if (pturn == 1 && Player1CurrentPos == arraygreen[fr_rnd1]) { Player1CurrentPos = Player1CurrentPos - 8; pturn = 2; breaker = 1; break; }
                if (pturn == 2 && Player2CurrentPos == arraygreen[fr_rnd1]) { Player2CurrentPos = Player2CurrentPos - 8; pturn = 1; breaker = 1; break; }
            }
            if (breaker == 1) { break; }//for breaking main loop 

            //-----------------------------------For Light Blue (Ladder OR MOVING up)--------------------------//
            for (int i = 0; i < 3; i++)//for last round we will not consider the 3rd index as last l.b will not be considered
            {
                if (pturn == 1 && Player1CurrentPos == arrayreward[i]) { Player1CurrentPos = Player1CurrentPos + 10; pturn = 2; breaker = 1; break; }
                if (pturn == 2 && Player2CurrentPos == arrayreward[i]) { Player2CurrentPos = Player2CurrentPos + 10; pturn = 1; breaker = 1; break; }
            }
            if (breaker == 1) { break; }//for breaking main loop

            //--CHECK for extra turn of opponent---
            if (pturn == 2 && swtch1 == 0)
            {
                system("cls");
                DrawBoard();
                status(p, r, NoofRounds, dice, Player1CurrentPos, roundnump1, Player2CurrentPos, roundnump2);
                DrawPlayer1(Player1CurrentPos, Player1Sym);
                DrawPlayer2(Player2CurrentPos, Player2Sym);
                temp1 = 10;
                pturn = 2; swtch1 = 1; break;
            }
            if (pturn == 1 && swtch1 == 0)
            {
                system("cls");
                DrawBoard();
                status(p, r, NoofRounds, dice, Player1CurrentPos, roundnump1, Player2CurrentPos, roundnump2);
                DrawPlayer1(Player1CurrentPos, Player1Sym);
                DrawPlayer2(Player2CurrentPos, Player2Sym);
                temp2 = 10;
                pturn = 1; swtch1 = 1; break;
            }

            //-----------------------------------For Extra turn of opponent-----------------------------------//
            for (int i = 0; i < 4; i++)
            {
                if ((pturn == 1 && Player1CurrentPos == arrayopprwrd[i]) && i != temp1) { pturn = 2; swtch1 = 0; temp1 = i; breaker = 1; break; }//here temp1 and temp2 will not let comparison with the same index for the next time so 
                if ((pturn == 2 && Player2CurrentPos == arrayopprwrd[i]) && i != temp2) { pturn = 1; swtch1 = 0; temp2 = i; breaker = 1; break; }//it will move easily without being repeated
            }
            if (breaker == 1) { break; }//for breaking main loop

            //-----------------------------------For Extra turn of Own-----------------------------------//
            //used inside so it will complete process here and will make game run efficiently
            for (int i = 0; i < 4; i++)
            {
                if ((pturn == 1 && Player1CurrentPos == arrayownrwrd[i]) && i != temp3)
                {
                    dicef(dice);
                    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    std::cout.flush();
                    r += 1;
                    COORD coord = { (SHORT)p, (SHORT)r };
                    SetConsoleCursorPosition(hOut, coord);
                    system("pause");
                    system("cls");
                    DrawBoard();
                    status(p, r, NoofRounds, dice, Player1CurrentPos, roundnump1, Player2CurrentPos, roundnump2);
                    DrawPlayer1(Player1CurrentPos, Player1Sym);
                    DrawPlayer2(Player2CurrentPos, Player2Sym);
                    Player1CurrentPos = Player1CurrentPos + dice;
                    breaker = 0;
                    break;
                }
                if ((pturn == 2 && Player2CurrentPos == arrayownrwrd[i]) && i != temp4)
                {
                    dicef(dice);
                    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    std::cout.flush();
                    r += 1;
                    COORD coord = { (SHORT)p, (SHORT)r };
                    SetConsoleCursorPosition(hOut, coord);
                    system("pause");
                    system("cls");
                    DrawBoard();
                    status(p, r, NoofRounds, dice, Player1CurrentPos, roundnump1, Player2CurrentPos, roundnump2);
                    DrawPlayer1(Player1CurrentPos, Player1Sym);
                    DrawPlayer2(Player2CurrentPos, Player2Sym);
                    Player2CurrentPos = Player2CurrentPos + dice;
                    breaker = 0;
                    break;
                }
            }
            if (breaker == 1) { break; }//for breaking main loop
            //---------for normal conditions
            if (pturn == 1 && breaker == 0) { pturn = 2; break; }
            if (pturn == 2 && breaker == 0) { pturn = 1; break; }
        
    }
    //-------------------------------------------------------------------for loop end-------------------------------------------------------------------------------------------------------------------
}
int main()
{
    char plyr1[100];//arrays for names of players
    char plyr2[100];
    cout << "Enter name of player 1 :";
    cin.getline(plyr1, 100);
    cout << "Enter name of player 2:";
    cin.getline(plyr2, 100);
    int p = 90, r;//p and r for cordinates of updating and swtch
    int NoofRounds = 0;//total rounds
    int roundnump1 = 1, roundnump2 = 1; //counter for rounds of player 1 and player 2
    cout << "Enter No of Rounds: ";
    cin >> NoofRounds;
    system("pause");//For starting of game
    int dice, pwin = 0;//pwin will act as a stopper for game and dice is for number
    int Player1CurrentPos = 1;
    int Player2CurrentPos = 1;
    char Player1Sym = '*';
    char Player2Sym = '^';
    for (int o = 0; pwin != 1; o++)
    {
        if (NoofRounds <= 0)
        {
            cout << "You have entered Invalid Round Number Please try again :";
            cin >> NoofRounds;
            system("pause");//For starting of game
            continue;
        }
        p = 90, r = 10;
        dicef(dice);
        static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        std::cout.flush();
        r += 1;
        COORD coord = { (SHORT)p, (SHORT)r };
        SetConsoleCursorPosition(hOut, coord);
        system("cls");
        DrawBoard();

        status(p, r, NoofRounds, dice, Player1CurrentPos, roundnump1, Player2CurrentPos, roundnump2);

        DrawPlayer1(Player1CurrentPos, Player1Sym);

        DrawPlayer2(Player2CurrentPos, Player2Sym);

        pLcheck(pturn, Player1CurrentPos, Player2CurrentPos, dice, NoofRounds, pwin, roundnump1, roundnump2, Player1Sym, Player2Sym, p, r);

        boxcheck(Player1CurrentPos, Player2CurrentPos, Color, NoofRounds, dice, p, r, Player1Sym, Player2Sym, roundnump1, pturn, roundnump2);
        
        if (pwin == 1)
        {
            r = r + 15;
            coord = { (SHORT)p, (SHORT)r };
            SetConsoleCursorPosition(hOut, coord);
            if (pturn == 1) 
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 2);
                pturn = 2; cout << plyr2 << " won, ";
                SetConsoleTextAttribute(h, 4);
                cout << plyr1 << " has lost the game,";
                SetConsoleTextAttribute(h, 3);
                cout << "better luck next time : ) "; break;
            }
            if (pturn == 2)
            {
                pturn = 1;
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 2);
                cout << plyr1 << " won and ";
                SetConsoleTextAttribute(h, 4);
                cout << plyr2 << " has lost the game,";
                SetConsoleTextAttribute(h, 3);
                cout<<"better luck next time : ) "; break;
            }
        }
    }
    return _getch();
}