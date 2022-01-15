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


unsigned int core_unicorn_init(PVOID* pEngine, CORE_UNICORN_CONFIG config)
{
    PCORE_UNICORN_ENGINE pCore = malloc(sizeof(CORE_UNICORN_ENGINE));

    if (pCore == NULL)
        return CORE_UNICORN_ERR_INTERNAL;

    arch_init(pCore, config.arch, config.mode);
    mem_init(pCore);
    reg_init(pCore);

    uc_open(pCore->arch, pCore->mode, &pCore->ucEngine);

    *pEngine = &pCore;
    
    return CORE_UNICORN_ERR_OK;
}

unsigned int core_unicorn_regRead(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

unsigned int core_unicorn_regWrite(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

unsigned int core_unicorn_memRead(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

unsigned int core_unicorn_memWrite(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}

unsigned int core_unicorn_step(PCORE_UNICORN_ENGINE pEngine, unsigned int steps)
{
    return CORE_UNICORN_ERR_OK;
}

unsigned int core_unicorn_run(PCORE_UNICORN_ENGINE pEngine)
{
    return CORE_UNICORN_ERR_OK;
}
