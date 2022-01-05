#ifndef CORE_UNICORN_CORE_H

#ifdef CORE_UNICORN
#include "arch/arch.h"
#endif // CORE_UNICORN


#define CORE_UNICORN_VERSION	"1.0.0.0"

typedef enum core_unicorn_err
{
	CORE_UNICORN_ERR_OK = 1,
	CORE_UNICORN_ERR_NOMEM,					// Out of Memory
};

typedef struct _LIST_ENTRY
{
	struct _LIST_ENTRY* Flink;
	struct _LIST_ENTRY* Blink;

}LIST_ENTRY, *PLIST_ENTRY;

typedef struct _MEM_LIST
{
	LIST_ENTRY listNode;

	unsigned int memStart;
	unsigned int memSize;

	unsigned int memLabel;

}MEM_LIST, *PMEM_LIST;

typedef struct _CORE_UNICORN_ENGINE
{
	unsigned int arch;
	MEM_LIST* memList;

}CORE_UNICORN_ENGINE, *PCORE_UNICORN_ENGINE;

typedef struct _CORE_UNICORN_CONFIG
{
	unsigned int arch;

}CORE_UNICORN_CONFIG, *PCORE_UNICORN_CONFIG;

#endif // !CORE_UNICORN_CORE_H
