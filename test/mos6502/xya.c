/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * xya.c
 * MOS 6502 compare, load and store to X/Y/A instruction test
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
	mos6502_cmp_imm8(0x5);
	mos6502_cmp_abs8(0x5);
	mos6502_cmp_abs8_rx(0x5);
	mos6502_cmp_abs16(0xffaa);
	mos6502_cmp_abs16_rx(0xffaa);
	mos6502_cmp_abs16_ry(0xffaa);
	mos6502_cmp_ind8_rx(0x5);
	mos6502_cmp_ind8_ry(0x5);

	mos6502_cpx_imm8(0xff);
	mos6502_cpx_abs8(0xff);
	mos6502_cpx_abs16(0xffaa);

	mos6502_cpy_imm8(0xff);
	mos6502_cpy_abs8(0xff);
	mos6502_cpy_abs16(0xffaa);

	mos6502_lda_imm8(0xff);
	mos6502_lda_abs8(0xff);
	mos6502_lda_abs8_rx(0xff);
	mos6502_lda_abs16(0xffaa);
	mos6502_lda_abs16_rx(0xffaa);
	mos6502_lda_ind8_rx(0xff);
	mos6502_lda_ind8_ry(0xff);

	mos6502_ldx_imm8(0xff);
	mos6502_ldx_abs8(0xff);
	mos6502_ldx_abs8_ry(0xff);
	mos6502_ldx_abs16(0xffaa);
	mos6502_ldx_abs16_ry(0xffaa);

	mos6502_ldy_imm8(0xff);
	mos6502_ldy_abs8(0xff);
	mos6502_ldy_abs8_rx(0xff);
	mos6502_ldy_abs16(0xffaa);
	mos6502_ldy_abs16_rx(0xffaa);

	mos6502_sta_abs8(0xff);
	mos6502_sta_abs8_rx(0xff);
	mos6502_sta_abs16(0xffaa);
	mos6502_sta_abs16_rx(0xffaa);
	mos6502_sta_ind8_rx(0xff);
	mos6502_sta_ind8_ry(0xff);

	mos6502_stx_abs8(0xff);
	mos6502_stx_abs8_ry(0xff);
	mos6502_stx_abs16(0xffaa);

	mos6502_sty_abs8(0xff);
	mos6502_sty_abs8_rx(0xff);
	mos6502_sty_abs16(0xffaa);

	return 0;
}

