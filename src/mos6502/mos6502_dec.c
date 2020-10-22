/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_dec.c
 * MOS 6502 encoder for dec instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_dec_abs8(int8_t value)
{
	return mos6502_write((int8_t) 0xc6) + mos6502_write(value);
}

size_t
mos6502_dec_abs8_rx(int8_t value)
{
	return mos6502_write((int8_t) 0xd6) + mos6502_write(value);
}

size_t
mos6502_dec_abs16(int16_t value)
{
	return mos6502_write((int8_t) 0xce) + mos6502_write(value);
}

size_t
mos6502_dec_abs16_rx(int16_t value)
{
	return mos6502_write((int8_t) 0xde) + mos6502_write(value);
}

