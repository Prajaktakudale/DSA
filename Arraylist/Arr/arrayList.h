typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);