#include <stdio.h>
#include <string.h>

//alla namn på spelare och spel ska va ett enda ord

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

void readFromFile(char fileName[])
{
    FILE *fp; 
    fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        //start from zero and WRITE to file at the end. Create a new filed called what the user typed in.
        fclose(fp);
    }
    else
    {
        //start to read from the file that exists.
    }
}

int findUser(User listOfUsers[], int *pNrOfUsers, char userName[]) //return the INDEX of the user it found
{
    for(int i = 0; i < (*pNrOfUsers); i++)
    {
        if(strcmp(listOfUsers[i].userName, userName) == 0)
        {
            printf("We found %s", userName);
            return i;
        }
    }
    printf("User does not exist\n");
}

int main()
{
    printf("Welcome to boardgame ratings.\n");
    printf("Which file do you want to use: ");

    char fileName[NAMELENGTH];
    char userName[NAMELENGTH];
    User listOfUsers[MAXUSERS];
    int nrOfUsers = 0;

    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';
    
    readFromFile(fileName);

    while(1)
    {
        printf("Please enter user name, admin or quit: ");
        fgets(userName, sizeof(userName), stdin);
        userName[strlen(userName) - 1] = '\0';
        if(strcmp(userName, "admin") == 0)
        {
            printf("Administration");
        } 
        else if(strcmp(userName, "quit") == 0)
        {
            //stop
            return 0;
        } else
        {
            findUser(listOfUsers, &nrOfUsers, userName);
        }
        
    }
    
    //ange fil
        //finns inte fil starta blankt
            //bara kunna logga in som admin

    //Logga in som admin
        //add / remove user
    
    //logga in som user
        //add / remove games and grade



    //spara all data i en fil vid avslutning
    return 0;
}