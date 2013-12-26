#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"
#include <stdio.h>

const int SUCCESS = 1;
const int FAILURE = 0;

typedef struct {
	int id;
	char* name;
	int age;
} Intern;
Intern Prajakta = {15440, "Prajakta",18};
Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}
void tearDown() {
	dispose(internsPtr);	
}
void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);
	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}
void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}
void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;
	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);
	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));
	dispose(listPtr);		
}
void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}
void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}
void test_insert_at_middle_should_shift_the_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &Prajakta);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&Prajakta == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}
void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}
void test_should_search_element_in_list(){
	int result = insert(internsPtr, 0, &prateek);
	int res;
	Intern *actual = (Intern*)get(internsPtr,0);
	ASSERT(result == SUCCESS);
	res = search(internsPtr,&prateek);
	ASSERT(res == SUCCESS);
}
void test_should_not_search_element_in_list(){
	int result = insert(internsPtr, 0, &prateek);
	int res;
	Intern *actual = (Intern*)get(internsPtr,0);
	ASSERT(result == SUCCESS);
	res = search(internsPtr,&Prajakta);
	ASSERT(res == FAILURE);
}
void test_iterator_gives_true_when_next_data_is_present(){
        Iterator it;
        insert(internsPtr, 0, &prateek);
        it = getIterator(internsPtr);
        ASSERT(1 == it.hasNext(&it));
}
void test_iterator_gives_false_when_next_data_is_not_present(){
        Iterator it;
        it = getIterator(internsPtr);
        ASSERT(0 == it.hasNext(&it));
}
void test_iterator_gives_the_data_of_next_index(){
        Iterator it;
        insert(internsPtr, 0, &Prajakta);
        insert(internsPtr, 0, &prateek);
        it = getIterator(internsPtr);
        ASSERT(&prateek == it.next(&it));
        ASSERT(&Prajakta == it.next(&it));
        ASSERT(NULL == it.next(&it));
}
void test_should_add_element_in_list(){
	Intern Prajakta = {15440, "Prajakta",18};
	Intern prateek = {15386, "prateek", 18};
	add(internsPtr,&Prajakta);
	add(internsPtr,&prateek);
	ASSERT(&Prajakta == get(internsPtr,0));
	ASSERT(&prateek == get(internsPtr,1));
}
void test_should_remove_element_in_list(){
	void* data;
	Intern Prajakta = {15440, "Prajakta",18};
	Intern prateek = {15386, "prateek", 18};
	Intern ji = {13432, "Immortal", 17};
	add(internsPtr,&Prajakta);
	add(internsPtr,&prateek);
	add(internsPtr,&ji);
	data = remove_element(internsPtr,1);
	ASSERT(data == &prateek);
}
void test_should_remove_first_element_in_list(){
	void* data;
	Intern Prajakta = {15440, "Prajakta",18};
	Intern prateek = {15386, "prateek", 18};
	Intern ji = {13432, "Immortal", 17};
	add(internsPtr,&Prajakta);
	add(internsPtr,&prateek);
	add(internsPtr,&ji);
	data = remove_element(internsPtr,1);
	ASSERT(data == &prateek);
}
void printId(void* data){
        Intern intern = *(Intern*)data;
        printf("%d\n", intern.id);
}

void test_prints_data_of_each_element(){
        add(internsPtr, &prateek);
        add(internsPtr, &ji);
        iterate(interns, printId);
}