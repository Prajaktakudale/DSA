typedef struct{
	void* elements;
	int end;
	int size;
	int elementSize;
} Queue;

typedef char String[256];

void dispose(Queue* queue);
Queue* createQueue(int elementSize,int size);
int is_full(Queue* queue);
int enqueue(Queue* queue,void* element);
int is_empty(Queue* queue);
void* dequeue(Queue* queue);