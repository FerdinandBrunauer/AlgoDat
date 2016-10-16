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

void Init(ArrayStack* stack)
{
	stack->top = 0;
}

bool IsFull(ArrayStack* stack)
{
	// We check for greater or equal because nothing is perfect
	return stack->top >= (MAX_SIZE);
}

bool IsEmpty(ArrayStack* stack)
{
	// We check for smaller than 1 because nothing is perfect
	return stack->top < 1;
}

/*
* \return false if stack is full, true if it is inserted successful
*/
bool Push(ArrayStack* stack, void* data)
{
	if (IsFull(stack))
	{
		return false;
	}

	stack->data[stack->top++] = data;
	return true;
}

void* Pop(ArrayStack* stack)
{
	if (IsEmpty(stack))
	{
		return NULL;
	}

	// It is voodoo magic. The -- decrements the value after executing the statement
	return stack->data[--stack->top];
}

void* Top(ArrayStack* stack)
{
	if (IsEmpty(stack))
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
} ArrayQueue;

void* Front()
{
	return NULL;
}

void* Back()
{
	return NULL;
}

bool Enqueue(void* data)
{
	return false;
}

void* Dequeue(void* data)
{
	return NULL;
}

#pragma endregion

int main()
{
	printf("** ArrayStack implementation **\n");
	ArrayStack arrayStack;
	// We have 2 possibilities. We init it with the method or use: ArrayStack arrayStack = { 0 };
	Init(&arrayStack);
	printf("Is full: %s\n", BOOL_TO_STRING(IsFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsEmpty(&arrayStack)));

	int* value = malloc(sizeof(int));
	value = (int*)22;
	printf("Push: %d->%s\n", (int)value, BOOL_TO_STRING(Push(&arrayStack, value)));
	printf("Top: %d\n", (int)((int*)Top(&arrayStack)));
	printf("Pop: %d\n", (int)((int*)Pop(&arrayStack)));

	printf("Add 11 chars: ");
	for (int i = 65; i < 76; ++i)
	{
		void* value = malloc(sizeof(char));
		value = (char*)i;
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BOOL_TO_STRING(Push(&arrayStack, value)));
	}

	printf("\nIs full: %s\n", BOOL_TO_STRING(IsFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsEmpty(&arrayStack)));
	printf("Top: %c\n", (char)((char*)Top(&arrayStack)));

	printf("Pop 15 elements: ");
	for (int i = 0; i < 15; ++i)
	{
		printf(i == 0 ? "%c" : ", %c", (char*)Pop(&arrayStack));
	}

	printf("\nIs full: %s\n", BOOL_TO_STRING(IsFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsEmpty(&arrayStack)));

	Dispose(&arrayStack);

	getchar();

	return 0;
}