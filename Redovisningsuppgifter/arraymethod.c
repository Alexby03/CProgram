#include <stdio.h>

void InputArray(int array[], int array_lenght)
{

    for(int i = 0; i < array_lenght; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

}

int main()
{

    int size = 4;

    int ex_array[4] = {0, 1, 2, 3};

    InputArray(ex_array, size);

    return 0;

}