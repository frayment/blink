/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_sbc.c
 * MOS 6502 encoder for sbc instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_sbc_imm8(int8_t value)
{
	return mos6502_write(0xe9) + mos6502_write(value);
}

size_t
mos6502_sbc_abs8(int8_t value)
{
	return mos6502_write(0xe5) + mos6502_write(value);
}

size_t
mos6502_sbc_abs8_rx(int8_t value)
{
	return mos6502_write(0xf5) + mos6502_write(value);
}

size_t
mos6502_sbc_abs16(int16_t value)
{
	return mos6502_write(0xed) + mos6502_imm16(value);
}

size_t
mos6502_sbc_abs16_rx(int16_t value)
{
	return mos6502_write(0xfd) + mos6502_imm16(value);
}

size_t
mos6502_sbc_abs16_ry(int16_t value)
{
	return mos6502_write(0xf9) + mos6502_imm16(value);
}

size_t
mos6502_sbc_ind8_rx(int8_t value)
{
	return mos6502_write(0xe1) + mos6502_write(value);
}

size_t
mos6502_sbc_ind8_ry(int8_t value)
{
	return mos6502_write(0xf1) + mos6502_write(value);
}

