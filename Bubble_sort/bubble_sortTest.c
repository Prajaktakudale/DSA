#include "testUtils.h"
#include <memory.h>
#include <string.h>
#include "bubble_sort.h"

int compare_int(void* element1, void* element2){
        return *(int*)element1 - *(int*)element2;
};
void test_to_sort_the_elements_list_of_integers_datatype(){
        int length = 4,i;
        int before_sorting[4] = {8,7,1,4};
        int after_sorting[4] = {1,4,7,8};
        void* elements[4] = {&before_sorting[0],&before_sorting[1],&before_sorting[2],&before_sorting[3]};
        bubble_Sort(elements,4,compare_int);
        for(i=0;i<length;i++)
                ASSERT(after_sorting[i] == *(int*)elements[i]);
};

