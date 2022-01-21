#include "reg.h"

#include "core.h"



UINT reg_init_x86(CORE_UNICORN_MODE mode, PVOID* pRegTable)
{
    PVOID ptr = NULL;

    switch (mode)
    {
    case CORE_UNICORN_MODE_32:
        ptr = malloc(sizeof(REG_LIST_X86_32));
        if (!ptr)
            return REG_MALLOC_ERR;
        *pRegTable = ptr;

        break;
    default:
        return REG_UNKNOW_TYPE;
    }

    return CORE_UNICORN_ERR_OK;
}

UINT reg_init(PCORE_UNICORN_ENGINE pEngine)
{
    UINT state = CORE_UNICORN_ERR_OK;

    switch (pEngine->arch)
    {
    case CORE_UNICORN_ARCH_X86:
        state = reg_init_x86(pEngine->mode, &pEngine->regTable);

        break;

    default:
        break;
    }

    switch (state)
    {
    case REG_UNKNOW_TYPE:
        state = CORE_UNICORN_ERR_ARG;

        break;
    case REG_MALLOC_ERR:
        state = CORE_UNICORN_ERR_INTERNAL;

        break;
    default:
        break;
    }

    return state;
}

UINT reg_read_x86(PCORE_UNICORN_ENGINE pEngine, UINT regType, PUINT pRegValue)
{
    switch (regType)
    {
        case REG_TYPE_X86_EAX:
            UC_REG_READ(pEngine, UC_X86_REG_EAX, PREG_LIST_X86_32, eax, pRegValue);

            break;
        case REG_TYPE_X86_ECX:
            UC_REG_READ(pEngine, UC_X86_REG_ECX, PREG_LIST_X86_32, ecx, pRegValue);

            break;
        case REG_TYPE_X86_EDX:
            UC_REG_READ(pEngine, UC_X86_REG_EDX, PREG_LIST_X86_32, edx, pRegValue);

            break;
        case REG_TYPE_X86_EBX:
            UC_REG_READ(pEngine, UC_X86_REG_EBX, PREG_LIST_X86_32, ebx, pRegValue);

            break;
        case REG_TYPE_X86_ESP:
            UC_REG_READ(pEngine, UC_X86_REG_ESP, PREG_LIST_X86_32, esp, pRegValue);

            break;
        case REG_TYPE_X86_EBP:
            UC_REG_READ(pEngine, UC_X86_REG_EBP, PREG_LIST_X86_32, ebp, pRegValue);

            break;
        case REG_TYPE_X86_ESI:
            UC_REG_READ(pEngine, UC_X86_REG_ESI, PREG_LIST_X86_32, esi, pRegValue);

            break;
        case REG_TYPE_X86_EDI:
            UC_REG_READ(pEngine, UC_X86_REG_EDI, PREG_LIST_X86_32, edi, pRegValue);

            break;
        case REG_TYPE_X86_EIP:
            UC_REG_READ(pEngine, UC_X86_REG_EIP, PREG_LIST_X86_32, eip, pRegValue);

            break;
        case REG_TYPE_X86_EFlags:
            UC_REG_READ(pEngine, UC_X86_REG_EFLAGS, PREG_LIST_X86_32, eflags, pRegValue);

            break;
    default:
        return REG_UNKNOW_TYPE;

        break;
    }

    return CORE_UNICORN_ERR_OK;
}

UINT reg_read(PCORE_UNICORN_ENGINE pEngine, UINT regType, PUINT pRegValue)
{
    UINT state = CORE_UNICORN_ERR_OK;

    switch (pEngine->arch)
    {
    case CORE_UNICORN_ARCH_X86:
        state = reg_read_x86(pEngine, regType, pRegValue);

        break;
    default:
        break;
    }

    if (state == REG_UNKNOW_TYPE)
    {
        state = CORE_UNICORN_ERR_ARG;
    }

    return state;
}

UINT reg_write_x86(PCORE_UNICORN_ENGINE pEngine, UINT regType, PUINT pRegValue)
{
    switch (regType)
    {
    case REG_TYPE_X86_EAX:
        UC_REG_WRITE(pEngine, UC_X86_REG_EAX, PREG_LIST_X86_32, eax, pRegValue);

        break;
    case REG_TYPE_X86_ECX:
        UC_REG_WRITE(pEngine, UC_X86_REG_ECX, PREG_LIST_X86_32, ecx, pRegValue);

        break;
    case REG_TYPE_X86_EDX:
        UC_REG_WRITE(pEngine, UC_X86_REG_EDX, PREG_LIST_X86_32, edx, pRegValue);

        break;
    case REG_TYPE_X86_EBX:
        UC_REG_WRITE(pEngine, UC_X86_REG_EBX, PREG_LIST_X86_32, ebx, pRegValue);

        break;
    case REG_TYPE_X86_ESP:
        UC_REG_WRITE(pEngine, UC_X86_REG_ESP, PREG_LIST_X86_32, esp, pRegValue);

        break;
    case REG_TYPE_X86_EBP:
        UC_REG_WRITE(pEngine, UC_X86_REG_EBP, PREG_LIST_X86_32, ebp, pRegValue);

        break;
    case REG_TYPE_X86_ESI:
        UC_REG_WRITE(pEngine, UC_X86_REG_ESI, PREG_LIST_X86_32, esi, pRegValue);

        break;
    case REG_TYPE_X86_EDI:
        UC_REG_WRITE(pEngine, UC_X86_REG_EDI, PREG_LIST_X86_32, edi, pRegValue);

        break;
    case REG_TYPE_X86_EIP:
        UC_REG_WRITE(pEngine, UC_X86_REG_EIP, PREG_LIST_X86_32, eip, pRegValue);

        break;
    case REG_TYPE_X86_EFlags:
        UC_REG_WRITE(pEngine, UC_X86_REG_EFLAGS, PREG_LIST_X86_32, eflags, pRegValue);

        break;
    default:
        return REG_UNKNOW_TYPE;

        break;
    }

    return CORE_UNICORN_ERR_OK;
}

UINT reg_write(PCORE_UNICORN_ENGINE pEngine, UINT regType, PUINT pRegValue)
{
    UINT state = CORE_UNICORN_ERR_OK;

    switch (pEngine->arch)
    {
    case CORE_UNICORN_ARCH_X86:
        state = reg_write_x86(pEngine, regType, pRegValue);

        break;
    default:
        break;
    }

    return state;
}
