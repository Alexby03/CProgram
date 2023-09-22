#include <stdio.h>
#include <math.h>
#include <limits.h>

#define SIZE 10

void view(int measurements[], int nrOfMeasurements)
{
    if(nrOfMeasurements == 0)
    {
        printf("No measurements\n");
    }
    else
    {
        printf("[ ");
        for(int i = 0; i < nrOfMeasurements; i++)
        {
            printf("%d ", measurements[i]);
        }
        printf("]\n");
    }
}

int enter(int measurements[], int nrOfMeasurements)
{
    if(nrOfMeasurements == SIZE)
    {
        printf("Values have exceeded the list limit. Please reset in order to enter new values.\n");
    }
    for(int i = nrOfMeasurements; i < SIZE; i++)
    {   
        int readInteger = 0;
        printf("Enter measurement #%d (or q to quit): ", (i + 1));
        int readIntegerSucceed = scanf("%d", &readInteger);
        if(readIntegerSucceed)
        {
            measurements[i] = readInteger;
        }
        else
        {
            char tmp;
            scanf(" %c", &tmp);
            return nrOfMeasurements;
        }
        nrOfMeasurements++;
    }

    return nrOfMeasurements;
}

int determineMax(int measurements[], int nrOfMeasurements)
{
    
    int max = INT_MIN;
    for(int i = 0; i < nrOfMeasurements; i++)
    {
        if(measurements[i] > max)
        {
            max = measurements[i];
        }
    }
    return max;
}

int determineMin(int measurements[], int nrOfMeasurements)
{
    
    int min = INT_MAX;
    for(int i = 0; i < nrOfMeasurements; i++)
    {
        if(measurements[i] < min)
        {
            min = measurements[i];
        }
    }
    return min;
}

float giveAverage(int measurements[], int nrOfMeasurements)
{
    float sumOfAllElements = 0.0f;
    for(int i = 0; i < nrOfMeasurements; i++)
    {
        sumOfAllElements += measurements[i];
    }
    sumOfAllElements = (float) sumOfAllElements / nrOfMeasurements;
    return sumOfAllElements;
}

void normalizedValue(int measurements[], int normalizedArray[], int nrOfMeasurements)
{

    int normalizedOffset = round(giveAverage(measurements, nrOfMeasurements));
    //printf("here is the normalizedoffset: (%d)", normalizedOffset);
    for(int i = 0; i < SIZE; i++)
    {
        normalizedArray[i] = measurements[i] - normalizedOffset;
    }

}

void compute(int measurements[], int nrOfMeasurements)
{
    if(nrOfMeasurements == 0)
    {
        printf("No measurements\n");
    }
    else
    {
        printf("Max value: %d\n", determineMax(measurements, nrOfMeasurements));
        printf("Min value: %d\n", determineMin(measurements, nrOfMeasurements));
        printf("Average value: %.2f\n", giveAverage(measurements, nrOfMeasurements));

        int normalizedArray[SIZE] = {0};
        normalizedValue(measurements, normalizedArray, nrOfMeasurements);
        view(normalizedArray, nrOfMeasurements);
    }
}

int main()
{

    printf("Measurement tool 2.0\n");

    int measurements[SIZE] = {0};
    int nrOfMeasurements = 0;
    char optionchoice;
    
    do
    {
        printf("VECRQ? ");
        scanf(" %c", &optionchoice);
        if(optionchoice == 'q')
        {  
            printf("Exit Measurement tool");
        }
        else if(optionchoice == 'v')
        {  
            view(measurements, nrOfMeasurements);
        }
        else if(optionchoice == 'e')
        {  
            nrOfMeasurements = enter(measurements, nrOfMeasurements);
        }
        else if(optionchoice == 'c')
        {  
            compute(measurements, nrOfMeasurements);
        }
        else if(optionchoice == 'r')
        {  
            nrOfMeasurements = 0;
            printf("Reset measurements\n");
        }

    } while (optionchoice != 'q');
    
    return 0;

}