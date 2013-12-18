#include "stack_using_link_list.h"
#include <memory.h>
#include <stdlib.h>

void dispose(Stack* start){
    free(start->head);
    free(start);
};
int push(Stack* start, void* data){
        insert_new_node(start, start->size, data);
        return 1;
};
void pop(Stack* start){
        delete_node(start, start->size-1);
};
int isEmpty(Stack* start){
    return 0 == start->size;
};
void* top(Stack *start){
    Node* head;
    if(isEmpty(start))
        return NULL;
    head = start->head;
    while(head->next!=NULL){
        head = head->next;
    }
    return head->data;
};