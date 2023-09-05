#include <stdio.h>

int main()
{

    int i=0;
    if(i++)
    {
        i++;
        printf("%d",i); //vad skrivs ut?
    }

    return 0;

}