/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * x86_64.h
 * x86_64 encoder header
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 13/10/2020
 */

#ifndef FR_RAYMENT_BLINK_X86_64_H
#define FR_RAYMENT_BLINK_X86_64_H

#include <stdint.h>
#include <stdio.h>

/*
 * register definitions
 *
 * note that smaller registers such as EAX, AX, AL and AH can still be used
 * in instructions - simply supply the 64-bit variant and it will resolve
 * itself automatically
 *
 * this happens because encodings explicitly define the operand sizes
 */
#define X86_64_RAX 0x0
#define X86_64_RCX 0x1
#define X86_64_RDX 0x2
#define X86_64_RBX 0x3
#define X86_64_RSP 0x4
#define X86_64_RBP 0x5
#define X86_64_RSI 0x6
#define X86_64_RDI 0x7
#define X86_64_R8  0x8
#define X86_64_R9  0x9
#define X86_64_R10 0xa
#define X86_64_R11 0xb
#define X86_64_R12 0xc
#define X86_64_R13 0xd
#define X86_64_R14 0xe
#define X86_64_R15 0xf

#define X86_64_REG64(x) (x >= X86_64_R8)

typedef int X86_64_REG;

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
void   x86_64_encoder_out(FILE *);

size_t x86_64_write(int8_t);

size_t x86_64_imm32(int32_t);
size_t x86_64_imm64(int64_t);

size_t x86_64_rex(int, int, int, int);
size_t x86_64_modrm(int, int, int);

size_t x86_64_xor_r32_r32(X86_64_REG, X86_64_REG);
size_t x86_64_xor_r64_r64(X86_64_REG, X86_64_REG);

size_t x86_64_mov_r32_imm32(X86_64_REG, int32_t);
size_t x86_64_mov_r64_imm64(X86_64_REG, int64_t);
size_t x86_64_mov_rm64_imm8(X86_64_REG, int8_t);
/*size_t x86_64_mov_r32_r32(X86_64_REG, X86_64_REG);*/
size_t x86_64_mov_r64_r64(X86_64_REG, X86_64_REG);

size_t x86_64_add_r32_imm8(X86_64_REG, int8_t);
size_t x86_64_add_r64_imm8(X86_64_REG, int8_t);
size_t x86_64_add_r32_imm32(X86_64_REG, int32_t);
size_t x86_64_add_r64_imm64(X86_64_REG, int64_t);
/*size_t x86_64_add_rm32_imm8(X86_64_REG, int8_t);*/
size_t x86_64_add_rm64_imm8(X86_64_REG, int8_t);
size_t x86_64_add_r32_r32(X86_64_REG, X86_64_REG);
size_t x86_64_add_r64_r64(X86_64_REG, X86_64_REG);

size_t x86_64_sub_r32_imm8(X86_64_REG, int8_t);
size_t x86_64_sub_r64_imm8(X86_64_REG, int8_t);
size_t x86_64_sub_r32_imm32(X86_64_REG, int32_t);
size_t x86_64_sub_r64_imm64(X86_64_REG, int64_t);
/*size_t x86_64_add_rm32_imm8(X86_64_REG, int8_t);*/
size_t x86_64_sub_rm64_imm8(X86_64_REG, int8_t);
size_t x86_64_sub_r32_r32(X86_64_REG, X86_64_REG);
size_t x86_64_sub_r64_r64(X86_64_REG, X86_64_REG);

size_t x86_64_cmp_r64_imm8(X86_64_REG, int8_t);
size_t x86_64_cmp_rm64_imm8(X86_64_REG, int8_t);

size_t x86_64_jmp_rel8(int8_t);
size_t x86_64_jmp_rel32(int32_t);
size_t x86_64_jne_rel8(int8_t);
size_t x86_64_jne_rel32(int32_t);

size_t x86_64_call_rel32(int32_t);

size_t x86_64_syscall();
size_t x86_64_ret_near();

#endif

