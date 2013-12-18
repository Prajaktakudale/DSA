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

	testStarted("test_for_creates_a_new_queue");
	setup();
		test_for_creates_a_new_queue();
	tearDown();
	testEnded();
	testStarted("test_for_add_element_at_the_starting_of_queue");
	setup();
		test_for_add_element_at_the_starting_of_queue();
	tearDown();
	testEnded();
	testStarted("test_for_add_element_which_have_lower_priority_for_int");
	setup();
		test_for_add_element_which_have_lower_priority_for_int();
	tearDown();
	testEnded();
	testStarted("test_for_add_double_element_to_the_queue");
	setup();
		test_for_add_double_element_to_the_queue();
	tearDown();
	testEnded();
	testStarted("test_for_add_char_element_to_the_queue");
	setup();
		test_for_add_char_element_to_the_queue();
	tearDown();
	testEnded();
	testStarted("test_for_enqueue_elements_which_has_different_priority");
	setup();
		test_for_enqueue_elements_which_has_different_priority();
	tearDown();
	testEnded();
	testStarted("test_for_removes_starting_element_of_the_queue");
	setup();
		test_for_removes_starting_element_of_the_queue();
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
