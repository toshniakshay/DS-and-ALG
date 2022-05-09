#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define TRUE 1

void input_array(int* ptr, int size);
void output_array(int* arr, int size, char* msg);
void sort(int* arr, int size);
void merge_sort(int* arr, int p, int r);
void merge(int* arr, int p, int q, int r);

int main() {

    int* arr;
    int size;

    printf("Enter array size");
    scanf("%d", &size);
    assert(size > 0);

    arr = (int*) malloc(size * sizeof(int));
    assert(arr != NULL);
    
    input_array(arr, size);
    output_array(arr, size, "Array before sort");
    sort(arr, size);
    output_array(arr, size, "Array after sort");
    
    free(arr);
    arr = NULL;
    return EXIT_SUCCESS;
}

void input_array(int* arr, int size) {
    
    for(int i=0; i<size; ++i) {
        arr[i] = rand();
    }
}

void output_array(int* arr, int N, char* msg) {

    if(msg) {
        puts(msg);
    }

    for(int i=0; i<N; i++) {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
}

void sort(int* arr, int N) {
    merge_sort(arr, 0, N-1);
}

void merge_sort(int* arr, int p, int r) {
    int q;
    if(p < r) {
        q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

void merge(int* arr, int p, int q, int r) {
    int* arr1 = NULL;
    int* arr2 = NULL;

    int N1 = q - p + 1;
    int N2 = r - q;

    // Copy elements in 2 arrays by dividing
    arr1 = (int*) malloc(N1 * sizeof(int));
    arr2 = (int*) malloc(N2 * sizeof(int));

    assert(arr1 != NULL && arr2 != NULL);

    for(int i=0; i<N1; ++i) {
        arr1[i] = arr[p + i];
    }

    for(int i=0; i<N2; ++i) {
        arr2[i] = arr[q + 1 + i];
    }

    // Now place the elements in array by comparing arr1 elements with arr2
    int i=0;
    int j=0;
    int k=0;

    while (TRUE)
    {
        if(arr1[i] <= arr2[j]) {
            arr[p + k] = arr1[i];
            i = i + 1;
            k = k + 1;

            if(i == N1) {
                while (j < N2) 
                {
                    arr[p + k] = arr2[j];
                    j = j + 1;
                    k = k + 1;
                }
                break;
            }
        } else {
            arr[p + k] = arr2[j];
            j = j + 1;
            k = k + 1;

            if(j == N2) {
                while (i < N1)
                {
                    arr[p + k] = arr1[i];
                    i = i + 1;
                    k = k + 1;
                }
                break;
            } 
        }
    }
}