#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 15

int MovementCheck(int posX, int posY, char board[LENGTH][LENGTH])
{
    int up = 0, right = 0, down = 0, left = 0;
    if(board[posY-1][posX] == '.' && (posY - 1) >= 0)
    {
        up = 1;
    }
    if(board[posY][posX+1] == '.' && (posX + 1) <= LENGTH)
    {
        right = 1;
    }
    if(board[posY+1][posX] == '.' && (posY + 1) <= LENGTH)
    {
        down = 1;
    }
    if(board[posY][posX-1] == '.' && (posX - 1) >= 0)
    {
        left = 1;
    }
    if((up + right + down + left) == 0)
    {
        return 5;
    }
    int randomDir = rand()%(up + right + down + left)+1;
    if(randomDir <= up)
    {
        return 0;
    }
    if(randomDir <= up + right)
    {
        return 1;
    }
    if(randomDir <= up + right + down)
    {
        return 2;
    }
    if(randomDir <= up + right + down + left)
    {
        return 3;
    }

}

int main()
{

    char walkerLetter = 'A';

    srand(time(NULL));

    char board[LENGTH][LENGTH];

    for(int i = 0; i < LENGTH; i++)
    {

        for(int j = 0; j < LENGTH; j++)
        {
            board[i][j] = '.';
        }
        
    }   

    int posX = 0, posY = 0;
    int movementCheckResult;

    board[posX][posY] = walkerLetter;

    while(walkerLetter != '~')
    {
        movementCheckResult = MovementCheck(posX, posY, board);
        walkerLetter++;
        if(movementCheckResult == 5)
        {
            break;
        }
        switch (movementCheckResult)
        {
        case 0:

            board[posY-1][posX] = walkerLetter;
            posY -= 1;
            break;
        case 1:
        
            board[posY][posX+1] = walkerLetter;
            posX += 1;
            break;
        case 2:

            board[posY+1][posX] = walkerLetter;
            posY += 1;
            break;
        case 3:

            board[posY][posX-1] = walkerLetter;
            posX -= 1;
            break;
        }
        
    }
    
    for(int i = 0; i < LENGTH; i++)
    {

        for(int j = 0; j < LENGTH; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;

}