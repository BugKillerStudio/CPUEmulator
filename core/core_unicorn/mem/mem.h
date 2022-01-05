#ifndef CORE_UNICORN_MEM_H
#define CORE_UNICORN_MEM_H

#include "core.h"

typedef struct _MEM_LIST
{
	LIST_ENTRY listNode;

	unsigned int memStart;
	unsigned int memSize;

	unsigned int memLabel;

}MEM_LIST, * PMEM_LIST;

unsigned int mem_init(PCORE_UNICORN_ENGINE pEngine);

#endif // !CORE_UNICORN_MEM_H
