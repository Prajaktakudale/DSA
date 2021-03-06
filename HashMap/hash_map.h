#include "./include/iterator.h"

typedef int (*hash)(void *key);
typedef int (*comparefunc)(void* element1, void* Element2);

typedef struct {
        void *buckets;
        hash hashFunc;
        comparefunc cmp;
        int no_of_buckets;
} HashMap;

HashMap createHashMap(hash hashFunc,comparefunc compare,int no_of_buckets);
int InsertRecordInHashMap(HashMap* table,void* key,void* value);
void* GetHashMapWithBuckets(HashMap* table, void* key);
int Remove_record_from_hashmap(HashMap* map, void* key);
Iterator Get_hashMap_keys(HashMap *map);
void dispose_hash_map(HashMap *table);