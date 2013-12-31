#include "./include/iterator.h"

typedef int (*hash)(void *key);
typedef int (*comparefunc)(void* element1, void* Element2);

typedef struct {
        void *buckets;
        hash hashFunc;
        comparefunc cmp;
} HashMap;

HashMap createHashMap(hash hashFunc,comparefunc compare);
int InsertRecordInHashMap(HashMap* table,void* key,void* value);
void* GetHashMapWithBuckets(HashMap* table, void* key);
int HashMap_remove(HashMap* map, void* key);
Iterator HashMap_keys(HashMap* map);