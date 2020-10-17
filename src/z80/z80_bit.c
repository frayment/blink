/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * z80_bit.c
 * Zilog Z80 encoder for bit instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "z80.h"

size_t
z80_bit_bit_r8(int8_t bit,
               Z80_REG reg)
{
	return z80_write(0xcb) + z80_rrr(0x40 + (bit << 3), 0, reg);
}

size_t
z80_bit_bit_hl(int8_t bit)
{
	return z80_write(0xcb) + z80_write(0x46 + (bit << 3));
}

size_t
z80_bit_bit_ir16_off8(int8_t bit,
                      Z80_REG reg,
                      int8_t off)
{
	return z80_i(reg) +
           z80_write(0xcb) +
           z80_write(off) +
           z80_write(0x40 + (bit << 3));
}

