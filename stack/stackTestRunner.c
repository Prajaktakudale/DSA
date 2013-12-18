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

	testStarted("test_1_for_create_stack_of_integer_datatype");
	setup();
		test_1_for_create_stack_of_integer_datatype();
	tearDown();
	testEnded();
	testStarted("test_2_for_create_stack_of_float_datatype");
	setup();
		test_2_for_create_stack_of_float_datatype();
	tearDown();
	testEnded();
	testStarted("test_3_for_create_stack_of_double_datatype");
	setup();
		test_3_for_create_stack_of_double_datatype();
	tearDown();
	testEnded();
	testStarted("test_4_for_create_stack_of_char_datatype");
	setup();
		test_4_for_create_stack_of_char_datatype();
	tearDown();
	testEnded();
	testStarted("test_5_for_create_stack_of_string_datatype");
	setup();
		test_5_for_create_stack_of_string_datatype();
	tearDown();
	testEnded();
	testStarted("test_6_for_create_stack_of_structure_datatype");
	setup();
		test_6_for_create_stack_of_structure_datatype();
	tearDown();
	testEnded();
	testStarted("test_7_push_integer_datatype_element_into_stack");
	setup();
		test_7_push_integer_datatype_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_8_for_push_float_datatype_element_in_to_stack");
	setup();
		test_8_for_push_float_datatype_element_in_to_stack();
	tearDown();
	testEnded();
	testStarted("test_9_for_push_double_datatype_element_in_to_stack");
	setup();
		test_9_for_push_double_datatype_element_in_to_stack();
	tearDown();
	testEnded();
	testStarted("test_10_for_push_char_datatype_element_in_to_stack");
	setup();
		test_10_for_push_char_datatype_element_in_to_stack();
	tearDown();
	testEnded();
	testStarted("test_11_for_push_string_datatype_element_in_to_stack");
	setup();
		test_11_for_push_string_datatype_element_in_to_stack();
	tearDown();
	testEnded();
	testStarted("test_12_pushing_an_integer_element_when_stack_is_full");
	setup();
		test_12_pushing_an_integer_element_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_13_for_pop_int_datatype_element_from_stack");
	setup();
		test_13_for_pop_int_datatype_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_14_for_pop_float_datatype_element_from_stack");
	setup();
		test_14_for_pop_float_datatype_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_15_for_pop_double_datatype_element_from_stack");
	setup();
		test_15_for_pop_double_datatype_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_16_for_pop_char_datatype_element_from_stack");
	setup();
		test_16_for_pop_char_datatype_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_17_for_pop_string_datatype_element_from_stack");
	setup();
		test_17_for_pop_string_datatype_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_18_pop_an_integer_element_when_stack_is_empty");
	setup();
		test_18_pop_an_integer_element_when_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_19_inserting_an_element_when_stack_is_full");
	setup();
		test_19_inserting_an_element_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_20_inserting_an_element_when_stack_is_not_full");
	setup();
		test_20_inserting_an_element_when_stack_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_21_is_empty_returns_1_if_the_stack_is_empty");
	setup();
		test_21_is_empty_returns_1_if_the_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_22_is_empty_returns_0_if_stack_is_not_empty");
	setup();
		test_22_is_empty_returns_0_if_stack_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_23_checking_value_of_peak_for_integer_datatype");
	setup();
		test_23_checking_value_of_peak_for_integer_datatype();
	tearDown();
	testEnded();
	testStarted("test_24_checking_value_of_peak_for_float_datatype");
	setup();
		test_24_checking_value_of_peak_for_float_datatype();
	tearDown();
	testEnded();
	testStarted("test_25_checking_value_of_peak_for_double_datatype");
	setup();
		test_25_checking_value_of_peak_for_double_datatype();
	tearDown();
	testEnded();
	testStarted("test_26_checking_value_of_peak_for_character_datatype");
	setup();
		test_26_checking_value_of_peak_for_character_datatype();
	tearDown();
	testEnded();
	testStarted("test_27_checking_value_of_peak_for_string_datatype");
	setup();
		test_27_checking_value_of_peak_for_string_datatype();
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
