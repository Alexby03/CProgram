#include <stdio.h>

int main()
{

    int amount, quotient;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    quotient = amount / 20;
    amount -= quotient * 20;

    printf("$20 bills: %d", quotient);

    quotient = amount / 10;
    amount -= quotient * 10;

    printf("\n$10 bills: %d", quotient);

    quotient = amount / 5;
    amount -= quotient * 5;

    printf("\n $5 bills: %d", quotient);

    quotient = amount / 1;
    amount -= quotient * 1;

    printf("\n $1 bills: %d", quotient);

    return 0;

}