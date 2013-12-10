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

	testStarted("test_for_create_queue_of_integer_datatype");
	setup();
		test_for_create_queue_of_integer_datatype();
	tearDown();
	testEnded();
	testStarted("test_for_create_queue_of_float_datatype");
	setup();
		test_for_create_queue_of_float_datatype();
	tearDown();
	testEnded();
	testStarted("test_for_create_queue_of_double_datatype");
	setup();
		test_for_create_queue_of_double_datatype();
	tearDown();
	testEnded();
	testStarted("test_for_create_queue_of_char_datatype");
	setup();
		test_for_create_queue_of_char_datatype();
	tearDown();
	testEnded();
	testStarted("test_for_create_queue_of_string_datatype");
	setup();
		test_for_create_queue_of_string_datatype();
	tearDown();
	testEnded();
	testStarted("test_for_create_queue_of_structure_datatype");
	setup();
		test_for_create_queue_of_structure_datatype();
	tearDown();
	testEnded();
	testStarted("test_push_integer_datatype_element_into_queue");
	setup();
		test_push_integer_datatype_element_into_queue();
	tearDown();
	testEnded();
	testStarted("test_push_float_datatype_element_into_queue");
	setup();
		test_push_float_datatype_element_into_queue();
	tearDown();
	testEnded();
	testStarted("test_push_Double_datatype_element_into_queue");
	setup();
		test_push_Double_datatype_element_into_queue();
	tearDown();
	testEnded();
	testStarted("test_push_chatacter_datatype_element_into_queue");
	setup();
		test_push_chatacter_datatype_element_into_queue();
	tearDown();
	testEnded();
	testStarted("test_push_String_datatype_element_into_queue");
	setup();
		test_push_String_datatype_element_into_queue();
	tearDown();
	testEnded();
	testStarted("test_push_Structure_datatype_element_into_queue");
	setup();
		test_push_Structure_datatype_element_into_queue();
	tearDown();
	testEnded();
	testStarted("test_when_stack_is_full");
	setup();
		test_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_user_should_be_informed_when_stack_is_not_full");
	setup();
		test_user_should_be_informed_when_stack_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_remove_an_element_when_queue_is_empty");
	setup();
		test_remove_an_element_when_queue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_for_remove_first_element_of_integer_to_queue");
	setup();
		test_for_remove_first_element_of_integer_to_queue();
	tearDown();
	testEnded();
	testStarted("test_for_remove_first_element_of_float_to_queue");
	setup();
		test_for_remove_first_element_of_float_to_queue();
	tearDown();
	testEnded();
	testStarted("test_for_remove_first_element_of_double_to_queue");
	setup();
		test_for_remove_first_element_of_double_to_queue();
	tearDown();
	testEnded();
	testStarted("test_for_remove_first_element_of_char_to_queue");
	setup();
		test_for_remove_first_element_of_char_to_queue();
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
