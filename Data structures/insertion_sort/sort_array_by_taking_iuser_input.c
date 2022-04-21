#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0

void insertion_sort(int* arr_p, int size);
void sort_array_at_pos(int* arr_p, int size);
void release_array(int** arr_p);

int main() {
    int* arr;
    int number_of_elements;

    printf("How many elements you want to enter in array?\n");
    scanf("%d", &number_of_elements);

    for(int i=0; i< number_of_elements; i++) {
        printf("Enter Element at index[%d]:", i);
        scanf("%d", &arr[i]);
    }

    printf("Array elements before sorting\n");
    for(int i=0; i< number_of_elements; i++) {
        printf("%d\n", arr[i]);
    }

    insertion_sort(arr, number_of_elements);

    printf("Array elements after sorting\n");
    for(int i=0; i< number_of_elements; i++) {
        printf("%d\n", arr[i]);
    }

    release_array(&arr);
    return SUCCESS;
}

void insertion_sort(int* arr_p, int size) {
    for(int i=1; i<=size; i++) {
        sort_array_at_pos(arr_p, i);
    }
}

void sort_array_at_pos(int* arr_p, int size) {
    int key = arr_p[size - 1];
    int i;

    for(i = size - 2; i > -1 && arr_p[i] > key; i--) {
        arr_p[i+1] = arr_p[i];
    }

    arr_p[i+1] = key;
}

void release_array(int** arr_p) {
    free(*arr_p);
    *arr_p = NULL;
}