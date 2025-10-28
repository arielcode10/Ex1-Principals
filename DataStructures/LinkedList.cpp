#include "LinkedList.h"
#include <iostream>
/*
* Function pushes node into a linked list
* INPUT: h (head), data
* OUTPUT: None
*/
void push_node(LinkedList* h, int data)
{
	LinkedList* node = new LinkedList; // create new node
	node->data = data;
	node->next = nullptr;

	// add node to head
	while (h->next != nullptr)
	{
		h = h->next;
	}

	h->next = node; // chain

}

/*
* Function pops last item in linked list
* INPUT: h (head)
* OUTPUT: None
*/
void pop_node(LinkedList** h)
{
	if (*h == nullptr) // head doesn't exist
	{
		std::cout << "No head!" << std::endl;
		return;
	}
	LinkedList* l = *h;
	// loop to last node
	if ((*h)->next != nullptr)
	{
		while (l->next->next != nullptr)
		{
			l = l->next;
		}

		l->next->data = 0;
		l->next = nullptr;
		delete(l->next); // delete node 
	}
	else
	{
		(*h)->data = 0;
		*h = nullptr;
		delete(*h);
	}
}


int main()
{
	LinkedList* l = new LinkedList;
	l->data = 10;
	l->next = nullptr;

	push_node(l, 20);
	push_node(l, 30);
	push_node(l, 40);

	pop_node(&l);
	pop_node(&l);


	while (l != nullptr) // print list 
	{
		std::cout << l->data << "->";
		l = l->next;
	}

	std::cout << "Null";




	return 0;
}