#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int N;

void recursive_function(int n);
void recursive_function_with_user_input();
void recursive_function1(int n);

int main() {
    //recursive_function(1);
    recursive_function_with_user_input();
}

void recursive_function(int n) {
    if(n == 6) {
        return;
    }

    printf("n = %d\n", n); 
    recursive_function(n+1);
}

void recursive_function_with_user_input(void) {
    printf("Emter positive integer: ");
    scanf("%d", &N);
    assert(N>0);

    recursive_function1(1);
}

void recursive_function1(int n) {
    if(n == N + 1) {
        return;
    }

    printf("n = %d\n", n); 
    recursive_function1(n+1);
}