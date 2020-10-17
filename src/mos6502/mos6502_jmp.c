/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_jmp.c
 * MOS 6502 encoder for jmp instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

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

