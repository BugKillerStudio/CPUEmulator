#include <stdio.h>
#include <Windows.h>

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

typedef UINT(*core_unicorn_init)(PCORE_UNICORN_ENGINE* pEngine, CORE_UNICORN_CONFIG config);
typedef UINT(*core_unicorn_memAdd)(PCORE_UNICORN_ENGINE pEngine, MEM_NODE_CONFIG memConfig);
typedef UINT(*core_unicorn_regRead)(PCORE_UNICORN_ENGINE pEngine, UINT regType, PUINT pRegValue);
typedef UINT(*core_unicorn_regWrite)(PCORE_UNICORN_ENGINE pEngine, UINT regType, UINT regValue);

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

    core_unicorn_init coreInit = (core_unicorn_init)GetProcAddress(hDll, "core_unicorn_init");
    core_unicorn_memAdd memListAdd = (core_unicorn_memAdd)GetProcAddress(hDll, "core_unicorn_memAdd");
    core_unicorn_regRead regRead = (core_unicorn_regRead)GetProcAddress(hDll, "core_unicorn_regRead");
    core_unicorn_regWrite regWrite = (core_unicorn_regWrite)GetProcAddress(hDll, "core_unicorn_regWrite");

    unsigned int a = coreInit(&engine, config);

    UINT b = memListAdd(engine, memNode);

    UINT eax = 0x00110011;

    regRead(engine, 0x1, &eax);

    regWrite(engine, 0x1, 0x00FF1100);

    regRead(engine, 0x1, &eax);

    printf("%d", a);

    return 0;
}