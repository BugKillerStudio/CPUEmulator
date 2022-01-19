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

typedef struct _MEM_NODE_CONFIG
{
    UINT memStart;
    UINT memSize;
    UINT index;
    PVOID pMemData;

}MEM_NODE_CONFIG;

typedef struct CORE_UNICORN_ENGINE *PCORE_UNICORN_ENGINE;

typedef unsigned int (*core_unicorn_init)(PCORE_UNICORN_ENGINE* pEngine, CORE_UNICORN_CONFIG config);
typedef UINT(*core_unicorn_memAdd)(PCORE_UNICORN_ENGINE pEngine, MEM_NODE_CONFIG memConfig);

int main()
{
    PCORE_UNICORN_ENGINE engine = NULL;
    CORE_UNICORN_CONFIG config = { 0 };
    MEM_NODE_CONFIG memNode = { 0 };

    BYTE mData[] = { 0x33, 0xC0 };

    config.arch = CORE_UNICORN_ARCH_X86;
    config.mode = CORE_UNICORN_MODE_32;

    memNode.index = 0xFFAA;
    memNode.memStart = 0x1000;
    memNode.pMemData = &mData;
    memNode.memSize = sizeof(mData);

    HMODULE hDll = LoadLibrary(L"core_unicorn.dll");

    if (!hDll)
        return -1;

    core_unicorn_init testFun = (core_unicorn_init)GetProcAddress(hDll, "core_unicorn_init");
    core_unicorn_memAdd memListAdd = (core_unicorn_memAdd)GetProcAddress(hDll, "core_unicorn_memAdd");

    unsigned int a = testFun(&engine, config);

    UINT b = memListAdd(engine, memNode);

    printf("%d", a);

    return 0;
}