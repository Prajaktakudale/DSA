typedef struct {
        void* data;
        int priority;
}Qelement;

void* create_queue();
int enqueue(void* queue, Qelement* element);
int dequeue(void* queue);