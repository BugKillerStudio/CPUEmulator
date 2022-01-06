#ifndef CORE_UNICORN_REG_H
#define CORE_UNICORN_REG_H

#include "core.h"

typedef struct _REG_LIST_X86_32
{
	unsigned int eax;
	unsigned int ecx;
	unsigned int edx;
	unsigned int ebx;
	unsigned int esp;
	unsigned int ebp;
	unsigned int esi;
	unsigned int edi;
	unsigned int eip;
	unsigned int eflags;

}REG_LIST_X86_32;

#endif // !CORE_UNICORN_REG_H
