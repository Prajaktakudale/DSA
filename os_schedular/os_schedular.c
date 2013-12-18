#include "os_schedular.h"
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
        queue->size++;
        return queue->size;        
}
int insertProcess1(Queue *queue,P *prev,P *process ,P *next){
        prev->next = process;
        process->next = next;
        return ++queue->size;
}
int insertProcess(Queue *queue, P *process){
        P *prev, *next,*ver;
        int i = 0;
        ver = queue->head;
        if(queue->size == 0)                
                return insertAtStart(queue, process);
        if(process->p_priority < ver->p_priority)
                return insertAtStart(queue, process);
        for(ver = 0;ver->next != '\0';ver = ver->next){
                prev = ver;
                next = ver->next;
                if(process->p_priority < next->p_priority)
                        return insertProcess1(queue ,prev, process ,next);
        };
        ver->next = process;
        process->next = '\0';
        return ++queue->size;
}
int removeProcess1(Queue *queue,P *prev ,P *next){
        prev->next = next->next;
        return --queue->size;
}

int removeProcess(Queue *queue){
        P *ver,*prev,*next;
        int i = 0;
        ver = queue->head;

        if(queue->size == 1){
                if(ver->p_time == 0)
                        queue->head = '\0';
                return --queue->size;
        }
        for(;ver->next != '\0';ver = ver->next){
                prev = ver;
                next = ver->next;
                if(next->p_time == 0)
                        return removeProcess1(queue ,prev ,next);
        }
        if('\0' == ver->next){
                prev->next = '\0';
                return --queue->size;
        };
        return 0;
}