#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1

int sum_all_elements(int index, int result);

int N;
int* g_ptr = NULL;

int main() {

    printf("Enter size of array");
    scanf("%d", &N);
    assert(N>0);
    g_ptr = (int*) malloc(N* sizeof(int));
    assert(g_ptr != NULL);

    for(int i=1; i<=N; i++) {
        *(g_ptr + i) = i;
    }

    for(int i=1; i<=N; i++) {
        printf("g_ptr[%d]: %d\n", i, *(g_ptr + i));
    }
    
    int result = sum_all_elements(0, 0);

    printf("Sum is %d\n", result);

    free(g_ptr);
    g_ptr = NULL;

    return SUCCESS;
}

int sum_all_elements(int index, int result) {
    if(index == N) {
        return result + g_ptr[index];
    }
    sum_all_elements(index + 1, result + g_ptr[index]);
}

/* We can do multiplication as well by just multiplying result instead if adding*/