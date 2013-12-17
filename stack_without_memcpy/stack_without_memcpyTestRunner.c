#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_create_stacks_a_stack_of_given_length");
	setup();
		test_create_stacks_a_stack_of_given_length();
	tearDown();
	testEnded();
	testStarted("test_for_push_int_element_at_top_of_the_stack");
	setup();
		test_for_push_int_element_at_top_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_delete_top_element_of_int_type_from_the_stack");
	setup();
		test_for_delete_top_element_of_int_type_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_float_element_at_top_of_the_stack");
	setup();
		test_for_push_float_element_at_top_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_delete_top_element_of_float_type_from_the_stack");
	setup();
		test_for_delete_top_element_of_float_type_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_double_element_at_top_of_the_stack");
	setup();
		test_for_push_double_element_at_top_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_delete_top_element_of_double_type_from_the_stack");
	setup();
		test_for_delete_top_element_of_double_type_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_character_element_at_top_of_the_stack");
	setup();
		test_for_push_character_element_at_top_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_delete_top_element_of_character_type_from_the_stack");
	setup();
		test_for_delete_top_element_of_character_type_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_String_element_at_top_of_the_stack");
	setup();
		test_for_push_String_element_at_top_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_delete_top_element_of_String_type_from_the_stack");
	setup();
		test_for_delete_top_element_of_String_type_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_for_return_NULL_if_stack_is_empty");
	setup();
		test_for_return_NULL_if_stack_is_empty();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
