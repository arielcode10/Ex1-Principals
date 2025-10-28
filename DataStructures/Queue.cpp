#include "Queue.h"


/*
* This function intializes queue.
* INPUT: size, q (queue)
* OUTPUT: None
*/
void initQueue(Queue* q, unsigned int size)
{
	q->elements = new int[size];
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
	delete[] q->elements;
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
int dequeue(Queue* q)
{
	int i = 0;
	int element = q->elements[0];
	// move all queue items back
	for (i = 0; i < q->currentSize; i++)
	{
		q->elements[i] = q->elements[i + 1];
	}
	q->currentSize--; // decrement

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
