/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_cpy.c
 * MOS 6502 encoder for cpy instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_cpy_imm8(int8_t value)
{
	return mos6502_write(0xc0) + mos6502_write(value);
}

size_t
mos6502_cpy_abs8(int8_t value)
{
	return mos6502_write(0xc4) + mos6502_write(value);
}

size_t
mos6502_cpy_abs16(int16_t value)
{
	return mos6502_write(0xcc) + mos6502_imm16(value);
}

