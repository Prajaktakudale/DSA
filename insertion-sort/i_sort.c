#include "i_sort.h"
#include <stdlib.h>
#include <memory.h>

void isort(void* base, size_t numberOfElements, size_t elementSize,
			compare comp) {
    int i, j;
    void* temp = calloc(1, elementSize);
    void* elementToCompare;
    int comparisonResult;
    
    for (i = 1; i < numberOfElements; i++) {
    	memcpy(temp, base + (i * elementSize), elementSize);

    	for (j = i - 1; j >= 0; j--) {
    		elementToCompare = base + j * elementSize;
    		comparisonResult = comp(temp, elementToCompare);

    		if (comparisonResult < 0) {
    			memcpy(elementToCompare + elementSize, 
    					elementToCompare, elementSize);    		    						
    			memcpy(elementToCompare, temp, elementSize);    			    					    					
    		}
    		
    	}     	
    }
    free(temp);
}
