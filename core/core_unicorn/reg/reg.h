#ifndef CORE_UNICORN_REG_H
#define CORE_UNICORN_REG_H

#include "core.h"


#define REG_UNKNOW_TYPE     100
#define REG_MALLOC_ERR      200

#define UC_REG_READ(engine, regType, pRegType, regName, pValue)     \
        uc_reg_read(engine->ucEngine, regType, &((pRegType)engine->regTable)->regName);  \
        *pValue = ((pRegType)engine->regTable)->eax;

#define UC_REG_WRITE(engine, regType, pRegType, regName, pValue)    \
        uc_reg_write(engine->ucEngine, regType, pValue);    \
        ((pRegType)engine->regTable)->regName = *pValue;



//====================X86====================//

#define REG_TYPE_X86_EAX        0x1
#define REG_TYPE_X86_ECX        0x2
#define REG_TYPE_X86_EDX        0x3
#define REG_TYPE_X86_EBX        0x4
#define REG_TYPE_X86_ESP        0x5
#define REG_TYPE_X86_EBP        0x6
#define REG_TYPE_X86_ESI        0x7
#define REG_TYPE_X86_EDI        0x8
#define REG_TYPE_X86_EIP        0x9
#define REG_TYPE_X86_EFlags     0xA

//====================X64====================//


UINT reg_init(PCORE_UNICORN_ENGINE pEngine);
UINT reg_read(PCORE_UNICORN_ENGINE pEngine, UINT regType, PUINT pRegValue);
UINT reg_write(PCORE_UNICORN_ENGINE pEngine, UINT regType, PUINT pRegValue);

#endif // !CORE_UNICORN_REG_H
