typedef int (*compare)(void* element1, void* element2);
void merge_sort(void** elements, int total_elements,int element_size,compare com);