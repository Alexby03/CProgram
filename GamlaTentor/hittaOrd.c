#include <stdio.h>
#include <string.h>

#define MAXWORDS 20
#define MAXLENGTH 30

int inputWords(char wordList[MAXWORDS][MAXLENGTH], char word[MAXLENGTH], int *pNrOfWords)
{
    int isFirstWordAsterisk = 1;
    printf("Ange ord avsluta med *: ");
    for(int i = (*pNrOfWords); i < MAXWORDS; i++)
    {
        scanf("%s%*c", word);
        strcpy(wordList[i], word);
        if(wordList[i][0] == '*' && isFirstWordAsterisk == 1)
        {
            printf("Avslutar\n");
            return 0;
        } 
        else
        {
            isFirstWordAsterisk = 0;
        }
        if(strcmp(word, "*") == 0)
        {
            break;
        }
        (*pNrOfWords)++;
    }
    
    return 1;
}

void findWordsByLetter(char wordList[MAXWORDS][MAXLENGTH], char letter, int *pNrOfWords)
{
    while(1)
    {
        printf("Ange bokstav (* for nya ord): ");
        scanf("%c%*c", &letter);
        if(letter == '*')
        {
            return;
        }
        for(int i = 0; i < (*pNrOfWords); i++)
        {
            if(wordList[i][0] == letter)
            {
                printf("%s ", wordList[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    char wordList[MAXWORDS][MAXLENGTH];
    char word[MAXLENGTH];
    char letter;
    int nrOfWords = 0;
    while(1)
    {
        if(inputWords(wordList, word, &nrOfWords) == 0) break;
        findWordsByLetter(wordList, letter, &nrOfWords);
    }
    return 0;
}