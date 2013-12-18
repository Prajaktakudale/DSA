typedef struct{
	void* elements;
	int peak;
	int size;
	int elementSize;
} Stack;

typedef char String[256];

void dispose(Stack* stack);
Stack* create_stack(int elementSize,int size);
int is_full(Stack* stack);
int push(Stack *stack,void* element);
int is_empty(Stack* stack);
void* pop(Stack* stack);
void* peak(Stack* stack);