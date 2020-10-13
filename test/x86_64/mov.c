/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mov.c
 * x86_64 mov instruction test
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 13/10/2020
 */

#include <stdio.h>

#include "x86_64.h"

int
main()
{
	x86_64_encoder_out(stdout);
	x86_64_mov_r64_r64(X86_64_RAX, X86_64_RAX);
	x86_64_mov_r64_r64(X86_64_R8, X86_64_R8);
	x86_64_mov_r64_r64(X86_64_RAX, X86_64_R8);
	x86_64_mov_r64_r64(X86_64_R8, X86_64_RAX);
	x86_64_mov_r32_imm32(X86_64_RAX, 0x2000004);
	x86_64_mov_r32_imm32(X86_64_RDI, 0x1);
	x86_64_mov_r64_r64(X86_64_RSI, X86_64_R8);
	x86_64_mov_r32_imm32(X86_64_RDX, 0x1);
	x86_64_mov_r32_imm32(X86_64_R8, 0x2000);
	x86_64_mov_rm64_imm8(X86_64_RAX, 0x0);
	x86_64_mov_rm64_imm8(X86_64_R8, 0x28);

	return 0;
}

