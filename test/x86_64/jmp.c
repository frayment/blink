/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * jmp.c
 * x86_64 jmp instruction test
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
	x86_64_jmp_rel8(-2);
	x86_64_jmp_rel8(2);
	x86_64_jmp_rel32(255);
	x86_64_jmp_rel32(-255);

	x86_64_jne_rel8(-2);
	x86_64_jne_rel8(2);
	x86_64_jne_rel32(255);
	x86_64_jne_rel32(-255);

	return 0;
}

