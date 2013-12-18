#include <stdlib.h>
#include "priority_queue.h"
#include "./need/link_list.h"


void* create_queue(){
       void* queue = calloc(1, sizeof(void));
        return queue;
};

int enqueue(void *queue, Qelement *element){
        int i = 1;
        Node* head = ((DLL*)queue)->head;
        Qelement* head_data;
        if(NULL == ((DLL*)queue)->head)
                return insert_new_node(queue, 0,element);
        head_data = head->data;
        if(head_data->priority > element->priority)
                return insert_new_node(queue,0,element);
        while(head->next != NULL){
                head = head->next;
                head_data = head->data;
                if(head_data->priority > element->priority){
                        return insert_new_node(queue,i,element);
                }
                i++;
        }
        return insert_new_node(queue,i,element);
};
int dequeue(void* queue){
        return delete_node(queue,0);
};