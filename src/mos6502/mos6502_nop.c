/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_nop.c
 * MOS 6502 encoder for nop instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_nop()
{
	return mos6502_write((int8_t) 0xea);
}

