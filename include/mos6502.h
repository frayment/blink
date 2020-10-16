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

#endif

