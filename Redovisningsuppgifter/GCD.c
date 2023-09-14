#include <stdio.h>

int GCD(int numer, int denom)
{
    
    int gcd;

    while(denom != 0)
    {
        int rest = numer % denom;
        numer = denom;
        denom = rest;
        gcd = numer;
    }

    return gcd;

}

int main()
{

    int m = 42, n = 285;

    printf("%d", GCD(m, n));

    return 0;

}