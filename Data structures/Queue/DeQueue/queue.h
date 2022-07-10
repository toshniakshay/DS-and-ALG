#ifndef _STACK_H
#define _STACK_H
#include "list.h"

typedef list_t queue_t;

queue_t* init_queue();
status_t pushFront(queue_t* p_stack, data_t data);
status_t pushRear(queue_t* p_stack, data_t data);
status_t popFront(queue_t* p_stack, data_t* data);
status_t popRear(queue_t* p_stack, data_t* data);
data_t peep(queue_t* p_stack);
void show_queue(queue_t* p_stack,const char* msg);
void destroy_stack(queue_t** p_stack);

#endif