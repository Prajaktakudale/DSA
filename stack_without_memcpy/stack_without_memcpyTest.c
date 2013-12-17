#include <stdlib.h>
#include "stack_without_memcpy.h"
#include "testUtils.h"

void test_create_stacks_a_stack_of_given_length (){
    Stack* p_to_stack = create_stack(3);
    void* topElement = top(p_to_stack);
    ASSERT(0 == topElement);
    dispose(p_to_stack);
};
