#include <stdio.h>
#include <string.h>

#define NAMELENGTH 40 //no spaces, and no checking
#define MAXUSERGAMES 20 //need checking
#define MAXUSERS 30 //need checking

struct game
{
    char gameName[NAMELENGTH];
    int grade;
};
typedef struct game Game;

struct user
{
    char userName[NAMELENGTH];
    int nrOfGames; //can not initialize?
    Game gamesList[MAXUSERGAMES];
};
typedef struct user User;

int main() 
{
    Game chess;
    strcpy(chess.gameName, "Chess");
    chess.grade = 2;
    Game golf;
    strcpy(golf.gameName, "Golf");
    golf.grade = 0;
    User listOfPlayers[MAXUSERS];
    User Pablo;
    strcpy(Pablo.userName, "PABLO");
    Pablo.nrOfGames = 2;
    Pablo.gamesList[0] = chess;
    Pablo.gamesList[1] = golf;
    listOfPlayers[24] = Pablo;
    
    return 0;
}
