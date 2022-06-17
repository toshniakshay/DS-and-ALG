#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "list.h"

int main(void) {

    list_t* p_list;
    list_t* p_list2;

    data_t data;
    status_t status;

    p_list = createList();
    assert(is_empty(p_list));
    show(p_list, "Init List");
    
    for(int i=0; i<5; i++) {
        assert(insert_start(p_list, i+100) == SUCCESS);
    }
    show(p_list, "after insert_start()");
    
    for(int i=0; i<5; i++) {
        assert(insert_end(p_list, i+200) == SUCCESS);
    }
    show(p_list, "after insert_end()");

    assert(insert_after(p_list, 109, 501) == LIST_DATA_NOT_FOUND);
    assert(insert_after(p_list, 103, 501) == SUCCESS);
    show(p_list, "insert after 103");

    assert(insert_before(p_list, 30, 450) == LIST_DATA_NOT_FOUND);
    assert(insert_before(p_list, 201, 780) == SUCCESS);
    show(p_list, "insert_before 201");

    assert(get_start(p_list, &data) == SUCCESS);
    printf("get_start() = %d\n", data);

    assert(get_end(p_list, &data) == SUCCESS);
    printf("get_end() = %d\n", data);

    assert(pop_start(p_list, &data) == SUCCESS);
    show(p_list, "after pop_start");

    assert(pop_end(p_list, &data) == SUCCESS);
    show(p_list, "after pop_end");

    assert(remove_start(p_list) == SUCCESS);
    show(p_list, "after remove_start");

    assert(remove_end(p_list) == SUCCESS);
    show(p_list, "after remove_end");

    assert(get_length(p_list) == 8);
    assert(is_member(p_list, 200) == TRUE);
    assert(is_member(p_list, 2000) == FALSE);

    p_list2 = createList();
    for(int i=0; i<5; i++) {
        assert(insert_end(p_list2, i+500) == SUCCESS);
    }
    show(p_list2, "p_list2");

    list_t* result = concatImmutable(p_list, p_list2);
    show(result, "After concatination");

    list_t* result = concat(p_list, p_list2);
    show(result, "After concatination mutable");

    show(p_list, "before reverse");
    result = get_reversed_list_immutable(p_list);
    show(result, "After reverse");

    destroy_list(&p_list);
    destroy_list(&p_list2);
    printf("All Functions passed the test\n");
    return SUCCESS;
}