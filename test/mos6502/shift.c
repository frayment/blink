/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * shift.c
 * MOS 6502 shift instruction test
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
	mos6502_asl_acc();
	mos6502_asl_abs8(0x50);
	mos6502_asl_abs8_rx(0x50);
	mos6502_asl_abs16(0x50ff);
	mos6502_asl_abs16_rx(0x50ff);

	mos6502_lsr_acc();
	mos6502_lsr_abs8(0x50);
	mos6502_lsr_abs8_rx(0x50);
	mos6502_lsr_abs16(0x50ff);
	mos6502_lsr_abs16_rx(0x50ff);

	mos6502_rol_acc();
	mos6502_rol_abs8(0x50);
	mos6502_rol_abs8_rx(0x50);
	mos6502_rol_abs16(0x50ff);
	mos6502_rol_abs16_rx(0x50ff);

	mos6502_ror_acc();
	mos6502_ror_abs8(0x50);
	mos6502_ror_abs8_rx(0x50);
	mos6502_ror_abs16(0x50ff);
	mos6502_ror_abs16_rx(0x50ff);
/*

asl a
asl $50
asl $50, x
asl $50ff
asl $50ff, x

lsr a
lsr $50
lsr $50, x
lsr $50ff
lsr $50ff, x

rol a
rol $50
rol $50, x
rol $50ff
rol $50ff, x

ror a
ror $50
ror $50, x
ror $50ff
ror $50ff, x
*/

	return 0;
}

