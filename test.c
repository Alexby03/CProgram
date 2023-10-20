#include <stdio.h>
#include <string.h>
#define MAXNROFWORDS 21
#define MAXCHAR 31

void printWords(char words[][MAXCHAR], int nrOfWords);
int readWords(char words[][MAXCHAR], int* pNrOfWords);

int main(){
    char words[MAXNROFWORDS][MAXCHAR];
    int nrOfWords = 0;
    while(1){
        if(!readWords(words,&nrOfWords)) break;
        printWords(words,nrOfWords);
    }
    printf("Avslutar\n");
    return 0;
}

int readWords(char words[][MAXCHAR], int* pNrOfWords){
    int quit = 0;
    printf("Ange ord avsluta med *: ");
    while((*pNrOfWords)<MAXNROFWORDS){
        scanf(" %s",words[*pNrOfWords]);
        if(strcmp(words[*pNrOfWords],"*") == 0) break;
        (*pNrOfWords)++;
        quit = 1;
    }
    return quit;
}

void printWords(char words[][MAXCHAR], int nrOfWords){
    char firstLetter;
    while(1){
        printf("Ange bokstav (* for nya ord): ");
        scanf(" %c",&firstLetter);
        if(firstLetter == '*') break;
        for(int i=0;i<nrOfWords;i++){
            if(words[i][0]==firstLetter) printf("%s ",words[i]);
        }
        printf("\n");
    }
}