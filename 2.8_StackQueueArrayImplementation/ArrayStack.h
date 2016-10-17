#pragma once

#include "Constants.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // memcpy

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
	void* data[MAX_ARRAY_SIZE];
	int top;
} ArrayStack;

void InitArrayStack(ArrayStack* stack);

bool IsArrayStackFull(ArrayStack* stack);
bool IsArrayStackEmpty(ArrayStack* stack);

void* TopOfArrayStack(ArrayStack* stack);

bool PushToArrayStack(ArrayStack* stack, void* data, size_t size);
void* PopFromArrayStack(ArrayStack* stack);