/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_rol.c
 * MOS 6502 encoder for rol instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 17/10/2020
 */

#include "mos6502.h"

size_t
mos6502_rol_acc()
{
	return mos6502_write(0x2a);
}

size_t
mos6502_rol_abs8(int8_t value)
{
	return mos6502_write(0x26) + mos6502_write(value);
}

size_t
mos6502_rol_abs8_rx(int8_t value)
{
	return mos6502_write(0x36) + mos6502_write(value);
}

size_t
mos6502_rol_abs16(int16_t value)
{
	return mos6502_write(0x2e) + mos6502_imm16(value);
}

size_t
mos6502_rol_abs16_rx(int16_t value)
{
	return mos6502_write(0x3e) + mos6502_imm16(value);
}

