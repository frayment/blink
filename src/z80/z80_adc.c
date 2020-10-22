/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * z80_adc.c
 * Zilog Z80 encoder for adc instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "z80.h"

size_t
z80_adc_r8(Z80_REG reg)
{
	if (z80_idx(reg))
		return z80_i(reg) + z80_b((int8_t) 0x8c, reg);
	else
		return z80_rrr((int8_t) 0x88, 0, reg);
}

size_t
z80_adc_imm8(int8_t value)
{
	return z80_write((int8_t) 0xce) + z80_write(value);
}

size_t
z80_adc_rhl()
{
	return z80_write((int8_t) 0x8e);
}

size_t
z80_adc_ir16_off8(Z80_REG reg,
                  int8_t off)
{
	return z80_i(reg) + z80_write((int8_t) 0x8e) + z80_write(off);
}

size_t
z80_adc_rhl_r16(Z80_REG reg)
{
	return z80_write((int8_t) 0xed) + z80_qq(0x4a, reg);
}

