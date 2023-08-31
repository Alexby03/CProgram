#include <stdio.h>

int main()
{

    int size;
    printf("Storlek: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        
        for (int j = 0; j < size; j++)
        {
                
            if (j > size - (i + 2) && (j < size - i) && ())
            {
                printf("*");
            } 
            else 
            {
                printf("+");
            }

        }
        printf("\n");

    }

}