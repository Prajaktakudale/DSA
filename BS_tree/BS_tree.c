#include "BS_tree.h"
#include "customTypes.h"
#include <stdlib.h>

BST create_BST(compare comp){
    BST tree = {comp , NULL};
    return tree;
};

Node_of_BST* createBSTNode(void *data){
    Node_of_BST *node = calloc(1,sizeof(Node_of_BST));
    node->data = data;
    node->left = node->right = NULL;
    return node;
};

Node_of_BST* getParent(Node_of_BST *node,void *data,compare comp){
	int result =comp(node->data,data);
    if(result >0) 
    	if(node->left !=NULL)
			return getParent(node->left, data, comp);
    if(result < 0)
  		if(node->right !=NULL)
        	return getParent(node->right, data, comp);
    return node;
};

int BST_insert(BST *tree, void *data){
    Node_of_BST *nodeToInsert=createBSTNode(data),*node;
    if(NULL == tree->root){
        tree->root = nodeToInsert;
        return 1;
    }
    node = getParent(tree->root,data,tree->comp);
    if(node->left !=NULL){ 
    	if(0 < tree->comp(node->left->data,data))
    		node->left =nodeToInsert;
    }	
    else	
    	node->right =nodeToInsert;
    return 1;
};

int BST_search(BST *tree, void *data){
	Node_of_BST *node =tree->root; 
	if(0 == tree->comp(node->data,data))
		return 1;
    node = getParent(tree->root,data,tree->comp);
  	if(node->left !=NULL) 
    	if(0 == tree->comp(node->left->data,data)) return 1;
  	if(node->right!=NULL) 
    	if(0 == tree->comp(node->right->data,data)) return 1;
    return 0;
}; 