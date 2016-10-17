#pragma once

#include "ArrayQueue.h"
#include "ArrayStack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* BoolToString(bool value)
{
	return (value == true) ? "true" : "false";
}

int main()
{
	printf("** ArrayStack implementation **\n");
	ArrayStack arrayStack;
	// We have 2 possibilities. We init it with the method or use: ArrayStack arrayStack = { 0 };
	InitArrayStack(&arrayStack);
	printf("Is full: %s\n", BoolToString(IsArrayStackFull(&arrayStack)));
	printf("Is empty: %s\n", BoolToString(IsArrayStackEmpty(&arrayStack)));

	int* arrayValue = malloc(sizeof(int));
	*arrayValue = 22;
	printf("Push: %d->%s\n", *arrayValue, BoolToString(PushToArrayStack(&arrayStack, arrayValue)));
	printf("Top: %d\n", *(int*)TopOfArrayStack(&arrayStack));
	printf("Pop: %d\n", *(int*)PopFromArrayStack(&arrayStack));

	printf("Add 11 chars: ");
	for (int i = 65; i < 76; ++i)
	{
		void* value = malloc(sizeof(char));
		value = (char*)i;
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BoolToString(PushToArrayStack(&arrayStack, value)));
	}

	printf("\nIs full: %s\n", BoolToString(IsArrayStackFull(&arrayStack)));
	printf("Is empty: %s\n", BoolToString(IsArrayStackEmpty(&arrayStack)));
	printf("Top: %c\n", (char)((char*)TopOfArrayStack(&arrayStack)));

	printf("Pop 15 elements: ");
	for (int i = 0; i < 15; ++i)
	{
		printf(i == 0 ? "%c" : ", %c", (char*)PopFromArrayStack(&arrayStack));
	}

	printf("\nIs full: %s\n", BoolToString(IsArrayStackFull(&arrayStack)));
	printf("Is empty: %s\n", BoolToString(IsArrayStackEmpty(&arrayStack)));

	printf("\n** ArrayQueue implementation **\n");
	ArrayQueue arrayQueue;
	InitArrayQueue(&arrayQueue);
	printf("Is full: %s\n", BoolToString(IsArrayQueueFull(&arrayQueue)));
	printf("Is empty: %s\n", BoolToString(IsArrayQueueEmpty(&arrayQueue)));

	int* queueValue = malloc(sizeof(int));
	queueValue = (int*)45;
	printf("Enqueue: %d->%s\n", (int)queueValue, BoolToString(EnqueueToArrayQueue(&arrayQueue, queueValue)));
	int* queueValue1 = malloc(sizeof(int));
	queueValue1 = (int*)136;
	printf("Enqueue: %d->%s\n", (int)queueValue1, BoolToString(EnqueueToArrayQueue(&arrayQueue, queueValue1)));
	printf("Front: %d\n", (int)((int*)FrontFromArrayQueue(&arrayQueue)));
	printf("Back: %d\n", (int)((int*)BackFromArrayQueue(&arrayQueue)));
	printf("Dequeue: %d\n", (int)((int*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Dequeue: %d\n", (int)((int*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Is full: %s\n", BoolToString(IsArrayQueueFull(&arrayQueue)));
	printf("Is empty: %s\n", BoolToString(IsArrayQueueEmpty(&arrayQueue)));

	printf("Add 11 chars: ");
	for (int i = 65; i < 76; ++i)
	{
		void* value = malloc(sizeof(char));
		value = (char*)i;
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BoolToString(EnqueueToArrayQueue(&arrayQueue, value)));
	}

	printf("\nDequeue: %c\n", (char)((char*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Dequeue: %c\n", (char)((char*)DequeueFromArrayQueue(&arrayQueue)));
	printf("Add 5 chars: ");
	for (int i = 76; i < 80; ++i)
	{
		void* value = malloc(sizeof(char));
		value = (char*)i;
		printf(i == 65 ? "%c->%s" : ", %c->%s", (char)i, BoolToString(EnqueueToArrayQueue(&arrayQueue, value)));
	}

	printf("\nFront: %c\n", (char)((char*)FrontFromArrayQueue(&arrayQueue)));
	printf("Back: %c\n", (char)((char*)BackFromArrayQueue(&arrayQueue)));
	printf("Is full: %s\n", BoolToString(IsArrayQueueFull(&arrayQueue)));
	printf("Is empty: %s\n", BoolToString(IsArrayQueueEmpty(&arrayQueue)));

	getchar();

	return 0;
}