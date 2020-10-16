/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * xor.c
 * x86_64 xor instruction test
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include <stdio.h>

#include "x86_64.h"

int
main()
{
	x86_64_encoder_out(stdout);
	x86_64_xor_r64_r64(X86_64_RAX, X86_64_RAX);
	x86_64_xor_r64_r64(X86_64_RDX, X86_64_RDX);
	x86_64_xor_r64_r64(X86_64_RAX, X86_64_R8);
	x86_64_xor_r64_r64(X86_64_R8, X86_64_RAX);
	x86_64_xor_r64_r64(X86_64_R8, X86_64_R8);

	x86_64_xor_r32_r32(X86_64_RAX, X86_64_RAX);
	x86_64_xor_r32_r32(X86_64_RDX, X86_64_RDX);
	x86_64_xor_r32_r32(X86_64_RAX, X86_64_R8);
	x86_64_xor_r32_r32(X86_64_R8, X86_64_RAX);
	x86_64_xor_r32_r32(X86_64_R8, X86_64_R8);

	return 0;
}

