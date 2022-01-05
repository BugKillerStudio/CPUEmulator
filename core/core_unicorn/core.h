#ifndef CORE_UNICORN_CORE_H
#define CORE_UNICORN_CORE_H

#define CORE_UNICORN

#ifdef CORE_UNICORN
#include "arch/arch.h"
#include "mem/mem.h"
#include "public/public.h"
#endif // CORE_UNICORN

#include <stdlib.h>


#define CORE_UNICORN_VERSION	"1.0.0.0"

typedef enum CORE_UNICORN_ERR
{
    CORE_UNICORN_ERR_OK = 1,
    CORE_UNICORN_ERR_NOMEM,					// Out of Memory
};

typedef struct _CORE_UNICORN_ENGINE
{
    CORE_UNICORN_ARCH arch;
    CORE_UNICORN_MODE mode;
    MEM_LIST* memList;
    void* regList;

}CORE_UNICORN_ENGINE, * PCORE_UNICORN_ENGINE;

typedef struct _CORE_UNICORN_CONFIG
{
    CORE_UNICORN_ARCH arch;

}CORE_UNICORN_CONFIG, * PCORE_UNICORN_CONFIG;

// unsigned int core_unicorn_init(PCORE_UNICORN_ENGINE pEngine, CORE_UNICORN_CONFIG config);

#endif // !CORE_UNICORN_CORE_H
