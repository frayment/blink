/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * other.c
 * MOS 6502 bit, brk and nop instruction test
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 22/10/2020
 */

#include <stdio.h>

#include "mos6502.h"

int
main()
{
	mos6502_encoder_out(stdout);
	mos6502_bit_abs8(0x50);
	mos6502_bit_abs16(0x50ff);

	mos6502_brk();

	mos6502_nop();

	return 0;
}

