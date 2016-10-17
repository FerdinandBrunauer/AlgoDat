#pragma once

#include "ArrayQueue.h"
#include "ArrayStack.h"
#include "Constants.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* BoolToString(bool value)
{
	return (value == true) ? "successful" : "failed";
}

void TestArrayStack()
{
	printf("** ArrayStack implementation **\n");

	// We have 2 possibilities. We init it with the method or use: ArrayStack arrayStack = { 0 };
	ArrayStack arrayStack;
	InitArrayStack(&arrayStack);

	// Stack state
	printf("Is full: %s\nIs empty: %s\n", BoolToString(IsArrayStackFull(&arrayStack)), BoolToString(IsArrayStackEmpty(&arrayStack)));

	printf("\n** INT **\n");
	// Push INT
	int intValue = 22;
	bool intResult = PushToArrayStack(&arrayStack, &intValue, sizeof(int));
	printf("Push: %d -> %s \n", intValue, BoolToString(intResult));
	// Top INT
	intValue = *(int*)TopOfArrayStack(&arrayStack);
	printf("Top: %d\n", intValue);
	// Pop INT
	void* rawIntData = PopFromArrayStack(&arrayStack);
	intValue = *(int*)rawIntData;
	free(rawIntData);
	printf("Popped: %d\n", intValue);

	printf("\n** CHAR **\n");
	// Push CHAR
	char charValue = 'A';
	bool charResult = PushToArrayStack(&arrayStack, &charValue, sizeof(char));
	printf("Push: %c -> %s \n", charValue, BoolToString(charResult));
	// Top CHAR
	charValue = *(int*)TopOfArrayStack(&arrayStack);
	printf("Top: %c\n", charValue);
	// Pop CHAR
	void* rawCharData = PopFromArrayStack(&arrayStack);
	charValue = *(int*)rawCharData;
	free(rawCharData);
	printf("Popped: %c\n", charValue);

	// Overfill
	printf("\n** Overfill with CHAR's **\n");
	const char FirstChar = 'A';
	const char LastChar = (char)((int)FirstChar + MAX_ARRAY_SIZE);
	printf("Push: [");
	for (int i = (int)FirstChar; i <= (int)LastChar; ++i)
	{
		bool fillResult = PushToArrayStack(&arrayStack, &i, sizeof(char));
		printf(i == FirstChar ? "%c -> %s" : "; %c -> %s", (char)i, BoolToString(fillResult));
	}
	printf("]\n");
	// Top CHAR
	charValue = *(int*)TopOfArrayStack(&arrayStack);
	printf("Top: %c\n", charValue);

	// Empty CHAR
	printf("\n** EMPTY with CHAR's **\n");
	void* rawResult;
	printf("Pop: [");
	bool firstRun = true;
	for (rawResult = PopFromArrayStack(&arrayStack); rawResult != NULL; rawResult = PopFromArrayStack(&arrayStack))
	{
		charValue = *(char*)rawResult;
		free(rawResult);
		printf(firstRun ? "%c" : "; %c", charValue);
		firstRun = false;
	}
	printf("]\n");
}

void TestArrayQueue()
{
	printf("** ArrayQueue implementation **\n");

	ArrayQueue arrayQueue;
	InitArrayQueue(&arrayQueue);

	// Queue state
	printf("Is full: %s\nIs empty: %s\n", BoolToString(IsArrayQueueFull(&arrayQueue)), BoolToString(IsArrayQueueEmpty(&arrayQueue)));

	printf("\n** INT **\n");
	// Enqueue INT
	int intValue = 22;
	bool intResult = EnqueueToArrayQueue(&arrayQueue, &intValue, sizeof(int));
	printf("Enqueue: %d -> %s \n", intValue, BoolToString(intResult));
	// Dequeue INT
	void* rawIntData = DequeueFromArrayQueue(&arrayQueue);
	intValue = *(int*)rawIntData;
	free(rawIntData);
	printf("Dequeue: %d\n", intValue);

	printf("\n** CHAR **\n");
	// Enqueue CHAR
	char charValue = 'A';
	bool charResult = EnqueueToArrayQueue(&arrayQueue, &charValue, sizeof(char));
	printf("Enqueue: %c -> %s \n", charValue, BoolToString(charResult));
	// Dequeue CHAR
	void* rawCharData = DequeueFromArrayQueue(&arrayQueue);
	charValue = *(int*)rawCharData;
	free(rawCharData);
	printf("Dequeue: %c\n", charValue);

	// Overfill
	printf("\n** Overfill with CHAR's **\n");
	const char FirstChar = 'A';
	const char LastChar = (char)((int)FirstChar + MAX_ARRAY_SIZE);
	printf("Enqueue: [");
	for (int i = (int)FirstChar; i <= (int)LastChar; ++i)
	{
		bool fillResult = EnqueueToArrayQueue(&arrayQueue, &i, sizeof(char));
		printf(i == FirstChar ? "%c -> %s" : "; %c -> %s", (char)i, BoolToString(fillResult));
	}
	printf("]\n");

	// Empty CHAR
	printf("\n** EMPTY with CHAR's **\n");
	void* rawResult;
	printf("Dequeue: [");
	bool firstRun = true;
	for (rawResult = DequeueFromArrayQueue(&arrayQueue); rawResult != NULL; rawResult = DequeueFromArrayQueue(&arrayQueue))
	{
		charValue = *(char*)rawResult;
		free(rawResult);
		printf(firstRun ? "%c" : "; %c", charValue);
		firstRun = false;
	}
	printf("]\n");
}

int main()
{
	TestArrayStack();
	TestArrayQueue();

	getchar();

	return 0;
}