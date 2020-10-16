/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_cmp.c
 * MOS 6502 encoder for cmp instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_cmp_imm8(int8_t value)
{
	return mos6502_write(0xc9) + mos6502_write(value);
}

size_t
mos6502_cmp_abs8(int8_t value)
{
	return mos6502_write(0xc5) + mos6502_write(value);
}

size_t
mos6502_cmp_abs8_rx(int8_t value)
{
	return mos6502_write(0xd5) + mos6502_write(value);
}

size_t
mos6502_cmp_abs16(int16_t value)
{
	return mos6502_write(0xcd) + mos6502_imm16(value);
}

size_t
mos6502_cmp_abs16_rx(int16_t value)
{
	return mos6502_write(0xdd) + mos6502_imm16(value);
}

size_t
mos6502_cmp_abs16_ry(int16_t value)
{
	return mos6502_write(0xd9) + mos6502_imm16(value);
}

size_t
mos6502_cmp_ind8_rx(int8_t value)
{
	return mos6502_write(0xc1) + mos6502_write(value);
}

size_t
mos6502_cmp_ind8_ry(int8_t value)
{
	return mos6502_write(0xd1) + mos6502_write(value);
}

