/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_register.c
 * MOS 6502 encoder for register instructions
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_tax()
{
	return mos6502_write((int8_t) 0xaa);
}

size_t
mos6502_tay()
{
	return mos6502_write((int8_t) 0xa8);
}

size_t
mos6502_txa()
{
	return mos6502_write((int8_t) 0x8a);
}

size_t
mos6502_tya()
{
	return mos6502_write((int8_t) 0x98);
}

size_t
mos6502_inx()
{
	return mos6502_write((int8_t) 0xe8);
}

size_t
mos6502_iny()
{
	return mos6502_write((int8_t) 0xc8);
}

size_t
mos6502_dex()
{
	return mos6502_write((int8_t) 0xca);
}

size_t
mos6502_dey()
{
	return mos6502_write((int8_t) 0x88);
}

