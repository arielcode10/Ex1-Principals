#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList {
	int data;
	LinkedList* next;

} LinkedList;

void push_node(LinkedList** h, int data);
int pop_node(LinkedList** h);
void delete_list(LinkedList** h);

#endif // LINKEDLIST_H