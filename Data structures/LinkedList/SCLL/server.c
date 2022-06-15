#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

// auxillary methods
static void* xalloc(data_t nr_elements, data_t size_of_elements) {
    void* ptr = NULL;

    ptr = calloc(nr_elements, size_of_elements);

    if(ptr == NULL) {
        fprintf(stderr, "calloc::fatal::out of virtual memory");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

static void generic_insert(list_t* p_begin, list_t* p_mid, list_t* p_end) {
    p_mid->next = p_end;
    p_begin->next=p_mid;
}

static void generic_delete(node_t* node_to_delete) {

}

static node_t* search_node(list_t* p_list, data_t data) {
    node_t* p_run = NULL;
    p_run = p_list->next;
    while (p_run != p_list)
    {
        if(p_run->data == data) {
            return p_run;
        }
        p_run = p_run->next;
    } 
    return NULL;
}

static node_t* get_node(data_t data) {
    node_t* new_node = NULL;

    new_node = (node_t*) xalloc(1, sizeof(node_t));
    new_node->next = NULL;
    new_node->data = data;

    return new_node;
}

//public funtions
list_t* create_list() {
    list_t* p_list = NULL;
    p_list = get_node(-1);
    p_list->next = p_list;

    return p_list;
}

status_t insert_first(list_t* p_list, data_t i_data) {
    generic_insert(p_list, get_node(i_data), p_list->next);
    return SUCCESS;
}

status_t insert_last(list_t* p_list, data_t i_data) {
    node_t* new_node = get_node(i_data);
    generic_insert(get_last_node(p_list), new_node, p_list);
    p_list = new_node;

    return SUCCESS;
}

void show_list(list_t* p_list, char* msg) {
    
    node_t* p_run = NULL;

    if(msg) {
        puts(msg);
    }

    p_run = p_list->next;

    printf("[START]->");
    while(p_run != p_list) {
        printf("[%d]->",p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");  
}

// Function that is required while inserting node at the end
node_t* get_last_node(list_t* p_list) {
    node_t* p_run = NULL;

    p_run = p_list->next;

    while (TRUE) {
        if(p_run->next == p_list) {
            return p_run;
        }
        p_run = p_run->next;
    }
    return NULL;
}

status_t get_first(list_t* p_list, data_t* data) {
    *data = p_list->next->data;
    return SUCCESS;
}

status_t get_last(list_t* p_list, data_t* data) {
    node_t* p_run = NULL;

    p_run = p_list->next;

    while (TRUE) {
        if(p_run->next == p_list) {
            *data = p_run->data;
            break;
        }
        p_run = p_run->next;
    }

    return SUCCESS;
}

bool is_empty(list_t* p_list) {
    return p_list->next == p_list;
}

len_t get_length(list_t* p_list) {
    if(is_empty(p_list)) {
        return 0;
    }

    node_t* p_run = NULL;
    len_t size_of_list = 0;

    p_run = p_list->next;

    while (p_run != p_list)
    {
        size_of_list++;
        p_run = p_run->next;
    }
    return size_of_list;
}

status_t remove_first(list_t* p_list) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }
    p_list->next = p_list->next->next;
    return SUCCESS;
}

status_t remove_last(list_t* p_list) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    node_t* p_run = NULL;
    len_t size = get_length(p_list) - 1; // traverse till 2nd last node 
    int counter = 1;
    p_run = p_list->next;

    
    while(TRUE) {
        if(counter == size) {
            break;
        }
        p_run = p_run->next;
        counter++;
    }

    p_run->next = p_run->next->next;
    return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t e_data, data_t n_data) {
    node_t* existing_node = search_node(p_list, e_data);
    if(existing_node == NULL) {
        return LIST_DATA_NOT_FOUND;
    }
    node_t* new_node = get_node(n_data);

    node_t* p_run = NULL;
    p_run = p_list->next;

    while(p_run != existing_node) {
        if(p_run->next = existing_node) {
            break;
        }
        p_run = p_run->next;
    }

    new_node->next=existing_node;
    p_run->next=new_node;
    return SUCCESS;
}

status_t insert_after(list_t* p_list, data_t e_data, data_t n_data) {
    node_t* existing_node = search_node(p_list, e_data);
    
    if(existing_node == NULL) {
        return LIST_DATA_NOT_FOUND;
    }
    
    node_t* new_node = get_node(n_data);

    new_node->next = existing_node->next;
    existing_node->next = new_node;

    return SUCCESS;
}

status_t remove_element(list_t* p_list, data_t d_data) {
    node_t* existing_node = search_node(p_list, d_data);
    if(existing_node == NULL) {
        return LIST_DATA_NOT_FOUND;
    }

    node_t* p_run = NULL;
    p_run = p_list->next;

    while(TRUE) {
        if(p_run->next == existing_node) {
            break;
        }
        p_run = p_run->next;
    }

    p_run->next = existing_node->next;
    existing_node->next = NULL;
    return SUCCESS;
}

list_t* concatImmutable(list_t* p_list1, list_t* p_list2) {
    list_t* result = NULL;
    result = create_list();

    node_t* p_run = NULL;
    p_run = p_list1->next;

    while(p_run != NULL) {
        insert_last(result, p_run->data);
    }

    p_run = p_list2->next;
    while (p_run != NULL)
    {
        insert_last(result, p_run->data);
    }
    
    return result;
}