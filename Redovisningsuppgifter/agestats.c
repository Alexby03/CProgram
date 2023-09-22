#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void generateArray(int arrPeople[], int nrOfPeople)
{
    for(int i = 0; i < nrOfPeople; i++)
    {
        arrPeople[i] = rand()%21+20;
    }
}

void printArray(int arrPeople[], int nrOfPeople)
{
    for(int i = 0; i < nrOfPeople; i++)
    {
        printf("%d, ", arrPeople[i]);
    }
}

float calculateAverage(int arrPeople[], int nrOfPeople)
{
    float averageValue = 0.0f;
    for(int i = 0; i < nrOfPeople; i++)
    {
        averageValue += arrPeople[i];
    }
    averageValue = (float) averageValue / nrOfPeople;
    return averageValue;
}

float calculateMedian(int arrPeople[], int nrOfPeople)
{
    for(int j = 0; j < nrOfPeople; j++)
    {
        for(int i = 0; i < (nrOfPeople - 1); i++)
        {
            if(arrPeople[i] > arrPeople[i+1] && arrPeople[i+1] <= 40)
            {
                int temp = arrPeople[i];
                arrPeople[i] = arrPeople[i+1];
                arrPeople[i+1] = temp;
            }
        }
    }
    float median;
    if(nrOfPeople % 2 == 0) //Median (M) = (Value at position n / 2 + Value at position (n / 2 + 1)) / 2
    {
        median = (float)(arrPeople[nrOfPeople / 2 - 1] + arrPeople[nrOfPeople / 2]) / 2;
        return median;
    } else
    {
        median = (float) arrPeople[nrOfPeople / 2];
        return median;
    }
}

void calculateMode(int arrPeople[], int nrOfPeople)
{
    int maxFrequency = 0;
    int frequencies[nrOfPeople];
    int nrOfModes = 0;
    int modes[nrOfPeople];
    int modesSeen[nrOfPeople];
    
    for (int i = 0; i < nrOfPeople; i++)
    {
        modes[i] = 0;
        modesSeen[i] = 0;
        frequencies[i] = 0;
    }

    for (int i = 0; i < nrOfPeople; i++) 
    {
        if (modesSeen[i] == 1) 
        {
            continue;
        }
        int count = 1;

        for (int j = i + 1; j < nrOfPeople; j++) 
        {
            if (arrPeople[i] == arrPeople[j])
            {
                count++;
                modesSeen[j] = 1;
            }
            frequencies[i] = count;
        }

        if (count > 1) 
        {
            modes[nrOfModes] = arrPeople[i];
            nrOfModes++;
            if(count > maxFrequency)
            {
                maxFrequency = count;
            }
        }
    }

    printf("\nTypvardet: ");
    for(int i = 0; i < nrOfPeople; i++)
    {
        if(frequencies[i] == maxFrequency)
        {
            printf("%d, ", modes[i]);
        }
    }

    printf("\n");
    for(int i = 0; i < nrOfModes; i++)
    {
        printf("%d, ", frequencies[i]);
    }
}

void createArray(int arrPeople[], int nrOfPeople)
{
    generateArray(arrPeople, nrOfPeople);
    printArray(arrPeople, nrOfPeople);
    printf("\nMedelvardet: %.1f ar", calculateAverage(arrPeople, nrOfPeople));
    printf("\nMedian: %.1f ar", calculateMedian(arrPeople, nrOfPeople));
    //printArray(arrPeople, nrOfPeople);
    calculateMode(arrPeople, nrOfPeople);
}

int main()
{
    srand(time(NULL));

    int nrOfPeople;
   

    printf("Hur manga personer vill du gora statistik pa? ");
    scanf("%d", &nrOfPeople);
    int arrPeople[nrOfPeople];
    for (int i = 0; i < nrOfPeople; i++)
    {
        arrPeople[i] = 0;
    }

    createArray(arrPeople, nrOfPeople);

    return 0;
}