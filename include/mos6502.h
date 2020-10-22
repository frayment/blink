/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502.h
 * MOS 6502 encoder header
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#ifndef FR_RAYMENT_BLINK_MOS6502_H
#define FR_RAYMENT_BLINK_MOS6502_H

#include <stdint.h>
#include <stdio.h>

/*
 * The 6502 CPU uses different addressing modes and the assembler contains
 * unique syntax for each mode. The following table contains these modes and
 * syntax as well as function suffixes.
 *
 *     MODE:        SYNTAX (example):  FUNCTION SUFFIX:
 *     Accumulator  ROR A              acc
 *     Implied      BRK                <none>
 *     Immediate    CMP #$A4           imm8
 *     Zero Page    INC $90            abs8
 *     Zero Page,X  LDA $61,X          abs8_rx
 *     Zero Page,Y  LDX $14,Y          abs8_ry
 *     Absolute     ORA $C030          abs16
 *     Absolute,X   ROL $4040,X        abs16_rx
 *     Absolute,Y   EOR $ABBF,Y        abs16_ry
 *     Indirect     JMP ($52B6)        ind16
 *     Indirect,X   SBC ($9E,X)        ind8_rx
 *     Indirect,Y   ADC ($21),Y        ind8_ry
 */

/*
 * Set the output file for all function calls.
 *
 * Should not error if set to NULL, instead write nothing but continue to
 * return the correct number of non-written bytes for each function.
 */
void   mos6502_encoder_out(FILE *);

/*
 * write an 8-bit value
 */
size_t mos6502_write(int8_t);

/*
 * write a 16-bit immediate value in little-endian
 */
size_t mos6502_imm16(int16_t);

/*
 * adc - add with carry
 */
size_t mos6502_adc_imm8(int8_t);
size_t mos6502_adc_abs8(int8_t);
size_t mos6502_adc_abs8_rx(int8_t);
size_t mos6502_adc_abs16(int16_t);
size_t mos6502_adc_abs16_rx(int16_t);
size_t mos6502_adc_abs16_ry(int16_t);
size_t mos6502_adc_ind8_rx(int8_t);
size_t mos6502_adc_ind8_ry(int8_t);

/*
 * and - bitwise AND with accumulator
 */
size_t mos6502_and_imm8(int8_t);
size_t mos6502_and_abs8(int8_t);
size_t mos6502_and_abs8_rx(int8_t);
size_t mos6502_and_abs16(int16_t);
size_t mos6502_and_abs16_rx(int16_t);
size_t mos6502_and_abs16_ry(int16_t);
size_t mos6502_and_ind8_rx(int8_t);
size_t mos6502_and_ind8_ry(int8_t);

/*
 * asl - arithmetic shift left
 */
size_t mos6502_asl_acc();
size_t mos6502_asl_abs8(int8_t);
size_t mos6502_asl_abs8_rx(int8_t);
size_t mos6502_asl_abs16(int16_t);
size_t mos6502_asl_abs16_rx(int16_t);

/*
 * bit - test bits
 */
size_t mos6502_bit_abs8(int8_t);
size_t mos6502_bit_abs16(int16_t);

/*
 * bcc - branch on carry clear
 * bcs - branch on carry set
 * beq - branch on equal
 * bmi - branch on minus
 * bne - branch on not equal
 * bpl - branch on plus
 * bvc - branch on overflow clear
 * bvs - branch on overflow set
 */
size_t mos6502_bcc_rel8(int8_t);
size_t mos6502_bcs_rel8(int8_t);
size_t mos6502_beq_rel8(int8_t);
size_t mos6502_bmi_rel8(int8_t);
size_t mos6502_bne_rel8(int8_t);
size_t mos6502_bpl_rel8(int8_t);
size_t mos6502_bvc_rel8(int8_t);
size_t mos6502_bvs_rel8(int8_t);

/*
 * brk - break
 */
size_t mos6502_brk();

/*
 * cmp - compare accumulator
 */
size_t mos6502_cmp_imm8(int8_t);
size_t mos6502_cmp_abs8(int8_t);
size_t mos6502_cmp_abs8_rx(int8_t);
size_t mos6502_cmp_abs16(int16_t);
size_t mos6502_cmp_abs16_rx(int16_t);
size_t mos6502_cmp_abs16_ry(int16_t);
size_t mos6502_cmp_ind8_rx(int8_t);
size_t mos6502_cmp_ind8_ry(int8_t);

/*
 * cpx - compare X register
 */
size_t mos6502_cpx_imm8(int8_t);
size_t mos6502_cpx_abs8(int8_t);
size_t mos6502_cpx_abs16(int16_t);

/*
 * cpy - compare Y register
 */
size_t mos6502_cpy_imm8(int8_t);
size_t mos6502_cpy_abs8(int8_t);
size_t mos6502_cpy_abs16(int16_t);

/*
 * clc - clear carry
 * cld - clear decimal
 * cli - clear interrupt
 * clv - clear overflow
 * sec - set carry
 * sed - set decimal
 * sei - set interrupt
 */
size_t mos6502_clc();
size_t mos6502_cld();
size_t mos6502_cli();
size_t mos6502_clv();
size_t mos6502_sec();
size_t mos6502_sed();
size_t mos6502_sei();

/*
 * dec - decrement memory
 */
size_t mos6502_dec_abs8(int8_t);
size_t mos6502_dec_abs8_rx(int8_t);
size_t mos6502_dec_abs16(int16_t);
size_t mos6502_dec_abs16_rx(int16_t);

/*
 * eor - bitwise exclusive OR
 */
size_t mos6502_eor_imm8(int8_t);
size_t mos6502_eor_abs8(int8_t);
size_t mos6502_eor_abs8_rx(int8_t);
size_t mos6502_eor_abs16(int16_t);
size_t mos6502_eor_abs16_rx(int16_t);
size_t mos6502_eor_abs16_ry(int16_t);
size_t mos6502_eor_ind8_rx(int8_t);
size_t mos6502_eor_ind8_ry(int8_t);

/*
 * inc - increment memory
 */
size_t mos6502_inc_abs8(int8_t);
size_t mos6502_inc_abs8_rx(int8_t);
size_t mos6502_inc_abs16(int16_t);
size_t mos6502_inc_abs16_rx(int16_t);

/*
 * jmp - jump
 */
size_t mos6502_jmp_abs16(int16_t);
size_t mos6502_jmp_ind16(int16_t);

/*
 * jsr - jump to subroutine
 */
size_t mos6502_jsr_abs16(int16_t);

/*
 * lda - load accumulator
 */
size_t mos6502_lda_imm8(int8_t);
size_t mos6502_lda_abs8(int8_t);
size_t mos6502_lda_abs8_rx(int8_t);
size_t mos6502_lda_abs16(int16_t);
size_t mos6502_lda_abs16_rx(int16_t);
size_t mos6502_lda_abs16_ry(int16_t);
size_t mos6502_lda_ind8_rx(int8_t);
size_t mos6502_lda_ind8_ry(int8_t);

/*
 * ldx - load X register
 */
size_t mos6502_ldx_imm8(int8_t);
size_t mos6502_ldx_abs8(int8_t);
size_t mos6502_ldx_abs8_ry(int8_t);
size_t mos6502_ldx_abs16(int16_t);
size_t mos6502_ldx_abs16_ry(int16_t);

/*
 * ldy - load Y register
 */
size_t mos6502_ldy_imm8(int8_t);
size_t mos6502_ldy_abs8(int8_t);
size_t mos6502_ldy_abs8_rx(int8_t);
size_t mos6502_ldy_abs16(int16_t);
size_t mos6502_ldy_abs16_rx(int16_t);

/*
 * lsr - logical shift right
 */
size_t mos6502_lsr_acc();
size_t mos6502_lsr_abs8(int8_t);
size_t mos6502_lsr_abs8_rx(int8_t);
size_t mos6502_lsr_abs16(int16_t);
size_t mos6502_lsr_abs16_rx(int16_t);

/*
 * nop - no operation
 */
size_t mos6502_nop();

/*
 * ora - bitwise OR with accumulator
 */
size_t mos6502_ora_imm8(int8_t);
size_t mos6502_ora_abs8(int8_t);
size_t mos6502_ora_abs8_rx(int8_t);
size_t mos6502_ora_abs16(int16_t);
size_t mos6502_ora_abs16_rx(int16_t);
size_t mos6502_ora_abs16_ry(int16_t);
size_t mos6502_ora_ind8_rx(int8_t);
size_t mos6502_ora_ind8_ry(int8_t);

/*
 * rol - rotate left
 */
size_t mos6502_rol_acc();
size_t mos6502_rol_abs8(int8_t);
size_t mos6502_rol_abs8_rx(int8_t);
size_t mos6502_rol_abs16(int16_t);
size_t mos6502_rol_abs16_rx(int16_t);

/*
 * ror - rotate right
 */
size_t mos6502_ror_acc();
size_t mos6502_ror_abs8(int8_t);
size_t mos6502_ror_abs8_rx(int8_t);
size_t mos6502_ror_abs16(int16_t);
size_t mos6502_ror_abs16_rx(int16_t);

/*
 * rti - return from interrupt
 */
size_t mos6502_rti();

/*
 * rts - return from subroutine
 */
size_t mos6502_rts();

/*
 * sbc - subtract with carry
 */
size_t mos6502_sbc_imm8(int8_t);
size_t mos6502_sbc_abs8(int8_t);
size_t mos6502_sbc_abs8_rx(int8_t);
size_t mos6502_sbc_abs16(int16_t);
size_t mos6502_sbc_abs16_rx(int16_t);
size_t mos6502_sbc_abs16_ry(int16_t);
size_t mos6502_sbc_ind8_rx(int8_t);
size_t mos6502_sbc_ind8_ry(int8_t);

/*
 * sta - store accumulator
 */
size_t mos6502_sta_abs8(int8_t);
size_t mos6502_sta_abs8_rx(int8_t);
size_t mos6502_sta_abs16(int16_t);
size_t mos6502_sta_abs16_rx(int16_t);
size_t mos6502_sta_abs16_ry(int16_t);
size_t mos6502_sta_ind8_rx(int8_t);
size_t mos6502_sta_ind8_ry(int8_t);

/*
 * stx - store X register
 */
size_t mos6502_stx_abs8(int8_t);
size_t mos6502_stx_abs8_ry(int8_t);
size_t mos6502_stx_abs16(int16_t);

/*
 * sty - store Y register
 */
size_t mos6502_sty_abs8(int8_t);
size_t mos6502_sty_abs8_rx(int8_t);
size_t mos6502_sty_abs16(int16_t);

/*
 * tax - transfer A to X
 * tay - transfer A to Y
 * txa - transfer X to A
 * tya - transfer Y to A
 * inx - increment X
 * iny - increment Y
 * dex - decrement X
 * dey - decrement Y
 */
size_t mos6502_tax();
size_t mos6502_tay();
size_t mos6502_txa();
size_t mos6502_tya();
size_t mos6502_inx();
size_t mos6502_iny();
size_t mos6502_dex();
size_t mos6502_dey();

/*
 * tsx - transfer stack pointer to X register
 * txs - transfer X register to stack pointer
 * pha - push accumulator
 * php - push process status
 * pla - pull accumulator
 * plp - pull process status
 */
size_t mos6502_tsx();
size_t mos6502_txs();
size_t mos6502_pha();
size_t mos6502_php();
size_t mos6502_pla();
size_t mos6502_plp();

#endif

