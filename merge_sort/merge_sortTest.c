#include "testUtils.h"
#include "merge_sort.h"

int compare_int (void* element1, void* element2){
    return (*(int*)element1 < *(int*)element2);
}

void test_to_sort_the_elements_list_of_integers_datatype(){
        int before_sorting[3] = {7,1,4};
        int after_sorting[3] = {1,4,7};
        void* elements[3] = {&before_sorting[0],&before_sorting[1],&before_sorting[2]};
        merge_sort(elements,3,sizeof(int),compare_int);
        ASSERT(after_sorting[0] == *(int*)elements[0]);
        ASSERT(after_sorting[1] == *(int*)elements[1]);
        ASSERT(after_sorting[2] == *(int*)elements[2]);
};
