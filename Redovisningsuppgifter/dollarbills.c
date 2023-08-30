#include <stdio.h>

int main()
{

    int amount;
    int quotient;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    quotient = amount / 20;

    printf("$20 bills: %d", quotient);

    amount -= quotient * 20;
    quotient = amount / 10;

    printf("\n$10 bills: %d", quotient);

    amount -= quotient * 10;
    quotient = amount / 5;

    printf("\n $5 bills: %d", quotient);

    amount -= quotient * 5;
    quotient = amount / 1;

    printf("\n $1 bills: %d", quotient);

    return 0;

}