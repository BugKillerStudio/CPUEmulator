#include "mem.h"

#include "core.h"
#include "public/public.h"

void mem_list_init(PCORE_UNICORN_ENGINE pEngine, PMEM_LIST memList)
{
    LIST_ENTRY listHead = { 0 };

    InitializeListHead(&listHead);

    memList->listNode = listHead;

    pEngine->memList->listNode = listHead;

    return;
}

unsigned int mem_init(PCORE_UNICORN_ENGINE pEngine)
{
    MEM_LIST memList = { 0 };

    mem_list_init(pEngine, &memList);

    return CORE_UNICORN_ERR_OK;
}

unsigned int mem_read(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

unsigned int mem_write(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}
