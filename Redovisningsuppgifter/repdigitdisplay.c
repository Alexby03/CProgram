/* Checks numbers for repeated digits */

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false}; 
    bool digit_seen_printed[10] = {false};
    bool same_digit = {false};
    int digit;
    long n;

    printf("Enter a number: "); 
    scanf("%ld", &n);
    printf("Repeated digit(s): ");

    while (n > 0)
    { 
        digit = n % 10;
        if (digit_seen[digit] && !digit_seen_printed[digit])
        {
            printf("%d ", digit);
            digit_seen[digit] = true;
            digit_seen_printed[digit] = true;
        } 
        else 
        {
            digit_seen[digit] = true;
        }
        n /= 10;
    }
    
}