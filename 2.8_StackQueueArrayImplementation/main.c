#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOOL_TO_STRING(BOOL) BOOL == 0 ? "false" : "true"
#define MAX_SIZE 10

#pragma region ArrayStack

typedef struct
{
	void* data[MAX_SIZE];
	int top;
} ArrayStack;

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
		return 0;
	}

	// It is voodoo magic. The -- decrements the value after executing the statement
	return &stack->data[--stack->top];
}

void* Top(ArrayStack* stack)
{
	if (IsEmpty(stack))
	{
		return 0;
	}

	return &stack->data[stack->top - 1];
}

#pragma endregion

int main()
{
	printf("** ArrayStack implementation **\n");
	ArrayStack arrayStack = { 0 };
	printf("Is full: %s\n", BOOL_TO_STRING(IsFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsEmpty(&arrayStack)));
	printf("Add 11 elements: ");
	for (int i = 65; i <= 75; ++i)
	{
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BOOL_TO_STRING(Push(&arrayStack, (void*)i)));
	}

	printf("\nIs full: %s\n", BOOL_TO_STRING(IsFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsEmpty(&arrayStack)));
	printf("Top: %s\n", (char*)Top(&arrayStack));

	printf("\nPop 11 elements: ");
	for (int i = 0; i <= 10; ++i)
	{
		printf(i == 0 ? "%s" : ", %s", (char*)Pop(&arrayStack));
	}

	printf("\nIs full: %s\n", BOOL_TO_STRING(IsFull(&arrayStack)));
	printf("Is empty: %s\n", BOOL_TO_STRING(IsEmpty(&arrayStack)));

	char* test = "TestTestTestTest";
	printf("Push: %s->%s\n", test, BOOL_TO_STRING(Push(&arrayStack, (void*)test)));
	printf("Top: %s\n", (char*)Pop(&arrayStack));

	getchar();

	return 0;
}