#include<stdio.h>
#include<stdlib.h>
#include "list.h"

list_t* createList() {
    list_t* new_list = NULL;
    new_list = create_new_node(-1);
    return new_list;
}

status_t insert_start(list_t* p_list, data_t data) {
    generic_insert(p_list, create_new_node(data), p_list->next);
    return SUCCESS; 
}

status_t insert_end(list_t* p_list, data_t data) {
    node_t* p_run = NULL;
    p_run = p_list->next;

    while(p_run != NULL) {
        p_run = p_run->next;
    }
    generic_insert(p_run, create_new_node(data), p_run->next);
    return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t data, data_t new_data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    node_t* p_run = NULL;
    node_t* e_data = NULL;
    node_t* e_data_prev = NULL;

    e_data = p_list->next;
    p_run = p_list->next;

    while(p_run != NULL) {
        if(p_run->data == data) {
            break;
        }
        e_data = e_data->next;
        e_data_prev = e_data_prev->next;
        p_run = p_run->next;
    }

    generic_insert(e_data_prev, create_new_node(new_data), e_data);
    return SUCCESS;
}

status_t insert_after(list_t* p_list, data_t data, data_t new_data) {
    node_t* e_node = search(p_list, data);

    if(e_node == NULL) {
        return LIST_DATA_NOT_FOUND;
    }

    generic_insert(e_node, create_new_node(new_data), e_node->next);
    return SUCCESS;
}

status_t get_start(list_t* p_list, data_t* data) {
    if(is_empty) {
        return LIST_EMPTY;
    }
    *data = p_list->next->data;
    return SUCCESS;
}

status_t get_end(list_t* p_list, data_t* data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    node_t* lastNode = get_last_node(p_list);
    *data = lastNode->data;
    return SUCCESS;
}

status_t pop_start(list_t* p_list, data_t* data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    *data = p_list->next->data;
    generic_delete(p_list->next);
    return SUCCESS;
}

status_t pop_end(list_t* p_list, data_t* data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    node_t* lastNode = get_last_node(p_list);
    *data = lastNode->data;
    generic_delete(lastNode);
    return SUCCESS;
}

status_t remove_start(list_t* p_list) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }
    generic_delete(p_list->next);
    return SUCCESS;
}

status_t remove_end(list_t* p_list) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }
    generic_delete(get_last_node(p_list));
    return SUCCESS;
}

status_t remove_data(list_t* p_list) {

}

len_t get_length(list_t* p_list) {
    if(is_empty(p_list)) {
        return 0;
    }

    node_t* p_run = NULL;
    len_t length = 0;
    p_run = p_list->next;

    while (p_run != NULL) {
        p_run = p_run->next;
        length++;
    }

    return length;
}

bool is_empty(list_t* p_list) {
    return p_list->next == NULL;
}

bool is_member(list_t* p_list, data_t data) {

}

void show(list_t* p_list, char* msg) {
    if(msg) {
        puts(msg);
    }
    node_t* p_run = NULL;

    p_run = p_list->next;

    printf("[START]->");
    while (p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");
    
}

list_t* concat(list_t* p_list1, list_t* p_list2) {

}

list_t* merge(list_t* p_list1, list_t* p_list2) {

}

list_t* get_reversed_list(list_t* p_list) {

}

status_t destroy_list(list_t** p_list) {

}

node_t* search(list_t* p_list, data_t s_data) {
    node_t* p_run = NULL;
    p_run = p_list->next;

    while(p_run != NULL) {
        if(p_run->data == s_data) return p_run;
        p_run = p_run->next;
    }
    return NULL;
}

// Auxillary functions
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) {
    p_mid->next = p_end;
    p_beg->next = p_mid;
}

static void generic_delete(node_t* p_prev_node, node_t* p_delete_node) {
    p_prev_node->next = p_delete_node->next;
    free(p_delete_node);
}

static node_t* create_new_node(data_t data) {
    node_t* node = NULL;
    node = (node_t*) xmalloc(sizeof(node_t));
    node->data=data;
    node->next = NULL;
    return node;
}

static void* xmalloc(size_t size) {
    void* ptr = NULL;

    ptr =(size_t*) malloc(sizeof(size_t));

    if(ptr == NULL) {
        fprintf(stderr, "malloc: out of memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

static node_t* get_last_node(list_t* p_list) {
    node_t* p_run = NULL;
    p_run = p_list->next;

    while(p_run != NULL) {
        p_run = p_run->next;
    }

    return p_run;
}

static status_t get_last_and_second_last_nodes(list_t* p_list, node_t** second_last_node, node_t* last_node) {
    node_t* p_run = NULL;
    node_t* p_run_prev = NULL;

    p_run = p_list->next;
    p_run_prev = p_list;

    while(p_run != NULL) {
        p_run = p_run->next;
        p_run_prev = p_run_prev->next;
    }

    *second_last_node = p_run_prev->data;
    *last_node = p_run->data;

    return SUCCESS;
}