#include <stdio.h>
#include <string.h>

#define MAXLEN 40

struct bankAccount
{
    char name[MAXLEN];
    int balance;
};
typedef struct bankAccount BankAcc;

BankAcc createAccount(char name[], int balance)
{
    BankAcc account;
    strcpy(account.name, name);
    account.balance = balance;
    return account;
}

void printAccount(BankAcc *pBankAcc)
{
    printf("%s %d kr\n", pBankAcc->name, pBankAcc->balance);
}

void transfer(BankAcc *pBankAcc1, BankAcc *pBankAcc2)
{
    pBankAcc2->balance += (pBankAcc1->balance);
    pBankAcc1->balance = 0;
}

int main()
{

    char accName[MAXLEN];
    int accBalance;

    BankAcc account1;
    BankAcc account2;

    printf("Namn ");
    scanf("%[^\n]%*c", accName);
    printf("Saldo ");
    scanf("%d%*c", &accBalance);
    account1 = createAccount(accName, accBalance);

    printf("Namn ");
    scanf("%[^\n]%*c", accName);
    printf("Saldo ");
    scanf("%d%*c", &accBalance);
    account2 = createAccount(accName, accBalance);

    printAccount(&account1);
    printAccount(&account2);

    transfer(&account1, &account2);

    printAccount(&account1);
    printAccount(&account2);

}