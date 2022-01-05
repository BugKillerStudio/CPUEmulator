#include "core.h"

unsigned int arch_init(PCORE_UNICORN_ENGINE pEngine, unsigned int arch)
{
	pEngine->arch = arch;

	return CORE_UNICORN_ERR_OK;
}
