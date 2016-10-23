#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "List.h"

void TestList()
{
	printf("** List Implementation **\n");
	List* list = CreateList();

	// Fill with 10 int
	printf("Add Back: [");
	for (int i = 0; i < 10; i++)
	{
		PushBack(list, (void*)&i, sizeof(int));
		printf(i == 0 ? "%d" : ", %d", i);
	}
	printf("]\n");

	printf("Items: [");
	for (unsigned int i = 0; i < GetListLength(list); i++)
	{
		printf(i == 0 ? "%d" : ", %d", *(int*)GetListDataAt(list, i));
	}
	printf("]\n");

	// Remove from back until list is empty
	printf("Remove Back: [");
	bool firstRun = true;
	while (!IsListEmpty(list))
	{
		int* data = (int*)RemoveBack(list);

		printf(firstRun ? "%d" : ", %d", *data);
		free(data);
		firstRun = false;
	}
	printf("]\n");

	printf("Add Front: [");
	// Fill with 10 chars
	for (char i = 65; i < 76; i++)
	{
		PushFront(list, (void*)&i, sizeof(char));
		printf(i == 65 ? "%c" : ", %c", i);
	}
	printf("]\n");

	printf("Items: [");
	for (unsigned int i = 0; i < GetListLength(list); i++)
	{
		printf(i == 0 ? "%c" : ", %c", *(char*)GetListDataAt(list, i));
	}
	printf("]\n");

	// Remove from front until list is empty
	printf("Remove Front: [");
	firstRun = true;
	while (!IsListEmpty(list))
	{
		char* data = (char*)RemoveFront(list);

		printf(firstRun ? "%c" : ", %c", *data);
		free(data);
		firstRun = false;
	}
	printf("]\n");
	free(list);
}

int main()
{
	TestList();

	printf("Finished ...");
	getchar();
	return 0;
}
