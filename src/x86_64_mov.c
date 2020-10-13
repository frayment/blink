/*
 * x86_64.c
 * x86_64 encoder for mov instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 13/10/2020
 */

#include "x86_64.h"

size_t
x86_64_mov_r32_imm32(X86_64_REG reg,
                     int32_t value)
{
	return (X86_64_REG64(reg) ? x86_64_rex(0, 0, 0, 1) : 0) +
	       x86_64_write(0xb0 + reg + (X86_64_REG64(reg) ? 0 : 8)) +
	       x86_64_imm32(value);
}

size_t
x86_64_mov_r64_imm64(X86_64_REG reg,
                     int64_t value)
{
	return x86_64_rex(1, 0, 0, X86_64_REG64(reg)) +
	       x86_64_write(0xb0 + reg + (X86_64_REG64(reg) ? 0 : 8)) +
	       x86_64_imm64(value);
}

size_t
x86_64_mov_rm64_imm8(X86_64_REG reg,
                    int8_t value)
{
	return (X86_64_REG64(reg) ? x86_64_rex(0, 0, 0, 1) : 0) +
	       x86_64_write(0xc6) +
	       x86_64_write(0x0) +
	       x86_64_write(value);
}

size_t
x86_64_mov_r64_r64(X86_64_REG rega,
                   X86_64_REG regb)
{
	return x86_64_rex(1, X86_64_REG64(regb), 0, X86_64_REG64(rega)) +
	       x86_64_write(0x89) +
	       x86_64_modrm(3, rega, regb);
}

