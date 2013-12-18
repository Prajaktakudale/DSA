#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
        void* elements;
        int size;
        int start;
        int end;
        int elementsize;        
} c_queue;
typedef char String[256];

c_queue* create_queue(int elementsize,int size);
bool is_full(c_queue* c_Queue);
bool enqueue(c_queue *c_Queue,void* element);
bool is_empty(c_queue* c_Queue);
void* dequeue(c_queue* c_Queue);