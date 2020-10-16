/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502.c
 * MOS 6502 encoder
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include <stdint.h>
#include <stdio.h>

#include "mos6502.h"

static FILE *enc_fp = NULL;

void
mos6502_encoder_out(FILE *fp)
{
	enc_fp = fp;
}

size_t
mos6502_write(int8_t i)
{
	if (enc_fp == NULL)
		return sizeof(i);
	return fwrite(&i, sizeof(i), 1, enc_fp);
}

size_t
mos6502_imm16(int16_t i)
{
	if (enc_fp == NULL)
		return sizeof(i);
	return mos6502_write((i & 0xFF00) >> 8) + mos6502_write(i & 0x00FF);
}

size_t
mos6502_bit_abs8(int8_t value)
{
	return mos6502_write(0x24) + mos6502_write(value);
}

size_t
mos6502_bit_abs16(int16_t value)
{
	return mos6502_write(0x2c) + mos6502_imm16(value);
}

size_t
mos6502_brk()
{
	return mos6502_write(0x00);
}

size_t
mos6502_cpx_imm8(int8_t value)
{
	return mos6502_write(0xe0) + mos6502_write(value);
}

size_t
mos6502_cpx_abs8(int8_t value)
{
	return mos6502_write(0xe4) + mos6502_write(value);
}

size_t
mos6502_cpx_abs16(int16_t value)
{
	return mos6502_write(0xec) + mos6502_imm16(value);
}

size_t
mos6502_cpy_imm8(int8_t value)
{
	return mos6502_write(0xc0) + mos6502_write(value);
}

size_t
mos6502_cpy_abs8(int8_t value)
{
	return mos6502_write(0xc4) + mos6502_write(value);
}

size_t
mos6502_cpy_abs16(int16_t value)
{
	return mos6502_write(0xcc) + mos6502_imm16(value);
}

size_t
mos6502_clc()
{
	return mos6502_write(0x18);
}

size_t
mos6502_cld()
{
	return mos6502_write((int8_t) 0xd8);
}

size_t
mos6502_cli()
{
	return mos6502_write(0x58);
}

size_t
mos6502_clv()
{
	return mos6502_write(0xb8);
}

size_t
mos6502_sec()
{
	return mos6502_write(0x38);
}

size_t
mos6502_sed()
{
	return mos6502_write((int8_t) 0xf8);
}

size_t
mos6502_sei()
{
	return mos6502_write(0x78);
}

size_t
mos6502_dec_abs8(int8_t value)
{
	return mos6502_write(0xc6) + mos6502_write(value);
}

size_t
mos6502_dec_abs8_regx(int8_t value)
{
	return mos6502_write(0xd6) + mos6502_write(value);
}

size_t
mos6502_dec_abs16(int16_t value)
{
	return mos6502_write(0xce) + mos6502_write(value);
}

size_t
mos6502_dec_abs16_regx(int16_t value)
{
	return mos6502_write(0xde) + mos6502_write(value);
}

size_t
mos6502_inc_abs8(int8_t value)
{
	return mos6502_write(0xe6) + mos6502_write(value);
}

size_t
mos6502_inc_abs8_regx(int8_t value)
{
	return mos6502_write(0xf6) + mos6502_write(value);
}

size_t
mos6502_inc_abs16(int16_t value)
{
	return mos6502_write(0xee) + mos6502_write(value);
}

size_t
mos6502_inc_abs16_regx(int16_t value)
{
	return mos6502_write(0xfe) + mos6502_write(value);
}

size_t
mos6502_jmp_abs16(int16_t off)
{
	return mos6502_write(0x4c) + mos6502_imm16(off);
}

size_t
mos6502_jmp_ind16(int16_t off)
{
	return mos6502_write(0x6c) + mos6502_imm16(off);
}

size_t
mos6502_jsr_abs16(int16_t off)
{
	return mos6502_write(0x20) + mos6502_imm16(off);
}

size_t
mos6502_nop()
{
	return mos6502_write((int8_t) 0xea);
}

