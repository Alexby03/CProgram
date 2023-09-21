#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

int main() {
    // Initialize random number generator with a seed (usually the current time)
    srand(time(NULL));
    
     // Change this to the size of your array
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand()%5+1; // Generates a random integer
    }

    // Print the random elements in the array
    printf("Random Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}