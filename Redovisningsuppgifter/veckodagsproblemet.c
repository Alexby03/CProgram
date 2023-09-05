#include <stdio.h>

int main()
{

    int day;
    int dayCount;
    int quotient;
    int dayTotal;

    printf("Vilken dag ar det idag (1-man, 2-tis, ..., 7-son): ");
    scanf("%d", &day);
    printf("Ange antal dagar: ");
    scanf("%d", &dayCount);
    printf("Om %d dagar ar det ", dayCount);

    dayTotal = day + dayCount;
    quotient = (dayTotal) / 7;
    dayTotal -= quotient * 7;

    switch(dayTotal)
    {
        case 0:
        printf("sondag");
        break;
        case 1:
        printf("mandag");
        break;
        case 2:
        printf("tisdag");
        break;
        case 3:
        printf("onsdag");
        break;
        case 4:
        printf("torsdag");
        break;
        case 5:
        printf("fredag");
        break;
        case 6:
        printf("lordag");
        break;
    }

    return  0;

}