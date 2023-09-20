#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizeArray(int nrOfNumbers, int array[])
{
    int temp;
    int randomOrder;
    for(int i = 1; i < (nrOfNumbers + 1); i++)
    {
        randomOrder = rand()%nrOfNumbers+1;
        temp = array[i];
        array[i] = array[randomOrder];
        array[randomOrder] = temp;
        
    }
}

void printArray(int nrOfNumbers, int array[])
{
    
    for(int i = 1; i < (nrOfNumbers + 1); i++)
    {
        printf("%d, ", array[i]);
    }
    
}

void generateArray(int nrOfNumbers, int array[])
{

    for(int i = 1; i < (nrOfNumbers + 1); i++)
    {
        array[i] = i;
    }
    randomizeArray(nrOfNumbers, array);
    printArray(nrOfNumbers, array);
    
}

int main()
{

    int input;
    int successfulInput = 1;

    srand(time(NULL));
    
    while(successfulInput)
    {
        printf("Vilket ar det hogsta heltal du vill ha med (1-1000): ");
        scanf("%d", &input);
        if(input < 1 || input > 1000)
        {
            printf("Du maste valja mellan 1 och 1000!\n");
            successfulInput = 0;
        }


    }
    
    int array[input + 1];
    generateArray(input, array);

    return 0;

}