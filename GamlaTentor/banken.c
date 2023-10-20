#include <stdio.h>
#include <string.h>

#define MAXSTRING 41
#define MAXCLIENTS 10

struct client
{
    char name[MAXSTRING];
    int balance;
};
typedef struct client Client;

void printClientList(Client listOfClients[MAXCLIENTS], int *pNrOfClients)
{
    for(int i = 0; i < (*pNrOfClients); i++)
    {
        printf("%d. %s\n", (i + 1), listOfClients[i].name);
    }
}

void printClientBalance(Client listOfClients[MAXCLIENTS], int *pNrOfClients)
{
    if((*pNrOfClients) == 0)
    {
        printf("Det saknas kunder\n");
        return;
    }
    else
    {
        int choice;
        printClientList(listOfClients, pNrOfClients);
        while(1)
        {
            printf("Ange kundnummer: ");
            scanf("%d%*c", &choice);
            if(choice > (*pNrOfClients) || choice < 1)
            {
                printf("Felaktigt nummer\n");
            }
            else
            {
                printf("%s, saldo: %d kr\n", listOfClients[choice - 1].name, listOfClients[choice - 1].balance);
                return;
            }
        }
    }
}

void registerClient(Client listOfClients[MAXCLIENTS], int *pNrOfClients)
{
    char clientName[MAXSTRING];
    while(1)
    {
        printf("Ange kund (q avslutar): ");
        fgets(clientName, sizeof(clientName), stdin);
        clientName[strlen(clientName) - 1] = '\0';
        if(strcmp(clientName, "q") == 0)
        {
            return;
        }
        else if((*pNrOfClients) < MAXCLIENTS)
        {
            strcpy(listOfClients[(*pNrOfClients)].name, clientName);
            listOfClients[(*pNrOfClients)].balance = 0;
            (*pNrOfClients)++;
        }
        else if((*pNrOfClients) >= MAXCLIENTS)
        {
            printf("Listan ar full.\n");
            return;
        }
    }
}

void enterBalance(Client listOfClients[MAXCLIENTS], int *pNrOfClients)
{
    if((*pNrOfClients) == 0)
    {
        printf("Det saknas kunder\n");
        return;
    }
    int choice;
    int addedBalance;
    printClientList(listOfClients, pNrOfClients);
    printf("Vem vill gora en insattning: ");
    scanf("%d%*c", &choice);
    if(choice > (*pNrOfClients) || choice < 1)
    {
        printf("Felaktigt nummer\n");
    }
    else
    {
        printf("%s, saldo: %d kr\n", listOfClients[choice - 1].name, listOfClients[choice - 1].balance);
        printf("Insattning (kr): ");
        scanf("%d%*c", &addedBalance);
        listOfClients[choice - 1].balance += addedBalance;
        printf("Nytt saldo: %d\n", listOfClients[choice - 1].balance);
    }
}

void adminMenu(Client listOfClients[MAXCLIENTS], int *pNrOfClients)
{
    char password[MAXSTRING];
    int choice;
    printf("Ange losenord: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1]  = '\0';
    if(strcmp(password, "abcd") != 0)
    {
        printf("Fel losenord\n");
        return;
    }
    while(1)
    {
        printf("1. Registrera kund, 2. Insattning, 3. Startmenyn: ");
        scanf("%d%*c", &choice);
        switch(choice)
        {
            case 1: //register client
                registerClient(listOfClients, pNrOfClients);
                break;
            case 2: //enter balance
                enterBalance(listOfClients, pNrOfClients);
                break;
            case 3: //back to start menu
                return;
            default: //entered something outside the other options
                printf("Felaktigt val\n");
                break;
        }
    }
}

int main()
{
    Client listOfClients[MAXCLIENTS];
    int nrOfClients = 0;
    int choice;
    char password[MAXSTRING];
    printf("Banken\n");
    while(1)
    {
        printf("1. Admin, 2. Kundsaldo, 3. Avsluta: ");
        scanf("%d%*c", &choice);
        switch(choice)
        {
            case 1: //administration
                adminMenu(listOfClients, &nrOfClients);
                break;
            case 2: //see balance of a client
                printClientBalance(listOfClients, &nrOfClients);
                break;
            case 3: //quit
                printf("Avslutar\n");
                return 0;
            default: //entered something outside the other options
                printf("Felaktigt val\n");
                break;
        }
    }
    return 0;
}