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
    int nrOfGames;
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

int findUser(User listOfUsers[], int *pNrOfUsers, char userName[]) //return if the user is found
{
    for(int i = 0; i < (*pNrOfUsers); i++)
    {
        if(strcmp(listOfUsers[i].userName, userName) == 0)
        {
            return 1; //returns 1 when found
        }
    }
    return 0; //returns 0 when no user could be found
}

int returnUserIndex(User listOfUsers[], int *pNrOfUsers, char userName[]) //return the INDEX of the user it found
{
    for(int i = 0; i < (*pNrOfUsers); i++)
    {
        if(strcmp(listOfUsers[i].userName, userName) == 0)
        {
            return i;
        }
    }
    return (-1);
}

User createUser(char userName[]) //creates one instance of the struct of type user
{
    User user;
    strcpy(user.userName, userName);
    user.nrOfGames = 0;
    return user;
}

void registerUser(User listOfUsers[], int *pNrOfUsers) //checks whether user can be put into list
{
    while(1)
    {
        char registerName[NAMELENGTH];
        printf("Register new user (q to quit): ");
        fgets(registerName, sizeof(registerName), stdin);
        registerName[strlen(registerName) - 1] = '\0';
        if(strcmp(registerName, "q") == 0)
        {
            break;
        }
        else if(findUser(listOfUsers, pNrOfUsers, registerName) == 1) // user name already exists, try another one!
        {
            printf("User name exists! Please choose another.\n");
            continue;
        }
        else if(findUser(listOfUsers, pNrOfUsers, registerName) == 0) // did not find user, lets create one!
        {
            if((*pNrOfUsers >= MAXUSERS))
            {
                printf("The register is full!\n");
                continue;
            }
            listOfUsers[(*pNrOfUsers)] = createUser(registerName);
            (*pNrOfUsers)++;
        }
    }
}

void removeUser(User listOfUsers[], int *pNrOfUsers) // removes one user from the list
{
    while(1)
    {
        char registerName[NAMELENGTH];
        printf("Remove user (q to quit): ");
        fgets(registerName, sizeof(registerName), stdin);
        registerName[strlen(registerName) - 1] = '\0';
        if(strcmp(registerName, "q") == 0)
        {
            break;
        }
        else if(returnUserIndex(listOfUsers, pNrOfUsers, registerName) == (-1)) // user name does not exist, try another one!
        {
            printf("User do not exist! Please choose another.\n");
            continue;
        }
        else if(returnUserIndex(listOfUsers, pNrOfUsers, registerName) != (-1)) // found user, lets delete them!
        {
            int j = returnUserIndex(listOfUsers, pNrOfUsers, registerName); //TODO: Add confirmation option when user has registered games and scores!!!
            for(j; j < MAXUSERS; j++)
            {
                User temp;
                temp = listOfUsers[j];
                listOfUsers[j] = listOfUsers[j + 1];
                listOfUsers[j + 1] = temp;
            }
            (*pNrOfUsers)--;
        }
    }
}

void adminMenu(User listOfUsers[], int *pNrOfUsers) //administrative menu
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
            case 1: //add user
                registerUser(listOfUsers, pNrOfUsers);
                break;
            case 2: //remove user
                removeUser(listOfUsers, pNrOfUsers);
                break;
            case 3: //print all users
                if((*pNrOfUsers) == 0)
                {
                    printf("No users registrered\n");
                }
                else
                {
                    printf("Users:\n_____________________________________\n");
                    for (int i = 0; i < (*pNrOfUsers); i++)
                    {
                        printf("%s\n", listOfUsers[i].userName);
                    }
                    printf("\n");
                }
                break;
            case 4: //print all users and ratings
                break;
            case 5: //exit
                exit = 1;
                break;
            default:
                break;
                exit = 1;
        }
    }
}

void registerGame(User listOfUsers[], int userIndex)
{
    char boardGameName[NAMELENGTH];
    int score;
    int gameAlreadyAdded;
    while(1)
    {
        if(listOfUsers[userIndex].nrOfGames >= MAXUSERGAMES)
        {
            printf("Your game register is full.\n");
            break;
        }
        printf("Register new boardgame (q to quit): ");
        gameAlreadyAdded = 0;
        fgets(boardGameName, sizeof(boardGameName), stdin);
        boardGameName[strlen(boardGameName) - 1] = '\0';
        if(strcmp(boardGameName, "q") == 0)
        {
            break; //we are quitting
        }
        else
        {  
            for(int i = 0; i <= (listOfUsers[userIndex].nrOfGames); i++)
            {
                if(strcmp(boardGameName, listOfUsers[userIndex].gamesList[i].gameName) == 0)
                {
                    printf("Boardgame already added.\n");
                    gameAlreadyAdded = 1;
                    break;
                }
            }
            if(gameAlreadyAdded == 0)
            {
                Game game;
                strcpy(game.gameName, boardGameName);
                while(1)
                {
                    printf("Rating (1-10): "); //we cannot register a game if we cant assign a grade / rating to it
                    scanf("%d%*c", &score);
                    if(score > 10 || score < 1)
                    {
                       printf("Illegal value!\n");
                    }
                    else
                    {
                        game.grade = score;
                        break;
                    }
                }
                listOfUsers[userIndex].gamesList[listOfUsers[userIndex].nrOfGames] = game; //assign the game and up the element amount
                (listOfUsers[userIndex].nrOfGames)++; 
            }
        }
    }
}

void printGames(User listOfUsers[], int userIndex)
{
    if(listOfUsers[userIndex].nrOfGames == 0)
    {
        printf("No games registered\n");
    }
    else
    {
        int dynamicLength = 0;
        for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++)
        {
            if(strlen(listOfUsers[userIndex].gamesList[i].gameName) > dynamicLength)
            {
                dynamicLength = strlen(listOfUsers[userIndex].gamesList[i].gameName);
            }
        }
        for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++)
        {
            printf("%-*s %d\n", dynamicLength, listOfUsers[userIndex].gamesList[i].gameName, listOfUsers[userIndex].gamesList[i].grade);
        }
    }
}

void searchGame(User listOfUsers[], int userIndex)
{
    char searchWord[NAMELENGTH];
    Game searchArray[MAXUSERGAMES];
    int newArrayIndex = 0;
    while(1)
    {
        printf("Search (q to quit): ");
        fgets(searchWord, sizeof(searchWord), stdin);
        searchWord[strlen(searchWord) - 1] = '\0'; //standard input where we clear newline character
        if(strcmp(searchWord, "q") == 0)
        {
            break; //we quit on q
        }
        for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++) // we start searching for matching strings
        {
            if(strstr(listOfUsers[userIndex].gamesList[i].gameName, searchWord) != NULL)
            {
                strcpy(searchArray[newArrayIndex].gameName, listOfUsers[userIndex].gamesList[i].gameName);
                searchArray[newArrayIndex].grade = listOfUsers[userIndex].gamesList[i].grade;
                newArrayIndex++;
            }
        }
        int dynamicLength = 0;
        for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++)
        {
            if(strlen(searchArray[i].gameName) > dynamicLength)
            {
                dynamicLength = strlen(searchArray[i].gameName);
            }
        }
        for(int i = 0; i < newArrayIndex; i++)
        {
            printf("%-*s %d\n", dynamicLength, searchArray[i].gameName, searchArray[i].grade);
        }
        newArrayIndex = 0;
    }
}

void deleteGame(User listOfUsers[], int userIndex, int gameIndex) //rewrite of the removeUser code retrofitted for a game
{
    int j = gameIndex;
    for(j; j < listOfUsers[userIndex].nrOfGames; j++)
    {
        Game temp;
        temp = listOfUsers[userIndex].gamesList[j];
        listOfUsers[userIndex].gamesList[j] = listOfUsers[userIndex].gamesList[j + 1];
        listOfUsers[userIndex].gamesList[j + 1] = temp;
    }
    (listOfUsers[userIndex].nrOfGames)--;
}

void removeGame(User listOfUsers[], int userIndex)
{
    char searchWord[NAMELENGTH];
    char choice;
    Game searchArray[MAXUSERGAMES];
    int removeGameIndex;
    int newArrayIndex = 0;
    while(1)
    {
        printf("Search boardgame to remove (q to quit): ");
        fgets(searchWord, sizeof(searchWord), stdin);
        searchWord[strlen(searchWord) - 1] = '\0'; //standard input where we clear newline character
        if(strcmp(searchWord, "q") == 0)
        {
            break; //we quit on q
        }
        for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++) // we start searching for matching strings
        {
            if(strstr(listOfUsers[userIndex].gamesList[i].gameName, searchWord) != NULL) //check that there actually is a game matched
            {
                strcpy(searchArray[newArrayIndex].gameName, listOfUsers[userIndex].gamesList[i].gameName); //my new array that I keep seperately from the players
                searchArray[newArrayIndex].grade = listOfUsers[userIndex].gamesList[i].grade;              //so that I can later decide the length of the longest gamename shown in the search (not necessarily in the players own gameslist because they are separate)
                removeGameIndex = i; //this tells you what position in the player's gamelist the gamelist was so that we can later remove
                newArrayIndex++; //used in the for loop that displays the amount of matches you got on your search
            }
        }
        int dynamicLength = 0; //decide the lenght of the string display in the cmd
        for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++)
        {
            if(strlen(searchArray[i].gameName) > dynamicLength)
            {
                dynamicLength = strlen(searchArray[i].gameName); //process of elimination
            }
        }
        for(int i = 0; i < newArrayIndex; i++)
        {
            printf("%-*s %d\n", dynamicLength, searchArray[i].gameName, searchArray[i].grade); //displays the matches
        }
        if(newArrayIndex != 1)
        {
            printf("You did not find one unique boardgame.\n");
        }
        else if(newArrayIndex == 1)
        {
            while(1)
            {
                printf("Do you want to remove this game (y/n): "); //checks whether you really want to delete the game
                scanf("%c%*c", &choice);
                if(choice == 'n')
                {
                    break;
                }
                else if(choice == 'y')
                {
                    deleteGame(listOfUsers, userIndex, removeGameIndex); //the removeGameIndex is the original element position of the game in the players
                    break;                                               //gamelist so that we can remove it AFTER formatting the output
                }
            }
        }
        newArrayIndex = 0;
    }
}

void userMenu(User listOfUsers[], char userName[], int userIndex)
{
    int userChoice;
    int exit = 0;
    while(!exit)
    {
        printf("%s's boardgames\n", userName);
        printf("          1) Print games\n");
        printf("          2) Add game\n");
        printf("          3) Search games\n");
        printf("          4) Remove game\n");
        printf("          5) Exit\n");
        printf("Choose: ");
        scanf("%d%*c", &userChoice);
        switch(userChoice)
        {
            case 1: //print games
                printGames(listOfUsers, userIndex);
                break;
            case 2: //add a game
                registerGame(listOfUsers, userIndex);
                break;
            case 3: //search for games
                searchGame(listOfUsers, userIndex);
                break;
            case 4: //remove a game
                removeGame(listOfUsers, userIndex);
                break;
            case 5: //exit
                exit = 1;
                break;
            default:
                break;
                exit = 1;
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
    int indexUser;

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
        else if(findUser(listOfUsers, &nrOfUsers, userName) == 0) //no matching user found
        {
            printf("User does not exist\n");
        } 
        else //we are assuming the admin typed in a username and thus we'll enter that profile
        {
            userMenu(listOfUsers, userName, returnUserIndex(listOfUsers, &nrOfUsers, userName));
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