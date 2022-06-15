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
    
};

list_t* createList();

status_t insert_start(list_t* p_list, data_t data);
status_t insert_end(list_t* p_list, data_t data);
status_t insert_before(list_t* p_list, data_t data, data_t new_data);
status_t insert_after(list_t* p_list, data_t data, data_t new_data);

status_t get_start(list_t* p_list, data_t* data);
status_t get_end(list_t* p_list, data_t* data);
status_t pop_start(list_t* p_list, data_t* data);
status_t pop_end(list_t* p_list, data_t* data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list);

len_t get_length(list_t* p_list);
bool is_empty(list_t* p_list);
bool is_member(list_t* p_list, data_t data);
void show(list_t* p_list, char* msg);
node_t* search(list_t* p_list, data_t s_data);

list_t* concat(list_t* p_list1, list_t* p_list2);
list_t* merge(list_t* p_list1, list_t* p_list2);
list_t* get_reversed_list(list_t* p_list);

status_t destroy_list(list_t** p_list);

// Auxillary functions
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_prev_node, node_t* p_delete_node);
static void* xmalloc(size_t size);
static node_t* create_new_node(data_t data);
static status_t get_last_and_second_last_nodes(list_t* p_list, node_t** second_last_node, node_t* last_node);
static node_t get_last_node(list_t* p_list);

#endif