/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_ror.c
 * MOS 6502 encoder for ror instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_ror_imm8(int8_t value)
{
	return mos6502_write(0x6a) + mos6502_write(value);
}

size_t
mos6502_ror_abs8(int8_t value)
{
	return mos6502_write(0x66) + mos6502_write(value);
}

size_t
mos6502_ror_abs8_rx(int8_t value)
{
	return mos6502_write(0x76) + mos6502_write(value);
}

size_t
mos6502_ror_abs16(int16_t value)
{
	return mos6502_write(0x6e) + mos6502_imm16(value);
}

size_t
mos6502_ror_abs16_rx(int16_t value)
{
	return mos6502_write(0x7e) + mos6502_imm16(value);
}

