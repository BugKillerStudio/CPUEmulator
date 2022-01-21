#ifndef CORE_UNICORN_CORE_H
#define CORE_UNICORN_CORE_H

#include "unicorn/unicorn.h"

#include <stdlib.h>


// #define CORE_EXTERN_FUNC        extern "C"


// Arch structs

typedef enum _CORE_UNICORN_ARCH
{
    CORE_UNICORN_ARCH_X86 = 4,

}CORE_UNICORN_ARCH;

typedef enum _CORE_UNICORN_MODE
{
    CORE_UNICORN_MODE_16 = 1 << 1,
    CORE_UNICORN_MODE_32 = 1 << 2,
    CORE_UNICORN_MODE_64 = 1 << 3,

}CORE_UNICORN_MODE;



// Mem structs

typedef struct _MEM_LIST
{
    LIST_ENTRY listNode;

    UINT memStart;
    UINT memSize;

    PVOID memData;

    UINT index;

}MEM_LIST, * PMEM_LIST;

typedef struct _MEM_NODE_CONFIG
{
    UINT memStart;
    UINT memSize;
    UINT index;
    PVOID pMemData;

}MEM_NODE_CONFIG;



// Reg structs

typedef struct _REG_LIST_X86_32
{
    UINT eax;
    UINT ecx;
    UINT edx;
    UINT ebx;
    UINT esp;
    UINT ebp;
    UINT esi;
    UINT edi;
    UINT eip;
    UINT eflags;

}REG_LIST_X86_32, *PREG_LIST_X86_32;



// Core structs

typedef uc_engine* PUC_ENGINE;

typedef enum _CORE_UNICORN_ERR
{
    CORE_UNICORN_ERR_INTERNAL = -1,
    CORE_UNICORN_ERR_OK = 0,
    CORE_UNICORN_ERR_NOMEM,					// Out of Memory
    CORE_UNICORN_ERR_ARG,                   // Arg is ERROR

}CORE_UNICORN_ERR;

typedef struct _CORE_UNICORN_ENGINE
{
    CORE_UNICORN_ARCH arch;
    CORE_UNICORN_MODE mode;
    LIST_ENTRY memList;
    PVOID regTable;
    uc_engine* ucEngine;

}CORE_UNICORN_ENGINE, * PCORE_UNICORN_ENGINE;

typedef struct _CORE_UNICORN_CONFIG
{
    CORE_UNICORN_ARCH arch;
    CORE_UNICORN_MODE mode;

}CORE_UNICORN_CONFIG;

#endif // !CORE_UNICORN_CORE_H
