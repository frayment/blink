/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * cmp.c
 * x86_64 cmp instruction test
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
	x86_64_cmp_r64_imm8(X86_64_R8, 0x0);
	x86_64_cmp_r64_imm8(X86_64_RAX, 0x0);
	x86_64_cmp_r64_imm8(X86_64_RDX, 0x0);
	x86_64_cmp_rm64_imm8(X86_64_R8, 0x0);
	x86_64_cmp_rm64_imm8(X86_64_RAX, 0x0);
	x86_64_cmp_rm64_imm8(X86_64_RDX, 0x0);

	return 0;
}

