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
    HashMap map = createHashMap(hashFun,compare_key);
    ASSERT(InsertRecordInHashMap(&map,&sugar.key,&sugar.value));
    ASSERT(0 == strcmp(sugar.value,
          (char*)GetHashMapWithBuckets(&map,&sugar.key)));
}
void test_for_add_more_records_into_hashMap(){
    HashMap map = createHashMap(hashFun,compare_key);
    ASSERT(InsertRecordInHashMap(&map,&sugar.key,&sugar.value));
    ASSERT(InsertRecordInHashMap(&map,&rice.key,&rice.value));
    ASSERT(0 == strcmp(sugar.value,
          (char*)GetHashMapWithBuckets(&map,&sugar.key)));
    ASSERT(0 == strcmp(rice.value,
          (char*)GetHashMapWithBuckets(&map,&rice.key)));
}
void test_for_get_record_from_hashmap(){
    HashMap map = createHashMap(hashFun,compare_key);
    ASSERT(NULL == GetHashMapWithBuckets(&map,&sugar.key));
}

