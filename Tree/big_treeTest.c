#include "testUtils.h"
#include "big_tree.h"
#include <string.h>

int compare_int(void *num1,void *num2){
        return *(int*)num1 - *(int*)num2;
}
int compare_float(void *num1,void *num2){
        return *(float*)num1 - *(float*)num2;
}
int compare_double(void *num1,void *num2){
        return *(double*)num1 - *(double*)num2;
}
int compare_char(void *num1,void *num2){
        return *(char*)num1 - *(char*)num2;
}
void test_for_inserting_root_node(){
        Tree tree = createTree(compare_int);
        int node_data = 1;
        int res = insert_node(&tree, NULL, &node_data);
        ASSERT(1 == res);
}
void test_for_inserting_root_node_for_float(){
        Tree tree = createTree(compare_float);
        float node_data = 1.0f;
        int res = insert_node(&tree, NULL, &node_data);
        ASSERT(1 == res);
}
void test_for_inserting_root_node_for_double(){
        Tree tree = createTree(compare_float);
        double node_data = 1.0;
        int res = insert_node(&tree, NULL, &node_data);
        ASSERT(1 == res);
}
void test_for_inserting_root_node_for_char(){
        Tree tree = createTree(compare_char);
        char node_data = 'p';
        int res = insert_node(&tree, NULL, &node_data);
        ASSERT(1 == res);
}
void test_for_insert_child_node_under_parent_node(){
        Tree tree = createTree(compare_int);
        int node_data[] = {1,2,3};
        Iterator res;
        insert_node(&tree, NULL, &node_data[0]);
        insert_node(&tree, &node_data[0], &node_data[1]);
        insert_node(&tree, &node_data[1], &node_data[2]);
        res = get_children(&tree, &node_data[1]);
        ASSERT(3 == *(int*)res.next(&res));
}
// void test_for_insert_child_node_under_parent_node_of_float_datatype(){
//         Tree tree = createTree(compare_float);
//         float node_data[] = {1.0f,2.0f,3.0f};
//         Iterator res;
//         insert_node(&tree, NULL, &node_data[0]);
//         insert_node(&tree, &node_data[0], &node_data[1]);
//         insert_node(&tree, &node_data[1], &node_data[2]);
//         res = get_children(&tree, &node_data[1]);
//         ASSERT(3.0 == *(int*)res.next(&res));
// }
void test_for_inserting_nodes_at_different_level(){
        Tree tree = createTree(compare_int);
        Iterator it;
        int node_data[5] = {1,2,3,4,5};
        ASSERT(insert_node(&tree, NULL, &node_data[0]));
        ASSERT(insert_node(&tree, &node_data[0], &node_data[1]));
        ASSERT(insert_node(&tree, &node_data[1], &node_data[2]));
        ASSERT(insert_node(&tree, &node_data[2], &node_data[3]));
}
void test_for_deleting_node_from_tree(){
        Tree tree = createTree(compare_int);
        Iterator res;
        int node_data[2] = {1,2};
        ASSERT(insert_node(&tree, NULL, &node_data));
        ASSERT(insert_node(&tree, &node_data, &node_data[1]));
        ASSERT(deleteNodeFromTree(&tree,&node_data[1]));
        res = get_children(&tree, &node_data);
        ASSERT(0 == res.hasNext(&res));
}
void test_for_delete_root_node_from_tree(){
        Tree tree = createTree(compare_int);
        Iterator res;
        int node_data[1] = {1};
        ASSERT(insert_node(&tree, NULL, &node_data));
}
void test_delete_nodes_from_different_level(){
        Tree tree = createTree(compare_int);
        Iterator res;
        int node_data[5] = {1,2,3,4,5};
        ASSERT(insert_node(&tree, NULL, &node_data[0]));
        ASSERT(insert_node(&tree, &node_data[0], &node_data[1]));
        ASSERT(insert_node(&tree, &node_data[1], &node_data[2]));
        ASSERT(insert_node(&tree, &node_data[2], &node_data[3]));
        ASSERT(insert_node(&tree, &node_data[3], &node_data[4]));
        ASSERT(insert_node(&tree, &node_data[4], &node_data[5]));
        ASSERT(deleteNodeFromTree(&tree, &node_data[5]));
        res = get_children(&tree, &node_data[4]);
        ASSERT(0 == res.hasNext(&res));
}
void test_for_search_element_in_the_tree(){
        Tree tree = createTree(compare_int);
        Iterator res;
        int node_data[5] = {1,2,3,4,5};
        ASSERT(insert_node(&tree, NULL, &node_data[0]));
        ASSERT(insert_node(&tree, &node_data[0], &node_data[1]));
        ASSERT(insert_node(&tree, &node_data[1], &node_data[2]));
        ASSERT(insert_node(&tree, &node_data[2], &node_data[3]));
        ASSERT(search(&tree,&node_data[2]));
        ASSERT(search(&tree,&node_data[1]));
}
void test_for_not_search_element_in_the_tree_when_its_not_present(){
        Tree tree = createTree(compare_int);
        Iterator res;
        int node_data[5] = {1,2,3,4,5};
        ASSERT(insert_node(&tree, NULL, &node_data[0]));
        ASSERT(insert_node(&tree, &node_data[0], &node_data[1]));
        ASSERT(insert_node(&tree, &node_data[1], &node_data[2]));
        ASSERT(insert_node(&tree, &node_data[2], &node_data[3]));
        ASSERT(search(&tree,&node_data[2]));
        ASSERT(search(&tree,&node_data[1]));
        ASSERT(0 == search(&tree,&node_data[5]));
}