#include "./need/link_list.h"

typedef struct {
        void* data;
        int priority;
}Qelement;

typedef DLL P_queue;

P_queue* create_queue();
int enqueue(P_queue* queue, Qelement* element);
int dequeue(P_queue* queue);