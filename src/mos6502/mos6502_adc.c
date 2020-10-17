/*
 * This file is licensed under BSD 3-Clause.
 * All license information is available in the included COPYING file.
 */

/*
 * mos6502_adc.c
 * MOS 6502 encoder for adc instruction
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 16/10/2020
 */

#include "mos6502.h"

size_t
mos6502_adc_imm8(int8_t value)
{
	return mos6502_write(0x69) + mos6502_write(value);
}

size_t
mos6502_adc_abs8(int8_t value)
{
	return mos6502_write(0x65) + mos6502_write(value);
}

size_t
mos6502_adc_abs8_rx(int8_t value)
{
	return mos6502_write(0x75) + mos6502_write(value);
}

size_t
mos6502_adc_abs16(int16_t value)
{
	return mos6502_write(0x6d) + mos6502_imm16(value);
}

size_t
mos6502_adc_abs16_rx(int16_t value)
{
	return mos6502_write(0x7d) + mos6502_imm16(value);
}

size_t
mos6502_adc_abs16_ry(int16_t value)
{
	return mos6502_write(0x79) + mos6502_imm16(value);
}

size_t
mos6502_adc_ind8_rx(int8_t value)
{
	return mos6502_write(0x61) + mos6502_write(value);
}

size_t
mos6502_adc_ind8_ry(int8_t value)
{
	return mos6502_write(0x71) + mos6502_write(value);
}

