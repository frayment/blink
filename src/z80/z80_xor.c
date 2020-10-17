/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * z80_xor.c
 * Zilog Z80 encoder for xor instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "z80.h"

size_t
z80_xor_r8(Z80_REG reg)
{
	if (z80_idx(reg))
		return z80_i(reg) + z80_b(0xac, reg);
	else
		return z80_rrr(0xa8, 0, reg);
}

size_t
z80_xor_imm8(int8_t value)
{
	return z80_write(0xee) + z80_write(value);
}

size_t
z80_xor_rhl()
{
	return z80_write(0xae);
}

size_t
z80_xor_ir16_off8(Z80_REG reg,
                  int8_t off)
{
	return z80_i(reg) + z80_write(0xae) + z80_write(off);
}

