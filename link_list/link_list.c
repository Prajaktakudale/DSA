#include <stdlib.h>
#include "link_list.h"

Node* create_Node(void *prev_add,void *data,void *next_add){
        Node *element = calloc(1,sizeof(Node));
        element->prev = prev_add;
        element->data = data;
        element->next = next_add;
        return element;
}
DLL* create_link_list(){
        DLL *List = calloc(1,sizeof(DLL));
        List->head = '\0';
        List->size = 0;
        return List;
}
int insert_new_node(DLL *List, int index, void *element){
        int i;
        Node *temp,*prev_node,*next_node,*new_node;
        if(index > List->size)
                return 0;
        temp = List->head;
        for (i = 0;i < index ; ++i){
                if(temp->next != '\0')
                        temp = temp->next;
        }
        if(i == 0 && List->size == 0){
                new_node = create_Node('\0',element,'\0');
                List->head = new_node;
                List->size++;
                return 1;
        }
        if(i == List->size){
                new_node = create_Node(temp,element,'\0');
                temp->next = new_node;
                List->size++;
                return 1;
        }
        if(i == 0){
                new_node = create_Node('\0',element,List->head);
                List->head->prev = new_node;
                List->head = new_node;
                return 1;
        }
        new_node = create_Node(temp->prev,element,temp);
        temp->prev->next = new_node;
        List->size++;
        return 1;
}
int delete_node(DLL *List, int index){
        int i;
        Node *temp,*new_node,*prev_node,*next_node;
        temp = List->head;
        if(index > List->size)
                return 0;
        for (i = 0;i<index && i<List->size;++i){
                        temp = temp->next;
        }
        if(i == 0 && List->size == 1){
                List->head = '\0';
                List->size--;
                return 1;
        }
        if(i == 0){
                List->head = temp->next;
                List->size--;
                return 1;
        }
        if(i == List->size - 1){
                temp->prev->next = '\0';
                List->size--;
                return 1;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        List->size--;
        return 1;
}