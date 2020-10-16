/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_bxx.c
 * MOS 6502 encoder for branch instructions
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_bcc_rel8(int8_t off)
{
	return mos6502_write((int8_t) 0x90) + mos6502_write(off);
}

size_t
mos6502_bcs_rel8(int8_t off)
{
	return mos6502_write((int8_t) 0xb0) + mos6502_write(off);
}

size_t
mos6502_beq_rel8(int8_t off)
{
	return mos6502_write((int8_t) 0xf0) + mos6502_write(off);
}

size_t
mos6502_bmi_rel8(int8_t off)
{
	return mos6502_write(0x30) + mos6502_write(off);
}

size_t
mos6502_bne_rel8(int8_t off)
{
	return mos6502_write((int8_t) 0xd0) + mos6502_write(off);
}

size_t
mos6502_bpl_rel8(int8_t off)
{
	return mos6502_write(0x10) + mos6502_write(off);
}

size_t
mos6502_bvc_rel8(int8_t off)
{
	return mos6502_write(0x50) + mos6502_write(off);
}

size_t
mos6502_bvs_rel8(int8_t off)
{
	return mos6502_write(0x70) + mos6502_write(off);
}

