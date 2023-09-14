#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 30

void InputArraySort(int array[], int array_lenght)
{

    for(int i = 0; i < array_lenght; i++)
    {
        array[i] = (rand()%21 - 10);
    }

    int swapped;
    do
    {

        swapped = 0;
        for(int i = 1; i < array_lenght; i++)
        {

            if(array[i - 1] < array[i])
            {

                int temp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = temp;
                swapped = 1;
            }

        }

    }while(swapped);

    for(int i = 0; i < array_lenght; i++)
    {

        printf("%d ", array[i]);

    }

}

void InputArrayRand(int array[], int array_lenght)
{

    for(int i = 0; i < array_lenght; i++)
    {

        array[i] = (rand()%21-10);

        printf("%d ", array[i]);

    }
    printf("\n");

}

void InputArrayDeterm(int array[], int array_lenght)
{

    for(int i = 0; i < array_lenght; i++)
    {

        printf("%d ", array[i]);

    }
    printf("\n");

}

int main()
{

    srand(time(NULL));

    //int ex_array[LENGTH] = {0, 1, 2, 3, 4};
    //InputArrayDeterm(ex_array, LENGTH);

    int ex_array[LENGTH];
    
    //InputArrayRand(ex_array, LENGTH);

    InputArraySort(ex_array, LENGTH);

    return 0;

}