/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_and.c
 * MOS 6502 encoder for and instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_and_imm8(int8_t value)
{
	return mos6502_write(0x29) + mos6502_write(value);
}

size_t
mos6502_and_abs8(int8_t value)
{
	return mos6502_write(0x25) + mos6502_write(value);
}

size_t
mos6502_and_abs8_rx(int8_t value)
{
	return mos6502_write(0x35) + mos6502_write(value);
}

size_t
mos6502_and_abs16(int16_t value)
{
	return mos6502_write(0x2d) + mos6502_imm16(value);
}

size_t
mos6502_and_abs16_rx(int16_t value)
{
	return mos6502_write(0x3d) + mos6502_imm16(value);
}

size_t
mos6502_and_abs16_ry(int16_t value)
{
	return mos6502_write(0x39) + mos6502_imm16(value);
}

size_t
mos6502_and_ind8_rx(int8_t value)
{
	return mos6502_write(0x21) + mos6502_write(value);
}

size_t
mos6502_and_ind8_ry(int8_t value)
{
	return mos6502_write(0x31) + mos6502_write(value);
}

