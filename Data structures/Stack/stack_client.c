#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "stack.h"

int main(void) {
    stack_t* p_stack = NULL;
    status_t status;
    data_t data;

    p_stack = init_stack();
    assert(is_empty(p_stack) == TRUE);

    for(int i=0; i<5; i++) {
        assert(push(p_stack, i+100) == SUCCESS);
    }
    show(p_stack, "After push");

    assert(pop(p_stack, &data) == SUCCESS);
    show(p_stack, "after pop");

    data = peep(p_stack);
    assert(data == 103);
    
    printf("All funtion tests passed successfully\n");
    return(SUCCESS);
}