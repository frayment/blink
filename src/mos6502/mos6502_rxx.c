/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_rxx.c
 * MOS 6502 encoder for return instructions
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_rti()
{
	return mos6502_write(0x40);
}

size_t
mos6502_rts()
{
	return mos6502_write(0x60);
}

