#include "testUtils.h"
#include "binarySearch.h"
#include <stdlib.h>
#include <string.h>

int compare_int(void* key,void* element){
    return (*(int*)key - *(int*)element );
}

int compare_float(void* key,void* element){
    return (*(float*)key - *(float*)element );
}

int compare_double(void* key,void* element){
    return (*(double*)key - *(double*)element );
}

int compare_string(void* key,void* element){
    return strcmp(*(String*)key, *(String*)element );
}

//-----------------------------------Integer---------------------------------
void test_to_search_int_element_in_the_array_of_3_elements(){
    int arr[]={1,2,3};
    int key=1;
    ASSERT(1==*(int*)binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare_int));
}

void test_to_find_int_element_which_is_absent_in_given_array(){
    int arr[]={1,2,3,4,5};
    int key=0;
    ASSERT(NULL==(int*)binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare_int));
}
//-----------------------------------Float---------------------------------

void test_to_search_float_element_in_the_array_of_3_elements(){
    float arr[]={0.1f,0.2f,0.3f};
    float key=0.2f;
    ASSERT(0.2f==*(float*)binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]),compare_float));
}

void test_to_find_float_element_which_is_absent_in_given_array(){
    float arr[]={0.1f,0.2f,0.3f,0.4f,0.5f};
    float key=8.8f;
    ASSERT(NULL==(float*)binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare_float));
}
//-----------------------------------Double---------------------------------

void test_to_search_double_element_in_the_array_of_3_elements(){
    double arr[]={0.2,2.0,5.0};
    double key=5.0;
    ASSERT(5.0==*(double*)binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare_double));
}

void test_to_find_double_element_which_is_absent_in_given_array(){
    double arr[]={0.1,0.2,0.3,0.4,0.5};
    double key=8.8;
    ASSERT(NULL==(double*)binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare_double));
}
//-----------------------------------String---------------------------------

void test_to_search_String_element_in_the_array_of_3_elements(){
	String arr[]={"prajakta","vilas","kudale"};
    String key="prajakta";
    ASSERT(0==strcmp("prajakta",*(String*)binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare_string)));
}

void test_to_find_string_element_which_is_absent_in_given_array(){
	String arr[]={"doll","mall","call","tall","hall"};
    String key="roll";
    ASSERT(NULL==binary_search(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare_string));
}