#include <stdio.h>
#include "testUtils.h"
#include "parentheses_matching.h"
#include <string.h>

void test_1_to_check_parentheses_are_mathching(){
	String actual;
	strcpy(actual,"()");
	ASSERT(1 == par_math(actual));
}
void test_2_to_check_parentheses_are_mathching(){
	String actual;
	String input = "void main{int a,b; \n int res = (a + b) printf(res)}";
	strcpy(actual,input);
	ASSERT(1 == par_math(actual));
}
void test_2_to_check_parentheses_are_not_mathching(){
	String actual;
	strcpy(actual,"{()");
	ASSERT( 0== par_math(actual));
}
void test_3_to_check_parentheses_are_not_mathching(){
	String actual;
	strcpy(actual,"{(pra)jakt]");
	ASSERT( 0== par_math(actual));
}