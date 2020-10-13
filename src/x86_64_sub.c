/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * x86_64.c
 * x86_64 encoder for sub instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 13/10/2020
 */

#include "x86_64.h"

size_t
x86_64_sub_r32_imm8(X86_64_REG reg,
                    int8_t value)
{
	return x86_64_write(0x67) +
	       x86_64_sub_r64_imm8(reg, value);
}

size_t
x86_64_sub_r64_imm8(X86_64_REG reg,
                    int8_t value)
{
	return x86_64_rex(1, 0, 0, X86_64_REG64(reg)) +
	       x86_64_write((int8_t) 0x83) +
	       x86_64_write(0xc0 + 0x28 + (X86_64_REG64(reg) ? reg - 8 : reg)) +
	       x86_64_write(value);
}

size_t
x86_64_sub_r32_imm32(X86_64_REG reg,
                     int32_t value)
{
	return x86_64_rex(1, 0, 0, X86_64_REG64(reg)) +
	       (reg == X86_64_RAX ? 
	           x86_64_write(0x05 + 0x28) :
	           x86_64_write((int8_t) 0x81) +
	           x86_64_write(0xc0 + 0x28 + (X86_64_REG64(reg) ? reg - 8 : reg))) +
	       x86_64_imm32(value);
}

size_t
x86_64_sub_r64_imm64(X86_64_REG reg,
                     int64_t value)
{
	return x86_64_rex(1, 0, 0, X86_64_REG64(reg)) +
	       x86_64_write(0xb0 + reg + (X86_64_REG64(reg) ? 0 : 8)) +
	       x86_64_imm64(value);
}

size_t
x86_64_sub_rm64_imm8(X86_64_REG reg,
                     int8_t value)
{
	return (X86_64_REG64(reg) ? x86_64_rex(0, 0, 0, 1) : 0) +
	       x86_64_write((int8_t) 0x80) +
	       x86_64_write(0x28 + (X86_64_REG64(reg) ? reg - 8 : reg)) +
	       x86_64_write(value);
}

size_t
x86_64_sub_r32_r32(X86_64_REG rega,
                   X86_64_REG regb)
{
	return x86_64_write(0x01 + 0x28) +
	       x86_64_modrm(3, rega, regb);
}


size_t
x86_64_sub_r64_r64(X86_64_REG rega,
                   X86_64_REG regb)
{
	return x86_64_rex(1, X86_64_REG64(regb), 0, X86_64_REG64(rega)) +
	       x86_64_sub_r32_r32(rega, regb);
}

