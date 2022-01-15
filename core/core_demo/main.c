#include <stdio.h>
#include <Windows.h>

typedef enum _CORE_UNICORN_ARCH
{
    CORE_UNICORN_ARCH_X86,

}CORE_UNICORN_ARCH;

typedef enum _CORE_UNICORN_MODE
{
    CORE_UNICORN_MODE_16 = 1 << 1,
    CORE_UNICORN_MODE_32 = 1 << 2,
    CORE_UNICORN_MODE_64 = 1 << 3,

}CORE_UNICORN_MODE;

typedef struct _CORE_UNICORN_CONFIG
{
    CORE_UNICORN_ARCH arch;
    CORE_UNICORN_MODE mode;

}CORE_UNICORN_CONFIG;

typedef unsigned int (*core_unicorn_init)(PVOID* pEngine, CORE_UNICORN_CONFIG config);

int main()
{
    PVOID engine = NULL;
    CORE_UNICORN_CONFIG config = { 0 };

    config.arch = CORE_UNICORN_ARCH_X86;
    config.mode = CORE_UNICORN_MODE_32;

    HMODULE hDll = LoadLibrary(L"core_unicorn.dll");

    if (!hDll)
        return -1;

    core_unicorn_init testFun = (core_unicorn_init)GetProcAddress(hDll, "core_unicorn_init");

    unsigned int a = testFun(&engine, config);

    printf("%d", a);

    return 0;
}