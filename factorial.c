#include <stdio.h>

int main()
{

    int factorial = 1;

    while (factorial != 0)
    {
        int result = 1;
        printf("Ange ett tal: ");
        scanf("%d", &factorial);

        if (factorial > 0)
        {

            for (int i = 1; i <= factorial; i++)
            {
                result *= i;
            }

            printf("%d! = %d\n", factorial, result);

        } else if (factorial < 0)
        {

            printf("Talet ska vara positivt.\n");
            
        }
    }

    printf("Avslutar");
    return 0;

}