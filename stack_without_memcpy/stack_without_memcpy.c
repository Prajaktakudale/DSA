#include "stack_without_memcpy.h"
#include <stdlib.h>
#include <memory.h>

void dispose(Stack* p_to_stack){
    free(p_to_stack->base_element);
    free(p_to_stack);
};

Stack* create_stack(int size){
    Stack* p_to_stack = calloc(1,sizeof(Stack));
    p_to_stack->base_element = calloc(size,sizeof(void*));
    p_to_stack->size = size;
    p_to_stack->top = 0;
    return p_to_stack;
};

int is_empty(Stack* p_to_stack){
    return p_to_stack->top == 0;
};

void* top(Stack* p_to_stack){
    void* top;
    if(is_empty(p_to_stack)) 
    	return NULL;
    top = *(p_to_stack->base_element + p_to_stack->top-1);
    return top;
};

int isFull(Stack* p_to_stack){
    return p_to_stack->top == p_to_stack->size;
};

int push(Stack* p_to_stack,void* element){
	int temp;
	temp = p_to_stack->size*sizeof(void*);
    if(isFull(p_to_stack)){
        p_to_stack->size = p_to_stack->size*2;
        p_to_stack->base_element = realloc(p_to_stack->base_element,temp);
    }
    *(p_to_stack->base_element+p_to_stack->top) = element;
    p_to_stack->top++;
    return 1;
};

void* pop(Stack* p_to_stack){
    void *pop_element;
    pop_element = top(p_to_stack);
    if(is_empty(p_to_stack)) 
    	return NULL;
    p_to_stack->top--;
    return pop_element;
};