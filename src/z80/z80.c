/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * z80.c
 * Zilog Z80 encoder
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include <stdint.h>
#include <stdio.h>

#include "z80.h"

static FILE *enc_fp = NULL;

void
z80_encoder_out(FILE *fp)
{
	enc_fp = fp;
}

size_t
z80_write(int8_t i)
{
	if (enc_fp == NULL)
		return sizeof(i);
	return fwrite(&i, sizeof(i), 1, enc_fp);
}

size_t
z80_imm16(int16_t i)
{
	int endian;
	if (enc_fp == NULL)
		return sizeof(i);
	endian = 1;
	/* check host system endianness */
	if (*((char *) &endian)) /* little endian (native) */
		return z80_write(i & 0x00FF) + z80_write((i & 0xFF00) >> 8);
	else                    /* big endian (convert) */
		return z80_write((i & 0xFF00) >> 8) + z80_write(i & 0x00FF);
	/*return fwrite(&i, sizeof(i), 1, enc_fp);*/
}

int
z80_idx(Z80_REG reg)
{
	switch (reg)
	{
	case Z80_IX:  /* fall through */
	case Z80_IXH:
	case Z80_IXL:
	case Z80_IY:
	case Z80_IYH:
	case Z80_IYL:
		return 1;
	default:
		return 0;
	}
}

size_t
z80_i(Z80_REG reg)
{
	return z80_write(0xdd +
	       (reg == Z80_IX || reg == Z80_IXH || reg == Z80_IXL ?
	        0 : 1 << 5));
}

size_t
z80_b(int8_t base,
      Z80_REG reg)
{
	return z80_write(base + (reg == Z80_IXL || reg == Z80_IYL));
}

size_t
z80_pp(int8_t base,
       Z80_REG reg)
{
	int8_t pp;
	switch (reg)
	{
	case Z80_BC:
		pp = 0x0;
		break;
	case Z80_DE:
		pp = 0x1;
		break;
	case Z80_HL:
		pp = 0x2;
		break;
	case Z80_AF:
		pp = 0x3;
		break;
	default:
		pp = 0x0;
	}
	return z80_write(base + (pp << 4));
}

size_t
z80_qq(int8_t base,
       Z80_REG reg)
{
	int8_t qq;
	switch (reg)
	{
	case Z80_BC:
		qq = 0x0;
		break;
	case Z80_DE:
		qq = 0x1;
		break;
	case Z80_HL: /* fall through */
	case Z80_IX:
	case Z80_IY:
		qq = 0x2;
		break;
	case Z80_SP:
		qq = 0x3;
		break;
	default:
		qq = 0x0;
	}
	return z80_write(base + (qq << 4));
}

size_t
z80_rrr(int8_t base,
        int8_t shift,
        Z80_REG reg)
{
	int8_t rrr;
	switch (reg)
	{
	case Z80_A:
		rrr = 0x7;
		break;
	case Z80_B:
		rrr = 0x0;
		break;
	case Z80_C:
		rrr = 0x1;
		break;
	case Z80_D:
		rrr = 0x2;
		break;
	case Z80_E:
		rrr = 0x3;
		break;
	case Z80_H:
		rrr = 0x4;
		break;
	case Z80_L:
		rrr = 0x5;
		break;
	default:
		rrr = 0x0;
		break;
	}
	return z80_write(base + (reg << shift));
}

