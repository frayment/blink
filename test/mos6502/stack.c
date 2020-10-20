/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * stack.c
 * MOS 6502 stack instruction test
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
	mos6502_tsx();
	mos6502_txs();
	mos6502_pha();
	mos6502_php();
	mos6502_pla();
	mos6502_plp();

	return 0;
}

