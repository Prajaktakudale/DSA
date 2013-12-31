#include "iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);
typedef void ForEach(void* data);
int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);
int search(ArrayList *list, void *data);
int add(ArrayList *list,void *data);
void* remove_element(ArrayList *list,int index);
Iterator getIteratorForArray(ArrayList* list);
void dispose(ArrayList *list);
void iterate(ArrayList list, ForEach* forEach);