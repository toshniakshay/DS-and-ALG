/*
Quick sort works on the partitioning strategy
We consider the last element of array as pivot element
and we place the pivot element in the array such that
All the elements left to the pivot element are less than pivot
All the elements right to the pivot element are greater than or equal to pivot

and once we apply this partioning strategy recurssively we get the sorted array.

Time complexity is O(log n)
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void input_array(int*, int);
void output_array(int*, int, char*);
void sort(int*, int);
void quick_sort(int*, int, int);
int partition(int*, int, int);
void swap(int**, int, int);

int main() {
    int* arr = NULL;
    int N;
    printf("Enter array size");
    scanf("%d", &N);

    assert(N > 0);
    arr = (int*) malloc(N * sizeof(int));

    input_array(arr, N);

    output_array(arr, N, "Array before sort");
    sort(arr, N);
    output_array(arr, N, "Array after sort");

    free(arr);
    arr = NULL;
    return EXIT_SUCCESS;
}

void input_array(int* arr, int N) {
    for (int i = 0; i< N; i++) {
        arr[i] = rand();
    }
}

void output_array(int* arr, int N, char* msg) {
    if(msg) {
        puts(msg);
    }

    for(int i=0; i<N; ++i) {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
}

void sort(int* arr, int N) {
    quick_sort(arr, 0, N-1);
}

void quick_sort(int* arr, int start, int end) {
    if(start < end) {
        int partitionIndex = partition(arr, start, end);
        quick_sort(arr, start, partitionIndex-1);
        quick_sort(arr, partitionIndex+1, end);
    }
}

int partition(int* arr, int start, int end) {
    int pivot = arr[end];
    int partitionIndex = start;

    for(int i=start; i<end ; i++) {
        if(arr[i] <= pivot) {
            swap(&arr, i, partitionIndex);
            partitionIndex++;
        }
    }

    swap(&arr, partitionIndex, end);
    return partitionIndex;
}

void swap(int** arr, int i, int j) {
    int temp;
    temp = (*arr)[i];
    (*arr)[i] = (*arr)[j];
    (*arr)[j] = temp;
}