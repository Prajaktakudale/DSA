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

	testStarted("test_to_sort_the_elements_list_of_integers_datatype");
	setup();
		test_to_sort_the_elements_list_of_integers_datatype();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_int_datatype_when_list_is_already_sorted");
	setup();
		test_to_sort_the_elements_list_of_int_datatype_when_list_is_already_sorted();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_int_datatype_when_element_are_duplicate");
	setup();
		test_to_sort_the_elements_list_of_int_datatype_when_element_are_duplicate();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_float_datatype");
	setup();
		test_to_sort_the_elements_list_of_float_datatype();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_float_datatype_when_list_is_already_sorted");
	setup();
		test_to_sort_the_elements_list_of_float_datatype_when_list_is_already_sorted();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_float_datatype_when_element_are_duplicate");
	setup();
		test_to_sort_the_elements_list_of_float_datatype_when_element_are_duplicate();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_double_datatype");
	setup();
		test_to_sort_the_elements_list_of_double_datatype();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_double_datatype_when_list_is_already_sorted");
	setup();
		test_to_sort_the_elements_list_of_double_datatype_when_list_is_already_sorted();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_double_datatype_when_element_are_duplicate");
	setup();
		test_to_sort_the_elements_list_of_double_datatype_when_element_are_duplicate();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_character_datatype");
	setup();
		test_to_sort_the_elements_list_of_character_datatype();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_char_datatype_when_list_is_already_sorted");
	setup();
		test_to_sort_the_elements_list_of_char_datatype_when_list_is_already_sorted();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_char_datatype_when_element_are_duplicate");
	setup();
		test_to_sort_the_elements_list_of_char_datatype_when_element_are_duplicate();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_String_datatype");
	setup();
		test_to_sort_the_elements_list_of_String_datatype();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_string_datatype_when_list_is_already_sorted");
	setup();
		test_to_sort_the_elements_list_of_string_datatype_when_list_is_already_sorted();
	tearDown();
	testEnded();
	testStarted("test_to_sort_the_elements_list_of_string_datatype_when_element_are_duplicate");
	setup();
		test_to_sort_the_elements_list_of_string_datatype_when_element_are_duplicate();
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
