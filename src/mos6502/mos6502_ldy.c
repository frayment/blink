/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_ldy.c
 * MOS 6502 encoder for ldy instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_ldy_imm8(int8_t value)
{
	return mos6502_write((int8_t) 0xa0) + mos6502_write(value);
}

size_t
mos6502_ldy_abs8(int8_t value)
{
	return mos6502_write((int8_t) 0xa4) + mos6502_write(value);
}

size_t
mos6502_ldy_abs8_rx(int8_t value)
{
	return mos6502_write((int8_t) 0xb4) + mos6502_write(value);
}

size_t
mos6502_ldy_abs16(int16_t value)
{
	return mos6502_write((int8_t) 0xac) + mos6502_imm16(value);
}

size_t
mos6502_ldy_abs16_rx(int16_t value)
{
	return mos6502_write((int8_t) 0xbc) + mos6502_imm16(value);
}

