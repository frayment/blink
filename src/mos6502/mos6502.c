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
	int endian;
	if (enc_fp == NULL)
		return sizeof(i);
	endian = 1;
	/* check host system endianness */
	if (*((char *) &endian)) /* little endian (native) */
		return mos6502_write(i & 0x00FF) + mos6502_write((i & 0xFF00) >> 8);
	else                    /* big endian (convert) */
		return mos6502_write((i & 0xFF00) >> 8) + mos6502_write(i & 0x00FF);
	/*return fwrite(&i, sizeof(i), 1, enc_fp);*/
}

