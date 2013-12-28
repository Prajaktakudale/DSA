typedef int (*compareFunc)(void *first,void *second);
void bubble_sort(void **elements,int number_of_elements,compareFunc compare);