typedef struct node {
        void* data;
        struct node* next;
        struct node* prev;
} Node;

typedef struct {
        Node* start;
        int size;
} DLL;      // double link list
typedef char String[256];

DLL* create_list();