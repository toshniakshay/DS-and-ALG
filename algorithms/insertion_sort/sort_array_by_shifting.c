#include<stdio.h>
#include<stdlib.h>

#define N 8
#define SUCCESS 1

void sort_array(int* arr);
void sort_last_element_array(int* arr, int position);
void release_array(int** ptr);

int main() {
    int arr[N] = {34,12,6,21,7,14,19,54};

    printf("Array before sorting : \n");
    for(int i= 0; i< N; i++) {
        printf("%d\n", arr[i]);
    }

    sort_array(arr);

    printf("Array after sorting : \n");
    for(int i= 0; i< N; i++) {
        printf("%d\n", arr[i]);
    }

    release_array(&arr);

    return SUCCESS;
}


void sort_array(int* arr_ptr) {
    for(int i = 1; i< N; i++) {
        sort_last_element_array(arr_ptr, i);
    }
}

/*
Precondition : Array should be sorted from 0 to N-2 
*/
void sort_last_element_array(int* arr_p, int size) {
    int key = arr_p[size - 1];
    int i;

    for(i = size - 2; i > -1 && arr_p[i] > key; i--) {
            arr_p[i+1] = arr_p[i];
    }

    arr_p[i+1] = key;
}

void release_array(int** ptr) {
    free(*ptr);
    *ptr = NULL;
}