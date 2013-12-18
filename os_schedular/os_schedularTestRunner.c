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

	testStarted("test_for_create_new_process");
	setup();
		test_for_create_new_process();
	tearDown();
	testEnded();
	testStarted("test_for_add_process_in_schedular");
	setup();
		test_for_add_process_in_schedular();
	tearDown();
	testEnded();
	testStarted("test_add_process_which_has_low_priority");
	setup();
		test_add_process_which_has_low_priority();
	tearDown();
	testEnded();
	testStarted("test_for_add_new_process_which_has_higher_priority_than_exsisting_process");
	setup();
		test_for_add_new_process_which_has_higher_priority_than_exsisting_process();
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
