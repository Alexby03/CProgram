#include <stdio.h>

struct pol
{
    float a, b, c; //ax^2+bx+c
};
typedef struct pol Pol;

Pol createPol(float f1, float f2, float f3)
{
    Pol pol;
    pol.a = f1;
    pol.b = f2;
    pol.c = f3;
    return pol;
}

void printPol(Pol pol)
{
    printf("(%.3f)x^2 + (%.3f)x + (%.3f)\n", pol.a, pol.b, pol.c);
}

float value(Pol pol, float f)
{
    float polResult = (pol.a * (f) * (f) + (pol.b) * (f) + (pol.c)); // vi intiatar en float istället för att direkt returna för att säkra oss att vi faktiskt returnar en float.
    return (polResult);
}

void differentiate(Pol *pPol)
{
    pPol->c = (pPol->b);
    pPol->b = 2 * (pPol->a);
    pPol->a = 0.0f;
}

int main()
{
    Pol pol1 = createPol(2.0f, -1.0f, -3.0f);
    printPol(pol1);
    printf("%.3f\n", value(pol1, 0.5f));
    differentiate(&pol1);
    printPol(pol1);
    return 0;
}