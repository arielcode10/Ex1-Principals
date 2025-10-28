#include "LinkedList.h"

/*
* Function pushes node into a linked list
* INPUT: h (head), data
* OUTPUT: None
*/
void push_node(LinkedList** h, int data)
{
	LinkedList* node = new LinkedList;
	node->data = data;
	node->next = nullptr;

	if (*h == nullptr)
	{
		*h = node;
	}
	else
	{
		LinkedList* l = *h;
		while (l->next != nullptr)
		{
			l = l->next;
		}
		l->next = node;
	}
}

/*
* Function pops last item in linked list
* INPUT: h (head)
* OUTPUT: None
*/
int pop_node(LinkedList** h)
{
	if (*h == nullptr)
		return -1;

	LinkedList* l = *h;
	int item;

	// only one node
	if (l->next == nullptr)
	{
		item = l->data;
		delete l;
		*h = nullptr;
		return item;
	}

	// more than one node
	while (l->next->next != nullptr)
	{
		l = l->next;
	}

	LinkedList* toDelete = l->next;
	item = toDelete->data;
	delete toDelete;
	l->next = nullptr;
	return item;
}


/*
* This function deletes a list
* INPUT: h (double pointer)
*/
void delete_list(LinkedList** h)
{
	LinkedList* curr = *h;
	while (curr)
	{
		LinkedList* temp = curr->next;
		delete curr;
		curr = temp;
	}
	*h = nullptr;
}