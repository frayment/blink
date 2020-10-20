/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * register.c
 * MOS 6502 register instruction test
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
	mos6502_tax();
	mos6502_tay();
	mos6502_txa();
	mos6502_tya();
	mos6502_inx();
	mos6502_iny();
	mos6502_dex();
	mos6502_dey();

	return 0;
}

