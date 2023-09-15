#include <stdio.h>
#define LENGTH 5

int main()
{

    int twodimensionalarray[LENGTH][LENGTH] = {
        {3, 5, 8, 4, 6},
        {0, 1, 4, 3, 4},
        {7, 8, 6, 8, 9},
        {0, 5, 2, 3, 4},
        {7, 6, 4, 6, 8},
    };

    int sumrow = 0, sumcolumn = 0;

    printf("Row totals: ");
    for(int i = 0; i < LENGTH; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {

            sumrow += twodimensionalarray[i][j];

        }
        printf("%d ", sumrow);
        sumrow = 0;
    }
    printf("\nColumns totals: ");
    for(int i = 0; i < LENGTH; i++)
    {  
        for(int j = 0; j < LENGTH; j++)
        {

            sumcolumn += twodimensionalarray[j][i];

        }
        printf("%d ", sumcolumn);
        sumcolumn = 0;
    }

    return 0;

}