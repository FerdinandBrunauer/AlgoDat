#include "ArrayStack.h"

void InitArrayStack(ArrayStack* stack)
{
	stack->top = 0;
}

bool IsArrayStackFull(ArrayStack* stack)
{
	// We check for greater or equal because nothing is perfect
	return stack->top >= (MAX_ARRAY_SIZE);
}

bool IsArrayStackEmpty(ArrayStack* stack)
{
	// We check for smaller than 1 because nothing is perfect
	return stack->top < 1;
}

void* TopOfArrayStack(ArrayStack* stack)
{
	if (IsArrayStackEmpty(stack))
	{
		return 0;
	}

	return stack->data[stack->top - 1];
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