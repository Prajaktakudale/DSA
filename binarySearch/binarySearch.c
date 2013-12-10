#include "binarySearch.h"
#include <math.h>
#include <stdlib.h>

void* binary_search(void *key,void *base,int length,int element_size,int(*compare)(void*,void*))
{
        int start = 0;
        int end = length-1;
        int mid,search;
        while(start <= end){
                mid = (start + end) / 2;
                search = compare(key,base+(mid*element_size));
                if(!search)
                        return base+(mid*element_size);
                if(search < 0)
                        end = mid -1;
                if(search > 0)
                        start = mid + 1;
        }
        return NULL;
}