#include "testUtils.h"
#include <memory.h>
#include <string.h>
#include "i_sort.h"

int compare_int(void* element1, void* element2){
        return *(int*)element1 - *(int*)element2;
};

int compare_float(void* element1, void* element2){
        return *(float*)element1 - *(float*)element2;
};

int compare_double(void* element1, void* element2){
        return *(double*)element1 - *(double*)element2;
};

int compare_string(void* element1, void* element2){
        return strcmp(*(String*)element1,*(String*)element2);
};

int areEqual(void* element1, void* element2,size_t size){
        int res = memcmp(element1,element2,sizeof(element1)*size);
        return 0 == res;
};

//=================================Integer==========================================

void test_to_sort_the_elements_list_of_integers_datatype() {
        int elements[4] = {8,7,1,4};
        int expected[4] = {1,4,7,8};
        isort(elements,4,sizeof(int),compare_int);
        ASSERT(areEqual(&elements,&expected,4));
};
void test_to_sort_the_int_elements_when_list_is_alredy_sorted_in_desending_order() {
        int elements[4] = {11,10,9,8};
        int expected[4] = {8,9,10,11};
        isort(elements, 4,sizeof(int),compare_int);
        ASSERT(areEqual(&elements,&expected,4));
};
void test_to_sort_the_elements_list_of_int_datatype_when_list_is_already_sorted(){
        int elements[4] = {1,2,3,4};
        int expected[4] = {1,2,3,4};
        isort(elements,4,sizeof(int),compare_int);
        ASSERT(areEqual(&elements,&expected,4));
};

//=================================Float============================================

void test_to_sort_the_elements_list_of_float_datatype() {
        float elements[4] = {8.0f,10.0f,7.0f,4.0};
        float expected[4] = {4.0f,7.0f,8.0f,10.0f};
        isort(elements,4,sizeof(float),compare_float);
        ASSERT(areEqual(&elements,&expected,4));
};
void test_to_sort_the_float_elements_when_list_is_alredy_sorted_in_desending_order() {
        float elements[4] = {10.0f,9.0f,8.0f,7.0f};
        float expected[4] = {7.0f,8.0f,9.0f,10.0f};
        isort(elements,4,sizeof(float),compare_float);
        ASSERT(areEqual(&elements,&elements,4));
};
void test_to_sort_the_elements_list_of_float_datatype_when_list_is_already_sorted() {
        float elements[4] = {4.0f,7.0f,8.0f,9.0f};
        float expected[4] = {4.0f,7.0f,8.0f,9.0f};
        isort(elements,4,sizeof(float), compare_float);
        ASSERT(areEqual(&elements,&expected,4));
};

//=================================double============================================

void test_to_sort_the_elements_list_of_double_datatype() {
        double elements[4] = {8.0,7.0,9.0,4.0};
        double expected[4] = {4.0,7.0,8.0,9.0};
        isort(elements,4,sizeof(double), compare_double);
        ASSERT(areEqual(&elements,&expected,4));
};
void test_to_sort_the_double_elements_when_list_is_alredy_sorted_in_desending_order() {
        double elements[4] = {10.0,9.0,8.0,7.0};
        double expected[4] = {4.0,7.0,8.0,9.0};
        isort(elements, 4, sizeof(double), compare_double);
        ASSERT(areEqual(&elements,&elements,4));
};
void test_to_sort_the_elements_list_of_double_datatype_when_list_is_already_sorted() {
        double elements[4] = {4.0,7.0,8.0,9.0};
        double expected[4] = {4.0,7.0,8.0,9.0};
        isort(elements, 4, sizeof(double), compare_double);
        ASSERT(areEqual(&elements,&expected,4));
};

//=================================String===============================================

void test_to_sort_the_elements_list_of_string_datatype(){
        String elements[4] = {"bbcc","dddd","aaaa","ccff"};
        String expected[4] = {"aaaa","bbcc","ccff","dddd"};
        isort(elements, 4, sizeof(String), compare_string);
        ASSERT(areEqual(&elements,&expected,4));
};
void test_to_sort_the_string_elements_when_list_is_alredy_sorted_in_desending_order(){
        String elements[4] = {"dddd","bbcc","ccff","aaaa"};
        String expected[4] = {"aaaa","bbcc","ccff","dddd"};
        isort(elements, 4, sizeof(String), compare_string);
        ASSERT(areEqual(&elements,&expected,4));
};
void test_to_sort_the_elements_list_of_string_datatype_when_list_is_already_sorted()  {
        String elements[4] = {"aaaa","bbcc","ccff","dddd"};
        String expected[4] = {"aaaa","bbcc","ccff","dddd"};
        isort(elements, 4, sizeof(String), compare_string);
        ASSERT(areEqual(&elements,&expected,4));
};