// license:BSD-3-Clause
// copyright-holders:hap
/******************************************************************************

Videopac 40 cartridge emulation

4KB ROM (program ROM is fixed, data ROM is 'bankswitched' via P11)

Used in:
- #31: Musician
- #40: 4 in 1 Row

******************************************************************************/

#include "emu.h"
#include "4in1.h"


//-------------------------------------------------
//  o2_4in1_device - constructor
//-------------------------------------------------

DEFINE_DEVICE_TYPE(O2_ROM_4IN1, o2_4in1_device, "o2_4in1", "Odyssey 2 Videopac 40")


o2_4in1_device::o2_4in1_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock) :
	o2_rom_device(mconfig, O2_ROM_4IN1, tag, owner, clock)
{ }

void o2_4in1_device::device_start()
{
	save_item(NAME(m_control));
	save_item(NAME(m_bank));
}

void o2_4in1_device::cart_init()
{
	if (m_rom_size != 0x1000)
		fatalerror("o2_4in1_device: Wrong ROM region size\n");
}


//-------------------------------------------------
//  mapper specific handlers
//-------------------------------------------------

u8 o2_4in1_device::io_read(offs_t offset)
{
	if (m_control & 2)
		return m_rom[m_bank << 8 | offset];
	else
		return 0xff;
}
