#include <stdio.h>

void calculateMode(int arr[], int size) {
    int maxCount = 0;
    int modeCount = 0;
    int modes[size];

    for (int i = 0; i < size; i++) {
        int count = 0;

        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            modes[0] = arr[i];
            modeCount = 1;
        } else if (count == maxCount && arr[i] != modes[0]) {
            modes[modeCount] = arr[i];
            modeCount++;
        }
    }

    // Remove duplicates from the modes array
    int uniqueModes[modeCount];
    int uniqueModeCount = 0;

    for (int i = 0; i < modeCount; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < uniqueModeCount; j++) {
            if (modes[i] == uniqueModes[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueModes[uniqueModeCount] = modes[i];
            uniqueModeCount++;
        }
    }

    printf("Modes: ");
    for (int i = 0; i < uniqueModeCount; i++) {
        printf("%d", uniqueModes[i]);
        if (i < uniqueModeCount - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    calculateMode(arr, size);

    return 0;
}
