#include <stdlib.h>
#include "stack_without_memcpy.h"
#include "testUtils.h"
#include <string.h>

typedef char String[256];

void test_create_stacks_a_stack_of_given_length (){
    Stack* p_to_stack = create_stack(3);
    void* topElement = top(p_to_stack);
    ASSERT(0 == topElement);
    dispose(p_to_stack);
};
//===============================Integer======================================
void test_for_push_int_element_at_top_of_the_stack(){
    Stack* p_to_stack = create_stack(1);
    int element = 1;
    push(p_to_stack, &element);
    ASSERT(element == *(int*)top(p_to_stack));
    dispose(p_to_stack);
};
void test_for_delete_top_element_of_int_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    int element = 1;
    push(p_to_stack, &element);
    ASSERT(element == *(int*)pop(p_to_stack));
    dispose(p_to_stack);
};
void test_for_get_top_element_of_int_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    int element = 1;
    push(p_to_stack, &element);
    ASSERT(element == *(int*)top(p_to_stack));
    dispose(p_to_stack);
}
//===============================Float======================================
void test_for_push_float_element_at_top_of_the_stack(){
    Stack* p_to_stack = create_stack(1);
    float element = 01.0f;
    push(p_to_stack, &element);
    ASSERT(element == *(float*)top(p_to_stack));
    dispose(p_to_stack);
};
void test_for_delete_top_element_of_float_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    float element = 01.0;
    push(p_to_stack, &element);
    ASSERT(element == *(float*)pop(p_to_stack));
    dispose(p_to_stack);
};

void test_for_get_top_element_of_float_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    float element = 01.0f;
    push(p_to_stack, &element);
    ASSERT(element == *(float*)top(p_to_stack));
    dispose(p_to_stack);
};

//===============================Double======================================
void test_for_push_double_element_at_top_of_the_stack(){
    Stack* p_to_stack = create_stack(1);
    double element = 01.0;
    push(p_to_stack, &element);
    ASSERT(element == *(double*)top(p_to_stack));
    dispose(p_to_stack);
};
void test_for_delete_top_element_of_double_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    double element = 01.0;
    push(p_to_stack, &element);
    ASSERT(element == *(double*)pop(p_to_stack));
    dispose(p_to_stack);
};
void test_for_get_top_element_of_double_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    double element = 01.0;
    push(p_to_stack, &element);
    ASSERT(element == *(double*)top(p_to_stack));
    dispose(p_to_stack);
};

//===============================Character======================================
void test_for_push_character_element_at_top_of_the_stack(){
    Stack* p_to_stack = create_stack(1);
    char element = 'p';
    push(p_to_stack, &element);
    ASSERT(element == *(char*)top(p_to_stack));
    dispose(p_to_stack);
};
void test_for_delete_top_element_of_character_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    char element = 'p';
    push(p_to_stack, &element);
    ASSERT(element == *(char*)pop(p_to_stack));
    dispose(p_to_stack);
};
void test_for_get_top_element_of_char_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    char element = 'p';
    push(p_to_stack, &element);
    ASSERT(element == *(char*)top(p_to_stack));
    dispose(p_to_stack);
};
//===============================String======================================
void test_for_push_String_element_at_top_of_the_stack(){
    Stack* p_to_stack = create_stack(1);
    String element = "Prajakta";
    push(p_to_stack, &element);
    ASSERT(0 == strcmp(element,*(String*)top(p_to_stack)));
    dispose(p_to_stack);
};
void test_for_delete_top_element_of_String_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    String element = "Prajakta";
    push(p_to_stack, &element);
    ASSERT(0 == strcmp(element,*(String*)pop(p_to_stack)));
    dispose(p_to_stack);
};
void test_for_get_top_element_of_String_type_from_the_stack(){
    Stack* p_to_stack = create_stack(1);
    String element = "Prajakta";
    push(p_to_stack, &element);
    ASSERT(0 == strcmp(element ,*(String*)top(p_to_stack)));
    dispose(p_to_stack);
};
// ============================Is_empty=======================================
void test_for_return_NULL_if_stack_is_empty(){
    Stack* stack = create_stack(1);
    void* result = pop(stack);
    ASSERT(NULL == result);
    dispose(stack);
};