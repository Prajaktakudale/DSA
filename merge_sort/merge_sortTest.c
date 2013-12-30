#include "testUtils.h"
#include "merge_sort.h"

int compare_int (void* element1, void* element2){
    return (*(int*)element1 < *(int*)element2);
};
int compare_float( void* element1, void* element2){
    return (*(float*)element1 < *(float*)element2);
};
int compare_double( void* element1, void* element2){
    return (*(double*)element1 < *(double*)element2);
};
int compare_char( void* element1, void* element2){
    return (*(char*)element1 < *(char*)element2);
};

//==============================Integer====================================

void test_to_sort_the_elements_list_of_integers_datatype(){
        int before_sorting[3] = {7,1,4};
        int after_sorting[3] = {1,4,7};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(int),compare_int);
        ASSERT(after_sorting[0] == *(int*)elements[0]);
        ASSERT(after_sorting[1] == *(int*)elements[1]);
        ASSERT(after_sorting[2] == *(int*)elements[2]);
};

//==============================Float====================================

void test_to_sort_the_elements_list_of_float_datatype(){
        float before_sorting[3] = {8.0f,7.0f,4.0f};
        float after_sorting[3] = {4.0f,7.0f,8.0f};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(float),compare_float);
        ASSERT(after_sorting[0] == *(float*)elements[0]);
        ASSERT(after_sorting[1] == *(float*)elements[1]);
        ASSERT(after_sorting[2] == *(float*)elements[2]);
};

//================================Double====================================

void test_to_sort_the_elements_list_of_double_datatype(){
        double before_sorting[3] = {8.0,7.0,4.0};
        double after_sorting[3] = {4.0,7.0,8.0,};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(double),compare_double);
        ASSERT(after_sorting[0] == *(double*)elements[0]);
        ASSERT(after_sorting[1] == *(double*)elements[1]);
        ASSERT(after_sorting[2] == *(double*)elements[2]);

};

//===============================Character====================================

void test_to_sort_the_elements_list_of_character_datatype(){
        char before_sorting[3] = {'d','c','b'};
        char after_sorting[3] = {'b','c','d'};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(char),compare_char);
        ASSERT(after_sorting[0] == *(char*)elements[0]);
        ASSERT(after_sorting[1] == *(char*)elements[1]);
        ASSERT(after_sorting[2] == *(char*)elements[2]);

};