/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * x86_64_jmp.c
 * x86_64 encoder for jmp instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 14/10/2020
 */

#include "x86_64.h"

size_t
x86_64_jmp_rel8(int8_t off)
{
	return x86_64_write((int8_t) 0xeb) +
	       x86_64_write(off);
}

size_t
x86_64_jmp_rel32(int32_t off)
{
	return x86_64_write((int8_t) 0xe9) +
	       x86_64_imm32(off);
}

size_t
x86_64_jne_rel8(int8_t off)
{
	return x86_64_write((int8_t) 0x75) +
	       x86_64_write(off);
}

size_t
x86_64_jne_rel32(int32_t off)
{
	return x86_64_write(0x0f) +
	       x86_64_write((int8_t) 0x85) +
	       x86_64_imm32(off);;
}

