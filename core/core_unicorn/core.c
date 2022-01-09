#include "core.h"

#include "arch/arch.h"
#include "mem/mem.h"

unsigned int core_unicorn_init(PCORE_UNICORN_ENGINE pEngine, CORE_UNICORN_CONFIG config)
{
    CORE_UNICORN_ENGINE core = { 0 };
    MEM_LIST memList = { 0 };

    arch_init(&core, config.arch);
    mem_init(&core);

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
