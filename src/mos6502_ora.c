/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_ora.c
 * MOS 6502 encoder for ora instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_ora_imm8(int8_t value)
{
	return mos6502_write(0x09) + mos6502_write(value);
}

size_t
mos6502_ora_abs8(int8_t value)
{
	return mos6502_write(0x05) + mos6502_write(value);
}

size_t
mos6502_ora_abs8_rx(int8_t value)
{
	return mos6502_write(0x15) + mos6502_write(value);
}

size_t
mos6502_ora_abs16(int16_t value)
{
	return mos6502_write(0x0d) + mos6502_imm16(value);
}

size_t
mos6502_ora_abs16_rx(int16_t value)
{
	return mos6502_write(0x1d) + mos6502_imm16(value);
}

size_t
mos6502_ora_abs16_ry(int16_t value)
{
	return mos6502_write(0x19) + mos6502_imm16(value);
}

size_t
mos6502_ora_ind8_rx(int8_t value)
{
	return mos6502_write(0x01) + mos6502_write(value);
}

size_t
mos6502_ora_ind8_ry(int8_t value)
{
	return mos6502_write(0x11) + mos6502_write(value);
}

