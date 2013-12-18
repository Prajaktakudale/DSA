#include "testUtils.h"
#include "stack_using_link_list.h"
#include <stdlib.h>

Stack *start;
typedef char String[256];

void setup(){
        start = create_link_list();
}

void test_for_create_Stack(){
        ASSERT(NULL == start->head);
        ASSERT(0 == start->size);
}
//========================Integer======================================
void test_for_push_int_type_element_into_stack(){
        int element = 1;
        push(start, &element);
        ASSERT(1 == start->size);
        ASSERT(element == *(int*)(start->head->data));
}
void test_for_remove_int_element_from_stack(){
    int element = 1;
    push(start, &element);
    ASSERT(element == *(int*)(start->head->data));
    pop(start);
    ASSERT(start->size == 0);
    ASSERT(NULL == start->head);
}
//========================float======================================
void test_for_push_float_type_element_into_stack(){
        float element = 1.0f;
        push(start, &element);
        ASSERT(1 == start->size);
        ASSERT(element == *(float*)(start->head->data));
}
void test_for_remove_float_element_from_stack(){
    float element = 1.0f;
    push(start, &element);
    ASSERT(element == *(float*)(start->head->data));
    pop(start);
    ASSERT(start->size == 0);
    ASSERT(NULL == start->head);
}
//========================double======================================
void test_for_push_double_type_element_into_stack(){
        double element = 1.0;
        push(start, &element);
        ASSERT(1 == start->size);
        ASSERT(element == *(double*)(start->head->data));
}
void test_for_remove_double_element_from_stack(){
    double element = 1.0;
    push(start, &element);
    ASSERT(element == *(double*)(start->head->data));
    pop(start);
    ASSERT(start->size == 0);
    ASSERT(NULL == start->head);
}
//========================Character======================================
void test_for_push_char_type_element_into_stack(){
        char element = 'p';
        push(start, &element);
        ASSERT(1 == start->size);
        ASSERT(element == *(char*)(start->head->data));
}
void test_for_remove_char_element_from_stack(){
    char element = 'p';
    push(start, &element);
    ASSERT(element == *(char*)(start->head->data));
    pop(start);
    ASSERT(start->size == 0);
    ASSERT(NULL == start->head);
}
//========================String======================================
void test_for_push_string_type_element_into_stack(){
        String element = "Prajakta";
        push(start, &element);
        ASSERT(1 == start->size);
        ASSERT(element == *(String*)(start->head->data));
}
void test_for_remove_String_element_from_stack(){
    String element = "Praju";
    push(start, &element);
    ASSERT(element == *(String*)(start->head->data));
    pop(start);
    ASSERT(start->size == 0);
    ASSERT(NULL == start->head);
}

void test_gives_the_top_most_element_from_the_stack_integers(){
    Stack* start = create_link_list();
    int element = 40;
    push(start, &element);
    ASSERT(element == *(int*)top(start));
};
