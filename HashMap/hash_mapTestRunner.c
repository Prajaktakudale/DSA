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

	testStarted("test_for_add_new_record_into_hashMap");
	setup();
		test_for_add_new_record_into_hashMap();
	tearDown();
	testEnded();
	testStarted("test_for_add_more_records_into_hashMap");
	setup();
		test_for_add_more_records_into_hashMap();
	tearDown();
	testEnded();
	testStarted("test_for_get_record_from_hashmap");
	setup();
		test_for_get_record_from_hashmap();
	tearDown();
	testEnded();
	testStarted("test_for_get_record_from_hashMap_which_is_not_present");
	setup();
		test_for_get_record_from_hashMap_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_for_remove_record_from_hashmap_by_cheking_key");
	setup();
		test_for_remove_record_from_hashmap_by_cheking_key();
	tearDown();
	testEnded();
	testStarted("test_for_remove_record_from_hashmap_when_record_is_not_present");
	setup();
		test_for_remove_record_from_hashmap_when_record_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_for_getting_all_keys_in_hash_map");
	setup();
		test_for_getting_all_keys_in_hash_map();
	tearDown();
	testEnded();
	testStarted("test_for_iterating_when_no_records_are_present");
	setup();
		test_for_iterating_when_no_records_are_present();
	tearDown();
	testEnded();
	testStarted("test_for_rehashing_no_of_buckets");
	setup();
		test_for_rehashing_no_of_buckets();
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
