#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(void) {

    list_t* p_list = NULL;

    list_t* p_list1 = NULL;
    list_t* p_list2 = NULL;
    list_t* p_concat_list = NULL; 
    data_t data;

    p_list = create_list();
    p_list1 = create_list();
    p_list2 = create_list();
    assert(p_list);

    show_list(p_list, "Showing empty list");

    for(int i=0; i<5; ++i) {
        insert_end(p_list, i);
    }

    show_list(p_list, "Showing filled list");

    insert_start(p_list, 100);
    show_list(p_list, "Showing list after insert start");

    insert_end(p_list, 200);
    show_list(p_list, "Showing list after insert end");

    int length = get_length(p_list);
    printf("Length of list : %d\n", length);

    get_start(p_list, &data);
    printf("Start of list : %d\n", data);

    get_end(p_list, &data);
    printf("End of list : %d\n", data);

    pop_start(p_list, &data);
    printf("Removed start of list : %d\n", data);

    show_list(p_list, "List after removing 1st element");

    pop_end(p_list, &data);
    printf("Removed end of list : %d\n", data);

    show_list(p_list, "List after removing last element");

    remove_first(p_list);
    show_list(p_list, "List after remove_first element");

    remove_last(p_list);
    show_list(p_list, "List after remove_last element");

    for(int i=0; i<5; ++i) {
        insert_end(p_list1, i+100);
    }

    for(int i=0; i<5; ++i) {
        insert_end(p_list2, i+200);
    }
    show_list(p_list1, "List 1");
    show_list(p_list2, "List 2");
    p_concat_list = concat_lists_im(p_list1, p_list2);
    show_list(p_concat_list, "After concat_lists_imm function");

    concat_lists(p_list1, p_list2);
    show_list(p_list1, "After concat_lists_imm function");


    show_list(p_list1, "List before reverse");
    p_list = get_reversed_list_im(p_list1);
    show_list(p_list, "List after reverse");

    p_list2 = create_list();

    list_t* p_list_3 = create_list(); 

    for(int i=0; i<5; ++i) {
        insert_end(p_list2, i+100);
    }

    for(int i=0; i<5; ++i) {
        insert_end(p_list_3, i+200);
    }


    show_list(p_list2, "List 2");
    show_list(p_list_3, "List 3");
    p_list = merge_lists(p_list_3, p_list2);
    show_list(p_list, "List after merge");

    destroy_list(&p_list);
    printf("All scenarios passed successfully\n");
    return EXIT_SUCCESS;
}   