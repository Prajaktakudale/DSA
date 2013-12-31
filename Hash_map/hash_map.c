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

int HashMap_remove(HashMap* map, void* key){
    int bucket_No,index = 0;
    DLL *list;
    Iterator it;
    Record *hash_node;
    bucket_No = (map->hashFunc(key)) % 10;
    list = (DLL*)get(map->buckets, bucket_No);
    it = getIterator_forList(list);
    while(it.hasNext(&it)){
            hash_node = it.next(&it);
            if(0 == map->cmp(hash_node->key,key))
                     break;        
            index++;
    }
    if(index == list->size)
            return 0;
    return delete_node(list, index);
};

Iterator HashMap_keys(HashMap *map){
    Iterator Arrayiterator = getIteratorForArray(map->buckets);
    Iterator listIterator;
    Record hash_node;
    DLL *dList = malloc(sizeof(DLL));
    while(Arrayiterator.hasNext(&Arrayiterator)){
            listIterator = getIterator_forList(Arrayiterator.next(&Arrayiterator));
            while(listIterator.hasNext(&listIterator)){
                    hash_node = *(Record*)listIterator.next(&listIterator);
                    insert_new_node(dList, dList->size, hash_node.key);
            }
    }
    return getIterator_forList(dList);
};