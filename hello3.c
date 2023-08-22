#include <stdio.h>

void Rectangle()
{
    int b;
    int h;
    int i;
    int j;

    printf("Ange bredd: ");
    scanf("%d", &b);
    printf("Ange hojd: ");
    scanf("%d", &h);

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (j > 0 && j < (h - 1) && i > 0 && i < (b - 1))
            {
                printf(" ");
            } else 
            {
                printf("*");
            }

        }
        printf("\n");
    }
}

void FlowChart()
{
    int a = 100;
    int b = 1;
    while(a > b)
    {
        printf("a = %d, b = %d\n", a, b);
        if((a / b) > 20)
        {
            a /= 2;
        } else if((a / b) < 20)
        {
            if((b < (a / 2)))
            {
                b += 2;
            } else if((b > (a / 2)))
            {
                b += 1;
            }
            printf("b = %d\n", b);
        }
    }
    printf("a = %d, b = %d\n", a, b);
}

int main()
{
    Rectangle();
    /*FlowChart();*/
    printf("Avslutar");

    return 0;
}