/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_bit.c
 * MOS 6502 encoder for bit instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_bit_abs8(int8_t value)
{
	return mos6502_write(0x24) + mos6502_write(value);
}

size_t
mos6502_bit_abs16(int16_t value)
{
	return mos6502_write(0x2c) + mos6502_imm16(value);
}

