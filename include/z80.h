/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * z80.h
 * Zilog Z80 encoder header
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#ifndef FR_RAYMENT_BLINK_Z80_H
#define FR_RAYMENT_BLINK_Z80_H

#include <stdint.h>
#include <stdio.h>

#define Z80_A   0x0
#define Z80_B   0x1
#define Z80_C   0x2
#define Z80_D   0x3
#define Z80_E   0x4
#define Z80_H   0x5
#define Z80_L   0x6
#define Z80_AF  0x7
#define Z80_BC  0x8
#define Z80_DE  0x9
#define Z80_HL  0xa
#define Z80_IX  0xb
#define Z80_IY  0xc
#define Z80_SP  0xd
#define Z80_I   0xe
#define Z80_R   0xf
#define Z80_IXH 0x10
#define Z80_IXL 0x11
#define Z80_IYH 0x12
#define Z80_IYL 0x13

typedef int Z80_REG;

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
void   z80_encoder_out(FILE *);

size_t z80_write(int8_t);

size_t z80_imm16(int16_t);

int z80_idx(Z80_REG);
size_t z80_i(Z80_REG);
size_t z80_b(int8_t, Z80_REG);
size_t z80_pp(int8_t, Z80_REG);
size_t z80_qq(int8_t, Z80_REG);
size_t z80_rrr(int8_t, int8_t, Z80_REG);

size_t z80_adc_ra_r8(Z80_REG);
size_t z80_adc_ra_imm8(int8_t);
size_t z80_adc_ra_rhl();
size_t z80_adc_ra_ir16_off8(Z80_REG, int8_t);
size_t z80_adc_rhl_r16(Z80_REG);

size_t z80_add_ra_r8(Z80_REG);
size_t z80_add_ra_imm8(int8_t);
size_t z80_add_ra_rhl();
size_t z80_add_ra_ir16_off8(Z80_REG, int8_t);
size_t z80_add_rhl_r16(Z80_REG);
size_t z80_add_ir16_r16(Z80_REG, Z80_REG);

size_t z80_and_r8(Z80_REG);
size_t z80_and_imm8(int8_t);
size_t z80_and_rhl();
size_t z80_and_ir16_off8(Z80_REG, int8_t);

size_t z80_bit_bit_r8(int8_t, Z80_REG);
size_t z80_bit_bit_hl(int8_t);
size_t z80_bit_bit_ir16_off8(int8_t, Z80_REG, int8_t);

size_t z80_xor_r8(Z80_REG);
size_t z80_xor_imm8(int8_t);
size_t z80_xor_rhl();
size_t z80_xor_ir16_off8(Z80_REG, int8_t);

#endif

