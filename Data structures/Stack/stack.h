#ifndef _STACK_H
#define _STACK_H
#include "list.h"

typedef list_t stack_t;

stack_t* init_stack();
status_t push(stack_t* p_stack, data_t data);
status_t pop(stack_t* p_stack, data_t* data);
data_t peep(stack_t* p_stack);
void show_stack(stack_t* p_stack,const char* msg);
void destroy_stack(stack_t** p_stack);

#endif