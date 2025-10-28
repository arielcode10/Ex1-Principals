#include "Stack.h"


/*
* Function push item into stack
* INPUT: s (stack), element 
*/
void push(Stack* s, unsigned int element)
{
	push_node(&s->head, element);
}

/*
* Function pops the first item pushed into the stack
* INPUT: s 
* OUTPUT: last item pushed 
*/
int pop(Stack* s)
{
	return pop_node(&s->head);
}

/*
* Function inits stack
* INPUT: s
* OUTPUT: None
*/
void initStack(Stack* s)
{
	s->head = nullptr;
}

/*
* Frees memory in stack
* INPUT: s
*/
void cleanStack(Stack* s)
{
	delete_list(&s->head);
}

/*
* Function checks if stack is empty
* INPUT: s
* OUTPUT: if stack is empty
*/
bool isEmpty(Stack* s)
{
	return s->head == nullptr;
}



