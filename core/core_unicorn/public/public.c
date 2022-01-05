#include "public.h"


void InitializeListHead(PLIST_ENTRY listHead)
{
	listHead->Flink = listHead->Blink = listHead;

	return;
}

int InsertHeadList(PLIST_ENTRY listHead, PLIST_ENTRY node)
{
	PLIST_ENTRY nextNode = { 0 };

	if (nextNode->Blink != listHead)
	{
		// Bad LIST_ENTRY struct
		return -1;
	}

	nextNode = listHead->Flink;
	node->Flink = nextNode;
	node->Blink = listHead;
	nextNode->Blink = node;
	listHead->Flink = node;

	return 0;
}

int InsertTailList(PLIST_ENTRY listHead, PLIST_ENTRY node)
{
	PLIST_ENTRY prevNode = { 0 };

	if (prevNode->Flink != listHead)
	{
		// Bad LIST_ENTRY struct
		return -1;
	}

	prevNode = listHead->Blink;
	node->Flink = listHead;
	node->Blink = prevNode;
	prevNode->Flink = node;
	listHead->Blink = node;

	return 0;
}


