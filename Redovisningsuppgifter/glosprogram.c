#include <stdio.h>
#include <string.h>

#define SIZE 20
#define WORDLIM 20

void printWordpairs(int nrOfWordPair, char arrSE[][WORDLIM], char arrEN[][WORDLIM])
{
    if(nrOfWordPair == 0)
    {
        printf("Gloslistan ar tom\n");
    }
    else if(nrOfWordPair > 0)
    {
        for(int i = 0; i < nrOfWordPair; i++)
        {
            printf("%s - %s\n", arrSE[i], arrEN[i]);
        }
    }
}

void addWordpairs(int *pNrOfWordPair, char arrSE[][WORDLIM], char arrEN[][WORDLIM])
{
    char tempWord[WORDLIM];
    for(int i = *pNrOfWordPair; i < SIZE; i++)
    {
        printf("Svenska: ");
        scanf("%s", tempWord);

        if(tempWord[0] == 'q') break;

        strcpy(arrSE[i], tempWord);
        printf("Engelska: ");
        scanf("%s", tempWord);
        strcpy(arrEN[i], tempWord);
        
        (*pNrOfWordPair)++;
    }
}

void deleteWordpairs(int *pNrOfWordPair)
{
    printf("Raderade ord\n");
    *pNrOfWordPair = 0;
}

int main()
{
    int nrOfWordPair = 0;
    int *pNrOfWordPair;
    pNrOfWordPair = &nrOfWordPair;
    int choice = 0;

    char arrGlosor[SIZE][WORDLIM];
    char arrWords[SIZE][WORDLIM];

    while(1)
    {
        printf("(1) Skriva in (2) Skriva ut (3) Radera (4)Avsluta: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addWordpairs(pNrOfWordPair, arrGlosor,arrWords);
                break;
            case 2:
                printWordpairs(nrOfWordPair, arrGlosor, arrWords);
                break;
            case 3:
                deleteWordpairs(pNrOfWordPair);
                break;
            case 4:
                printf("Avslutar");
                return 0;
        }
    }
    return 0;
}