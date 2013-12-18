#include "testUtils.h"
#include "os_schedular.h"
#include <stdlib.h>

Queue *queue;

void test_for_create_new_process(){
        Queue expected = {NULL,0};
        queue = createNewProcess();
        ASSERT(queue->size == expected.size);
        ASSERT(queue->head == expected.head);
}

void test_for_add_process_in_schedular(){
        Queue expected = {NULL,0};
        Status statusp1 = {0,1,0};
        P p1 = {"pA",10,statusp1,3,NULL};
        queue = createNewProcess();
        ASSERT(1 == add_process(queue, &p1));
        ASSERT(queue->head == &p1);
        ASSERT(queue->head->next == NULL);
}
void test_add_process_which_has_low_priority(){
        Status statusp1 = {0,1,0};
        P *second,*third,*fourth,*fifth;
        P p1 = {"p1",10,statusp1,5,NULL};
        P p2 = {"p2",5,statusp1,1,NULL};
        queue = createNewProcess();
        ASSERT(1 == add_process(queue, &p1));
        ASSERT(2 == add_process(queue, &p2));
        second = queue->head->next;
        third = second->next;
        ASSERT(NULL == fifth->next);
}
void test_for_add_new_process_which_has_higher_priority_than_exsisting_process(){
        Queue expected = {NULL,0};
        Status statusp1 = {0,1,0};
        P p1 = {"pA",10,statusp1,3,NULL};
        P p2 = {"pB",5,statusp1,1,NULL};
        queue = createNewProcess();
        ASSERT(1 == add_process(queue, &p1));
        ASSERT(2 == add_process(queue, &p2));
        ASSERT(queue->head == &p2);
        ASSERT(queue->head->next == &p1);
}
void test_for_remove_process_between_two_processes(){
        Status statusp1 = {0,1,0};
        P pA = {"pA",10,statusp1,1,NULL};
        P pB = {"pB",0,statusp1,5,NULL};
        P pC = {"pC",10,statusp1,7,NULL};
        queue = createNewProcess();
        add_process(queue, &pA);
        add_process(queue, &pB);
        add_process(queue, &pC);
        ASSERT(2 == remove_process(queue));
        ASSERT(queue->head->next == &pC);
}
void test_for_delete_first_process_from_schedular(){
        Status statusp1 = {0,1,0};
        P pA = {"p1",0,statusp1,5,NULL};
        queue = createNewProcess();
        add_process(queue, &pA);
        ASSERT(0 == remove_process(queue));
}