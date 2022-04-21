#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define SUCCESS 1
#define TOTAL_NUMBER 10000

struct vector_int
{
    int* ptr_arr;
    unsigned long long int size;
};


struct vector_int* create_vector();
int append_element(struct vector_int* array, int element);
void show_vector(struct vector_int* array, char* msg);
void destroy_vector(struct vector_int** array);


int main(int argc, char const *argv[])
{
    struct vector_int* p_vec_rem0 = NULL;
    struct vector_int* p_vec_rem1 = NULL;
    struct vector_int* p_vec_rem2 = NULL;
    struct vector_int* p_vec = NULL;


    p_vec_rem0 = create_vector();
    p_vec_rem1 = create_vector();
    p_vec_rem2 = create_vector();

    for(int i=0; i< TOTAL_NUMBER; ++i) {
        int no = rand();
        switch (no % 3)
        {
        case 0:
            p_vec = p_vec_rem0;
            break;
        case 1:
            p_vec = p_vec_rem1;
            break;
        case 2:
            p_vec = p_vec_rem2;
            break;
        }
        append_element(p_vec, no);
        p_vec = NULL;
    }

    show_vector(p_vec_rem0, "Numbers divisible by 3"); 
    show_vector(p_vec_rem1, "Numbers which yield remainder 1 after division by 3"); 
    show_vector(p_vec_rem2, "Numbers which yield remainder 2 after division by 3"); 

     printf("nr_elements(p_vec_rem0):%llu\n", p_vec_rem0->size); 
    printf("nr_elements(p_vec_rem1):%llu\n", p_vec_rem1->size); 
    printf("nr_elements(p_vec_rem2):%llu\n", p_vec_rem2->size); 

    destroy_vector(&p_vec_rem0);
    destroy_vector(&p_vec_rem1);
    destroy_vector(&p_vec_rem2);

    return (0);
}

struct vector_int* create_vector() {
    struct vector_int* ptr = NULL;
    ptr =(struct vector_int*) malloc(sizeof(struct vector_int));
    assert(ptr != NULL);

    ptr -> ptr_arr = NULL;
    ptr -> size = 0;

    return ptr;
}

int append_element(struct vector_int* ptr, int element) {

    ptr -> ptr_arr = (int*) realloc(ptr -> ptr_arr, ((ptr -> size)+1) * sizeof(int));
    assert(ptr != NULL);

    ptr ->size += 1;
    ptr -> ptr_arr[ptr -> size - 1] = element;

    return(SUCCESS);
}

void show_vector(struct vector_int* array, char* msg) {
    unsigned long long int i;
    if(msg != NULL) {
        puts(msg);
    }

    for(i=0; i< array -> size; ++i) {
        printf("ptr[%llu] : %d\n",i, array ->ptr_arr[i]);
    }
}

void destroy_vector(struct vector_int** pp_vector_int) {
    struct vector_int* p_vector_int = *pp_vector_int;
    free(p_vector_int ->ptr_arr);
    p_vector_int -> ptr_arr = NULL;

    free(p_vector_int);
    *pp_vector_int = NULL;
}