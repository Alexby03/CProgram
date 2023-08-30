#include <stdio.h>

int main()
{

    int int1, int2, int3, int4;
    int largest, smallest;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &int1, &int2, &int3, &int4);

    largest = int1;
    smallest = int1;

    if (int2 > largest)
    {
        largest = int2;
    } else if (int2 < smallest)
    {
        smallest = int2;
    }
    if (int3 > largest)
    {
        largest = int3;
    } else if (int3 < smallest)
    {
        smallest = int3;
    }
    if (int4 > largest)
    {
        largest = int4;
    } else if (int4 < smallest)
    {
        smallest = int4;
    }

    printf("Largest: %d\nSmallest: %d", largest, smallest);

    return 0;

}