
#include<stdio.h>
#include<stdlib.h>
#include "list.h"

// Static functions
static void* xalloc(size_t nr_elements, size_t size_of_element) {
    void* ptr = NULL;

    ptr = calloc(nr_elements, size_of_element);
    if(ptr == NULL) {
        fprintf(stderr, "callac::fatal::out of virtual memory\n");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

static node_t* get_node(data_t s_data) {
    node_t* node = NULL;

    node = (node_t*) xalloc(1, sizeof(node_t));
    node->next = node;
    node->prev = node;
    node->data = s_data;

    return node;
}

static node_t* search_node(list_t* p_list, data_t s_data) {
       node_t* p_run = NULL;
       p_run = p_list -> next;

       while (p_run == p_list)
       {
           if(p_run -> data == s_data) {
               return p_run;
           }

           p_run = p_run -> next;
       }
       return NULL;
}

static void generic_insert(node_t* p_begin, node_t* p_mid, node_t* p_end) {
    p_mid -> next = p_end;
    p_mid -> prev = p_begin;
    p_begin -> next = p_mid;
    p_end -> prev = p_mid;
}

static void generic_delete(node_t* d_data) {
    d_data->next->prev = d_data -> prev;
    d_data->prev->next = d_data -> next;
    free(d_data);
    d_data = NULL;
}

// public interface methods
list_t* create_list(void) {
    list_t* p_list = NULL;

    p_list = get_node(-1);

    p_list -> next = p_list;
    p_list -> prev = p_list;

    return p_list;
}

bool is_empty(list_t* p_list) {
    return p_list->next == p_list && p_list -> prev == p_list;
}

status_t insert_start(list_t* p_list, data_t new_data) {
    generic_insert(p_list, get_node(new_data), p_list->next);
    return SUCCESS;
}

status_t insert_end(list_t* p_list, data_t new_data) {
    generic_insert(p_list-> prev, get_node(new_data), p_list);
    return SUCCESS;
}

status_t insert_before(list_t* p_list, data_t e_data, data_t n_data) {

    node_t* node = NULL;

    node = get_node(e_data);

    if(node == NULL) {
        return LIST_DATA_NOT_FOUND;
    }

    generic_insert(node->prev, get_node(n_data), node);
    return SUCCESS;

}

status_t insert_after(list_t* p_list, data_t e_data, data_t n_data) {
    node_t* node = NULL;
    node = get_node(e_data);

    if(node == NULL) {
        return LIST_DATA_NOT_FOUND;
    }

    generic_insert(node, get_node(n_data), node->next);
    return SUCCESS;
}

void show_list(list_t* p_list, char* msg) {
    if(msg) {
        puts(msg);
    }

    node_t* p_run = NULL;

    p_run = p_list->next;

    printf("[START]<->");
    while (p_run != p_list) {
        printf("[%d]<->",p_run-> data);
        p_run = p_run->next;
    }

    puts("[END]");
}

len_t get_length(list_t* p_list) {

    node_t* p_run = NULL;
    len_t length = 0;

    p_run = p_list->next;

    while (p_run != p_list)
    {
        length++;
        p_run = p_run->next;
    }

    return length;
}

status_t get_start(list_t* p_list, data_t* p_start_data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    *p_start_data = p_list->next->data;
    return SUCCESS;
}

status_t get_end(list_t* p_list, data_t* p_end_data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    *p_end_data = p_list->prev->data;
    return SUCCESS;
}

status_t pop_start(list_t* p_list, data_t* p_start_data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    *p_start_data = p_list->next->data;
    generic_delete(p_list->next);
    return SUCCESS;
}

status_t pop_end(list_t* p_list, data_t* p_end_data) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    *p_end_data = p_list->prev->data;
    generic_delete(p_list->prev);
    return SUCCESS;
}

status_t remove_first(list_t* p_list) {
    if (is_empty(p_list)) {
        return LIST_EMPTY;
    }

    generic_delete(p_list -> next);
    return SUCCESS;

}

status_t remove_last(list_t* p_list) {
    if(is_empty(p_list)) {
        return LIST_EMPTY;
    }

    generic_delete(p_list->prev);
    return SUCCESS;
}

status_t destroy_list(list_t** pp_list) {
    list_t* p_list = NULL;
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    p_list = *pp_list;
    p_run = p_list->next;
    while (p_run != p_list)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_list);
    p_list = NULL;
    
    return SUCCESS;
}

list_t* concat_lists_im(list_t* p_list_1, list_t* p_list_2) {
    list_t* p_list = NULL;
    node_t* p_run = NULL;

    p_list = create_list();

    for(p_run = p_list_1->next; p_run != p_list_1; p_run = p_run->next) {
        insert_end(p_list, p_run->data);
    }

    for(p_run = p_list_2->next; p_run != p_list_2; p_run = p_run->next) {
        insert_end(p_list, p_run->data);
    }

    return p_list;
}

status_t concat_lists(list_t* p_list_1, list_t* p_list_2) {
    if(is_empty(p_list_2)) {
        return SUCCESS;
    }

    node_t* p_run = NULL;

    for(p_run = p_list_2 -> next; p_run != p_list_2; p_run = p_run->next) {
        insert_end(p_list_1, p_run->data);
    }

    free(p_list_2);
    p_list_2 = NULL;

    return SUCCESS;
}

list_t* get_reversed_list_im(list_t* p_list) {
    list_t* reversed_list = create_list();
    node_t* p_run = NULL;

    for(p_run = p_list->prev; p_run != p_list; p_run = p_run->prev) {
        insert_end(reversed_list, p_run->data);
    }

    return reversed_list;
}

list_t* merge_lists(list_t* p_list_1, list_t* p_list_2) {
    
    if(is_empty(p_list_2)) {
        return p_list_2;
    }
    
    list_t* p_list = NULL;
    node_t* p_run_1 = NULL;
    node_t* p_run_2 = NULL;

    p_list = create_list();
    p_run_1 = p_list_1 -> next;
    p_run_2 = p_list_2 -> next;

    while (TRUE)
    {
       if(p_run_1 == p_list_1) {
           while(p_run_2 != p_list_2) {
               insert_end(p_list, p_run_2->data);
               p_run_2 = p_run_2->next;
           }
           break;
        }

        if(p_run_2 == p_list_2) {
            while(p_run_1 != p_list_1) {
                insert_end(p_list, p_run_1->data);
                p_run_1 = p_run_1->next;
            }
            break;
        }

        if(p_run_1->data <= p_run_2->data) {
            insert_end(p_list, p_run_1->data);
            p_run_1 = p_run_1->next;
        } else {
            insert_end(p_list, p_run_2->data);
            p_run_2 = p_run_2->next;
        }
    }
    
    return p_list;
}

// Need to understand a bit
status_t get_reversed_list(list_t* p_list) {

}