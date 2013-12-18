#include "testUtils.h"
#include "circular_queue.h"

c_queue *integerQueue;
int are_equal(c_queue* actual,c_queue* expected){
        int temp = expected->size*expected->elementsize;
        return (actual->elementsize == expected->elementsize) &&
        (actual->size == expected->size) &&
        (actual->start == expected->start) &&
        (actual->end == expected->end &&
        (0 == memcmp(actual->elements,expected->elements,temp)));
}
typedef  struct {
	int num;
	float f_num;
	double d_num;
	String string;
	char ch;
} queue;

void test_create_circular_queue_with_integer_datatype_element(){
        c_queue* actual = create_queue(sizeof(int),3);
        int a[5] = {0,0,0,0,0};
        c_queue expected = {a,3,-1,-1,sizeof(int)};
       //  printf("%d\n %d",actual->start,expected.start);
        ASSERT(are_equal(actual,&expected));
};
void test_create_circular_queue_with_float_datatype_element(){
        c_queue* actual = create_queue(sizeof(float),5);
        float a[5] = {0.0,0.0,0.0,0.0,0.0};
        c_queue expected = {a,5,-1,-1,sizeof(float)};
        ASSERT(are_equal(actual,&expected));
};
void test_create_circular_queue_with_double_datatype_element(){
        c_queue* actual = create_queue(sizeof(double),5);
        double a[5] = {0.0,0.0,0.0,0.0,0.0};
        c_queue expected = {a,5,-1,-1,sizeof(double)};
        ASSERT(are_equal(actual,&expected));
};
void test_create_circular_queue_with_char_datatype_element(){
        c_queue* actual = create_queue(sizeof(char),5);
        char a[5] = {'\0','\0','\0','\0','\0'};
        c_queue expected = {a,5,-1,-1,sizeof(char)};
        ASSERT(are_equal(actual,&expected));
};
void test_create_circular_queue_with_String_datatype_element(){
        c_queue* actual = create_queue(sizeof(String),5);
        String a[5] = {"\0","\0","\0","\0","\0"};
        c_queue expected = {a,5,-1,-1,sizeof(String)};
        ASSERT(are_equal(actual,&expected));
};
void test_create_circular_queue_with_structure_datatype(){
        c_queue* actual = create_queue(sizeof(String),5);
        queue *q = calloc(5,sizeof(queue));
        c_queue expected = {q,5,-1,-1,sizeof(String)};
        ASSERT(are_equal(actual,&expected));
}
void test_enqueue_integer_element_at_end_of_queue(){
        c_queue* c_Queue;
        int c=1;
        c_Queue = create_queue(sizeof(int),5);
        ASSERT(enqueue(c_Queue,&c));
        ASSERT(*(int*)(c_Queue->elements)==1);
        ASSERT(c_Queue->end==0);
}
void test_enqueue_float_element_at_end_of_queue(){
        c_queue* c_Queue;
        float c=1.0f;
        c_Queue = create_queue(sizeof(float),5);
        ASSERT(enqueue(c_Queue,&c));
        ASSERT(*(float*)(c_Queue->elements)==1.0f);
        ASSERT(c_Queue->end==0);
}
void test_enqueue_double_element_at_end_of_queue(){
        c_queue* c_Queue;
        double c=1.0;
        c_Queue = create_queue(sizeof(double),5);
        ASSERT(enqueue(c_Queue,&c));
        ASSERT(*(double*)(c_Queue->elements)==1.0);
        ASSERT(c_Queue->end==0);
}
void test_enqueue_char_element_at_end_of_queue(){
        c_queue* c_Queue;
        char c='a';
        c_Queue = create_queue(sizeof(char),5);
        ASSERT(enqueue(c_Queue,&c));
        ASSERT(*(char*)(c_Queue->elements)=='a');
        ASSERT(c_Queue->end==0);
}
void test_dequeue_integer_element_at_front_of_queue(){
        void* element;
        c_queue* c_Queue;
        int arr[]={8,2,1};
        c_Queue = create_queue(sizeof(int),5);
        enqueue(c_Queue,&arr[0]);
        enqueue(c_Queue,&arr[1]);
        ASSERT(c_Queue->end == 1);
        element = dequeue(c_Queue);
        ASSERT(*(int*)element == 8);
        ASSERT(c_Queue->start == 0);
}
void test_dequeue_float_element_at_front_of_queue(){
        void* element;
        c_queue* c_Queue;
        float arr[]={2.8f,8.8f,4.8f};
        c_Queue = create_queue(sizeof(float),5);
        enqueue(c_Queue,&arr[0]);
        enqueue(c_Queue,&arr[1]);
        ASSERT(c_Queue->end == 1);
        element = dequeue(c_Queue);
        ASSERT(*(float*)element == 2.8f);
        ASSERT(c_Queue->start == 0);
}
void test_dequeue_double_element_at_front_of_queue(){
        void* element;
        c_queue* c_Queue;
        double arr[]={2.8,8.8,4.8};
        c_Queue = create_queue(sizeof(double),5);
        enqueue(c_Queue,&arr[0]);
        enqueue(c_Queue,&arr[1]);
        ASSERT(c_Queue->end == 1);
        element = dequeue(c_Queue);
        ASSERT(*(double*)element == 2.8);
        ASSERT(c_Queue->start == 0);
}
void test_dequeue_character_element_at_front_of_queue(){
        void* element;
        c_queue* c_Queue;
        char arr[]={'a','b','c'};
        c_Queue = create_queue(sizeof(char),5);
        enqueue(c_Queue,&arr[0]);
        enqueue(c_Queue,&arr[1]);
        ASSERT(c_Queue->end == 1);
        element = dequeue(c_Queue);
        ASSERT(*(char*)element == 'a');
        ASSERT(c_Queue->start == 0);
}
void test_dequeue_String_element_at_front_of_queue(){
        void* element;
        c_queue* c_Queue;
        String arr[]={"abc","bbc","ccd"};
        c_Queue = create_queue(sizeof(String),5);
        enqueue(c_Queue,&arr[0]);
        enqueue(c_Queue,&arr[1]);
        element = dequeue(c_Queue);
        ASSERT(c_Queue->start == 0);
}