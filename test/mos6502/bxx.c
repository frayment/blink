/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * bxx.c
 * MOS 6502 branch instructions test
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
	mos6502_bcc_rel8(0xff);
	mos6502_bcs_rel8(0xff);
	mos6502_beq_rel8(0xff);
	mos6502_bmi_rel8(0xff);
	mos6502_bne_rel8(0xff);
	mos6502_bpl_rel8(0xff);
	mos6502_bvc_rel8(0xff);
	mos6502_bvs_rel8(0xff);

	return 0;
}

