#include "queueLib.h"
#include <stdlib.h>
#include <string.h> 

void dispose(Queue* queue){
	free(queue->elements);
	free(queue);
}

Queue* createQueue(int elementSize, int size){
	Queue *queue = calloc(1,sizeof(Queue));
	queue->elementSize = elementSize;
	queue->elements= calloc(size,elementSize);
	queue->size = size;
	queue->end  = (-1);
	return queue; 
};

void* address(Queue* queue){
        return (queue->end*queue->elementSize)+queue->elements;
};
int is_full(Queue* queue){
	return(queue -> end == queue -> size -1);
}
int enqueue(Queue* queue,void* element){
	if(is_full(queue))
			return 0;
		queue->end ++;
		memcpy(address(queue),element,queue ->elementSize);
		return 1;
}


int is_empty(Queue* queue){
	return(queue -> end == -1);
}

void* dequeue(Queue *queue){
	void* start;
	void* temp = queue->elements+queue ->elementSize;
	if(is_empty(queue))
		return NULL;
	start = malloc(queue->elementSize);
	memcpy(start,queue->elements,queue ->elementSize);
	memmove(queue->elements,temp,queue ->size-1*queue->elementSize);
	queue->end--;
	return start;
}
