#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

struct searchGameIndex
{
    int nrOfMatches;
    int originalIndex;
};
typedef struct searchGameIndex SearchGameIndex;

/*    ---    funktioner   ---   */

void readFromFile(FILE *fp, char fileName[], User listOfUsers[], int *pNrOfUsers)
{
    fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        //start from zero and WRITE to file at the end. Create a new filed called what the user typed in.
    }
    else
    {
        fscanf(fp, "%d\n", pNrOfUsers);
        for(int i = 0; i < (*pNrOfUsers); i++)
        {
            fscanf(fp, "%s %d", listOfUsers[i].userName, &listOfUsers[i].nrOfGames);
            for(int j = 0; j < listOfUsers[i].nrOfGames; j++)
            {
                fscanf(fp, "%s %d", listOfUsers[i].gamesList[j].gameName, &listOfUsers[i].gamesList[j].grade);
            }
        }
        fclose(fp);
    }
}

void writeToFile(FILE *fp, char fileName[], User listOfUsers[], int *pNrOfUsers)
{
    fp = fopen(fileName, "w");
    fprintf(fp, "%d\n", (*pNrOfUsers));
    for(int i = 0; i < (*pNrOfUsers); i++)
    {
        fprintf(fp, "%s %d\n", listOfUsers[i].userName, listOfUsers[i].nrOfGames);
        for(int j = 0; j < (listOfUsers[i].nrOfGames); j++)
        {
            fprintf(fp, "%s %d\n", listOfUsers[i].gamesList[j].gameName, listOfUsers[i].gamesList[j].grade);
        }
    }
    fclose(fp);
}

int findUser(User listOfUsers[], int *pNrOfUsers, char userName[]) 
{
    for(int i = 0; i < (*pNrOfUsers); i++)
    {
        if(strcmp(listOfUsers[i].userName, userName) == 0)
        {
            return i; //return the INDEX of the user it found
        }
    }
    return (-1); //returns -1 when no user could be found
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
        int userNameExists;
        printf("Register new user (q to quit): ");
        fgets(registerName, sizeof(registerName), stdin);
        registerName[strlen(registerName) - 1] = '\0';
        if(strcmp(registerName, "q") == 0)
        {
            break;
        }
        userNameExists = findUser(listOfUsers, pNrOfUsers, registerName);
        if(userNameExists != (-1)) // user name already exists, try another one!
        {
            printf("User name exists! Please choose another.\n");
            continue;
        }
        else if(userNameExists == (-1)) // did not find user, lets create one!
        {
            if((*pNrOfUsers >= MAXUSERS))
            {
                printf("The register is full!\n");
                continue;
            }
            listOfUsers[(*pNrOfUsers)] = createUser(registerName);
            (*pNrOfUsers)++;
            for(int j = 0; j < (*pNrOfUsers); j++)
            {
                for(int i = 0; i < (*pNrOfUsers) - 1; i++)
                {
                if(strcmp(listOfUsers[i].userName, listOfUsers[i + 1].userName) > 0) //checks if the element before the other has a name that is lexicographically larger, and then moves it down the list.
                {
                    User temp = listOfUsers[i];
                    listOfUsers[i] = listOfUsers[i + 1];
                    listOfUsers[i + 1] = temp;
                }
                }
            }
        }
    }
}

void removeUser(User listOfUsers[], int *pNrOfUsers) // removes one user from the list
{
    char registerName[NAMELENGTH];
    int userIndex;
    char choice;
    int continueLoop = 0;
    while(1)
    {
        
        printf("Remove user (q to quit): ");
        fgets(registerName, sizeof(registerName), stdin);
        registerName[strlen(registerName) - 1] = '\0';
        if(strcmp(registerName, "q") == 0)
        {
            break;
        }
        userIndex = findUser(listOfUsers, pNrOfUsers, registerName);
        if(userIndex == (-1)) // user name does not exist, try another one!
        {
            printf("User do not exist! Please choose another.\n");
            continue;
        }
        else if(userIndex != (-1)) // found user, lets delete them!
        {
            if(listOfUsers[userIndex].nrOfGames > 0)
            {
                printf("Warning: User has rated games.\n");
                while(1)
                {
                    printf("Do you still want to remove %s (y/n)? ", listOfUsers[userIndex].userName);
                    scanf("%c%*c", &choice);
                    if(choice == 'n')
                    {
                        continueLoop = 1;
                        break;
                    }
                    else if(choice == 'y')
                    {
                        break;
                    }
                }

            }
            if(continueLoop == 0)
            {
                int i = userIndex;
                for(i; i < ((*pNrOfUsers) - 1); i++)
                {
                    listOfUsers[i] = listOfUsers[i + 1];
                }
                (*pNrOfUsers)--;
                printf("Removed\n");
            }
        }
    }
}

int getStringLength(User listOfUsers[], int userIndex)
{
    int dynamicLength = 0;
    for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++)
    {
        if(strlen(listOfUsers[userIndex].gamesList[i].gameName) > dynamicLength)
        {
            dynamicLength = strlen(listOfUsers[userIndex].gamesList[i].gameName);
        }
    }
    return dynamicLength;
}

void printUserRatings(User listOfUsers[], int *pNrOfUsers)
{
    int dynamicLength;
    if((*pNrOfUsers) == 0)
    {
        printf("No users registrered\n");
    }
    else
    {
        for(int i = 0; i < ((*pNrOfUsers) - 1); i++)
        {
            if(getStringLength(listOfUsers, i) < getStringLength(listOfUsers, (i + 1)))
            {
                dynamicLength = getStringLength(listOfUsers, (i + 1));
            }
        }
        printf("Users and boardgames:\n_____________________________________\n");
        for(int i = 0; i < (*pNrOfUsers); i++) //here we just print out the ratings and game names, and nothing if the user has nothing registered
        {
            printf("%s\n", listOfUsers[i].userName);
            if(listOfUsers[i].nrOfGames == 0)
            {
                printf("        No games registrered\n");
                continue;
            }
            for(int j = 0; j < listOfUsers[i].nrOfGames; j++)
            {
                printf("        %-*s %d\n", dynamicLength, listOfUsers[i].gamesList[j].gameName, listOfUsers[i].gamesList[j].grade);
            }
        }
        printf("\n");
    }
}

void printUsers(User listOfUsers[], int *pNrOfUsers)
{
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
}

void adminMenu(User listOfUsers[], int *pNrOfUsers) //administrative menu
{
    char adminChoice[NAMELENGTH];
    int atoiInteger;
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
        fgets(adminChoice, sizeof(adminChoice), stdin);
        adminChoice[strlen(adminChoice) - 1] = '\0';
        atoiInteger = atoi(adminChoice);
        if(atoiInteger == 0)
        {
            printf("Please enter a valid choice.\n");
            continue;
        }
        switch(atoiInteger)
        {
            case 1: //add user
                registerUser(listOfUsers, pNrOfUsers);
                break;
            case 2: //remove user
                removeUser(listOfUsers, pNrOfUsers);
                break;
            case 3: //print all users
                printUsers(listOfUsers, pNrOfUsers);
                break;
            case 4: //print all users and ratings
                printUserRatings(listOfUsers, pNrOfUsers);
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
    int dynamicLength;
    if(listOfUsers[userIndex].nrOfGames == 0)
    {
        printf("No games registered\n");
    }
    else
    {
        dynamicLength = getStringLength(listOfUsers, userIndex);
        for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++)
        {
            printf("        %-*s %d\n", dynamicLength, listOfUsers[userIndex].gamesList[i].gameName, listOfUsers[userIndex].gamesList[i].grade);
        }
    }
}

SearchGameIndex searchDisplayGames(User listOfUsers[], char searchWord[], int userIndex)
{
    Game searchArray[MAXUSERGAMES];
    SearchGameIndex searchGameInfo;
    int newArrayIndex = 0;
    int dynamicLength;
    int originalIndex;
    for(int i = 0; i < listOfUsers[userIndex].nrOfGames; i++) // we start searching for matching strings
    {
        if(strstr(listOfUsers[userIndex].gamesList[i].gameName, searchWord) != NULL)
        {
            strcpy(searchArray[newArrayIndex].gameName, listOfUsers[userIndex].gamesList[i].gameName);
            searchArray[newArrayIndex].grade = listOfUsers[userIndex].gamesList[i].grade;
            originalIndex = i;
            newArrayIndex++;
        }
    }
    dynamicLength = getStringLength(listOfUsers, userIndex); //we decide the proper formatting length for the string of the game names
    for(int i = 0; i < newArrayIndex; i++) //we print out the scores accordingly with proper formattings
    {
        printf("%-*s %d\n", dynamicLength, searchArray[i].gameName, searchArray[i].grade);
    }
    searchGameInfo.nrOfMatches = newArrayIndex;
    searchGameInfo.originalIndex = originalIndex;
    return searchGameInfo; //we return HOW many games we found with your searchword
}

void searchGame(User listOfUsers[], int userIndex)
{
    char searchWord[NAMELENGTH];
    if(listOfUsers[userIndex].nrOfGames == 0)
    {
        printf("No games registrered\n");
        return;
    }
    while(1)
    {
        printf("Search (q to quit): ");
        fgets(searchWord, sizeof(searchWord), stdin);
        searchWord[strlen(searchWord) - 1] = '\0'; //standard input where we clear newline character
        if(strcmp(searchWord, "q") == 0)
        {
            break; //we quit on q
        }
        else
        {
            searchDisplayGames(listOfUsers, searchWord, userIndex);
        }
    }
}

void deleteGame(User listOfUsers[], int userIndex, int gameIndex) //rewrite of the removeUser function retrofitted for a game
{
    int i = gameIndex;
    for(i; i < (listOfUsers[userIndex].nrOfGames - 1); i++)
    {
        listOfUsers[userIndex].gamesList[i] = listOfUsers[userIndex].gamesList[i + 1];
    }
    (listOfUsers[userIndex].nrOfGames)--;
}

void removeGame(User listOfUsers[], int userIndex)
{
    SearchGameIndex removedGameInfo;
    char searchWord[NAMELENGTH];
    char choice;
    int removeGameIndex;
    if(listOfUsers[userIndex].nrOfGames == 0)
    {
        printf("No games registrered\n");
    }
    else
    {
        while(1)
        {
            printf("Search boardgame to remove (q to quit): ");
            fgets(searchWord, sizeof(searchWord), stdin);
            searchWord[strlen(searchWord) - 1] = '\0'; //standard input where we clear newline character
            if(strcmp(searchWord, "q") == 0)
            {
                break; //we quit on q
            }
            removedGameInfo = searchDisplayGames(listOfUsers, searchWord, userIndex);
            if(removedGameInfo.nrOfMatches != 1)
            {
                printf("You did not find one unique boardgame.\n");
            }
            else if(removedGameInfo.nrOfMatches == 1)
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
                        deleteGame(listOfUsers, userIndex, removedGameInfo.originalIndex); //the removeGameIndex is the original element position of the game in the players
                        break;                                                             //gamelist so that we can remove it AFTER formatting the output
                    }
                }
            }
        }
    }
}

void userMenu(User listOfUsers[], char userName[], int userIndex)
{
    char userChoice[NAMELENGTH];
    int atoiInteger;
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
        fgets(userChoice, sizeof(userChoice), stdin);
        userChoice[strlen(userChoice) - 1] = '\0';
        atoiInteger = atoi(userChoice);
        if(atoiInteger == 0)
        {
            printf("Please enter a valid choice.\n");
            continue;
        }
        switch(atoiInteger)
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

    FILE *fp;

    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';
    
    readFromFile(fp, fileName, listOfUsers, &nrOfUsers);

    while(1)
    {
        printf("Please enter user name, admin or quit: ");
        fgets(userName, sizeof(userName), stdin);
        userName[strlen(userName) - 1] = '\0';
        if(strcmp(userName, "admin") == 0) //temporarily changed "admin" to "a" for debug workflow purposes.
        {
            adminMenu(listOfUsers, &nrOfUsers); //enter admin menu
        } 
        else if(strcmp(userName, "quit") == 0)
        {
            writeToFile(fp, fileName, listOfUsers, &nrOfUsers); //spara all data i en fil vid avslutning
            return 0; //we are quitting the program
        } 
        else if(findUser(listOfUsers, &nrOfUsers, userName) == (-1)) //no matching user found
        {
            printf("User does not exist\n");
        } 
        else //we are assuming the admin typed in a username and thus we'll enter that profile
        {
            userMenu(listOfUsers, userName, findUser(listOfUsers, &nrOfUsers, userName));
        }
    }
    return 0;
}