#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOOL_TO_STRING(BOOL) BOOL == 0 ? "false" : "true"
#define MAX_SIZE 10

#pragma region ArrayStack

/*
*	+---+
*	| N |
*	+---+
*	| 5 |
*	+---+
*	| 4 |
*	+---+
*	| 3 |
*	+---+
*	| 2 |
*	+---+
*	| 1 |
*	+---+
*	| 0 |
*	+---+
*/
typedef struct ArrayStack
{
	void* data[MAX_SIZE];
	int top;
} ArrayStack;

void InitArrayStack(ArrayStack* stack)
{
	stack->top = 0;
}

bool IsArrayStackFull(ArrayStack* stack)
{
	// We check for greater or equal because nothing is perfect
	return stack->top >= (MAX_SIZE);
}

bool IsArrayStackEmpty(ArrayStack* stack)
{
	// We check for smaller than 1 because nothing is perfect
	return stack->top < 1;
}

/*
* \return false if stack is full, true if it is inserted successful
*/
bool PushToArrayStack(ArrayStack* stack, void* data)
{
	if (IsArrayStackFull(stack))
	{
		return false;
	}

	stack->data[stack->top++] = data;
	return true;
}

void* PopFromArrayStack(ArrayStack* stack)
{
	if (IsArrayStackEmpty(stack))
	{
		return NULL;
	}

	// It is voodoo magic. The -- decrements the value after executing the statement
	return stack->data[--stack->top];
}

void* TopOfArrayStack(ArrayStack* stack)
{
	if (IsArrayStackEmpty(stack))
	{
		return 0;
	}

	return stack->data[stack->top - 1];
}

#pragma endregion

#pragma region ArrayQueue

/*
*	FRONT					BACK
*	+---+---+---+---+---+---+---+
*	| 0 | 1 | 2 | 3 | 4 | 5 | N |
*	+---+---+---+---+---+---+---+
*/
typedef struct ArrayQueue
{
	void* data[MAX_SIZE];
	int elements;
} ArrayQueue;

void InitArrayQueue(ArrayQueue* queue)
{
	queue->elements = 0;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		queue->data[i] = NULL;
	}
}

bool IsArrayQueueFull(ArrayQueue* queue)
{
	return queue->elements >= MAX_SIZE;
}

bool IsArrayQueueEmpty(ArrayQueue* queue)
{
	return queue->elements == 0;
}

void* FrontFromArrayQueue(ArrayQueue* queue)
{
	for (int i = 0; i < MAX_SIZE; ++i)
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
	for (int i = MAX_SIZE - 1; i >= 0; --i)
	{
		if (queue->data[i] != NULL)
		{
			return queue->data[i];
		}
	}

	return NULL;
}

/*
* \return False if not enqueued, true if enqueued
*/
bool EnqueueToArrayQueue(ArrayQueue* queue, void* data)
{
	if (IsArrayQueueEmpty(queue))
	{
		queue->data[queue->elements++] = data;
		return true;
	}

	if (IsArrayQueueFull(queue))
	{
		return false;
	}

	bool foundElem = false;
	for (int i = 0; i < MAX_SIZE; ++i)
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
				queue->data[i] = data;
				++queue->elements;
				return true;
			}
		}
	}

	// Lets see if there is freespace at the beginning
	// If so, swap all items to the place n-1 and enqueue at the end
	if (queue->data[0] == NULL)
	{
		// Swap tango
		for (int i = 1; i < MAX_SIZE; i++)
		{
			queue->data[i - 1] = queue->data[i];
		}

		queue->data[MAX_SIZE - 1] = data;
		++queue->elements;
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

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		if (queue->data[i] != NULL)
		{
			void* temp = queue->data[i];
			queue->data[i] = NULL;
			--queue->elements;
			return temp;
		}
	}
}

#pragma endregion

int main()
{
	printf("** ArrayStack implementation **\n");
	ArrayStack arrayStack;
	// We have 2 possibilities. We init it with the method or use: ArrayStack arrayStack = { 0 };
	InitArrayStack(&arrayStack);
	printf("Is full: %s\n", BOOL_TO_STRING(IsArrayStackFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsArrayStackEmpty(&arrayStack)));

	int* arrayValue = malloc(sizeof(int));
	arrayValue = (int*)22;
	printf("Push: %d->%s\n", (int)arrayValue, BOOL_TO_STRING(PushToArrayStack(&arrayStack, arrayValue)));
	printf("Top: %d\n", (int)((int*)TopOfArrayStack(&arrayStack)));
	printf("Pop: %d\n", (int)((int*)PopFromArrayStack(&arrayStack)));

	printf("Add 11 chars: ");
	for (int i = 65; i < 76; ++i)
	{
		void* value = malloc(sizeof(char));
		value = (char*)i;
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BOOL_TO_STRING(PushToArrayStack(&arrayStack, value)));
	}

	printf("\nIs full: %s\n", BOOL_TO_STRING(IsArrayStackFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsArrayStackEmpty(&arrayStack)));
	printf("Top: %c\n", (char)((char*)TopOfArrayStack(&arrayStack)));

	printf("Pop 15 elements: ");
	for (int i = 0; i < 15; ++i)
	{
		printf(i == 0 ? "%c" : ", %c", (char*)PopFromArrayStack(&arrayStack));
	}

	printf("\nIs full: %s\n", BOOL_TO_STRING(IsArrayStackFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsArrayStackEmpty(&arrayStack)));

	printf("\n** ArrayQueue implementation **\n");
	ArrayQueue arrayQueue;
	InitArrayQueue(&arrayQueue);
	printf("Is full: %s\n", BOOL_TO_STRING(IsArrayQueueFull(&arrayQueue)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsArrayQueueEmpty(&arrayQueue)));

	int* queueValue = malloc(sizeof(int));
	queueValue = (int*)45;
	printf("Enqueue: %d->%s\n", (int)queueValue, BOOL_TO_STRING(EnqueueToArrayQueue(&arrayQueue, queueValue)));
	int* queueValue1 = malloc(sizeof(int));
	queueValue1 = (int*)136;
	printf("Enqueue: %d->%s\n", (int)queueValue1, BOOL_TO_STRING(EnqueueToArrayQueue(&arrayQueue, queueValue1)));
	printf("Front: %d\n", (int)((int*)FrontFromArrayQueue(&arrayQueue)));
	printf("Back: %d\n", (int)((int*)BackFromArrayQueue(&arrayQueue)));
	printf("Dequeue: %d\n", (int)((int*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Dequeue: %d\n", (int)((int*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Is full: %s\n", BOOL_TO_STRING(IsArrayQueueFull(&arrayQueue)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsArrayQueueEmpty(&arrayQueue)));

	printf("Add 11 chars: ");
	for (int i = 65; i < 76; ++i)
	{
		void* value = malloc(sizeof(char));
		value = (char*)i;
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BOOL_TO_STRING(EnqueueToArrayQueue(&arrayQueue, value)));
	}

	printf("\nDequeue: %c\n", (char)((char*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Dequeue: %c\n", (char)((char*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Add 5 chars: ");
	for (int i = 76; i < 80; ++i)
	{
		void* value = malloc(sizeof(char));
		value = (char*)i;
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BOOL_TO_STRING(EnqueueToArrayQueue(&arrayQueue, value)));
	}

	printf("\nFront: %c\n", (char)((char*)FrontFromArrayQueue(&arrayQueue)));
	printf("Back: %c\n", (char)((char*)BackFromArrayQueue(&arrayQueue)));
	printf("Is full: %s\n", BOOL_TO_STRING(IsArrayQueueFull(&arrayQueue)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsArrayQueueEmpty(&arrayQueue)));

	getchar();

	return 0;
}