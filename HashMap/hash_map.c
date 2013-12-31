#include "hash_map.h"
#include "hash.h"
#include <stdlib.h>

void createListAsBucket(void *bucket){
    DLL* list;
    list = create_link_list();
	bucket = list;
};

HashMap createHashMap(hash hashFunc,comparefunc compare){
    HashMap table;
    int i;
    int initial_no_of_buckets = 10;
    ArrayList buckets = create(initial_no_of_buckets);
    table.buckets = calloc(1,sizeof(ArrayList));
    *(ArrayList*)table.buckets = buckets;
    table.hashFunc = hashFunc;
    table.cmp = compare;
    for(i = 0;i < initial_no_of_buckets;i++)
        add(table.buckets, calloc(1,sizeof(DLL)));
    	iterate(*(ArrayList*)table.buckets,createListAsBucket);
    return table;
};

Record* CreateRecordInHashMap(void *key,void *value){
     Record *record = calloc(1,sizeof(Record));
     record->key = key;
     record->value = value;
     return record;
};

int InsertRecordInHashMap(HashMap *table,void *key,void *value){
     DLL *list;
     Record *record;
     int bucket_No;
     int initial_no_of_buckets = 10;
     bucket_No = (table->hashFunc(key)) % initial_no_of_buckets;
     record = CreateRecordInHashMap(key,value);
     list = (DLL*)get(table->buckets,bucket_No);
     insert_new_node(list,list->size,record);
     return 1;
};

void* GetHashMapWithBuckets(HashMap *table,void *key){
     DLL *list_as_bucket;
     int bucket_No;
     Record *record;
     int initial_no_of_buckets = 10;
     bucket_No = (table->hashFunc(key)) % initial_no_of_buckets;
     list_as_bucket = (DLL*)get(table->buckets,bucket_No);
     record = DLL_data(*list_as_bucket,key,table->cmp);
     if(record != NULL)    
         return record->value;
     return record;
};