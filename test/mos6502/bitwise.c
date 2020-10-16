/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * bitwise.c
 * MOS 6502 bitwise instruction test
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include <stdio.h>

#include "mos6502.h"

int
main()
{
	mos6502_encoder_out(stdout);
	mos6502_and_imm8(0x50);
	mos6502_and_abs8(0x50);
	mos6502_and_abs8_rx(0x50);
	mos6502_and_abs16(0x50ff);
	mos6502_and_abs16_rx(0x50ff);
	mos6502_and_abs16_ry(0x50ff);
	mos6502_and_ind8_rx(0x50);
	mos6502_and_ind8_ry(0x50);

	mos6502_eor_imm8(0x50);
	mos6502_eor_abs8(0x50);
	mos6502_eor_abs8_rx(0x50);
	mos6502_eor_abs16(0x50ff);
	mos6502_eor_abs16_rx(0x50ff);
	mos6502_eor_abs16_ry(0x50ff);
	mos6502_eor_ind8_rx(0x50);
	mos6502_eor_ind8_ry(0x50);

	mos6502_ora_imm8(0x50);
	mos6502_ora_abs8(0x50);
	mos6502_ora_abs8_rx(0x50);
	mos6502_ora_abs16(0x50ff);
	mos6502_ora_abs16_rx(0x50ff);
	mos6502_ora_abs16_ry(0x50ff);
	mos6502_ora_ind8_rx(0x50);
	mos6502_ora_ind8_ry(0x50);

	return 0;
}

