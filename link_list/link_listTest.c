#include "testUtils.h"
#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void test_for_create_link_list_Node(){
        Node expected = {'\0','\0','\0'};
        Node *actual = create_Node('\0','\0','\0');
        ASSERT(expected.next == actual->next);
        ASSERT(expected.prev == actual->prev);
        ASSERT(expected.data == actual->data);
}
void test_for_create_double_list(){
        DLL* list = create_link_list();
        ASSERT(list->size == 0); 
}
void test_for_add_data_to_empty_list(){
        DLL* list = create_link_list();
        int num = 1;
        insert_new_node(list,0,&num);
        ASSERT(1 == *(int*)list->head->data);
        ASSERT(list->size == 1);
}
void test_for_add_data_to_end_of_link_list(){
        DLL* list = create_link_list();
        Node *second;
        int num1 = 1,num2 = 2;
        insert_new_node(list, 0, &num1);
        insert_new_node(list, 1, &num2);
        second = list->head->next;
        ASSERT(1 == *(int*)list->head->data);
        ASSERT(2 == *(int*)second->data);
        ASSERT(list->size == 2);
        ASSERT(list->head == second->prev);
}
void test_for_add_data_in_between_list(){
        DLL* list = create_link_list();
        Node *second;
        int num1 = 1,num2 = 2;
        insert_new_node(list,0,&num1);
        insert_new_node(list,1,&num2);
        second = list->head->next;
        ASSERT(1 == *(int*)list->head->data);
        ASSERT(2 == *(int*)second->data);
}
void test_for_delete_first_node(){
        DLL* list = create_link_list();
        int num1 = 1,num2 = 2,num3 = 3,num4 = 4;
        insert_new_node(list,0,&num1);
        insert_new_node(list,1,&num2);
        insert_new_node(list,2,&num3);
        insert_new_node(list,3,&num4);
        ASSERT(delete_node(list,0));
        ASSERT(3 == list->size);
        ASSERT(2 == *(int*)list->head->data);
}
void test_for_delete_first_node_in_list_of_one_node(){
        DLL* list = create_link_list();
        int num1 = 1,num2 = 2,num3 = 3;
        insert_new_node(list,0,&num1);
        ASSERT(delete_node(list, 0));
        ASSERT(0 == list->size);
        ASSERT(NULL == list->head);
}
void test_for_delete_node_between_two_nodes(){
        DLL* list = create_link_list();
        int num1 = 1,num2 = 2,num3 =3,num4 = 4,num5 = 5;
        insert_new_node(list,0,&num1);
        insert_new_node(list,1,&num2);
        insert_new_node(list,2,&num3);
        insert_new_node(list,3,&num4);
        insert_new_node(list,4,&num5);
        ASSERT(delete_node(list,1));
        ASSERT(4 == list->size);
        ASSERT(3 == *(int*)list->head->next->data);
}
void test_for_delete_last_node(){
        DLL* list = create_link_list();
        int num1 = 1,num2 = 2,num3 = 3;
        insert_new_node(list,0,&num1);
        insert_new_node(list,1,&num2);
        insert_new_node(list,2,&num3);
        ASSERT(delete_node(list, 2));
        ASSERT(2 == list->size);
        ASSERT(NULL == list->head->next->next);
}
void test_for_find_node_by_using_index(){
        DLL* list = create_link_list();
        int num1 = 1,num2 = 2,num3 = 2;
        insert_new_node(list,0,&num1);
        insert_new_node(list,1,&num2);
        insert_new_node(list,2,&num3);
        ASSERT(2 == traverse(list,&num3));
}