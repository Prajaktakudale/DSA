#include "include/iterator.h"

typedef int (*compare)(void* firstElement, void* secondElement);

typedef struct {
        compare cmp;
        void *root;
} Tree;

Tree createTree(compare cmp);
int insert_node(Tree* tree, void* parentData, void* data);
Iterator get_children(Tree* tree, void* parentData);
int deleteNodeFromTree(Tree* tree, void* data);
int search(Tree* tree, void* data);