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
mos6502_jmp_abs16(int16_t off)
{
	return mos6502_write(0x4c) +
	       mos6502_imm16(off);
}

size_t
mos6502_jmp_ind16(int16_t off)
{
	return mos6502_write(0x6c) +
	       mos6502_imm16(off);
}

size_t
mos6502_nop()
{
	return mos6502_write((int8_t) 0xea);
}

