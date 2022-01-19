#ifndef CORE_UNICORN_MEM_H
#define CORE_UNICORN_MEM_H

#include "core.h"


#define MEM_LIST_SEARCH_ERR         100
#define MEM_LIST_INDEX_NOT_FOUND    101
#define MEM_LIST_UNMAP_ERR          102


UINT mem_init(PCORE_UNICORN_ENGINE pEngine);
UINT mem_list_add(PCORE_UNICORN_ENGINE pEngine, MEM_NODE_CONFIG memConfig);
UINT mem_list_remove(PCORE_UNICORN_ENGINE pEngine, UINT index);
UINT mem_write(PCORE_UNICORN_ENGINE pEngine);

#endif // !CORE_UNICORN_MEM_H
