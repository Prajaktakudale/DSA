typedef struct {
    void** base_element;
    int size;
    int top;
} Stack;

Stack* create_stack(int size);
void* top(Stack* stack);
void dispose();
int isEmpty(Stack* stack);
int push(Stack* stack,void* element);