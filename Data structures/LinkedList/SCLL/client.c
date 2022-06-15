#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "list.h"

int main(void) {

    list_t* p_list = NULL;
    node_t* node = NULL;
    data_t data;

    list_t* p_list1 = NULL;
    list_t* p_list2 = NULL;
  
    p_list = create_list();

    for(int i=0; i<5; i++) {
        insert_last(p_list, i+100);
    }
    show_list(p_list, "Singly Linked list");

    insert_first(p_list, 300);
    show_list(p_list, "after insert first");
    
    get_first(p_list, &data);
    printf("\nFirst element of list : [%d]\n", data);

    get_last(p_list, &data);
    printf("Last element of list : [%d]\n", data);

    printf("size of list : [%d]\n", get_length(p_list));

    printf("list is empty: [%d]\n", is_empty(p_list));

    show_list(p_list, "List before removing element");
    remove_first(p_list);
    show_list(p_list, "List after removing first element");

    show_list(p_list, "List before removing last element");
    remove_last(p_list);
    show_list(p_list, "List after removing last element");

    show_list(p_list, "List before adding element after 103");
    insert_after(p_list, 103, 200);
    show_list(p_list, "List after adding element after 103");

    show_list(p_list, "List before adding element after 102");
    insert_before(p_list, 102, 300);
    show_list(p_list, "List after adding element after 102");

    show_list(p_list, "List before removing element after 102");
    remove_element(p_list, 102);
    show_list(p_list, "List after removing element after 102");

    p_list1 = create_list();
    p_list2 = create_list();

    for(int i=0; i<5; i++) {
        insert_last(p_list1, i+100);
    }

     for(int i=0; i<5; i++) {
        insert_last(p_list2, i+200);
    }

    printf("Lists created");
    list_t* result = concatImmutable(p_list1, p_list2);
    show_list(result, "After adding list1 and list 2");

    return(EXIT_SUCCESS);
}