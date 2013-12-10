#include "testUtils.h"
#include "link_list.h"
#include <stdio.h>

void test_linked_list_is_created_initially_head_is_null(){
        List* list = create_list();
        ASSERT(NULL == list->start);
};
void test_linked_list_is_created_initially_size_is_0(){
        List* list = create_list();
        ASSERT(list->size == 0);
};