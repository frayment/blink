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

size_t
z80_xor_r8(Z80_REG reg)
{
	if (z80_idx(reg))
		return z80_i(reg) + z80_b(0xac, reg);
	else
		return z80_rrr(0xa8, 0, reg);
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
z80_xor_ir16_off8(Z80_REG reg,
                  int8_t off)
{
	return z80_i(reg) + z80_write(0xae) + z80_write(off);
}

size_t
z80_adc_r8(Z80_REG reg)
{
	if (z80_idx(reg))
		return z80_i(reg) + z80_b(0x8c, reg);
	else
		return z80_rrr(0x88, 0, reg);
}

size_t
z80_adc_imm8(int8_t value)
{
	return z80_write(0xce) + z80_write(value);
}

size_t
z80_adc_rhl()
{
	return z80_write(0x8e);
}

size_t
z80_adc_ir16_off8(Z80_REG reg,
                  int8_t off)
{
	return z80_i(reg) + z80_write(0x8e) + z80_write(off);
}

size_t
z80_adc_rhl_r16(Z80_REG reg)
{
	return z80_write(0xed) + z80_qq(0x4a, reg);
}

size_t
z80_add_r8(Z80_REG reg)
{
	if (z80_idx(reg))
		return z80_i(reg) + z80_b(0x84, reg);
	else
		return z80_rrr(0x80, 0, reg);
}

size_t
z80_add_imm8(int8_t value)
{
	return z80_write(0xc6) + z80_write(value);
}

size_t
z80_add_rhl()
{
	return z80_write(0x86);
}

size_t
z80_add_ir16_off8(Z80_REG reg,
                  int8_t off)
{
	return z80_i(reg) + z80_write(0x86) + z80_write(off);
}

size_t
z80_add_rhl_r16(Z80_REG reg)
{
	return z80_qq(0x09, reg);
}

size_t
z80_add_ir16_r16(Z80_REG rega,
                 Z80_REG regb)
{
	return z80_i(rega) + z80_qq(0x09, regb);
}

size_t
z80_and_r8(Z80_REG reg)
{
	if (z80_idx(reg))
		return z80_i(reg) + z80_b(0xa4, reg);
	else
		return z80_rrr(0xa0, 0, reg);
}

size_t
z80_and_imm8(int8_t value)
{
	return z80_write(0xe6) + z80_write(value);
}

size_t
z80_and_rhl()
{
	return z80_write(0xa6);
}

size_t
z80_and_ir16_off8(Z80_REG reg,
				  int8_t off)
{
	return z80_i(reg) + z80_write(0xa6) + z80_write(off);
}

