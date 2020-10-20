/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_stx.c
 * MOS 6502 encoder for stx instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_stx_abs8(int8_t value)
{
	return mos6502_write(0x86) + mos6502_write(value);
}

size_t
mos6502_stx_abs8_ry(int8_t value)
{
	return mos6502_write(0x96) + mos6502_write(value);
}

size_t
mos6502_stx_abs16(int16_t value)
{
	return mos6502_write(0x8e) + mos6502_imm16(value);
}

