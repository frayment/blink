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

size_t
z80_i(Z80_REG reg)
{
	return z80_write(0xdd +
	       (reg == Z80_IX || reg == Z80_IXH || reg == Z80_IXL ?
	        0 : 1 << 5));
}

size_t
z80_b(int8_t base, Z80_REG reg)
{
	return z80_write(base + (reg == Z80_IXL || reg == Z80_IYL));
}

int8_t
z80_pp(Z80_REG reg)
{
	switch (reg)
	{
	case Z80_BC: return 0x0;
	case Z80_DE: return 0x1;
	case Z80_HL: return 0x2;
	case Z80_AF: return 0x3;
	default: return 0x0;
	}
}

int8_t
z80_qq(Z80_REG reg)
{
	switch (reg)
	{
	case Z80_BC: return 0x0;
	case Z80_DE: return 0x1;
	case Z80_HL: /* fall through */
	case Z80_IX:
	case Z80_IY:
		return 0x2;
	case Z80_SP:
		return 0x3;
	default: return 0x0;
	}
}

int8_t
z80_rrr(Z80_REG reg)
{
	switch (reg)
	{
	case Z80_A: return 0x7;
	case Z80_B: return 0x0;
	case Z80_C: return 0x1;
	case Z80_D: return 0x2;
	case Z80_E: return 0x3;
	case Z80_H: return 0x4;
	case Z80_L: return 0x5;
	default: return 0x0;
	}
}

size_t
z80_xor_r8(Z80_REG reg)
{
	switch (reg)
	{
	case Z80_IXH: /* fall through */
	case Z80_IXL:
	case Z80_IYH:
	case Z80_IYL:
		return z80_i(reg) + z80_b(0xac, reg);
	default:
		return z80_write(0xa8 + z80_rrr(reg));
	}
}

size_t
z80_xor_imm8(int8_t value)
{
	return z80_write(0xee) + z80_write(value);
}

size_t
z80_xor_rhl()
{
	return z80_write(0xae);
}

size_t
z80_xor_ir16_off8(Z80_REG reg, int8_t off)
{
	return z80_i(reg) + z80_write(0xae) + z80_write(off);
}

