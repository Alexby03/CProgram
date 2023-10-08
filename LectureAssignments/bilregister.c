#include <stdio.h>
#include <string.h>

#define MAXLENGTH 20
#define REGLENGTH 20

struct car
{
    char carname[MAXLENGTH];
    int caryear;
    int carmile;
};
typedef struct car Car;

void addCars(Car carRegistry[], int *pNrOfCars)
{
    Car car;
    char model[MAXLENGTH];
    int year;
    int mileage;
    printf("What model: ");
    scanf("%s", &model);
    strcpy(car.carname, model);
    printf("What year: ");
    scanf("%d", &year);
    car.caryear = year;
    printf("What mileage: ");
    scanf("%d", &mileage);
    car.carmile = mileage;
    carRegistry[(*pNrOfCars)] = car;
    (*pNrOfCars)++;
}

Car createCar(char model[], int year, int mileage)
{
    Car car;
    strcpy(car.carname, model);
    car.caryear = year;
    car.carmile = mileage;
    return car;
}

void printCars(Car carRegistry[], int *pNrOfCars)
{
    for(int i = 0; i < (*pNrOfCars); i++)
    {
        printf("Model: %s, Year: %d, Mileage: %d\n", carRegistry[i].carname, carRegistry[i].caryear, carRegistry[i].carmile);
    }
}

void writeToFile(Car carRegistry[], int *pNrOfCars)
{
    FILE *fp;
    fp = fopen("carRegistry.txt", "w");
    for(int i = 0; i < (*pNrOfCars); i++)
    {
        fprintf(fp, "%s %d %d\n", carRegistry[i].carname, carRegistry[i].caryear, carRegistry[i].carmile);
    }
    printf("Wrote to file.\n");
    fclose(fp);
}

void readFromFile(Car carRegistry[], int *pNrOfCars)
{
    FILE *fp;
    char model[MAXLENGTH];
    int year;
    int mileage;
    *pNrOfCars = 0;
    fp = fopen("carRegistry.txt", "r");
    if(fp!=NULL)
    {
        while(fscanf(fp, "%s %d %d", model, &year, &mileage) == 3)
        {
            carRegistry[(*pNrOfCars)] = createCar(model, year, mileage);
            (*pNrOfCars)++;
        }
        printf("Read from file.\n");
        fclose(fp);
    } else
    {
        printf("WTF\n");
    }
    
}

int main()
{
    int nrOfCars = 0;
    int *pNrOfCars = &nrOfCars;
    Car carRegistry[REGLENGTH];

    while(1)
    {
        printf("What do you want to do? 1 ADDCARS 2 PRINT 3 WRITETOFILE 4 READFROMFILE :: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addCars(carRegistry, pNrOfCars);
                break;
            case 2:
                printCars(carRegistry, pNrOfCars);
                break;
            case 3:
                writeToFile(carRegistry, pNrOfCars);
                break;
            case 4:
                readFromFile(carRegistry, pNrOfCars);
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}