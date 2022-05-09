/*
Precondition :
arr = [100, 200, 300, 400, 50,55,60,70,80]
2 sub-arrays need to be sorted such that
arr1 = [100, 200, 300, 400]
arr2 = [50,55,60,70,80]

The above arrays are part of the main array 
We need to merge these arrays such that the elements are sorted
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TRUE 1

void merge_array(int* arr, int size);
void output_array(int* arr, int size, const char* msg);

int main() {
    int N = 0;
    int* arr = NULL;
    
    printf("Enter size of the array");
    scanf("%d", &N);
    assert(N > 0);
    
    arr = (int*) malloc(N * sizeof(int));
    assert(arr != NULL);

    int mid = N/2;

    for(int i=0; i<=mid; i++) {
        arr[i] = (i + 1)* 10;
    }

    for(int i=mid+1; i<N; i++) {
        arr[i] = (i + 1)* 5;
    }

    output_array(arr, N, "Array elements before sort are:");
    merge_array(arr, N);
    output_array(arr, N, "Array elements after sort are:");
    return (EXIT_SUCCESS);
}


void merge_array(int* arr, int size) {
    int* arr1;
    int N1;

    int* arr2;
    int N2;

    int mid = size / 2;
    N1 = mid + 1;
    N2 = size - mid - 1;

    arr1 = (int*) malloc(N1 * sizeof(int));
    assert(arr1 != NULL);

    arr2 = (int*) malloc(N2 * sizeof(int));
    assert(arr2 != NULL);

    for(int i=0; i< N1; i++) {
        arr1[i] = arr[i];
    }

    for(int i=0; i<size - mid; i++) {
        arr2[i] = arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=0;

    while (TRUE) {
        if(arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
            k++;

            if(i == N1) {
                while (j < N2)
                {
                   arr[k] = arr2[j];
                   j++;
                   k++;
                }
                break;
                
            }
        } else {
            arr[k] = arr2[j];
            j++;
            k++;

             if(j == N2) {
                while (i < N1)
                {
                    arr[k] = arr1[i];
                    i++;
                    k++;
                }
                break;
            }
        }
    }

}

void output_array(int* arr, int size, const char* msg) {
    if(msg != NULL) {
        puts(msg);
    }

    for(int i=0; i<size; ++i) {
        printf("%d\n", arr[i]);
    }
}
