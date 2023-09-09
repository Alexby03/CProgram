/* Checks numbers for repeated digits */

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
    int digit_display_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int digit_display_occurences[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int digit;
    long n;

    printf("Enter a number: "); 
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        
        digit_display_occurences[digit]++;

        n /= 10;
    }
    printf("Digit:          ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", digit_display_array[i]);
    }
    printf("\nOccurences:     ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", digit_display_occurences[i]);
    } 
}