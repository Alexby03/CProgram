#include <stdio.h>
#include <string.h>

#define NAMELENGTH 21
#define MAXTEMPERATURES 8

struct patient
{
    char firstName[NAMELENGTH];
    char lastName[NAMELENGTH];
    float temperatures[MAXTEMPERATURES];
    int nrOfTemperatures;
};
typedef struct patient Patient;

float calculateAverage(Patient patient)
{
    float sum = 0;
    for(int i = 0; i < (patient.nrOfTemperatures); i++)
    {
        sum += patient.temperatures[i];
    }
    return (sum / (patient.nrOfTemperatures));
}

void printPatient(Patient patient)
{
    printf("%c. %s ", patient.firstName[0], patient.lastName);
    for(int i = 0; i < patient.nrOfTemperatures; i++)
    {
        printf("%.1f, ", patient.temperatures[i]);
    }
    printf("medelvarde %.2f\n", calculateAverage(patient));
}

void addTemp(Patient *pPatient, float newTemperature)
{
    if(pPatient->nrOfTemperatures < MAXTEMPERATURES)
    {
        pPatient->temperatures[pPatient->nrOfTemperatures] = newTemperature;
        (pPatient->nrOfTemperatures)++;
    }
}

int main()
{
    Patient patient1 = {"Fredrik", "Eber", {38.1, 39.2, 37.9, 37.2}, 4};
    printPatient(patient1);
    addTemp(&patient1, 36.4f);
    printPatient(patient1);
    return 0;
}