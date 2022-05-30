#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>

/* Symbolic constants */
#define SUCCESS                 1
#define TRUE                    1
#define FALSE                   0
#define LIST_DATA_NOT_FOUND     2 
#define LIST_EMPTY              3

typedef int data_t;
typedef int len_t;
typedef int status_t;
typedef int bool;

typedef struct node node_t;
typedef node_t list_t;
 
struct node {
    struct node* prev;
    data_t data;
    struct node* next;
};

/* Interface functions */
list_t* create_list(void);

status_t insert_start(list_t*, data_t);
status_t insert_end(list_t*, data_t);
status_t insert_before(list_t*, data_t, data_t);
status_t insert_after(list_t*, data_t, data_t);

status_t get_start(list_t*, data_t*);
status_t get_end(list_t*, data_t*);
status_t pop_start(list_t*, data_t*);
status_t pop_end(list_t*, data_t*);
status_t remove_first(list_t*);
status_t remove_last(list_t*);


bool is_empty(list_t*);
bool find(list_t*, data_t);
len_t get_length(list_t*);
void show_list(list_t*, char*);

// Advanced functions
list_t* concat_lists_im(list_t*, list_t*); // return new list
status_t concat_lists(list_t*, list_t*); // addAll in list1 and return list1

list_t* get_reversed_list_im(list_t*); // immutable version
status_t get_reversed_list(list_t*); // mutable version

// Function to sort the 2 sorted lists 
list_t* merge_lists(list_t*, list_t*);

status_t destroy_list(list_t**);

/* Auxillary methods */
static void generic_insert(node_t*, node_t*, node_t*);
static void generic_delete(node_t*);
static node_t* search_node(list_t*, data_t);
static node_t* get_node(data_t);

static void* xalloc(size_t, size_t);

#endif



