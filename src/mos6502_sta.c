/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_sta.c
 * MOS 6502 encoder for sta instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_sta_abs8(int8_t value)
{
	return mos6502_write(0x85) + mos6502_write(value);
}

size_t
mos6502_sta_abs8_rx(int8_t value)
{
	return mos6502_write(0x95) + mos6502_write(value);
}

size_t
mos6502_sta_abs16(int16_t value)
{
	return mos6502_write(0x8d) + mos6502_imm16(value);
}

size_t
mos6502_sta_abs16_rx(int16_t value)
{
	return mos6502_write(0x9d) + mos6502_imm16(value);
}

size_t
mos6502_sta_abs16_ry(int16_t value)
{
	return mos6502_write(0x99) + mos6502_imm16(value);
}

size_t
mos6502_sta_ind8_rx(int8_t value)
{
	return mos6502_write(0x81) + mos6502_write(value);
}

size_t
mos6502_sta_ind8_ry(int8_t value)
{
	return mos6502_write(0x91) + mos6502_write(value);
}

