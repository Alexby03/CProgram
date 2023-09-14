#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10

int main(void)
{

    int swapped = 1;
    int temp;

    int arr[LENGTH] = {122, 1, 232, 3, 44, 5, 6, 7, 867, 9};

    while(swapped)
    {
        swapped = 0;
        for(int i = 1; i < LENGTH; i++)
        {

            if(arr[i - 1] < arr[i])
            {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }

        }

    }

    

    for(int i = 0; i < LENGTH; i++)
    {

        printf("%d ", arr[i]);

    }

    return 0;

}