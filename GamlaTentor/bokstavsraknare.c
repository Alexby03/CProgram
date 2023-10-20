#include <stdio.h>
#include <string.h>

#define MAX 100



int main()
{
    char mening[MAX];
    char bokstav;
    int antalBokstaver = 0;
    int count = 0;
    printf("Ange mening: ");
    fgets(mening, sizeof(mening), stdin);
    mening[strlen(mening) - 1] = '\0';

    while(bokstav != '*')
    {
        printf("Ange bokstav att rakna (* avslutar): ");
        scanf("%c%*c", &bokstav);
        while(mening[count++] != '\0')
        {
            if(mening[count] == bokstav)
            {
                antalBokstaver++;
            }
        }
        printf("Det finns %d stycken %c i meningen.\n", antalBokstaver, bokstav);
        antalBokstaver = 0;
        count = 0;
    }
    printf("Avslutar\n");

    return 0;
}