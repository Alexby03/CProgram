/* Checks numbers for repeated digits */

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false}; 
    int digit;
    int input;
    long n;

    do
    {
        printf("Enter a number: "); 
        scanf("%ld", &input);

        n = input;

        while (n > 0)
        { 
            digit = n % 10;
            if (digit_seen[digit])
            {
                break;
            }
            digit_seen[digit] = true;
            n /= 10;
        }
        if (n > 0)
        {
            printf("Repeated digit\n");
        } 
        else
        {
            printf("No repeated digit\n");
        }
        for (int i = 0; i < 10; i++) 
        {
            digit_seen[i] = false;
        }

    } while (input > 0);

    return 0;
}