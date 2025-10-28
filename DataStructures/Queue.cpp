#include "Queue.h"


/*
* This function intializes queue.
* INPUT: size, q (queue)
* OUTPUT: None
*/
void initQueue(Queue* q, unsigned int size)
{
	q->elements = new int[size];
	q->base = q->elements;
	q->maxSize = size;
	q->currentSize = 0;
}

/*
* This function frees the memory in queue.
* INPUT: q (queue)
* OUTPUT: None
*/
void cleanQueue(Queue* q)
{
	delete[] q->base;
	q->elements = nullptr;
	q->maxSize = 0;
	q->currentSize = 0;
}

/*
* This function enques a mew value.
* INPUT: q (queue), newValue
* OUTPUT: None
*/
void enqueue(Queue* q, unsigned int newValue)
{
	if (!isFull(q)) // if current size not max size
	{
		q->elements[q->currentSize] = newValue;
		q->currentSize++;
	}
}

/*
* This function deques the first item in the queue.
* INPUT: q (queue)
* OUTPUT: the dequeued item (int)
*/

// bonus (deque O(1)) - implimented it by rather then moving all the items back we move the pointer one 
// step forward. In a circular motion.
int dequeue(Queue* q)
{
	int element = q->elements[0];
	q->elements++;
	q->currentSize--;

	if (q->currentSize == 0) {
		q->elements = q->base;  // reset to start when empty
	}

	return element;
}

/*
* This function cheks if the queue is empty.
* INPUT: q (queue)
* OUTPUT: if the queue is empty
*/
bool isEmpty(Queue* q)
{
	return q->currentSize == 0;
}

/*
* This function checks if the queue is full.
* INPUT: q (queue)
* OUTPUT: if the queue is full
*/
bool isFull(Queue* q)
{
	return q->currentSize == q->maxSize;
}
