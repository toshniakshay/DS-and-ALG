#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void print_array_elements(int index);
void print_array_elements_reverse(int index);

int N; 
int* g_ptr = NULL;

int main() {
    printf("Enter size of array: ");
    scanf("%d", &N);
    assert(N > 0);

    g_ptr = (int*) malloc(N * sizeof(int));
    for(int i=0; i<N; i++) {
        *(g_ptr + i) = i;
    }

    printf("Array in normal order\n");
    print_array_elements(0);
    printf("Array in reverse order\n");
    print_array_elements_reverse(0);
    free(g_ptr);
    g_ptr = NULL;
    return 0;
}

void print_array_elements(int index) {
    if(index == N) {
        return;
    }

    printf("g_ptr[%d] : %d\n", index, g_ptr[index]);
    print_array_elements(index+1);
}

void print_array_elements_reverse(int index) {
    if(index == N) {
        return;
    }
    print_array_elements_reverse(index + 1);
    printf("g_ptr[%d] : %d\n", index, g_ptr[index]);
}