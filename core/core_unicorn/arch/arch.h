#ifndef CORE_UNICORN_ARCH_H
#define CORE_UNICORN_ARCH_H

#include "core.h"

typedef enum CORE_UNICORN_ARCH
{
    CORE_UNICORN_ARCH_X86 = 0,

};

typedef enum CORE_UNICORN_MODE
{
    // x86 / x64
    CORE_UNICORN_MODE_16 = 1 << 1,          // 16-bit ģʽ
    CORE_UNICORN_MODE_32 = 1 << 2,          // 32-bit ģʽ
    CORE_UNICORN_MODE_64 = 1 << 3,          // 64-bit ģʽ

};


unsigned int arch_init(PCORE_UNICORN_ENGINE pEngine, CORE_UNICORN_ARCH arch);

#endif // !CORE_UNICORN_ARCH_H
