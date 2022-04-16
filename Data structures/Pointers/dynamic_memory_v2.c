
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define N 5

void allocate_dynamic_memory_by_asking_user(void);

int main(void) {
    allocate_dynamic_memory_by_asking_user();
    return (0);
}

void allocate_dynamic_memory_by_asking_user(void) {
    puts("Simple console program to dynamically allocate memory");
    puts("Enter 1 to continue adding element otherwise enter anything");

    int* ptr;
    int user_choice;
    int size = 0;
    int number; 

    while (1)
    {
        printf("Please enter your choice : ");
        scanf("%d\n", &user_choice);

        
        if(user_choice != 1) {
            break;
        }

        ptr = (int*) realloc(ptr, (size + 1) * sizeof(int));;
        printf("Enter Number you want : ");
        scanf("%d\n", &number);
        ptr[size] = number;
    }

    puts("Result is: ");
    printf("----------------------");
    for(int i=0; i<size; ++i) {
        printf("%d", ptr[i]);
    }
    printf("----------------------");

    puts("Free up memory");

    free(ptr);
    ptr = NULL;
}