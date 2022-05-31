#ifndef _LIST_H
#define _LIST_H


#define SUCCESS             1  
#define TRUE                1
#define FALSE               0
#define LIST_EMPTY          2
#define LIST_DATA_NOT_FOUND 3

typedef int status_t;
typedef int bool;
typedef int data_t;
typedef int len_t;

typedef struct node node_t;
typedef node_t list_t;

struct node
{
    data_t data;
    struct node* next;    
};

// interface methods
list_t* create_list();
void show_list(list_t* p_list, char* msg);
bool is_empty(list_t* p_list);
len_t get_length(list_t* p_list);

status_t insert_first(list_t* p_list, data_t i_data);
status_t insert_last(list_t* p_list, data_t i_data);
status_t insert_before(list_t* p_list, data_t e_data, data_t n_data);
status_t insert_after(list_t* p_list, data_t e_data, data_t n_data);

status_t remove_first(list_t* p_list);
status_t remove_last(list_t* p_list);


status_t get_first(list_t* p_list, data_t* data);
status_t get_last(list_t* p_list, data_t* data);

node_t* get_last_node(list_t* p_list);


// auxillary methods
static void* xalloc(data_t nr_elements, data_t size_of_elements);
static void generic_insert(list_t* p_begin, list_t* p_mid, list_t* p_end);
static void generic_delete(node_t* node_to_delete);
static node_t* search_node(list_t* p_list, data_t data);
static node_t* get_node(data_t data);


#endif