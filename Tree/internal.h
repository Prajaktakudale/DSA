#include "include/link_list.h"

typedef struct tree_node{
	void* parent;
	DLL* child;
	void* data;
} TreeNode;