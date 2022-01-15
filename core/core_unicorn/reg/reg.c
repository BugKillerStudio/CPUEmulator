#include "reg.h"

#include "core.h"



void* reg_init_x86(CORE_UNICORN_MODE mode)
{
    switch (mode)
    {
    case CORE_UNICORN_MODE_32:
        return malloc(sizeof(REG_LIST_X86_32));

    default:
        return NULL;
    }
}

unsigned int reg_init(PCORE_UNICORN_ENGINE pEngine)
{
    switch (pEngine->arch)
    {
    case CORE_UNICORN_ARCH_X86:
        pEngine->regList = reg_init_x86(pEngine->mode);

        break;

    default:
        break;
    }

    return CORE_UNICORN_ERR_OK;
}
