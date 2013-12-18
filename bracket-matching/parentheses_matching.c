#include "parentheses_matching.h"
#include <stdio.h>
#include <string.h>

int is_match(Stack* stack,char s){
	return (s == ')' && *(char*)peak(stack) == '(') ||
	(s == ']' && *(char*)peak(stack) == '[') ||
	(s == '}' && *(char*)peak(stack) == '{');

}
int par_math(String s){
	Stack* stack;
	int i;

	stack = create_stack(sizeof(char),strlen(s));
	for (i = 0; i < strlen(s);i++)
	{
		if (s[i]=='(' || s[i]=='[' || s[i]=='{')
			push(stack,&s[i]);
		if (s[i]==')' || s[i]==']' || s[i]=='}'){
			if(!is_match(stack,s[i]))
				return 0;
			pop(stack);	
		}
		
	}
	if(is_empty(stack))
		return 1;
	return 0;	
}