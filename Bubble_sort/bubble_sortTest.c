#include "testUtils.h"
#include <memory.h>
#include <string.h>
#include "bubble_sort.h"

int compare_ints(void* element1, void* element2){
        return *(int*)element1 - *(int*)element2;
};
int compare_floats(void* element1, void* element2){
        return *(float*)element1 - *(float*)element2;
};
void test_to_sort_the_elements_list_of_integers_datatype(){
        int length = 4,i;
        int before_sorting[4] = {8,7,1,4};
        int after_sorting[4] = {1,4,7,8};
        void* elements[4] = {&before_sorting[0],&before_sorting[1],&before_sorting[2],&before_sorting[3]};
        bubble_sort(elements,4,compare_ints);
        for(i=0;i<length;i++)
                ASSERT(after_sorting[i] == *(int*)elements[i]);
};
void test_to_sort_the_elements_list_of_float_datatype(){
        int length = 4,i;
        float before_sorting[4] = {8.0f,10.0f,7.0f,4.0f};
        float after_sorting[4] = {4.0f,7.0f,8.0f,10.0f};
        void* elements[4] = {&before_sorting[0],&before_sorting[1],&before_sorting[2],&before_sorting[3]};
        bubble_sort(elements,4,compare_floats);
        for(i=0;i<length;i++)
                ASSERT(after_sorting[i] == *(float*)elements[i]);
};