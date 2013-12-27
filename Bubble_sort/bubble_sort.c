#include "bubble_sort.h"
#include <stdlib.h>
#include <memory.h>
void bubble_Sort(void **elements,int number_of_elements,compareFunc compare){
    int i,j,result_compare;
    void *temp;
    for (i=1;i<number_of_elements;i++)
    {
        for(j=0;j<(number_of_elements-i);j++){
            result_compare = compare(elements[j],elements[j+1]);
                if(0 < result_compare){
                    temp = elements[j];
                    elements[j] = elements[j+1];
                    elements[j+1] = temp;
                }
        }
    }
};