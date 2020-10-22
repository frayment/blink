/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_sty.c
 * MOS 6502 encoder for sty instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_sty_abs8(int8_t value)
{
	return mos6502_write((int8_t) 0x84) + mos6502_write(value);
}

size_t
mos6502_sty_abs8_rx(int8_t value)
{
	return mos6502_write((int8_t) 0x94) + mos6502_write(value);
}

size_t
mos6502_sty_abs16(int16_t value)
{
	return mos6502_write((int8_t) 0x8c) + mos6502_imm16(value);
}

