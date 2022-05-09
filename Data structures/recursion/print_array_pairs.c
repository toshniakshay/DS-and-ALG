#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SUCCESS 1
#define FAILURE 0

void print_array_pairs(int* ptr, int start_index, int end_index);
void inplace_reversal_array(int* ptr, int index);
void max_element_array(int* ptr, int i, int j);
int binary_search(int* ptr, int i, int j, int element);
void merge_sort_started(int* ptr, int size);

int main() {
    int arr[7] = {34,45,20,70,15,45,13};
    merge_sort_started(arr, 7);
    return (SUCCESS);
}

// void print_array_pairs(int* ptr, int start_index, int end_index) {
//     if(start_index < end_index) {
//         return ptr[start_index];
//     }

//     printf("[%d, %d]:[%d, %d]\n", start_index, end_index, ptr[start_index], ptr[end_index]);
//     print_array_pairs(ptr, start_index+1, end_index+1);
// }

// void inplace_reversal_array(int* ptr, int index, int size) {
//     if(index == size - 1) {
//         return 0;
//     }
//     else if(index < size - 1) {
//         int temp = ptr[index];
//         ptr[size - 1] = ptr[index];
//         ptr[index] = temp;
//     } else {
//         inplace_reversal_array(ptr, index++, size--);
//     }
// }

// /*
//                     max(
//                         max(a, i, (i+j)/2),
//                         max(a, (i+j)/ +1, j)
//                     )  ........ i < j 
// max(a, i, j) =      
//                     a[i] ..... i == j
// */
// void max_element_array(int* ptr, int i, int j) {
    
//     int l_max;
//     int r_max;
//     int mid = (i+j)/2;
//     if(i == j) {
//         return ptr[i];
//     }

//     if(i < j) {
//         l_max = max_element_array(ptr, i, mid);
//         r_max = max_element_array(ptr, mid+1, j);
//     }

//     return l_max > r_max ? l_max : r_max;
// }


// /*
//                                 arr[i] ..... (i+j)/2 == element

// bsearch(arr, i, j , element) =  bsearch(arr, i, (i+j)/2) .... if element > i

//                                 bsearch(arr,(i+j)/2, J) .... if element < i
// */
// int binary_search(int* ptr, int i, int j, int element)  {
//     int mid = (i+j)/2;

//     if(i <= j) {
//         if(ptr[mid] == element) {
//             return mid;
//         }
//         else if(ptr[mid] > element) {
//             return binary_search(ptr, i,  mid - 1, element);
//         }
//         else if(ptr[mid] < element) {
//             return binary_search(ptr,mid + 1, j,element);
//         }
//     } 
    
//     return -1;
// }



void merge_sort_started(int* ptr, int size) {
    int* n1 = NULL;
    int* n2 = NULL;

    int mid = (size/2);

    n1 = (int*) malloc(mid * sizeof(int));
    n2 = (int*) malloc((size -mid) * sizeof(int));

     //Print Array
    for(int i=0; i< size; i++) {
            printf("%d,", ptr[i]);
    }

    // Fill elements in N1
    for(int i=0; i< mid; i++) {
        n1[i] = ptr[i]; 
    }

    // Fill elements in N2
    for(int i=0; i< (size -mid); i++) {
        n2[i] = ptr[(size -mid) + i];
    }

    // Copy even elements
    for(int i=0; i< size; i+2) {
            ptr[i] = n1[i];
    }

    // Copy odd elements
    for(int i=1; i< size; i+2) {
            ptr[i] = n2[i];
    }

    //Print Array
    for(int i=0; i< size; i++) {
            printf("%d,", ptr[i]);
    }
}


void sorting_sorted_arrays(int* arr, int size) {
    int* n1 = NULL;
    int n1_size;

    int* n2 = NULL;
    int n2_size;

    n1_size = 

    n1 = (int*) malloc(mid * sizeof(int));
    n2 = (int*) malloc((size -mid) * sizeof(int));
}

