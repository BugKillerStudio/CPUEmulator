#define CORE_UNICORN

#include "core.h"

#include <stdlib.h>

/*
* Warning!!!:
* Here has something functions
* But these functions need to move to public cpp file.	As a public functions to use
*/

void InitializeListHead(PLIST_ENTRY listHead)
{
	listHead->Flink = listHead->Blink = listHead;
	
	return;
}

void InsertHeadList(PLIST_ENTRY listHead, PLIST_ENTRY node)
{
	PLIST_ENTRY nextNode = { 0 };

	nextNode = listHead->Flink;
	node->Flink = nextNode;
	node->Blink = listHead;
	nextNode->Blink = node;
	listHead->Flink = node;

	return;
}

void InsertTailList(PLIST_ENTRY listHead, PLIST_ENTRY node)
{
	PLIST_ENTRY prevNode = { 0 };

	prevNode = listHead->Blink;

	node->Flink = listHead;
	node->Blink = prevNode;
	prevNode->Flink = node;
	listHead->Blink = node;

	return;
}

/*
	done here
*/


void mem_list_init(PCORE_UNICORN_ENGINE pEngine, PMEM_LIST memList)
{
	LIST_ENTRY listHead = { 0 };

	InitializeListHead(&listHead);

	memList->listNode = listHead;

	pEngine->memList->listNode = listHead;

	return;
}



unsigned int core_unicorn_init(void* pEngine, CORE_UNICORN_CONFIG config)
{
	CORE_UNICORN_ENGINE core = { 0 };
	MEM_LIST memList = { 0 };

	arch_init(&core, config.arch);
	mem_list_init(&core, &memList);

	return CORE_UNICORN_ERR_OK;
}

