
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct node {
    struct node* next;
    struct node* prev;
    int data;
}


int main() {

    int N;
    printf("Enter size of list");
    scanf("%d", &N);
    assert(N > 0);

    return (EXIT_SUCCESS);
}