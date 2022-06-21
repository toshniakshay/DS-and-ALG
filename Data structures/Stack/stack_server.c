#include<stdio.h>
#include "stack.h"
#include "list.h"

stack_t* init_stack() {
    return createList(); 
}

status_t push(stack_t* p_stack, data_t data) {
    return insert_end(p_stack, data);
}

status_t pop(stack_t* p_stack, data_t* data) {
    return remove_end(p_stack, data);
}

data_t peep(stack_t* p_stack) {
    return p_stack->next->data;
}

void show_stack(stack_t* p_stack,const char* msg) {
    show(p_stack, msg);
}

void destroy_stack(stack_t** p_stack) {

}