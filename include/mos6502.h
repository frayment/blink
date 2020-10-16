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
 * #define MOS6502_A  0x1
 * #define MOS6502_X  0x2
 * #define MOS6502_Y  0x3
 * #define MOS6502_PC 0x4
 * #define MOS6502_S  0x5
 * #define MOS6502_P  0x6

 * typedef int MOS6502_REG;
 */

/*
 * all of the following functions return size_t - this represents the number
 * of bytes that are written to the file pointer
 *
 * instructions use intel syntax, that is:
 *     opcode destination source
 */

/*
 * set the file pointer to write all bytes to
 *
 * should not error if set to NULL, instead write nothing but continue to
 * return the correct number of non-written bytes for each function
 */
void   mos6502_encoder_out(FILE *);

size_t mos6502_write(int8_t);

size_t mos6502_imm16(int16_t);

size_t mos6502_jmp_abs16(int16_t);
size_t mos6502_jmp_ind16(int16_t);

size_t mos6502_nop();

size_t mos6502_adc_imm8(int8_t);
size_t mos6502_adc_abs8(int8_t);
size_t mos6502_adc_abs8_rx(int8_t);
size_t mos6502_adc_abs16(int16_t);
size_t mos6502_adc_abs16_rx(int16_t);
size_t mos6502_adc_abs16_ry(int16_t);
size_t mos6502_adc_ind8_rx(int8_t);
size_t mos6502_adc_ind8_ry(int8_t);

size_t mos6502_and_imm8(int8_t);
size_t mos6502_and_abs8(int8_t);
size_t mos6502_and_abs8_rx(int8_t);
size_t mos6502_and_abs16(int16_t);
size_t mos6502_and_abs16_rx(int16_t);
size_t mos6502_and_abs16_ry(int16_t);
size_t mos6502_and_ind8_rx(int8_t);
size_t mos6502_and_ind8_ry(int8_t);

size_t mos6502_asl_acc();
size_t mos6502_asl_abs8(int8_t);
size_t mos6502_asl_abs8_rx(int8_t);
size_t mos6502_asl_abs16(int16_t);
size_t mos6502_asl_abs16_rx(int16_t);

size_t mos6502_bit_abs8(int8_t);
size_t mos6502_bit_abs16(int16_t);

size_t mos6502_bcc_rel8(int8_t);
size_t mos6502_bcs_rel8(int8_t);
size_t mos6502_beq_rel8(int8_t);
size_t mos6502_bmi_rel8(int8_t);
size_t mos6502_bne_rel8(int8_t);
size_t mos6502_bpl_rel8(int8_t);
size_t mos6502_bvc_rel8(int8_t);
size_t mos6502_bvs_rel8(int8_t);

size_t mos6502_brk();

size_t mos6502_cmp_imm8(int8_t);
size_t mos6502_cmp_abs8(int8_t);
size_t mos6502_cmp_abs8_rx(int8_t);
size_t mos6502_cmp_abs16(int16_t);
size_t mos6502_cmp_abs16_rx(int16_t);
size_t mos6502_cmp_abs16_ry(int16_t);
size_t mos6502_cmp_ind8_rx(int8_t);
size_t mos6502_cmp_ind8_ry(int8_t);

size_t mos6502_cpx_imm8(int8_t);
size_t mos6502_cpx_abs8(int8_t);
size_t mos6502_cpx_abs16(int16_t);

size_t mos6502_cpy_imm8(int8_t);
size_t mos6502_cpy_abs8(int8_t);
size_t mos6502_cpy_abs16(int16_t);

#endif

