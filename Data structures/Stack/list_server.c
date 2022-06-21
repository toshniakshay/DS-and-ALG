#include<stdio.h>
#include<stdlib.h>
#include "list.h"

list_t* createList() {
    node_t* p_list = create_new_node(-1);
    p_list->next = p_list;
    p_list->prev = p_list;
    return p_list;
}

status_t insert_end(list_t* p_list, data_t data) {
    generic_insert(p_list, create_new_node(data), p_list->next);
    return SUCCESS;
}

status_t remove_end(list_t* p_list, data_t* data) {
    *data = p_list->next->data;
    generic_delete(p_list->next);
    return SUCCESS;
}


len_t get_length(list_t* p_list) {
    len_t size = 0;
    node_t* p_run = p_list->next;

    while(p_run != p_list) {
        size++;
        p_run = p_run->next;
    }
    return size;
}

bool is_empty(list_t* p_list) {
    return p_list->next == p_list && p_list->prev == p_list;
}

void show(list_t* p_list, const char* msg) {
    if(msg) {
        puts(msg);
    }

    node_t* p_run = NULL;
    p_run = p_list->next;

    printf("[STACK START]->");
    while(p_run != p_list) {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");
}


status_t destroy_list(list_t** pp_list) {
    
}

// Auxillary functions
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) {
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

static void generic_delete(node_t* p_delete_node) {
    p_delete_node->next->prev = p_delete_node->prev;
    p_delete_node->prev->next = p_delete_node->next;
}

static void* xmalloc(size_t size) {
    void* ptr = malloc(sizeof(size));
    return ptr;
}

static node_t* create_new_node(data_t data) {
    node_t* new_node = (node_t*) xmalloc(sizeof(struct node_t*));
    new_node->data = data;
    new_node->next = new_node;
    new_node->prev = new_node;

    return new_node;
}
