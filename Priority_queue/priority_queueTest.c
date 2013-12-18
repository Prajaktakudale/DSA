#include <stdlib.h>
#include "testUtils.h"
#include "priority_queue.h"


P_queue* queue;
int areElementsEqual(Qelement expected, Qelement actual){
        return expected.data == actual.data && 
        expected.priority == actual.priority;
}

Qelement* create_element(void* data,int priority){
        Qelement* element = calloc(1,sizeof(Qelement));
        element->data = data;
        element->priority = priority;
        return element;
}

void test_for_creates_a_new_queue(){
        queue = create_queue();
        ASSERT(queue->head == NULL);
        ASSERT(0 == queue->size);
}
void test_for_add_element_at_the_starting_of_queue(){
        int * num = calloc(1,sizeof(int));
        Qelement* element = create_element(num,1);
        *num = 1;
        queue = create_queue();
        enqueue(queue, element);
        ASSERT(areElementsEqual(*element,*(Qelement*)queue->head->data));
}
//================================Integer==================================

void test_for_add_element_which_have_lower_priority_for_int(){
        int * num = calloc(1,sizeof(int)*2);
        Qelement* element1 = create_element(&num[0], 1);
        Qelement* element2 = create_element(&num[1], 2);
        Qelement* element3 = create_element(&num[1], 3);
        num[0] = 1;
        num[1] = 2;
        num[2] = 3;
        queue = create_queue();
        enqueue(queue, element1);
        enqueue(queue, element2);
        enqueue(queue, element3);
        ASSERT(areElementsEqual(*element1, *(Qelement*)queue->head->data));
        ASSERT(areElementsEqual(*element2, *(Qelement*)queue->head->next->data));
}
//================================double==================================

void test_for_add_double_element_to_the_queue(){
        Node* result;
        double *num = calloc(1,sizeof(double)*3);
        Qelement* element1 = create_element(&num[0], 2);
        Qelement* element2 = create_element(&num[1], 4);
        Qelement* element3 = create_element(&num[2], 3);
        num[0] = 01.0;
        num[1] = 02.0;
        num[2] = 03.0;
        queue = create_queue();
        enqueue(queue, element1);
        enqueue(queue, element3);
        enqueue(queue, element2);
        result = queue->head->next;
        ASSERT(areElementsEqual(*element1, *(Qelement*)queue->head->data));
        ASSERT(areElementsEqual(*element3, *(Qelement*)result->data));
        result = result->next;
        ASSERT(areElementsEqual(*element2, *(Qelement*)result->data));
}

//================================character==================================

void test_for_add_char_element_to_the_queue(){
        char * char_element = calloc(1,sizeof(char)*2);
        Qelement* element1 = create_element(&char_element[0], 2);
        Qelement* element2 = create_element(&char_element[1], 3);
        char_element[0] = 'p';
        char_element[1] = 'k';
        queue = create_queue();
        enqueue(queue, element1);
        enqueue(queue, element2);
        ASSERT(areElementsEqual(*element1, *(Qelement*)queue->head->data));
}

void test_for_enqueue_elements_which_has_different_priority(){
        int* num = calloc(1,sizeof(int)*3);
        Node* result;
        Qelement* element1 = create_element(&num[0], 5);
        Qelement* element2 = create_element(&num[1], 2);
        num[0]=1;
        num[1]=2;
        queue = create_queue();
        enqueue(queue, element2);
        enqueue(queue, element1);
        result = queue->head->next;
        ASSERT(areElementsEqual(*element2, *(Qelement*)queue->head->data));
        result = result->next;
}

