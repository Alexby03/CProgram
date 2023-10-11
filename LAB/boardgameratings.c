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

/*    ---    funktioner   ---   */

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

User createUser(char userName[], int nrOfGames) // maybe we'll use the nrOfGames argument later?
{
    User user;
    strcpy(user.userName, userName);
    user.nrOfGames = nrOfGames;
    user.gamesList;
    for(int i = 0; i < (MAXUSERGAMES); i++)
    {
        user.gamesList[i].grade = 0;
        strcpy(user.gamesList[i].gameName, "temp");
    }
    return user;
}

User addUser(User listOfUsers[], int *pNrOfUsers)
{
    char registerName[NAMELENGTH];
    int userExists = 0;
    do
    {
        printf("Register new user (q to quit): ");
        fgets(registerName, sizeof(registerName), stdin);
        registerName[(strlen(registerName)) - 1] = '\0';

        for(int i = 0; i < (*pNrOfUsers); i++) //checks if username given is already in the list
        {   
            if(strcmp(registerName, listOfUsers[i].userName) == 0)
            {
                printf("User name exists! Please choose another.\n");
                userExists = 1; //this skips the registering part
            }
        }
        if((*pNrOfUsers) >= MAXUSERS) //checks if we have exceeded the limit of the user list
        {
            printf("The register is full!");
            userExists = 1; //this skips the registering part
        }
        if(userExists == 0) //lets create a user
        {
            User createdUser;
            createdUser = createUser(registerName, 0);
            listOfUsers[(*pNrOfUsers)] = createdUser;
            (*pNrOfUsers)++;
        }
    } while (strcmp(registerName, "q") != 0);
}

void adminMenu(User listOfUsers[], int *pNrOfUsers)
{
    int adminChoice;
    int exit = 0;
    while(!exit)
    {
        printf("Administration\n");
        printf("          1) Add user\n");
        printf("          2) Remove user\n");
        printf("          3) Print all users\n");
        printf("          4) Print all users and all their ratings\n");
        printf("          5) Exit\n");
        printf("Choose: ");
        scanf("%d%*c", &adminChoice);
        switch(adminChoice)
        {
            case 1:
                listOfUsers[(*pNrOfUsers)] = addUser(listOfUsers, pNrOfUsers);
                break;
            case 2:
                //remove user
                break;
            case 3:
                //print all users
                for (int i = 0; i < (*pNrOfUsers) - 1; i++)
                    {
                        printf("%s\n", listOfUsers[i].userName);
                    }
                break;
            case 4:
                //print all users and ratings
                break;
            case 5:
                //exit
                exit = 1;
                break;
            default:
                break;
        }
    }
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
    
    //readFromFile(fileName);

    while(1)
    {
        printf("Please enter user name, admin or quit: ");
        fgets(userName, sizeof(userName), stdin);
        userName[strlen(userName) - 1] = '\0';
        if(strcmp(userName, "a") == 0) //temporarily changed "admin" to "a" for debug workflow purposes.
        {
            adminMenu(listOfUsers, &nrOfUsers); //enter admin menu
        } 
        else if(strcmp(userName, "quit") == 0)
        {
            return 0; //we are quitting the program
        } 
        else
        {
            findUser(listOfUsers, &nrOfUsers, userName); //we search for a user since the admin typed in a userName (allegedly)
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