/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_ldx.c
 * MOS 6502 encoder for ldx instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_ldx_imm8(int8_t value)
{
	return mos6502_write((int8_t) 0xa2) + mos6502_write(value);
}

size_t
mos6502_ldx_abs8(int8_t value)
{
	return mos6502_write((int8_t) 0xa6) + mos6502_write(value);
}

size_t
mos6502_ldx_abs8_ry(int8_t value)
{
	return mos6502_write((int8_t) 0xb6) + mos6502_write(value);
}

size_t
mos6502_ldx_abs16(int16_t value)
{
	return mos6502_write((int8_t) 0xae) + mos6502_imm16(value);
}

size_t
mos6502_ldx_abs16_ry(int16_t value)
{
	return mos6502_write((int8_t) 0xbe) + mos6502_imm16(value);
}

