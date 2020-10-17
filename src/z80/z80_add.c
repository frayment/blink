/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * z80_add.c
 * Zilog Z80 encoder for add instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "z80.h"

size_t
z80_add_r8(Z80_REG reg)
{
	if (z80_idx(reg))
		return z80_i(reg) + z80_b(0x84, reg);
	else
		return z80_rrr(0x80, 0, reg);
}

size_t
z80_add_imm8(int8_t value)
{
	return z80_write(0xc6) + z80_write(value);
}

size_t
z80_add_rhl()
{
	return z80_write(0x86);
}

size_t
z80_add_ir16_off8(Z80_REG reg,
                  int8_t off)
{
	return z80_i(reg) + z80_write(0x86) + z80_write(off);
}

size_t
z80_add_rhl_r16(Z80_REG reg)
{
	return z80_qq(0x09, reg);
}

size_t
z80_add_ir16_r16(Z80_REG rega,
                 Z80_REG regb)
{
	return z80_i(rega) + z80_qq(0x09, regb);
}

