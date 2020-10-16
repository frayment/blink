/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_lsr.c
 * MOS 6502 encoder for lsr instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_lsr_acc()
{
	return mos6502_write(0x4a);
}

size_t
mos6502_lsr_abs8(int8_t value)
{
	return mos6502_write(0x46) + mos6502_write(value);
}

size_t
mos6502_lsr_abs8_rx(int8_t value)
{
	return mos6502_write(0x56) + mos6502_write(value);
}

size_t
mos6502_lsr_abs16(int16_t value)
{
	return mos6502_write(0x4e) + mos6502_imm16(value);
}

size_t
mos6502_lsr_abs16_rx(int16_t value)
{
	return mos6502_write(0x5e) + mos6502_imm16(value);
}

