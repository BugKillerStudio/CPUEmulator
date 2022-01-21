#include "arch.h"

#include "core.h"

unsigned int arch_init(PCORE_UNICORN_ENGINE pEngine, CORE_UNICORN_ARCH arch, CORE_UNICORN_MODE mode)
{
	switch (arch)
	{
	case CORE_UNICORN_ARCH_X86:
		pEngine->arch = UC_ARCH_X86;

		break;
	default:
		break;
	}


	switch (mode)
	{
	case CORE_UNICORN_MODE_16:
		pEngine->mode = UC_MODE_16;

		break;
	case CORE_UNICORN_MODE_32:
		pEngine->mode = UC_MODE_32;

		break;
	case CORE_UNICORN_MODE_64:
		pEngine->mode = UC_MODE_64;

		break;
	default:
		break;
	}

    return CORE_UNICORN_ERR_OK;
}
