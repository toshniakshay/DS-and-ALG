/**
 * @file zip_array.c
 * @author Akshay
 * @brief 
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Divide array into 2 parts and then paste elements back to array in even odd position
 * array 1 elements and array 2 elements should be alternative in position
 * 
 * Example Input 
 * [10,20,30,40,50,60,70,80]
 * 
 * Output 
 * [10,60,20,70,30,80,40,50]
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TRUE 1


void zip_array(int* arr, int size);
void output_array(int* arr, int size, const char* msg);
void release_array(int** arr);

int main() {
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    output_array(arr, 8, "Array Before Zip: ");
    zip_array(arr, 8);
    output_array(arr, 8, "Array After Zip: ");

    return (EXIT_SUCCESS);
}


void zip_array(int* arr, int size) {
    int* arr1 = NULL;
    int arr1_size;

    int* arr2 = NULL;
    int arr2_size;

    int mid = size/2;

    arr1_size = mid + 1;
    arr2_size = size - mid - 1;

    arr1 = (int*) malloc(arr1_size * sizeof(int));
    assert(arr1 != NULL);

    arr2 = (int*) malloc(arr2_size * sizeof(int));
    assert(arr2 != NULL);

    for(int i=0; i<arr1_size; ++i) {
        arr1[i] = arr[i];
    }

    for(int i=0; i<arr2_size; ++i) {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (TRUE)
    {
        if(k % 2 == 0) {
            arr[k] = arr1[i];
            i += 1;
            k += 1;

            if(i == arr1_size) {
                while (j < arr2_size)
                {
                    arr[k] = arr2[j];
                    j += 1;
                    k += 1;
                }
                break;
            }
        } else {
            arr[k] = arr2[j];
            j += 1;
            k += 1;

            if(j == arr2_size) {
                while (i < arr1_size)
                {
                    arr[k] = arr1[i];
                    i += 1;
                    k += 1;
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

    for(int i=0; i<size; i++) {
        printf("%d\n", arr[i]);
    }

}
void release_array(int** arr) {

}