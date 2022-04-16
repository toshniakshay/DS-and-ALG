#include<stdio.h>
#include<stdlib.h>

#define N 5

void simplePointer() {
     int *pointer = NULL;
    int i;
    int n = 10;

    pointer = &n;

    printf("%d\n", *pointer);
}


void pointerToArray() {
     int *ptr = NULL;

    int arr[5] = {1,2,3,4,5};

    ptr = arr;

    for(int i=0; i<5; ++i) {
        printf("%d", *(ptr + i));
    }
}

void pointerToArrayDynamic() {
    int *ptr = NULL;

    ptr = (int*) malloc(N * sizeof(int));

    for(int i=0; i<5; ++i) {
        ptr[i] = i * 10;
        //*(ptr + i) = i * 10;
        printf("%d\n", *(ptr + i));
    }
}

void double_pointer_variable_basic() {
    int n=10;

    int *ptr = &n;
    int **ptr1 = &ptr;

    printf("%d\n", *ptr);
    printf("%d\n", **ptr1);
}

void array_of_pointers_to_built_in_data_type(void) {
    int **ptr = NULL;
    int n;

    ptr = (int**) malloc(N * sizeof(int*));
    
    for(int i=0; i<N; i++) {
        ptr[i] = (int*) malloc(sizeof(int));
        *(ptr[i]) = i + 100;
    }

    for(int i=0; i<N; ++i) {
        n = *ptr[i];
        printf("%d\n", n);
    }
}

int main() {
    array_of_pointers_to_built_in_data_type();
}