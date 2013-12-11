#include "q4_test.h"
#include <stdlib.h>
Queue* createNewProcess(){
        Queue *queue = calloc(sizeof(Queue),1);
        return queue;
}
int insertAtStart(Queue *queue, P *process){
        if(queue->head == NULL)
                        process->next = NULL;
        else process->next = queue->head;
        queue->head = process;
        queue->length++;
        return queue->length;        
}
int insertProcess1(Queue *queue,P *prev,P *process ,P *next){
        prev->next = process;
        process->next = next;
        return ++queue->length;
}
int insertProcess(Queue *queue, P *process){
        P *prev, *next,*ver;
        int i = 0;
        ver = queue->head;
        if(queue->length == 0)                
                return insertAtStart(queue, process);
        if(process->p_priority < ver->p_priority)
                return insertAtStart(queue, process);
        for(ver = 0;ver->next != NULL;ver = ver->next){
                prev = ver;
                next = ver->next;
                if(process->p_priority < next->p_priority)
                        return insertProcess1(queue ,prev, process ,next);
        };
        ver->next = process;
        process->next = NULL;
        return ++queue->length;
}
