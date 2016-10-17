#pragma once

#include "Constants.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
*	FRONT					BACK
*	+---+---+---+---+---+---+---+
*	| 0 | 1 | 2 | 3 | 4 | 5 | N |
*	+---+---+---+---+---+---+---+
*/
typedef struct ArrayQueue
{
	void* data[MAX_ARRAY_SIZE];
	int elements;
} ArrayQueue;

void InitArrayQueue(ArrayQueue* queue);

bool IsArrayQueueFull(ArrayQueue* queue);
bool IsArrayQueueEmpty(ArrayQueue* queue);

void* FrontFromArrayQueue(ArrayQueue* queue);
void* BackFromArrayQueue(ArrayQueue* queue);

bool EnqueueToArrayQueue(ArrayQueue* queue, void* data, size_t size);
void* DequeueFromArrayQueue(ArrayQueue* queue);