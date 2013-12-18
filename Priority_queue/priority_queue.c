#include <stdlib.h>
#include "priority_queue.h"

P_queue* create_queue(){
        P_queue* queue = calloc(1, sizeof(P_queue));
        return queue;
}

int enqueue(P_queue *queue, Qelement *element){
        int i = 1;
        Node* head = queue->head;
        Qelement* head_data;
        if(NULL == queue->head)
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
}