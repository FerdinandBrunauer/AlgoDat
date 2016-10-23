#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct ListNode
{
	void *data;
	struct ListNode *next;
	struct ListNode *prev;
} ListNode;

typedef struct List
{
	struct ListNode *front;
	struct ListNode *back;
	unsigned int elements;
} List;

List* CreateList();
ListNode* CreateListNode();
ListNode* CreateListNodeWithData(void* data, size_t size);

bool IsListEmpty(List* list);
unsigned int GetListLength(List* list);

void PushBackNode(List* list, ListNode* listNode);
void PushBack(List* list, void* data, size_t size);
void PushFrontNode(List* list, ListNode* listNode);
void PushFront(List* list, void* data, size_t size);
void InsertAt(List* list, void* data, size_t size, unsigned int position);
void InsertAtNode(List* list, ListNode* listNode, unsigned int position);

void* GetListDataAt(List* list, unsigned int position);
ListNode* GetListNodeAt(List* list, unsigned int position);

void* RemoveBack(List* list);
void* RemoveFront(List* list);
void* RemoveAt(List* list, unsigned int position);