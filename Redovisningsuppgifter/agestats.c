#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int arrPeople[], int nrOfPeople)
{
    for(int i = 0; i < nrOfPeople; i++)
    {
        arrPeople[i] = rand()%21+20;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i >= 30)
        {
            break;
        }
        printf("%d, ", arr[i]);
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

void cloneArray(int inputArray[], int outputArray[], int index)
{
    
    for(int i = 0; i < index; i++)
    {
        outputArray[i] = inputArray[i];
    }

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
    int occurances[nrOfPeople];
    
    printf("\n");

    for (int i = 0; i < nrOfPeople; i++)
    {
        occurances[i] = 0;
        
        for (int j = i + 1; j < nrOfPeople; j++)
        {
            if(arrPeople[i] == arrPeople[j]){
                occurances[i]++;
            }
        }
    }

    printf("Typvardet: ");

    int currentLargest = 0;

    for (int i = 0; i < nrOfPeople - 1; i++)
    {
        if(occurances[i] > currentLargest)
        {
            currentLargest = occurances[i];
        }
    }

    for (int i = 0; i < nrOfPeople; i++)
    {  
        if(occurances[i] < currentLargest)
        {
            occurances[i] = 0;
        }
    }

    for (int i = 0; i < nrOfPeople; i++)
    {
        if(occurances[i] != 0){
            printf("%d, ", arrPeople[i]);
        }
    }
}

void createArray(int arrPeople[], int arrMedianDisplay[], int nrOfPeople)
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
    int arrMedianDisplay[nrOfPeople];
    for (int i = 0; i < nrOfPeople; i++)
    {
        arrPeople[i] = 0;
        arrMedianDisplay[i] = 0;
    }
    cloneArray(arrPeople, arrMedianDisplay, nrOfPeople);
    createArray(arrPeople, arrMedianDisplay, nrOfPeople);

    return 0;
}