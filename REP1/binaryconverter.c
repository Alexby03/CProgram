#include <stdio.h>

void BinaryConverter(int n)
{
    int binary[32];
    int index = 0;
    while(n > 0)
    {
        binary[index] = n % 2;
        n /= 2;
        index++;
    }
    for (int i = (index - 1); i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
}

int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    BinaryConverter(number);

    return 0;
}