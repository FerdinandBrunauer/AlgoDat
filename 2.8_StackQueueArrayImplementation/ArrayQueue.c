#include "ArrayQueue.h"

void InitArrayQueue(ArrayQueue* queue)
{
	queue->elements = 0;

	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		queue->data[i] = NULL;
	}
}

bool IsArrayQueueFull(ArrayQueue* queue)
{
	return queue->elements >= MAX_ARRAY_SIZE;
}

bool IsArrayQueueEmpty(ArrayQueue* queue)
{
	return queue->elements == 0;
}

void* FrontFromArrayQueue(ArrayQueue* queue)
{
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		if (queue->data[i] != NULL)
		{
			return queue->data[i];
		}
	}

	return NULL;
}

void* BackFromArrayQueue(ArrayQueue* queue)
{
	for (int i = MAX_ARRAY_SIZE - 1; i >= 0; --i)
	{
		if (queue->data[i] != NULL)
		{
			return queue->data[i];
		}
	}

	return NULL;
}

#define ENQUEUE(QUEUE,POSITION,DATA,SIZE) QUEUE->data[POSITION] = memcpy(malloc(SIZE), DATA, SIZE); ++QUEUE->elements;

/*
* \return False if not enqueued, true if enqueued
*/
bool EnqueueToArrayQueue(ArrayQueue* queue, void* data, size_t size)
{
	if (IsArrayQueueEmpty(queue))
	{
		ENQUEUE(queue, 0, data, size)
		return true;
	}

	if (IsArrayQueueFull(queue))
	{
		return false;
	}

	bool foundElem = false;
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		if (foundElem == false)
		{
			foundElem = queue->data[i] != NULL;
		}
		else
		{
			// When we now find a NULL element, we found the next free space
			if (queue->data[i] == NULL)
			{
				ENQUEUE(queue, i, data, size)
				return true;
			}
		}
	}

	// Lets see if there is freespace at the beginning
	// If so, swap all items to the place n-1 and enqueue at the end
	if (queue->data[0] == NULL)
	{
		// Swap tango
		for (int i = 1; i < MAX_ARRAY_SIZE; i++)
		{
			queue->data[i - 1] = queue->data[i];
		}

		ENQUEUE(queue, MAX_ARRAY_SIZE - 1, data, size)
		return true;
	}

	return false;
}

void* DequeueFromArrayQueue(ArrayQueue* queue)
{
	if (IsArrayQueueEmpty(queue))
	{
		return NULL;
	}

	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
	{
		if (queue->data[i] != NULL)
		{
			void* temp = queue->data[i];
			queue->data[i] = NULL;
			--queue->elements;
			return temp;
		}
	}

	return NULL;
}