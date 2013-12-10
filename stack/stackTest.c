#include "testUtils.h"
#include <string.h>
#include "stack.h"
#include <stdlib.h>

int areEqual(Stack* actual, Stack* expected){
	if(actual->elementSize == expected->elementSize&&
	actual->size == expected->size &&
	actual->peak == expected->peak)
	return 0 == memcmp(actual->elements,expected->elements,actual->elementSize*actual->size);
	return 1;
}
	
typedef  struct {
	int num;
	float f_num;
	double d_num;
	String string;
	char ch;
} S;

void test_1_for_create_stack_of_integer_datatype(){
	Stack *actual = create_stack(sizeof(int),3);
	int expected_arr[3] = {0,0,0};
	Stack expected = {&expected_arr,-1,3,sizeof(int)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}

void test_2_for_create_stack_of_float_datatype(){
	Stack *actual = create_stack(sizeof(float),3);
	int expected_arr[3] = {0.0f,0.0,0.0};
	Stack expected = {&expected_arr,-1,3,sizeof(float)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_3_for_create_stack_of_double_datatype(){
	Stack *actual = create_stack(sizeof(double),3);
	double expected_arr[3] = {00.00,00.00,00.00};
	Stack expected = {&expected_arr,-1,3,sizeof(double)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_4_for_create_stack_of_char_datatype(){
	Stack *actual = create_stack(sizeof(char),3);
	char expected_arr[3] = {0,0,0};
	Stack expected = {&expected_arr,-1,3,sizeof(char)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_5_for_create_stack_of_string_datatype(){
	Stack *actual = create_stack(sizeof(String),3);
	String expected_arr[3] = {"","",""};
	Stack expected = {&expected_arr,-1,3,sizeof(String)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_6_for_create_stack_of_structure_datatype(){
	Stack* actual = create_stack(sizeof(String),3);
	S *s = calloc(3,sizeof(S));
	Stack expected = {s,-1,3,sizeof(String)};
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}

//===============================PUSH===================================
void test_7_push_integer_datatype_element_into_stack(){
	int a[3] = {3,0,0};
	int result;
	int element = 3;
	Stack expected = {a,0,sizeof(int),3};
	Stack* actual = create_stack(3,sizeof(int));
	push(actual,&element);
	result = areEqual(actual,&expected);
	ASSERT(result);
}
void test_8_for_push_float_datatype_element_in_to_stack(){
	Stack* stack = create_stack(sizeof(float),5);
	float element = 5;
	int res = push(stack,&element);
	ASSERT(res==1);
	ASSERT(((float*)stack->elements)[stack->peak] == element);
}
void test_9_for_push_double_datatype_element_in_to_stack(){
	Stack* stack = create_stack(sizeof(double),5);
	double element = 5;
	int res = push(stack,&element);
	ASSERT(res==1);
	ASSERT(((double*)stack->elements)[stack->peak] == element);
}
void test_10_for_push_char_datatype_element_in_to_stack(){
	Stack* stack = create_stack(sizeof(char),5);
	char element = 'a';
	int res = push(stack,&element);
	ASSERT(res==1);
	ASSERT(((char*)stack->elements)[stack->peak] == element);
}
void test_11_for_push_string_datatype_element_in_to_stack(){
	Stack* actual = create_stack(sizeof(String),5);
	String a[] = {"a","\0","\0","\0","\0"};
	Stack expected = {a,0,5,sizeof(String)};
	String element = "a";
	push(actual,&element);
	ASSERT(areEqual(actual, &expected));
	dispose(actual);
}

void test_12_pushing_an_integer_element_when_stack_is_full(){
Stack* stack = create_stack(sizeof(int),3);
int element = 5;
int result = push(stack,&element);
result = push(stack,&element);
ASSERT(stack->peak == 1);
result = push(stack,&element);
ASSERT(result == 1);
};

//=================================POP===========================================

void test_13_for_pop_int_datatype_element_from_stack(){
	Stack* actual = create_stack(sizeof(int),3);
	int exp_arr[3] = {8,0,0};
	Stack expected = {exp_arr,-1,3,sizeof(int)};
	int element = 8;
	int res = push(actual,&element);
	void* pop_element = pop(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_14_for_pop_float_datatype_element_from_stack(){
	Stack* actual = create_stack(sizeof(float),3);
	float exp_arr[3] = {8.8,0,0};
	Stack expected = {exp_arr,-1,3,sizeof(float)};
	float element = 8.8;
	float res = push(actual,&element);
	void* pop_element = pop(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_15_for_pop_double_datatype_element_from_stack(){
	Stack* actual = create_stack(sizeof(double),3);
	double exp_arr[3] = {88.88,0,0};
	Stack expected = {exp_arr,-1,3,sizeof(double)};
	double element = 88.88;
	double res = push(actual,&element);
	void* pop_element = pop(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_16_for_pop_char_datatype_element_from_stack(){
	Stack* actual = create_stack(sizeof(char),3);
	String exp_arr[3] = {'u','\0','\0'};
	Stack expected = {exp_arr,-1,3,sizeof(char)};
	char element = 'u';
	char res = push(actual,&element);
	void* pop_element = pop(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}
void test_17_for_pop_string_datatype_element_from_stack(){
	Stack* actual = create_stack(sizeof(String),3);
	String exp_arr[3] = {"uu","\0","\0"};
	Stack expected = {exp_arr,-1,3,sizeof(String)};
	String element = "uu";
	int res = push(actual,&element);
	void* pop_element = pop(actual);
	ASSERT(areEqual(actual,&expected));
	dispose(actual);
}

void test_18_pop_an_integer_element_when_stack_is_empty(){
Stack* stack = create_stack(sizeof(int), 3);
int* res;
res = pop(stack);
ASSERT(NULL == res);
};

//=============================is_full=================================
void test_19_inserting_an_element_when_stack_is_full(){
	int expected_array[] = {0,0,0};
	Stack stack = {&expected_array,2,3,sizeof(int)};
	int res = is_full(&stack);
	ASSERT(1 == res);
}
void test_20_inserting_an_element_when_stack_is_not_full(){
	int expected_array[] = {0,0,0};
	Stack stack = {&expected_array,1,3,sizeof(int)};
	int res = is_full(&stack);
	ASSERT(0 == res);
}
//============================is_empty==================================
void test_21_is_empty_returns_1_if_the_stack_is_empty(){
	Stack* stack = create_stack(sizeof(int), 3);
	int result = is_empty(stack);
	ASSERT(1==result);
}
void test_22_is_empty_returns_0_if_stack_is_not_empty(){
	Stack* stack = create_stack(sizeof(int), 3);
	int no = 8;
	int element = push(stack,&no);
	int result = is_empty(stack);
	ASSERT(0 == result);
}

//==========================peak======================================
void test_23_checking_value_of_peak_for_integer_datatype(){
	Stack* stack = create_stack(sizeof(int),3);
	int *result;
	int res;
	int element = 8;
	res = push(stack,&element);
	result = peak(stack);
	ASSERT(element == *result);
}
void test_24_checking_value_of_peak_for_float_datatype(){
	Stack* stack = create_stack(sizeof(float),3);
	float *result;
	float res;
	float element = 8.8f;
	res = push(stack,&element);
	result = peak(stack);
	ASSERT(element == *result);
}
void test_25_checking_value_of_peak_for_double_datatype(){
	Stack* stack = create_stack(sizeof(double),3);
	double *result;
	double res;
	double element = 8.8f;
	res = push(stack,&element);
	result = peak(stack);
	ASSERT(element == *result);
}
void test_26_checking_value_of_peak_for_character_datatype(){
	Stack* stack = create_stack(sizeof(char),3);
	char *result;
	char res;
	char element = 'a';
	res = push(stack,&element);
	result = peak(stack);
	ASSERT(element == *result);
}
void test_27_checking_value_of_peak_for_string_datatype(){
	Stack* stack = create_stack(sizeof(String),3);
	String *result;
	int res;
	String element = "aaa";
	res = push(stack,element);
	result = peak(stack);
	ASSERT(strcmp(element, *(String*)result) == 0);
}