#include "merge_sort.h"
#include <stdlib.h>

void merge_elements(void** elements,void** left,void** right,int left_length,
	       int right_length,compare com)
{
        int p, q, r;
        for(p=0,q=0;p < left_length && q < right_length;r++){
                if(com(left[p],right[p])){
                        elements[r] = left[p];
                        p++;
                }
                else{
                        elements[r] = right[q];
                        q++;
                }
        }
        for(;p < left_length;p++,r++)
                elements[r] = left[p];

        for(;q < right_length; q++,r++)
                elements[r] = right[q];
        
}

void merge_sort(void** elements,int total_elements,int element_size,compare com)
{
    int half = 2,i;
    int middle = total_elements / half;
    int right_length = total_elements - middle;
    int left_length = middle;

    void** right = calloc((total_elements-middle),element_size);
    void** left = calloc(middle,element_size);

    

    for (i = 0; i < left_length ; i++) 
    	left[i] = elements[i];

    for (i = middle; i < total_elements ; i++) 
    	right[i-middle] = elements[i];
    
    if(total_elements < half) 
    	return;

    merge_sort(right, right_length, element_size, com);
    merge_sort(left , left_length , element_size , com);

    merge_elements(elements,left,right,left_length,right_length,com);

    free(left);
    free(right);
}