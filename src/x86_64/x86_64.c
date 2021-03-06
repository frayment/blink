/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * x86_64.c
 * x86_64 encoder
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 12/10/2020
 */

#include <stdint.h>
#include <stdio.h>

#include "x86_64.h"

static FILE *enc_fp = NULL;

void
x86_64_encoder_out(FILE *fp)
{
	enc_fp = fp;
}

size_t
x86_64_write(int8_t i)
{
	if (enc_fp == NULL)
		return sizeof(i);
	return fwrite(&i, sizeof(i), 1, enc_fp);
}

size_t
x86_64_imm32(int32_t i)
{
	int endian;
	if (enc_fp == NULL)
		return sizeof(i);
	endian = 1;
	/* check host system endianness */
	if (*((char *) &endian))
	{
		/* little endian (native) */
		return x86_64_write(i & 0x000000FF) +
		       x86_64_write((i & 0x0000FF00) >> 8) +
		       x86_64_write((i & 0x00FF0000) >> 16) +
		       x86_64_write((i & 0xFF000000) >> 24);
	}
	else
	{
		/* big endian (convert) */
		return x86_64_write((i & 0xFF000000) >> 24) +
		       x86_64_write((i & 0x00FF0000) >> 16) +
		       x86_64_write((i & 0x0000FF00) >> 8) +
		       x86_64_write(i & 0x000000FF);
	}
	/*return fwrite(&i, sizeof(i), 1, enc_fp);*/
}

size_t
x86_64_imm64(int64_t i)
{
	int endian;
	if (enc_fp == NULL)
		return sizeof(i);
	endian = 1;
	/* check host system endianness */
	if (*((char *) &endian))
	{
		/* little endian (native) */
		return x86_64_write(i & 0x00000000000000FF) +
		       x86_64_write((i & 0x000000000000FF00) >> 8) +
		       x86_64_write((i & 0x0000000000FF0000) >> 16) +
		       x86_64_write((i & 0x00000000FF000000) >> 24) +
		       x86_64_write((i & 0x000000FF00000000) >> 32) +
		       x86_64_write((i & 0x0000FF0000000000) >> 40) +
		       x86_64_write((i & 0x00FF000000000000) >> 48) +
		       x86_64_write((i & 0xFF00000000000000) >> 56);
	}
	else
	{
		/* big endian (convert) */
		return x86_64_write((i & 0xFF00000000000000) >> 56) +
		       x86_64_write((i & 0x00FF000000000000) >> 48) +
		       x86_64_write((i & 0x0000FF0000000000) >> 40) +
		       x86_64_write((i & 0x000000FF00000000) >> 32) +
		       x86_64_write((i & 0x00000000FF000000) >> 24) +
		       x86_64_write((i & 0x0000000000FF0000) >> 16) +
		       x86_64_write((i & 0x000000000000FF00) >> 8) +
		       x86_64_write(i & 0x00000000000000FF);
	}
	/*return fwrite(&i, sizeof(i), 1, enc_fp);*/
}

size_t
x86_64_rex(int w,
           int r,
           int x,
           int b)
{
	uint8_t i = 0x40;
	if (w)
		i += 1 << 3;
	if (r)
		i += 1 << 2;
	if (x)
		i += 1 << 1;
	if (b)
		i += 1;
	return x86_64_write(i);
}

/*
 * mod argument should be 0, 1, 2 or 3 (representing 00, 01, 10 and 11)
 */
size_t
x86_64_modrm(int mod,
             int reg,
             int rm)
{
	int8_t val;
	/* 32-bit modr/m table for mod 00 */
	int8_t table[8][8] = {
		{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07},
		{0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f},
		{0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17},
		{0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f},
		{0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27},
		{0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f},
		{0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37},
		{0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f}
	};
	if (reg >= X86_64_R8)
		reg -= 8;
	if (rm >= X86_64_R8)
		rm -= 8;
	/* 0x40 * mod will give an offset for mod 01, 10 and 11 */
	val = table[rm][reg] + (0x40 * mod);
	return x86_64_write(val);
}

size_t
x86_64_xor_r32_r32(X86_64_REG rega, X86_64_REG regb)
{
	return (X86_64_REG64(rega) || X86_64_REG64(regb) ?
	           x86_64_rex(0, X86_64_REG64(regb), 0, X86_64_REG64(rega)) : 0) +
	       x86_64_write(0x31) +
	       x86_64_modrm(3, rega, regb);
}

size_t
x86_64_xor_r64_r64(X86_64_REG rega, X86_64_REG regb)
{
	return x86_64_rex(1, X86_64_REG64(regb), 0, X86_64_REG64(rega)) +
	       x86_64_write(0x31) +
	       x86_64_modrm(3, rega, regb);
}

size_t
x86_64_cmp_r64_imm8(X86_64_REG reg, int8_t value)
{
	return x86_64_rex(1, 0, 0, X86_64_REG64(reg)) +
	       x86_64_write((int8_t) 0x83) +
	       x86_64_write((int8_t) 0xf8 + (X86_64_REG64(reg) ? reg - 8 : reg)) +
	       x86_64_write(value);
}

size_t
x86_64_cmp_rm64_imm8(X86_64_REG reg, int8_t value)
{
	return (X86_64_REG64(reg) ? x86_64_rex(0, 0, 0, 1) : 0) +
	       x86_64_write((int8_t) 0x80) +
	       x86_64_write(0x38 + (X86_64_REG64(reg) ? reg - 8 : reg)) +
	       x86_64_write(value);
}

size_t
x86_64_call_rel32(int32_t off)
{
	return x86_64_write((int8_t) 0xe8) + x86_64_imm32(off);
}

size_t
x86_64_syscall()
{
	return x86_64_write(0x0f) + x86_64_write(0x05);
}

size_t
x86_64_ret_near()
{
	return x86_64_write((int8_t) 0xc3);
}

size_t
x86_64_pusha()
{
	return x86_64_write(0x60);
}

size_t
x86_64_popa()
{
	return x86_64_write(0x61);
}

size_t
x86_64_pushf()
{
	return x86_64_write((int8_t) 0x9c);
}

size_t
x86_64_popf()
{
	return x86_64_write((int8_t) 0x9d);
}

size_t
x86_64_nop()
{
	return x86_64_write((int8_t) 0x90);
}

size_t
x86_64_nop_r32(X86_64_REG reg)
{
	return (X86_64_REG64(reg) ? x86_64_rex(0, 0, 0, 1) : 0) +
	       x86_64_write(0x0f) +
	       x86_64_write(0x1f) +
	       x86_64_modrm(3, reg, X86_64_RAX);
}

size_t
x86_64_nop_r64(X86_64_REG reg)
{
	return x86_64_rex(1, 0, 0, X86_64_REG64(reg)) +
	       x86_64_write(0x0f) +
	       x86_64_write(0x1f) +
	       x86_64_modrm(3, reg, X86_64_RAX);
}

