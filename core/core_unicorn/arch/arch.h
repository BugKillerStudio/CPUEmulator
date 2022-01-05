#ifndef CORE_UNICORN_ARCH_H

typedef enum core_unicorn_arch
{
	CORE_UNICORN_ARCH_X86_32 = 1,
	CORE_UNICORN_ARCH_X86_64,

	CORE_UNICORN_ARCH_X64_32,
	CORE_UNICORN_ARCH_X64_64,

	// CORE_UNICORN_ARCH_ARM_32,
	// CORE_UNICORN_ARCH_ARM_64
};


unsigned int arch_init(PCORE_UNICORN_ENGINE pEngine, unsigned int arch);

#endif // !CORE_UNICORN_ARCH_H
