#include "arch.h"

#include "core.h"

unsigned int arch_init(PCORE_UNICORN_ENGINE pEngine, CORE_UNICORN_ARCH arch)
{
    pEngine->arch = arch;

    return CORE_UNICORN_ERR_OK;
}
