#include "testUtils.h"
#include "merge_sort.h"
#include <string.h>

typedef char String[256];
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
int compare_string(void* element1, void* element2){
        return strcmp(*(String*)element1, *(String*)element2) < 1;
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
void test_to_sort_the_elements_list_of_int_datatype_when_list_is_already_sorted(){
        int before_sorting[3] = {1,2,3};
        int after_sorting[3] = {1,2,3};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(int),compare_int);
        ASSERT(after_sorting[0] == *(int*)elements[0]);
        ASSERT(after_sorting[1] == *(int*)elements[1]);
        ASSERT(after_sorting[2] == *(int*)elements[2]);

};
void test_to_sort_the_elements_list_of_int_datatype_when_element_are_duplicate(){
        int before_sorting[3] = {4,2,2};
        int after_sorting[3] = {2,2,4};
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

void test_to_sort_the_elements_list_of_float_datatype_when_list_is_already_sorted(){
        float before_sorting[3] = {4.0f,7.0f,8.0f};
        float after_sorting[3] = {4.0f,7.0f,8.0f};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(float),compare_float);
        ASSERT(after_sorting[0] == *(float*)elements[0]);
        ASSERT(after_sorting[1] == *(float*)elements[1]);
        ASSERT(after_sorting[2] == *(float*)elements[2]);

};
void test_to_sort_the_elements_list_of_float_datatype_when_element_are_duplicate(){
        float before_sorting[3] = {7.0f,7.0f,4.0f};
        float after_sorting[3] = {4.0f,7.0f,7.0f};
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
void test_to_sort_the_elements_list_of_double_datatype_when_list_is_already_sorted(){        double before_sorting[3] = {4.0,7.0,8.0};
        double after_sorting[3] = {4.0,7.0,8.0,};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(double),compare_double);
        ASSERT(after_sorting[0] == *(double*)elements[0]);
        ASSERT(after_sorting[1] == *(double*)elements[1]);
        ASSERT(after_sorting[2] == *(double*)elements[2]);

};
void test_to_sort_the_elements_list_of_double_datatype_when_element_are_duplicate(){
        double before_sorting[3] = {7.0,7.0,4.0};
        double after_sorting[3] = {4.0,7.0,7.0,};
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
void test_to_sort_the_elements_list_of_char_datatype_when_list_is_already_sorted(){
        char before_sorting[3] = {'b','c','d'};
        char after_sorting[3] = {'b','c','d'};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(char),compare_char);        
        ASSERT(after_sorting[0] == *(char*)elements[0]);
        ASSERT(after_sorting[1] == *(char*)elements[1]);
        ASSERT(after_sorting[2] == *(char*)elements[2]);

};
void test_to_sort_the_elements_list_of_char_datatype_when_element_are_duplicate(){
        char before_sorting[3] = {'d','c','c'};
        char after_sorting[3] = {'c','c','d'};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(char),compare_char);
        ASSERT(after_sorting[0] == *(char*)elements[0]);
        ASSERT(after_sorting[1] == *(char*)elements[1]);
        ASSERT(after_sorting[2] == *(char*)elements[2]);

};

//================================String=======================================

void test_to_sort_the_elements_list_of_String_datatype(){
        String before_sorting[3] = {"dddd","bbcc","ccff"};
        String after_sorting[3] = {"bbcc","ccff","dddd"};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(String),compare_string);
        ASSERT(0==strcmp(after_sorting[0],*(String*)elements[0]));
        ASSERT(0==strcmp(after_sorting[1],*(String*)elements[1]));
        ASSERT(0==strcmp(after_sorting[2],*(String*)elements[2]));
};
void test_to_sort_the_elements_list_of_string_datatype_when_list_is_already_sorted(){
        String before_sorting[3] = {"bbcc","ccff","dddd"};
        String after_sorting[3] = {"bbcc","ccff","dddd"};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(String),compare_string);
        ASSERT(0==strcmp(after_sorting[0],*(String*)elements[0]));
        ASSERT(0==strcmp(after_sorting[1],*(String*)elements[1]));
        ASSERT(0==strcmp(after_sorting[2],*(String*)elements[2]));

};
void test_to_sort_the_elements_list_of_string_datatype_when_element_are_duplicate(){
        String before_sorting[3] = {"dddd","bbcc","bbcc"};
        String after_sorting[3] = {"bbcc","bbcc","dddd"};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(String),compare_string);        
        ASSERT(0==strcmp(after_sorting[0],*(String*)elements[0]));
        ASSERT(0==strcmp(after_sorting[1],*(String*)elements[1]));
        ASSERT(0==strcmp(after_sorting[2],*(String*)elements[2]));

};