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

	testStarted("test_create_circular_queue_with_integer_datatype_element");
	setup();
		test_create_circular_queue_with_integer_datatype_element();
	tearDown();
	testEnded();
	testStarted("test_create_circular_queue_with_float_datatype_element");
	setup();
		test_create_circular_queue_with_float_datatype_element();
	tearDown();
	testEnded();
	testStarted("test_create_circular_queue_with_double_datatype_element");
	setup();
		test_create_circular_queue_with_double_datatype_element();
	tearDown();
	testEnded();
	testStarted("test_create_circular_queue_with_char_datatype_element");
	setup();
		test_create_circular_queue_with_char_datatype_element();
	tearDown();
	testEnded();
	testStarted("test_create_circular_queue_with_String_datatype_element");
	setup();
		test_create_circular_queue_with_String_datatype_element();
	tearDown();
	testEnded();
	testStarted("test_create_circular_queue_with_structure_datatype");
	setup();
		test_create_circular_queue_with_structure_datatype();
	tearDown();
	testEnded();
	testStarted("test_enqueue_integer_element_at_end_of_queue");
	setup();
		test_enqueue_integer_element_at_end_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_float_element_at_end_of_queue");
	setup();
		test_enqueue_float_element_at_end_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_double_element_at_end_of_queue");
	setup();
		test_enqueue_double_element_at_end_of_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_char_element_at_end_of_queue");
	setup();
		test_enqueue_char_element_at_end_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_integer_element_at_front_of_queue");
	setup();
		test_dequeue_integer_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_float_element_at_front_of_queue");
	setup();
		test_dequeue_float_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_double_element_at_front_of_queue");
	setup();
		test_dequeue_double_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_character_element_at_front_of_queue");
	setup();
		test_dequeue_character_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_String_element_at_front_of_queue");
	setup();
		test_dequeue_String_element_at_front_of_queue();
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
