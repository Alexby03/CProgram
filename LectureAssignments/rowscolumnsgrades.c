#include <stdio.h>
#define LENGTH 5

int main()
{

    float twodimensionalarray[LENGTH][LENGTH] = {
        {3, 5, 8, 4, 6},
        {0, 1, 4, 3, 4},
        {7, 8, 6, 8, 9},
        {0, 5, 2, 3, 4},
        {7, 6, 4, 6, 8},
    };

    float totalscore = 0.0f, meanscore = 0.0f;
    float lowscore = 10.0f, highscore = 0.0f;

    printf("\nTotalscore/student: ");
    for(int i = 0; i < LENGTH; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            totalscore += twodimensionalarray[i][j];
        }
        printf("%3.0f ", totalscore);
        totalscore = 0;
    }
    printf("\nMeanscore/student:   ");
    for(int i = 0; i < LENGTH; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            meanscore += twodimensionalarray[i][j];
        }
        printf("%3.1f ", (meanscore / LENGTH));
        meanscore = 0;
    }
    printf("\n\nMeanscore/quiz:      ");
    for(int i = 0; i < LENGTH; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            meanscore += twodimensionalarray[j][i];
        }
        printf("%3.1f ", (meanscore / LENGTH));
        meanscore = 0;
    }
    printf("\nLowscore/quiz:     ");
    for(int i = 0; i < LENGTH; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            lowscore = (twodimensionalarray[j][i] < lowscore) ? twodimensionalarray[j][i] : lowscore;
        }
        printf("%3.0f ", (lowscore));
        lowscore = 10.0f;
    }
    printf("\nHighscore/quiz:    ");
    for(int i = 0; i < LENGTH; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            highscore = (twodimensionalarray[j][i] > highscore) ? twodimensionalarray[j][i] : highscore;
        }
        printf("%3.0f ", (highscore));
        highscore = 0.0f;
    }

    return 0;

}