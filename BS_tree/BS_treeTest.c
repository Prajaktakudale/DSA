#include "testUtils.h"
#include "BS_tree.h"
#include "customTypes.h"
#include <stdlib.h>
#include <string.h>

typedef char String[256];
int compareInt(void* firstElement, void* secondElement){
        return *(int*)firstElement - *(int*)secondElement;
};

int compareString(void* firstElement, void* secondElement){
	return strcmp(firstElement,secondElement);
};
void test_inserts_first_data_as_root_of_the_tree(){
    int number = 15;
    BST tree = create_BST(compareInt);
    ASSERT(BST_insert(&tree,&number));
    ASSERT(BST_search(&tree,&number));
};

void test_inserts_children_of_root_data(){
    int number = 15;
    int num2 = 12;
    BST tree = create_BST(compareInt);
    ASSERT(BST_insert(&tree, &number));
    ASSERT(BST_insert(&tree,&num2));
    ASSERT(BST_search(&tree,&number));
    ASSERT(BST_search(&tree,&num2));
};

void test_inserts_left_child_when_given_data_is_less_than_node_data(){
    String names[2] = {"Prajakta", "suraj"};
    BST tree = create_BST(compareString);
    BST_insert(&tree, &names[1]);
    BST_insert(&tree, &names[0]);
    ASSERT(BST_search(&tree,&names[0]));
    ASSERT(BST_search(&tree,&names[1]));
};
