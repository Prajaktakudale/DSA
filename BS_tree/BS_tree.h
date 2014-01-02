typedef int (*compare)(void* firstElement, void* secondElement);

typedef struct {
        compare comp;
        void *root;
} BST; //Binary Search tree

BST create_BST(compare comp);
int BST_insert(BST* tree, void* data);
int BST_search(BST *tree, void* data);
int BST_delete(BST *tree, void* data);