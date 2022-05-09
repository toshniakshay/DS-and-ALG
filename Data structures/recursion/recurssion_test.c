#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void test_recursion(int i, int j);

int main() {
    test_recursion(1,8);
}

void test_recursion(int i, int j) {
    int mid;

    if (i<j){
        printf("i= %d j= %d\n", i, j);
        mid = (i+j)/2;
        test_recursion(i, mid);
        test_recursion(mid + 1, j);
    }
}
