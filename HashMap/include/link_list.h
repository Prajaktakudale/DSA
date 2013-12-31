# include "iterator.h"
typedef struct type{
        void *data;
        struct type *next,*prev;
}Node;

typedef struct{
        int size;
        Node *head;
} DLL; //double link list

typedef int (*compare_for_list)(void *elementToCompare,void *element);
DLL* create_link_list();
Node* create_Node(void* prev_add,void *data,void* next_add);
int insert_new_node(DLL* List,int index,void *element);
int delete_node(DLL* List,int index);
void* DLL_data(DLL List, void *searchElement, compare_for_list cmp);
int traverse(DLL* List,void *element);
Iterator getIterator_forList(DLL *dList);