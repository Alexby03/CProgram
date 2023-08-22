#include <stdio.h>

void Segelbat()
{

    printf("   *\n   **\n  ****\n ******\n*  *    *\n *******");

}

void Veckodag()
{

    int n;
    printf("Ange veckodag: ");
    scanf("%d", &n);
    if (n == 0){
        printf("Ogiltigt tal.");
    } else if(n == 1){
        printf("Det motsvarar Måndag.");
    } else if(n == 2){
        printf("Det motsvarar Tisdag.");
    } else if(n == 3){
        printf("Det motsvarar Onsdag.");
    } else if(n == 4){
        printf("Det motsvarar Torsdag.");
    } else if(n == 5){
        printf("Det motsvarar Fredag.");
    } else if(n == 6){
        printf("Det motsvarar Lördag.");
    } else if(n == 7){
        printf("Det motsvarar Söndag.");
    } else {
        printf("Ogiltigt tal.");
    }
    
}

void MaxtalWL()
{

    int max;
    int n = 1;
    printf("Ange maxtal: ");
    scanf("%d", &max);
    while(n <= max)
    {
        printf("%d", n);
        n++;
        if (n < (max + 1))
        {
            printf(", ");
        }
    }

}

void MaxtalFL()
{

    int max;
    int n;
    printf("Ange maxtal: ");
    scanf("%d", &max);
    for (n = 0; n < (max + 1); n++)
    {
        printf("%d", n);
        if (n < max)
        {
            printf(", ");
        }
    }

}

void Factorial()
{

    int n;
    int i;
    int factorial = 1;
    printf("Ange ett tal: ");
    scanf("%d", &n);
    if(n >= 0)
    {
        for (i = 1; i < (n + 1); i++)
        {
        factorial *= i;
        }
        printf("%d! = %d", n, factorial);
    } else if(n < 0)
    {
        printf("Talet ska vara positivt.");
    }

}

void FactorialC()
{

    int n;
    int i;
    int factorial = 1;
    printf("Ange ett tal: ");
    scanf("%d", &n);
    while(n != 0)
    {

        if(n > 0)
        {
            for (i = 1; i < (n + 1); i++)
            {
            factorial *= i;
            }
            printf("%d! = %d\n", n, factorial);
        } else if(n < 0)
        {
            printf("Talet ska vara positivt.\n");
        }

        printf("Ange ett tal: ");
        scanf("%d", &n);
        i = 1;
        factorial = 1;

    }

}

int main()
{

    /*Segelbat();*/
    /*Veckodag();*/
    /*MaxtalWL();*/
    /*MaxtalFL();*/
    /*Factorial();*/
    FactorialC();

    printf("\nAvslutar");

    return 0;
}