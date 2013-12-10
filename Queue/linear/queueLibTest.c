#include "testUtils.h"
#include "queueLib.h"
#include <string.h>
#include <stdlib.h>

int areEqual(Queue* actual, Queue* expected){
	if(actual->elementSize == expected->elementSize&&
	actual->size == expected->size &&
	actual->end == expected->end)
	return 0 == memcmp(actual->elements,expected->elements,actual->elementSize*actual->size);
	return 1;
}
	
typedef  struct {
	int num;
	float f_num;
	double d_num;
	String string;
	char ch;
} Q;

void test_for_create_queue_of_integer_datatype(){
	Queue *actual = createQueue(sizeof(int),3);
	int expected_arr[5] = {0,0,0,0,0};
	Queue expected = {&expected_arr,-1,5,sizeof(int)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_for_create_queue_of_float_datatype(){
	Queue *actual = createQueue(sizeof(float),3);
	float expected_arr[5] = {0.0,0.0,0.0,0.0,0.0};
	Queue expected = {&expected_arr,-1,5,sizeof(float)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_for_create_queue_of_double_datatype(){
	Queue *actual = createQueue(sizeof(double),3);
	double expected_arr[5] = {00.00,00.00,00.00,00.00,00.00};
	Queue expected = {&expected_arr,-1,5,sizeof(double)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_for_create_queue_of_char_datatype(){
	Queue *actual = createQueue(sizeof(char),3);
	char expected_arr[5] = {'\0','\0','\0','\0','\0'};
	Queue expected = {&expected_arr,-1,5,sizeof(char)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_for_create_queue_of_string_datatype(){
	Queue *actual = createQueue(sizeof(String),3);
	String expected_arr[5] = {'\0','\0','\0','\0','\0'};
	Queue expected = {&expected_arr,-1,5,sizeof(String)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_for_create_queue_of_structure_datatype(){
	Queue* actual = createQueue(sizeof(String),3);
	Q *s = calloc(3,sizeof(Q));
	Queue expected = {s,-1,3,sizeof(String)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}

void test_push_integer_datatype_element_into_queue(){
	Queue* actual = createQueue(3,sizeof(int));
	int element = 3;
	int a[5] = {3,0,0,0,0};
	int result;
	Queue expected = {a,0,5,sizeof(int)};
	enqueue(actual,&element);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_push_float_datatype_element_into_queue(){
	Queue* actual = createQueue(3,sizeof(float));
	float a[5] = {3.0,0.0,0.0,0.0,0.0};
	int result;
	float element = 3.0;
	Queue expected = {a,0,5,sizeof(float)};
	enqueue(actual,&element);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_push_Double_datatype_element_into_queue(){
	Queue* actual = createQueue(3,sizeof(double));
	double a[5] = {03.00,00.00,00.00,00.00,00.00};
	int result;
	double element = 3.00;
	Queue expected = {a,0,5,sizeof(double)};
	enqueue(actual,&element);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_push_chatacter_datatype_element_into_queue(){
	Queue* actual = createQueue(3,sizeof(char));
	char a[3] = {'a','\0','\0'};
	int result;
	char element = 'a';
	Queue expected = {a,0,3,sizeof(char)};
	enqueue(actual,&element);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_push_String_datatype_element_into_queue(){
	Queue* actual = createQueue(3,sizeof(String));
	String a[3] = {"praju","\0","\0"};
	int result;
	String element = "praju";
	Queue expected = {a,0,3,sizeof(String)};
	enqueue(actual,&element);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};
void test_push_Structure_datatype_element_into_queue(){
	Queue* actual = createQueue(3,sizeof(String));
	Q *element = calloc(1,sizeof(Q));
	int a[3] = {0,0,0};
	int result;
	int no = 0;
	Queue expected = {a,0,3,sizeof(String)};
	enqueue(actual,&element);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
};

void test_when_stack_is_full(){
    int a[] = {8,8,8,8,8};
    Queue queue = {a,4,5,sizeof(int)};
    int result = is_full(&queue);
    ASSERT(1 == result);
};
void test_user_should_be_informed_when_stack_is_not_full(){
    int a[] = {8,8,8};
    Queue queue = {a,1,3,sizeof(int)};
    int result = is_full(&queue);
    ASSERT(0 == result);
};
void test_remove_an_element_when_queue_is_empty(){
    Queue* queue = createQueue(sizeof(int),0);
    int* start;
    start = dequeue(queue);
    ASSERT(start == NULL);
};
void test_for_remove_first_element_of_integer_to_queue()
{
	Queue* actual = createQueue(3,sizeof(int));
	int exp_arr[] = {0,8,8};
	Queue expected = {exp_arr,2,3,sizeof(int)};
	int element = 8;
	int* start;
	int result = enqueue(actual,&element);
	start = dequeue(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_for_remove_first_element_of_float_to_queue()
{
	Queue* actual = createQueue(3,sizeof(float));
	float exp_arr[] = {0.0,8.0,8.0};
	Queue expected = {exp_arr,2,3,sizeof(float)};
	float element = 8.0;
	int* start;
	float result = enqueue(actual,&element);
	start = dequeue(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);

}
void test_for_remove_first_element_of_double_to_queue()
{
	Queue* actual = createQueue(3,sizeof(double));
	double exp_arr[] = {0.0,8.0,8.0};
	Queue expected = {exp_arr,2,3,sizeof(double)};
	double element = 8.0;
	int* start;
	double result = enqueue(actual,&element);
	start = dequeue(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_for_remove_first_element_of_char_to_queue()
{
	Queue* actual = createQueue(sizeof(char),3);
	char exp_arr[] = {'c',0,0};
	Queue expected = {exp_arr,0,3,sizeof(char)};
	char element = 'c';
	char* start;
	char result = enqueue(actual,&element);
	start = dequeue(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
