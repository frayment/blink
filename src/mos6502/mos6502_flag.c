/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_flag.c
 * MOS 6502 encoder for flag instructions
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

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

