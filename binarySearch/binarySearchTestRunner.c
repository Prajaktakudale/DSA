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

	testStarted("test_to_search_int_element_in_the_array_of_3_elements");
	setup();
		test_to_search_int_element_in_the_array_of_3_elements();
	tearDown();
	testEnded();
	testStarted("test_to_find_int_element_which_is_absent_in_given_array");
	setup();
		test_to_find_int_element_which_is_absent_in_given_array();
	tearDown();
	testEnded();
	testStarted("test_to_search_float_element_in_the_array_of_3_elements");
	setup();
		test_to_search_float_element_in_the_array_of_3_elements();
	tearDown();
	testEnded();
	testStarted("test_to_find_float_element_which_is_absent_in_given_array");
	setup();
		test_to_find_float_element_which_is_absent_in_given_array();
	tearDown();
	testEnded();
	testStarted("test_to_search_double_element_in_the_array_of_3_elements");
	setup();
		test_to_search_double_element_in_the_array_of_3_elements();
	tearDown();
	testEnded();
	testStarted("test_to_find_double_element_which_is_absent_in_given_array");
	setup();
		test_to_find_double_element_which_is_absent_in_given_array();
	tearDown();
	testEnded();
	testStarted("test_to_search_String_element_in_the_array_of_3_elements");
	setup();
		test_to_search_String_element_in_the_array_of_3_elements();
	tearDown();
	testEnded();
	testStarted("test_to_find_string_element_which_is_absent_in_given_array");
	setup();
		test_to_find_string_element_which_is_absent_in_given_array();
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
