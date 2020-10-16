/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * arith.c
 * MOS 6502 arithmetic instruction test
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
	mos6502_adc_imm8(0x50);
	mos6502_adc_abs8(0x50);
	mos6502_adc_abs8_rx(0x50);
	mos6502_adc_abs16(0x50ff);
	mos6502_adc_abs16_rx(0x50ff);
	mos6502_adc_abs16_ry(0x50ff);
	mos6502_adc_ind8_rx(0x50);
	mos6502_adc_ind8_ry(0x50);

	mos6502_sbc_imm8(0x50);
	mos6502_sbc_abs8(0x50);
	mos6502_sbc_abs8_rx(0x50);
	mos6502_sbc_abs16(0x50ff);
	mos6502_sbc_abs16_rx(0x50ff);
	mos6502_sbc_abs16_ry(0x50ff);
	mos6502_sbc_ind8_rx(0x50);
	mos6502_sbc_ind8_ry(0x50);

	return 0;
}

