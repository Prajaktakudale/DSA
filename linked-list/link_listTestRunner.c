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

	testStarted("test_for_create_link_list_Node");
	setup();
		test_for_create_link_list_Node();
	tearDown();
	testEnded();
	testStarted("test_for_create_double_list");
	setup();
		test_for_create_double_list();
	tearDown();
	testEnded();
	testStarted("test_for_add_data_to_empty_list");
	setup();
		test_for_add_data_to_empty_list();
	tearDown();
	testEnded();
	testStarted("test_for_add_int_data_to_end_of_link_list");
	setup();
		test_for_add_int_data_to_end_of_link_list();
	tearDown();
	testEnded();
	testStarted("test_for_add_double_data_to_end_of_link_list");
	setup();
		test_for_add_double_data_to_end_of_link_list();
	tearDown();
	testEnded();
	testStarted("test_for_add_char_data_to_end_of_link_list");
	setup();
		test_for_add_char_data_to_end_of_link_list();
	tearDown();
	testEnded();
	testStarted("test_for_add_data_in_between_list");
	setup();
		test_for_add_data_in_between_list();
	tearDown();
	testEnded();
	testStarted("test_for_delete_first_node");
	setup();
		test_for_delete_first_node();
	tearDown();
	testEnded();
	testStarted("test_for_delete_first_node_in_list_of_one_node");
	setup();
		test_for_delete_first_node_in_list_of_one_node();
	tearDown();
	testEnded();
	testStarted("test_for_delete_node_between_two_nodes");
	setup();
		test_for_delete_node_between_two_nodes();
	tearDown();
	testEnded();
	testStarted("test_for_delete_last_node");
	setup();
		test_for_delete_last_node();
	tearDown();
	testEnded();
	testStarted("test_for_find_node_by_using_index");
	setup();
		test_for_find_node_by_using_index();
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
