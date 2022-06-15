#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "list.h"

int main(void) {

    list_t* p_list;
    data_t data;
    status_t status;

    p_list = createList();
    
    for(int i=0; i<5; ++data) {
        status = insert_start(p_list, i);
        assert(status);
    }

    show(p_list, "List");
    return SUCCESS;
}