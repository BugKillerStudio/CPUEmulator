#include "mem.h"

#include "core.h"
#include "public/public.h"

VOID mem_list_init(PCORE_UNICORN_ENGINE pEngine)
{
    InitializeListHead(&pEngine->memList);

    return;
}

UINT mem_list_searchNode(PLIST_ENTRY node, UINT index, PMEM_LIST* tarMemList)
{
    PLIST_ENTRY pNowMemNode = NULL;
    pNowMemNode = node->Blink;

    while (pNowMemNode != node)
    {
        PMEM_LIST memNode = CONTAINING_RECORD(pNowMemNode, MEM_LIST, listNode);

        if (memNode->index == index)
        {
            *tarMemList = memNode;

            return 0;
        }

        pNowMemNode = pNowMemNode->Blink;
    }

    return MEM_LIST_SEARCH_ERR;
}

UINT mem_list_add(PCORE_UNICORN_ENGINE pEngine, MEM_NODE_CONFIG memConfig)
{
    UINT state = CORE_UNICORN_ERR_OK;

    if (UC_ERR_OK != uc_mem_map(pEngine->ucEngine, memConfig.memStart, (memConfig.memSize * 0x100000), UC_PROT_ALL)) //TODO: Custom Mem Permissions
        return CORE_UNICORN_ERR_ARG;

    if (UC_ERR_OK != uc_mem_write(pEngine->ucEngine, memConfig.memStart, memConfig.pMemData, memConfig.memSize))
        return CORE_UNICORN_ERR_ARG;


    // Add this MemNode to the Mem ListEntry
    PMEM_LIST newMemList = malloc(sizeof(MEM_LIST));

    if (!newMemList)
        return CORE_UNICORN_ERR_INTERNAL;

    newMemList->memStart =      memConfig.memStart;
    newMemList->memSize =       memConfig.memSize;
    newMemList->index =         memConfig.index;
    newMemList->memData =       memConfig.pMemData;

    state = InsertTailList(&pEngine->memList, &newMemList->listNode);

    return state;
}

UINT mem_list_remove(PCORE_UNICORN_ENGINE pEngine, UINT index)
{
    UINT state = CORE_UNICORN_ERR_OK;

    // Search index in MEM_LIST_ENTRY
    PMEM_LIST memNode = NULL;

    if (!mem_list_searchNode(&pEngine->memList, index, &memNode))
    {
        // Found index
        if (UC_ERR_OK != uc_mem_unmap(pEngine->ucEngine, memNode->memStart, memNode->memSize))
            return MEM_LIST_UNMAP_ERR;

        state = RemoveEntryList(&memNode->listNode);

        return state;
    }

    return MEM_LIST_INDEX_NOT_FOUND;
}

UINT mem_init(PCORE_UNICORN_ENGINE pEngine)
{
    mem_list_init(pEngine);

    return CORE_UNICORN_ERR_OK;
}

UINT mem_read(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

UINT mem_write(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}
