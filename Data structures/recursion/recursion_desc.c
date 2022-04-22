#include<stdio.h>
#include<stdlib.h>


int N;

void print_numbers_reverse_recur_1(int no);
void print_numbers_reverse_recur_2(int no);

int main() {

    printf("Enter the number you want:");
    scanf("%d", &N);

    //print_numbers_reverse_recur_1(N);
    print_numbers_reverse_recur_2(1);
}

void print_numbers_reverse_recur_1(int no) {
    if(no == 0) {
        return;
    }

    printf("n = %d\n", no);
    print_numbers_reverse_recur_1(no - 1);
    
}

void print_numbers_reverse_recur_2(int no) {
    if(no == N+1) {
        return;
    }

    print_numbers_reverse_recur_2(no + 1);
    printf("n = %d\n", no);
}