/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_eor.c
 * MOS 6502 encoder for eor instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_eor_imm8(int8_t value)
{
	return mos6502_write(0x49) + mos6502_write(value);
}

size_t
mos6502_eor_abs8(int8_t value)
{
	return mos6502_write(0x45) + mos6502_write(value);
}

size_t
mos6502_eor_abs8_rx(int8_t value)
{
	return mos6502_write(0x55) + mos6502_write(value);
}

size_t
mos6502_eor_abs16(int16_t value)
{
	return mos6502_write(0x4d) + mos6502_imm16(value);
}

size_t
mos6502_eor_abs16_rx(int16_t value)
{
	return mos6502_write(0x5d) + mos6502_imm16(value);
}

size_t
mos6502_eor_abs16_ry(int16_t value)
{
	return mos6502_write(0x59) + mos6502_imm16(value);
}

size_t
mos6502_eor_ind8_rx(int8_t value)
{
	return mos6502_write(0x41) + mos6502_write(value);
}

size_t
mos6502_eor_ind8_ry(int8_t value)
{
	return mos6502_write(0x51) + mos6502_write(value);
}

