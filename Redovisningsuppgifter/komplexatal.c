#include <stdio.h>

struct complex
{
    float re;
    float im;
};
typedef struct complex Complex;

Complex createComplex(float real, float imagin)
{
    Complex complexNr;
    complexNr.re = real;
    complexNr.im = imagin;
    return complexNr;
}

void multiplyComplex(Complex *pComplex, float multiplier)
{
    (pComplex->re) *= multiplier;
    (pComplex->im) *= multiplier;
}

void printComplex(Complex *pComplex)
{
    if((pComplex->im) < 0)
    {
        printf("%6.4f - %6.4fi", (pComplex->re), -(pComplex->im));
    } 
    else if((pComplex->im) > 0)
    {
        printf("%6.4f + %6.4fi", (pComplex->re), (pComplex->im));
    } 
    else if((pComplex->im) == 0)
    {
        printf("%6.4f", (pComplex->re));
    } 
    printf("\n"); 
}

int main()
{
    Complex c1 = createComplex(3.0f, 2.0f);
    Complex c2 = createComplex(2.0f, -3.0f);

    multiplyComplex(&c1, -2.5f);
    multiplyComplex(&c2, -1.0f);

    printComplex(&c1);
    printComplex(&c2);
}