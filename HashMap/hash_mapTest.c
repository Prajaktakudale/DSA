#include "testUtils.h"
#include "hash_map.h"
#include <string.h>

int hashFun(void *key){
        return *(int*)key;
};
int compare_key(void* first_key,void* second_key){
        return *(int*)first_key - *(int*)second_key;
};

typedef struct{
        int key;
        char value[50];
}Item;

Item rice = {1,"rice"};
Item sugar = {2,"sugar"};
Item salt = {3,"salt"};

void test_for_add_new_record_into_hashMap(){
    HashMap record = createHashMap(hashFun,compare_key);
    ASSERT(InsertRecordInHashMap(&record,&sugar.key,&sugar.value));
    ASSERT(0 == strcmp(sugar.value,
          (char*)GetHashMapWithBuckets(&record,&sugar.key)));
}
void test_for_add_more_records_into_hashMap(){
    HashMap record = createHashMap(hashFun,compare_key);
    ASSERT(InsertRecordInHashMap(&record,&sugar.key,&sugar.value));
    ASSERT(InsertRecordInHashMap(&record,&rice.key,&rice.value));
    ASSERT(0 == strcmp(sugar.value,
          (char*)GetHashMapWithBuckets(&record,&sugar.key)));
    ASSERT(0 == strcmp(rice.value,
          (char*)GetHashMapWithBuckets(&record,&rice.key)));
}
void test_for_get_record_from_hashmap(){
    HashMap record = createHashMap(hashFun,compare_key);
    ASSERT(NULL == GetHashMapWithBuckets(&record,&sugar.key));
}
void test_for_remove_record_from_hashmap_by_cheking_key(){
        HashMap record = createHashMap(hashFun, compare_key);
        ASSERT(InsertRecordInHashMap(&record, &sugar.key, &sugar.value));
        ASSERT(InsertRecordInHashMap(&record, &salt.key, &salt.value));
        ASSERT(1 == Remove_record_from_hashmap(&record, &sugar.key));
        ASSERT(1 == Remove_record_from_hashmap(&record, &salt.key));
        ASSERT(NULL == GetHashMapWithBuckets(&record, &sugar.key));
}
void test_for_remove_record_from_hashmap_when_record_is_not_present(){
        HashMap record = createHashMap(hashFun, compare_key);
        ASSERT(InsertRecordInHashMap(&record, &sugar.key, &sugar.value));
        ASSERT(0 == Remove_record_from_hashmap(&record, &rice.key));
}