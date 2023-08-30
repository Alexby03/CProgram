#include <stdio.h>
#include <stdlib.h>

/*Notes: %p will print a memory address, it assumes that we pass in a void pointer which means we need to cast the input as a void pointer. If we don't assign the pointer to an already existing memory address then we need to allocate memory for it. Basically telling it to point to a certain part of the memory. This can be done with either calloc or malloc and to add more we use realloc.*/
int main() {
    int n = 4;
    int *ptr = &n;
    
    int *ptr2 = ptr;
    
    /*ptr points to the memory address of n, *ptr will get you the value of said memory address and ptr will give you the memory addres of n, &ptr will give you the address of ptr instead of n. ptr2 points to the same memory address as ptr, which means that *ptr = *ptr2 and ptr = ptr2 but ptr2 resides on a different memory addres from ptr and n which means that &ptr != &ptr2 != &n, but ptr = ptr2 = &n and *ptr = *ptr2 = n.*/
    
    printf("Value of ptr = %d, \nAddress of ptr = %p, \nAddress of n = %p, \nWhat ptr points to = %p, \nValue of ptr2 = %d, \nAddress of ptr2 = %p, \nWhat ptr2 points to = %p\n", *ptr, (void*)&ptr, (void*)&n, (void*)ptr, *ptr2, (void*)&ptr2, (void*)ptr2);
    
    
    
    /*ptr3 points to the memory address of ptr. *ptr3 would give the value of ptr which is the memory address of n and **ptr3 would give the value of n. This means that ptr3 = &ptr != &ptr2, **ptr3 = *ptr = *ptr2 = n and *ptr3 = ptr = &n = ptr2.*/
    printf("\n");
    int **ptr3 = &ptr;
    printf("What ptr3 points to = %p, \nValue of ptr3 = %d, \nWhat pointer that ptr3 points to points to = %p\n", (void*)ptr3, **ptr3, (void*)*ptr3);
    printf("\n");
    
    
    /*Arrays are pointers to the memory address of the first element in the array. ptrArr allocates enough memory to fit 4 integer values. Then it assignes them in the loop. ptrArr + i is the memory address of the first element + the iteration number and *(ptrArr + i) is the value of the first element + the iteration number.*/
    
    int *ptrArr, size = 2;
    ptrArr = (int*)malloc(sizeof(int) * size);
    
    for(int i = 0; i <= size; i++){
        *(ptrArr + i) = i;
        printf("Value of ptrArr[%d] = %d, Address of ptrArr[%d] = %p, ", i, *(ptrArr + i), i, (void*)(ptrArr + i));
    }
    
    printf("\n");
    
    /*ptrArr2 first allocates memory then adds some values of its own. It the assignes the last of its values to be the same as the values of ptrArr, this does not mean that the memory addresses are the same at those positions, it will still have unique memory addresses, which isn't great for performance, but I so not yet know of a way to store the memory address instead of the value, if it even is possible in a non-roundabout way.*/
    
    int* ptrArr2, size2 = 4;
    ptrArr2 = (int*)malloc(sizeof(int) * (size + size2));
    
    for(int i = 0; i <= size2; i++){
        *(ptrArr2 + i) = i + 2;
    }
    
    for(int i = 0; i <= size; i++){
        *(ptrArr2 + (size2 + i)) = *(ptrArr + i);
    }
    
    for(int i = 0; i <= (size2 + size); i++){
        printf("Value of ptrArr2[%d] = %d, Address of ptrArr2[%d] = %p, ", i, *(ptrArr2 + i), i, (void*)(ptrArr2 + i));
    }
    
    
    /*When allocating memory to a pointer array its important to free it so that it doesn't take up a bunch of memory.*/
    free(ptrArr);
    free(ptrArr2);
    
    
    
    return 0;

}