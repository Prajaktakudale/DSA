#include "circular_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

c_queue* create_queue(int elementsize,int size){
        c_queue* c_Queue = calloc(1,sizeof(c_queue));
        c_Queue->start = -1;
        c_Queue->end = -1;
        c_Queue->size = size;
        c_Queue->elementsize = elementsize;
        c_Queue->elements = calloc(size,elementsize);
        return c_Queue;
};
bool is_full(c_queue* c_Queue){ 
        if(c_Queue->start == -1 && c_Queue->end == c_Queue->size-1)
             return true;
        return (c_Queue->start == c_Queue->end+1);
};
bool enqueue(c_queue* c_Queue,void* element)
{
        if(is_full(c_Queue)) 
            return false;
        c_Queue->end++;
        memcpy((c_Queue->elements+(c_Queue->elementsize*c_Queue->end)),element,c_Queue->elementsize);
        return true;
};
bool is_empty(c_queue* c_Queue){
        if(c_Queue->start ==-1 && c_Queue->end == -1) 
            return true;
        return (c_Queue->start == c_Queue->end+1);
};
void* dequeue(c_queue* c_Queue){
        void* element = malloc(c_Queue->elementsize);
        if(is_empty(c_Queue)) 
            return false;
        c_Queue->start++;
        memmove(element, c_Queue->elements+(c_Queue->elementsize*c_Queue->start), c_Queue->elementsize);
        return element;
};