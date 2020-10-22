/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * flag.c
 * MOS 6502 flag instruction test
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
	mos6502_clc();
	mos6502_cld();
	mos6502_cli();
	mos6502_clv();
	mos6502_sec();
	mos6502_sed();
	mos6502_sei();

	return 0;
}

