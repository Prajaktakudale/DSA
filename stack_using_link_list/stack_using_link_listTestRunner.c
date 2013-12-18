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

	testStarted("test_for_create_Stack");
	setup();
		test_for_create_Stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_int_type_element_into_stack");
	setup();
		test_for_push_int_type_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_for_remove_int_element_from_stack");
	setup();
		test_for_remove_int_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_float_type_element_into_stack");
	setup();
		test_for_push_float_type_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_for_remove_float_element_from_stack");
	setup();
		test_for_remove_float_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_double_type_element_into_stack");
	setup();
		test_for_push_double_type_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_for_remove_double_element_from_stack");
	setup();
		test_for_remove_double_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_char_type_element_into_stack");
	setup();
		test_for_push_char_type_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_for_remove_char_element_from_stack");
	setup();
		test_for_remove_char_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_for_push_string_type_element_into_stack");
	setup();
		test_for_push_string_type_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_for_remove_String_element_from_stack");
	setup();
		test_for_remove_String_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_the_top_most_element_from_the_stack_integers");
	setup();
		test_gives_the_top_most_element_from_the_stack_integers();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
