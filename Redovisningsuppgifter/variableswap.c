#include <stdio.h>

int main()
{

    int a, b;
    printf("Ange a: ");
    scanf("%d",&a);
    printf("Ange b: ");
    scanf("%d",&b);
    
    int temp;

    temp = a;
    a = b;
    b = temp;
    
    printf("a: %d, b: %d",a,b);

}