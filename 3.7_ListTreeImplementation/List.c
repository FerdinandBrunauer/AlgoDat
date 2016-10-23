#pragma once

#include "List.h"

List* CreateList()
{
	List* list = (List*)malloc(sizeof(List));
	list->front = NULL;
	list->back = NULL;
	list->elements = 0;

	return list;
}

ListNode* CreateListNode()
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = NULL;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

ListNode* CreateListNodeWithData(void *data, size_t size)
{
	ListNode* node = CreateListNode();
	void* newData = malloc(size);
	memcpy(newData, data, size);
	node->data = newData;

	return node;
}

bool IsListEmpty(List *list)
{
	return list->elements == 0;
}

unsigned int GetListLength(List *list)
{
	return list->elements;
}

void PushBackNode(List *list, ListNode *listNode)
{
	InsertAtNode(list, listNode, GetListLength(list) - 1);
}

void PushBack(List *list, void *data, size_t size)
{
	InsertAtNode(list, CreateListNodeWithData(data, size), GetListLength(list));
}

void PushFrontNode(List *list, ListNode *listNode)
{
	InsertAtNode(list, listNode, 0);
}

void PushFront(List *list, void *data, size_t size)
{
	InsertAtNode(list, CreateListNodeWithData(data, size), 0);
}

void InsertAt(List *list, void *data, size_t size, unsigned int position)
{
	InsertAtNode(list, CreateListNodeWithData(data, size), position);
}

void InsertAtNode(List *list, ListNode *listNode, unsigned int position)
{
	// List is empty, special case
	if (IsListEmpty(list))
	{
		list->front = listNode;
		list->back = listNode;
		listNode->next = NULL;
		listNode->prev = NULL;
		list->elements++;
		return;
	}

	if (GetListLength(list) < position)
	{
		// What now? The list is not that big ...
		// IDC, add it to the end
		PushBackNode(list, listNode);
		return;
	}

	if (GetListLength(list) == position)
	{
		// Looks like someone wants to add something at the back of the queue
		list->back->next = listNode;
		listNode->prev = list->back;
		listNode->next = NULL;
		list->back = listNode;
		++list->elements;

		return;
	}

//	+-----------+			+-----------+
//	|			|<---prev---|			|
//	|	  1		|			|	 OLD	|
//	|			|---next--->|			|
//	+-----------+			+-----------+
//					  |
//					  V
//	+-----------+			+-----------+			+-----------+
//	|			|<---prev---|			|<---prev---|			|
//	|	  1		|			|	 NEW	|			|	 OLD	|
//	|			|---next--->|			|---next--->|			|
//	+-----------+			+-----------+			+-----------+

	ListNode* oldItem = GetListNodeAt(list, position);
	if (oldItem->prev == NULL)
	{
		// Front
		list->front = listNode;
		listNode->prev = NULL;
	}
	else
	{
		oldItem->prev->next = listNode;
		listNode->prev = oldItem->prev;
	}

	listNode->next = oldItem;
	oldItem->prev = listNode;

	//oldItem->prev->next = listNode;
	//listNode->prev = oldItem->prev;
	//listNode->next = oldItem;
	//oldItem->prev = listNode;

	++list->elements;
}

void* GetListDataAt(List* list, unsigned int position)
{
	return GetListNodeAt(list, position)->data;
}

ListNode* GetListNodeAt(List* list, unsigned int position)
{
	ListNode* temp = list->front;

	// Maybe we should check if it is faster to go from the back ??
	for (unsigned int i = 1; i <= position; ++i)
	{
		temp = temp->next;
	}

	return temp;
}

void* RemoveBack(List *list)
{
	return RemoveAt(list, GetListLength(list) - 1);
}

void* RemoveFront(List *list)
{
	return RemoveAt(list, 0);
}

void* RemoveAt(List *list, unsigned int position)
{
	if (IsListEmpty(list))
	{
		return NULL;
	}

	if (GetListLength(list) < position)
	{
		// Housten we have a problem
		return NULL;
	}

	ListNode *deleteElement = GetListNodeAt(list, position);
	void *data = deleteElement->data;
	if (deleteElement->prev == NULL && deleteElement->next == NULL)
	{
		// The list is now empty
		list->back = NULL;
		list->front = NULL;
	}
	else if (deleteElement->prev == NULL)
	{
		// It is the first elemet in the list
		list->front = deleteElement->next;
		deleteElement->next->prev = NULL;
	}
	else if (deleteElement->next == NULL)
	{
		// It is the last element in the list
		list->back = deleteElement->prev;
		deleteElement->prev->next = NULL;
	}
	else
	{
		// It is a element in the middle of the list
		deleteElement->prev->next = deleteElement->next;
		deleteElement->next->prev = deleteElement->prev;
	}

	free(deleteElement);
	--list->elements;
	return data;
}