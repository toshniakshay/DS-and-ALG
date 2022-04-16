
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define N 5

struct point
{
    int x;
    int y;
    int z;
};

void built_in_data_type(void);
void array_of_built_in_data_type(void);
void pointer_to_array_of_built_in_data_type(void);

void user_defined_data_type(void);
void array_of_user_defined_type(void);
void pointer_to_array_of_user_defined_data_type(void);

int main(void) {
    built_in_data_type();
    array_of_built_in_data_type();
    pointer_to_array_of_built_in_data_type();
    user_defined_data_type();
    array_of_user_defined_type();
    pointer_to_array_of_user_defined_data_type();
    return(0);
}

void built_in_data_type(void) {
    int* ptr = NULL;
    puts("Built in Data type");
    ptr = (int*) malloc(sizeof(int));
    assert(ptr != NULL);
    memset(ptr, 0, sizeof(int));

    *ptr = 500; // set value to pointer

    printf("*ptr = %d\n", *ptr);
    free(ptr);
    ptr = NULL;
}

void array_of_built_in_data_type(void) {
    int *ptr = NULL;

    puts("Array of built in data type");
    ptr = (int*) malloc(N * sizeof(int));

    // Add elements in array
    for(int i=0; i<N; ++i) {
        ptr[i] = i + 1000;
    }

    // Print elements using pointer
    for (int i = 0; i < N; i++) {
        int number = ptr[i];
        printf("p[%d]: %d\n", i, ptr[i]);
    }
    
    free(ptr);
    ptr = NULL;
}

void pointer_to_array_of_built_in_data_type(void) {
    int** ptr = NULL;
    puts("Pointer to array of ints");

    ptr = (int**) malloc(N * sizeof(int*));
    assert(ptr != NULL);
    memset(ptr, 0, N * sizeof(int*));

    // Add elements to array
    for (int i = 0; i < N; i++) {
        ptr[i] = (int*) malloc(sizeof(int));
        assert(ptr[i] != NULL);
        *(ptr[i]) = i + 5000;
    }

    // Print array elements using pointer
    for (int i = 0; i < N; i++)
    {
        int no = *ptr[i];
        printf("p[%d]: %d\n", i, no);
    }

    // Free array elements
    for (int i = 0; i < N; i++){
        free(ptr[i]);
        ptr[i] = NULL;
    }
    

    free(ptr);
    ptr == NULL;
    
}

void user_defined_data_type(void) {
    struct point* ptr;
    puts("user defined data types");
    ptr = (struct point*) malloc(sizeof(struct point));
    assert(ptr != NULL);

    ptr -> x = 100;
    ptr -> y = 200;
    ptr -> z = 300;

    printf("ptr[x]: %d\n", ptr -> x);
    printf("ptr[y]: %d\n", ptr -> y);
    printf("ptr[z]: %d\n", ptr -> z);
}

void array_of_user_defined_type(void) {
    struct point* ptr;
    puts("Array of user defined objects");

    ptr = (struct point*) malloc(N * sizeof(struct point));
    assert(ptr != NULL);

    // Add values to structures
    for(int i=0; i<N; ++i) {
        ptr[i].x = i + 1000;
        ptr[i].y = i + 2000;
        ptr[i].z = i + 3000;
    }

    // Print values
    for (int i = 0; i < N; i++) {
        printf("point -> x = %d\npoint -> y = %d\npoint -> z = %d\n", ptr[i].x, ptr[i].y, ptr[i].z);
    }

    free(ptr);
    ptr = NULL;
}

void pointer_to_array_of_user_defined_data_type(void) {
    struct point** ptr;

    puts("pointer to array user defined data tyoe");
    ptr  = (struct point**) malloc(N * sizeof(struct point*));  
    assert(ptr != NULL);

    for (int i = 0; i < N; i++) {
        ptr[i] = (struct point*) malloc(sizeof(struct point));
        assert(ptr[i] != NULL);

        ptr[i] -> x = 1 + i;
        ptr[i] -> y = 2 + i;
        ptr[i] -> z = 3 + i;
    }

    for(int i=0; i<N; i++) {
        printf("point is : [%d, %d, %d]\n", ptr[i] -> x, ptr[i] -> z, ptr[i] -> z);
    }

     for(int i=0; i<N; i++) {
        free(ptr[i]);
        ptr[i] = NULL;
    }

    free(ptr);
    ptr = NULL;
}