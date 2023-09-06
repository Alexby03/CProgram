#include <stdio.h>

void DrawSticks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("|");
    }
    printf("\n");
}

int PCtake(int nrOfSticks)
{
    if(nrOfSticks % 4 == 0)
    {
        return 1;
    } else {
        return (nrOfSticks % 4);
    }
}

int main()
{
    int nrOfSticks = 15;
    int playerTake;
    int playerLast;

    printf("Valkommen till tandsticksspelet.");
    DrawSticks(nrOfSticks);
    do
    {
        printf("Hur manga stickor vill du ta? (1-3) ");
        scanf("%d", &playerTake);
        nrOfSticks -= playerTake;
        playerLast = 1;
        if (nrOfSticks <= 0)
        {
            break;
        }
        DrawSticks(nrOfSticks);
        if (nrOfSticks > 0)
        {
            printf("Datorn tar %d stickor.\n", PCtake(nrOfSticks));
            nrOfSticks -= PCtake(nrOfSticks);
            playerLast = 0;
        }
        if (nrOfSticks <= 0)
        {
            break;
        }
        DrawSticks(nrOfSticks);

    } while (nrOfSticks > 0);

    if (playerLast)
    {
        printf("Du vann!");
    } else {
        printf("Datorn vann.");
    }
    
    return 0;
}