#include "core.h"

#include "arch/arch.h"
#include "mem/mem.h"
#include "reg/reg.h"


/*
* ====================GLOBAL VALUE====================
*/

/*
* ====================GLOBAL VALUE====================
*/


UINT core_unicorn_init(PCORE_UNICORN_ENGINE* pEngine, CORE_UNICORN_CONFIG config)
{
    UINT state = CORE_UNICORN_ERR_OK;
    PCORE_UNICORN_ENGINE pCore = malloc(sizeof(CORE_UNICORN_ENGINE));

    if (pCore == NULL)
        return CORE_UNICORN_ERR_INTERNAL;

    state = arch_init(pCore, config.arch, config.mode);
    state = mem_init(pCore);
    state = reg_init(pCore);

    if (uc_open(pCore->arch, pCore->mode, &pCore->ucEngine))
        return CORE_UNICORN_ERR_ARG;

    *pEngine = pCore;
    
    return state;
}

UINT core_unicorn_regRead(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

UINT core_unicorn_regWrite(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

UINT core_unicorn_memAdd(PCORE_UNICORN_ENGINE pEngine, MEM_NODE_CONFIG memConfig)
{
    UINT state = CORE_UNICORN_ERR_OK;

    state = mem_list_add(pEngine, memConfig);

    return state;
}

UINT core_unicorn_memRemove(PCORE_UNICORN_ENGINE pEngine, UINT index)
{
    UINT state = CORE_UNICORN_ERR_OK;

    state = mem_list_remove(pEngine, index);

    return state;
}

UINT core_unicorn_memRead(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

UINT core_unicorn_memWrite(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

UINT core_unicorn_step(PVOID pEngine, unsigned int steps)
{
    return CORE_UNICORN_ERR_OK;
}

UINT core_unicorn_run(PVOID pEngine)
{
    return CORE_UNICORN_ERR_OK;
}
