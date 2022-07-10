#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>

#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_EMPTY 2
#define LIST_DATA_NOT_FOUND 3

typedef int data_t;
typedef struct node node_t;
typedef node_t list_t;
typedef int status_t;
typedef int len_t;
typedef int bool;

struct node {
    data_t data;
    struct node* next;
    struct node* prev;
    
};

list_t* createList();


status_t insert_end(list_t* p_list, data_t data);

status_t get_start(list_t* p_list);

status_t remove_end(list_t* p_list, data_t* data);


len_t get_length(list_t* p_list);
bool is_empty(list_t* p_list);
void show(list_t* p_list, const char* msg);


status_t destroy_list(list_t** pp_list);

// Auxillary functions
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_prev_node);
static void* xmalloc(size_t size);
static node_t* create_new_node(data_t data);

#endif