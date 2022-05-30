/**
 * @file add_two_sll.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define TRUE 1

struct Node {
    int data;
    struct Node* next;
};


struct Node* fill_list(struct Node**, struct Node* head, int, int);
void print_list(struct Node**, int);
void addTwoNumbers(struct Node*, struct Node*);

int main() {

    struct Node** l1 = NULL;
    struct Node** l2 = NULL;

    struct Node* l1_head = NULL;
    struct Node* l2_head = NULL;

    (struct Node**) malloc(3 * sizeof(struct Node*));
    (struct Node**) malloc(3 * sizeof(struct Node*));

    fill_list(l1, l1_head, 3, 1);
    fill_list(l2, l2_head, 3, 0);

    print_list(l1, 3);
    print_list(l2, 3);

    addTwoNumbers(*l1, *l2);

    return (EXIT_SUCCESS);
}

void fill_list(struct Node** list, struct Node* head, int size, int isLL1) {

    printf("value : %d \n", isLL1);
    for (int i=0; i<size; i++) {
        head = list[i] = (struct Node*) malloc(sizeof(struct Node));
        if(isLL1 == 1) {
            (*list)[i].data = i + 2;
        } else {
            (*list)[i].data = i + 3;
        }
    }
}

void print_list(struct Node** arr, int size) {
    for(int i=0; i<size; i++) {
        printf("%d\n", (*arr)[i].data);
    }
}

void addTwoNumbers(struct Node* l1, struct Node* l2) {
    int result;
    int carry_forward;
    
  
        while(l1!= NULL && l2 != NULL) {
            printf("l1 -> data : %d\n",l1 -> data);
            printf("l2 -> data : %d\n",l2 -> data);
            result += (l1 -> data) + (l2 -> data);
            printf("result : %d\n", result);
            l1 = l1 ->next;
            l2 = l2 -> next;

        }

   // printf("result is : %d", result); 
}