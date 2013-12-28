#include "testUtils.h"
#include <memory.h>
#include <string.h>
#include "bubble_sort.h"

typedef char String[256];
int compare_ints(void* element1, void* element2){
        return *(int*)element1 - *(int*)element2;
};
int compare_floats(void* element1, void* element2){
        return *(float*)element1 - *(float*)element2;
};
int compare_doubles(void* element1, void* element2){
        return *(double*)element1 - *(double*)element2;
};
int compare_chars(void* element1, void* element2){
        return *(char*)element1 - *(char*)element2;
};
int compare_Strings(void* element1, void* element2){
        return *(String*)element1 - *(String*)element2;
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
void test_to_sort_the_elements_list_of_double_datatype(){
        int length = 4,i;
        double before_sorting[4] = {8.0,10.0,7.0,4.0};
        double after_sorting[4] = {4.0,7.0,8.0,10.0};
        void* elements[4] = {&before_sorting[0],&before_sorting[1],&before_sorting[2],&before_sorting[3]};
        bubble_sort(elements,4,compare_doubles);
        for(i=0;i<length;i++)
                ASSERT(after_sorting[i] == *(double*)elements[i]);
};
void test_to_sort_the_elements_list_of_character_datatype(){
        int length = 4,i;
        char before_sorting[4] = {'d','c','b','a'};
        char after_sorting[4] = {'a','b','c','d'};
        void* elements[4] = {&before_sorting[0],&before_sorting[1],&before_sorting[2],&before_sorting[3]};
        bubble_sort(elements,4,compare_chars);
        for(i=0;i<length;i++)
                ASSERT(after_sorting[i] == *(char*)elements[i]);
};