#include "./need/link_list.h"
 
typedef DLL Stack;
int push(Stack* start, void* data);
void pop(Stack* start);
int isEmpty(Stack* stack);
void* top(Stack* stack);