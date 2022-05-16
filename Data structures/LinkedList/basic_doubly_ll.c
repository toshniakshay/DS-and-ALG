#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define SUCCESS 1
#define FAILURE 0

struct node {
    struct node* prev;
    struct node* next;
    int data;
};

int main() {
    struct node* n1 = NULL;
    struct node* n2 = NULL;
    struct node* n3 = NULL;
    struct node* n4 = NULL;

    n1 = (struct node*) malloc(sizeof(struct node));
    n2 = (struct node*) malloc(sizeof(struct node));
    n3 = (struct node*) malloc(sizeof(struct node));
    n4 = (struct node*) malloc(sizeof(struct node));

    n1 -> data = 10;
    n1 -> next = n2;
    n1 -> prev = NULL;

    n2 -> data = 20;
    n2 -> next = n3;
    n2 -> prev = n1;

    n3 -> data = 30;
    n3 -> next = n4;
    n3 -> prev = n2;

    n4 -> data = 40;
    n4 -> next = NULL;
    n4 -> prev = n3;

    struct node* HEAD = n1;
    while(HEAD != NULL) {
        printf("%d\n", HEAD -> data);
        HEAD = HEAD -> next;
    }

    
    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return (SUCCESS);
}