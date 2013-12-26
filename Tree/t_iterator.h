typedef struct {
        void* node;
} TreeIterator;

void* next(TreeIterator* it);
int hasNext(TreeIterator* it);