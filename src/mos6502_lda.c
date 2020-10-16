/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_lda.c
 * MOS 6502 encoder for lda instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_lda_imm8(int8_t value)
{
	return mos6502_write(0xa9) + mos6502_write(value);
}

size_t
mos6502_lda_abs8(int8_t value)
{
	return mos6502_write(0xa5) + mos6502_write(value);
}

size_t
mos6502_lda_abs8_rx(int8_t value)
{
	return mos6502_write(0xb5) + mos6502_write(value);
}

size_t
mos6502_lda_abs16(int16_t value)
{
	return mos6502_write(0xad) + mos6502_imm16(value);
}

size_t
mos6502_lda_abs16_rx(int16_t value)
{
	return mos6502_write(0xbd) + mos6502_imm16(value);
}

size_t
mos6502_lda_abs16_ry(int16_t value)
{
	return mos6502_write(0xb9) + mos6502_imm16(value);
}

size_t
mos6502_lda_ind8_rx(int8_t value)
{
	return mos6502_write(0xa1) + mos6502_write(value);
}

size_t
mos6502_lda_ind8_ry(int8_t value)
{
	return mos6502_write(0xb1) + mos6502_write(value);
}

