#include <stdio.h>

void ritaTriangel(int sida)
{
    for(int i = 0; i < sida; i++)
    {
        for(int j = 0; j < sida; j++)
        {
            if((j <= i) && (j == 0 || i == (sida - 1)) || i == j)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int sida;
    while(1)
    {
        printf("Ange sida (2-30): ");
        scanf("%d%*c", &sida);
        if(sida < 2 || sida > 30)
        {
            printf("Felaktigt val.\n");
        }
        else if(sida >= 2 && sida <= 30)
        {
            ritaTriangel(sida);
            printf("Avslutar\n");
            break;
        }
    }
    return 0;
}