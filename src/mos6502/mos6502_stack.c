/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_stack.c
 * MOS 6502 encoder for stack instructions
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_tsx()
{
	return mos6502_write((int8_t) 0xba);
}

size_t
mos6502_txs()
{
	return mos6502_write((int8_t) 0x9a);
}

size_t
mos6502_pha()
{
	return mos6502_write(0x48);
}

size_t
mos6502_php()
{
	return mos6502_write(0x08);
}

size_t
mos6502_pla()
{
	return mos6502_write(0x68);
}

size_t
mos6502_plp()
{
	return mos6502_write(0x28);
}

