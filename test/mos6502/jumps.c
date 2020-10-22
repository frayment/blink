/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * jumps.c
 * MOS 6502 jump and return instruction test
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 20/10/2020
 */

#include <stdio.h>

#include "mos6502.h"

int
main()
{
	mos6502_encoder_out(stdout);
	mos6502_jmp_abs16(0xffaa);
	mos6502_jmp_ind16(0xffaa);

	mos6502_jsr_abs16(0xffaa);

	mos6502_rti();

	mos6502_rts();

	return 0;
}

