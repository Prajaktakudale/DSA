#include "stack.h"
#include <stdlib.h>
#include <string.h> 

void dispose(Stack* stack){
	free(stack->elements);
	free(stack);
}

Stack* create_stack(int elementSize, int size){
	Stack *stack = calloc(1,sizeof(Stack));
	stack->elementSize = elementSize;
	stack->elements= calloc(size,elementSize);
	stack->size = size;
	stack->peak  = (-1);
	return stack; 
};

int is_full(Stack* stack){
	return(stack->size == (stack->peak+1));
}

int push(Stack* stack,void* element){
	int address;
	if(is_full(stack))
		return 0;
	stack->peak = stack->peak + 1;
	address = stack->peak*stack->elementSize;
	memcpy(stack->elements+address,element,stack->elementSize);
	return 1;
}

int is_empty(Stack* stack){
	return((stack->peak)== -1);
}
void* pop(Stack* stack){
	int address;
	void* pop_element = malloc(stack->elementSize);
	if(is_empty(stack))
		return 0;
	address = stack->peak*stack->elementSize;
	memcpy(pop_element,stack->elements+address,stack->elementSize);
	stack->peak = stack->peak - 1;
	return pop_element;
}
void* peak(Stack* stack){
	int address;
	void* peak_element = malloc(stack->elementSize);
	if(is_empty(stack))
		return 0;
	address = stack->peak*stack->elementSize;
	memcpy(peak_element,stack->elements+address,stack->elementSize);
	return peak_element;
}