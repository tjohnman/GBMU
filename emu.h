#ifndef EMU_H
#define EMU_H

#define EMU_EV_BIOS_END 1
#define EMU_EV_LCD_OFF 2

#include "includes.h"

namespace emu
{
	std::vector<uint16_t> trace;

    // Original BIOS (with logo lock)
    uint8_t bios[] = {
        0x31,0xfe,0xff,0xaf,0x21,0xff,0x9f,0x32,0xcb,0x7c,0x20,0xfb,0x21,0x26,0xff,0x0e,
        0x11,0x3e,0x80,0x32,0xe2,0x0c,0x3e,0xf3,0xe2,0x32,0x3e,0x77,0x77,0x3e,0xfc,0xe0,
        0x47,0x11,0x04,0x01,0x21,0x10,0x80,0x1a,0xcd,0x95,0x00,0xcd,0x96,0x00,0x13,0x7b,
        0xfe,0x34,0x20,0xf3,0x11,0xd8,0x00,0x06,0x08,0x1a,0x13,0x22,0x23,0x05,0x20,0xf9,
        0x3e,0x19,0xea,0x10,0x99,0x21,0x2f,0x99,0x0e,0x0c,0x3d,0x28,0x08,0x32,0x0d,0x20,
        0xf9,0x2e,0x0f,0x18,0xf3,0x67,0x3e,0x64,0x57,0xe0,0x42,0x3e,0x91,0xe0,0x40,0x04,
        0x1e,0x02,0x0e,0x0c,0xf0,0x44,0xfe,0x90,0x20,0xfa,0x0d,0x20,0xf7,0x1d,0x20,0xf2,
        0x0e,0x13,0x24,0x7c,0x1e,0x83,0xfe,0x62,0x28,0x06,0x1e,0xc1,0xfe,0x64,0x20,0x06,
        0x7b,0xe2,0x0c,0x3e,0x87,0xe2,0xf0,0x42,0x90,0xe0,0x42,0x15,0x20,0xd2,0x05,0x20,
        0x4f,0x16,0x20,0x18,0xcb,0x4f,0x06,0x04,0xc5,0xcb,0x11,0x17,0xc1,0xcb,0x11,0x17,
        0x05,0x20,0xf5,0x22,0x23,0x22,0x23,0xc9,0xce,0xed,0x66,0x66,0xcc,0x0d,0x00,0x0b,
        0x03,0x73,0x00,0x83,0x00,0x0c,0x00,0x0d,0x00,0x08,0x11,0x1f,0x88,0x89,0x00,0x0e,
        0xdc,0xcc,0x6e,0xe6,0xdd,0xdd,0xd9,0x99,0xbb,0xbb,0x67,0x63,0x6e,0x0e,0xec,0xcc,
        0xdd,0xdc,0x99,0x9f,0xbb,0xb9,0x33,0x3e,0x3c,0x42,0xb9,0xa5,0xb9,0xa5,0x42,0x3c,
        0x21,0x04,0x01,0x11,0xa8,0x00,0x1a,0x13,0xbe,0x20,0xfe,0x23,0x7d,0xfe,0x34,0x20,
        0xf5,0x06,0x19,0x78,0x86,0x23,0x05,0x20,0xfb,0x86,0x20,0xfe,0x3e,0x01,0xe0,0x50
    };

    /*uint8_t bios[] = {
        0x31,0xfe,0xff,0xaf,0x21,0xff,0x9f,0x32,0xcb,0x7c,0x20,0xfb,0x21,0x26,0xff,0x0e,
        0x11,0x3e,0x80,0x32,0xe2,0x0c,0x3e,0xf3,0xe2,0x32,0x3e,0x77,0x77,0x3e,0xfc,0xe0,
        0x47,0x11,0x04,0x01,0x21,0x10,0x80,0x1a,0xcd,0x95,0x00,0xcd,0x96,0x00,0x13,0x7b,
        0xfe,0x34,0x20,0xf3,0x11,0xd8,0x00,0x06,0x08,0x1a,0x13,0x22,0x23,0x05,0x20,0xf9,
        0x3e,0x19,0xea,0x10,0x99,0x21,0x2f,0x99,0x0e,0x0c,0x3d,0x28,0x08,0x32,0x0d,0x20,
        0xf9,0x2e,0x0f,0x18,0xf3,0x67,0x3e,0x64,0x57,0xe0,0x42,0x3e,0x91,0xe0,0x40,0x04,
        0x1e,0x02,0x0e,0x0c,0xf0,0x44,0xfe,0x90,0x20,0xfa,0x0d,0x20,0xf7,0x1d,0x20,0xf2,
        0x0e,0x13,0x24,0x7c,0x1e,0x83,0xfe,0x62,0x28,0x06,0x1e,0xc1,0xfe,0x64,0x20,0x06,
        0x7b,0xe2,0x0c,0x3e,0x87,0xe2,0xf0,0x42,0x90,0xe0,0x42,0x15,0x20,0xd2,0x05,0x20,
        0x4f,0x16,0x20,0x18,0xcb,0x4f,0x06,0x04,0xc5,0xcb,0x11,0x17,0xc1,0xcb,0x11,0x17,
        0x05,0x20,0xf5,0x22,0x23,0x22,0x23,0xc9,0xce,0xed,0x66,0x66,0xcc,0x0d,0x00,0x0b,
        0x03,0x73,0x00,0x83,0x00,0x0c,0x00,0x0d,0x00,0x08,0x11,0x1f,0x88,0x89,0x00,0x0e,
        0xdc,0xcc,0x6e,0xe6,0xdd,0xdd,0xd9,0x99,0xbb,0xbb,0x67,0x63,0x6e,0x0e,0xec,0xcc,
        0xdd,0xdc,0x99,0x9f,0xbb,0xb9,0x33,0x3e,0x3c,0x42,0xb9,0xa5,0xb9,0xa5,0x42,0x3c,
        0x21,0x04,0x01,0x11,0xa8,0x00,0x1a,0x13,0xbe,0x00,0x00,0x23,0x7d,0xfe,0x34,0x20,
        0xf5,0x06,0x19,0x78,0x86,0x23,0x05,0x20,0xfb,0x86,0x00,0x00,0x3e,0x01,0xe0,0x50
    };*/

    uint8_t cartidge_data[8388608];

	std::string gameTitle;

	uint8_t MBCType = 0;
	uint8_t selectedROMBank = 1;
	uint8_t selectedRAMBank = 0;
	bool RAMEnabled = false;
	bool ROMBanking = true;
	uint8_t RAM[0x8000];
	bool LCD_Enabled = false;

    bool bios_ran = false;
    SDL_Texture * framebuffer;
    Uint32 framebuffer_pixels[23040];
    uint8_t reg_a, reg_b, reg_c, reg_d, reg_e, reg_h, reg_l, reg_f;
    uint16_t reg_sp, reg_pc;
    uint16_t reg_hl()
    {
        return (reg_h << 8) | reg_l;
    }
    uint16_t reg_af()
    {
        return (reg_a << 8) | reg_f;
    }
    uint16_t reg_bc()
    {
        return (reg_b << 8) | reg_c;
    }
    uint16_t reg_de()
    {
        return (reg_d << 8) | reg_e;
    }

	double DIV, TIMA;

	bool IME;

	void (*opcode_map[256])();
	void (*cb_prefix_map[256])();
    uint8_t mem[0x10000];
    uint32_t ticks;
    uint32_t gpu_modeclock;
    uint8_t gpu_mode;
    bool gpu_vblank;
	bool stopped;

	void (*onEmulationEvent)(int);

	void memdump()
    {
        for(int i=0; i<0xffff; i+=16)
        {
            std::cout << std::hex << i << " : " << (int)mem[i] << " " << (int)mem[i+1] << "\t" << (int)mem[i+2] << " " << (int)mem[i+3] << "\t" << (int)mem[i+4] << " " << (int)mem[i+5] << "\t" << (int)mem[i+6] << " " << (int)mem[i+7] << "\t" << (int)mem[i+8] << " " << (int)mem[i+9] << "\t" << (int)mem[i+10] << " " << (int)mem[i+11] << "\t" << (int)mem[i+12] << " " << (int)mem[i+13] << "\t" << (int)mem[i+14] << " " << (int)mem[i+15] << "\n";
        }
    }

    void regdump()
    {
    	std::cout << std::hex << (int) reg_pc << "\t" << (int)mem[reg_pc] << "\n";
        std::cout << std::hex << "A: " << (int)emu::reg_a << " B: " << (int)emu::reg_b << " C: " << (int)emu::reg_c << " D: " << (int)emu::reg_d << " E: " << (int)emu::reg_e << " H: " << (int)emu::reg_h << " L: " << (int)emu::reg_l << " SP: " << emu::reg_sp << " PC: " << emu::reg_pc << "\n";
    }

	void mset(uint16_t addr, uint8_t byte)
	{
		// FEA0-FEFF   Not Usable
		if(addr >= 0xfea0 && addr <= 0xfeff) return;

		if(addr < 0x100) return;

		// VRAM (memory at 8000h-9FFFh) is accessable during Mode 0-2
		if(addr >= 0x8000 && addr <= 0x9fff && gpu_mode > 2) return;

		// OAM (memory at FE00h-FE9Fh) is accessable during Mode 0-1
		if(addr >= 0xfe00 && addr <= 0xfe9f && gpu_mode > 1) return;

		if ((addr >= 0xA000) && (addr < 0xC000))
		{
			if (RAMEnabled)
			{
				addr -= 0xa000;
				RAM[addr + (selectedRAMBank*0x2000)] = byte;
				return;
			}
		}
		else
		{
            if(addr < 0x2000)
			{
				if(MBCType == 1 || MBCType == 2) // RAM enable
				{
					if(MBCType == 2 && addr & 0x10) return;
					RAMEnabled = !(byte & 0x0f);
					if(RAMEnabled) std::cout << "RAM is now enabled.\n"; else std::cout << "RAM is now disabled.\n";
				}
			}
			else if(addr > 0x2000 && addr < 0x4000) // ROM bank change
			{
				if(MBCType == 1 || MBCType == 2)
				{
					if(MBCType == 2)
					{
						selectedROMBank = byte & 0x0f;
						if(selectedROMBank == 0) ++selectedROMBank;
						std::cout << "Selected ROM bank " << (int)selectedROMBank << "\n";
					}
					else
					{
                        uint8_t lo = byte & 0x1f;
                        selectedROMBank &= 0xe0;
                        selectedROMBank |= lo;
						if(selectedROMBank == 0) ++selectedROMBank;
						std::cout << "Selected ROM bank " << (int)selectedROMBank << "\n";
					}
				}
			}
			else if(addr > 0x4000 && addr < 0x6000)
			{
				if(MBCType == 1)
				{
					if(ROMBanking)
					{
						selectedROMBank &= 0x1f;
						selectedROMBank |= byte & 0xe0;
						if(selectedROMBank == 0) ++selectedROMBank;
						std::cout << "Selected ROM bank " << (int)selectedROMBank << "\n";
					}
					else
					{
						selectedRAMBank = byte & 0x03;
						std::cout << "Selected RAM bank " << (int)selectedRAMBank << "\n";
					}
				}
			}
			else if(addr > 0x6000 && addr < 0x8000)
			{
                if(MBCType == 1)
				{
					ROMBanking = !(byte & 0x01);
					if (ROMBanking)
					{
						selectedRAMBank = 0 ;
						std::cout << "Selected RAM bank " << (int)selectedRAMBank << "\n";
					}
					if(ROMBanking) std::cout << "Now ROM banking.\n"; else std::cout << "Now RAM banking.\n";
				}
			}
			else
			{
				switch(addr)
				{
				case 0xff44: // FF44 - LY - LCDC Y-Coordinate (R)

					mem[addr] = 0;
					return;

					break;

				case 0xff46: // FF46 - DMA - DMA Transfer and Start Address (W)
					{
						uint16_t src = byte << 8;
						memcpy(&mem[src], &mem[0xfe00], 0xa0);
					}
					break;

				default:
					mem[addr] = byte;

					// Memory echo
					if(addr >= 0xe000 && addr <= 0xfdff) mem[addr-0x2000] = mem[addr];
					if(addr >= 0xc000 && addr <= 0xddff) mem[addr+0x2000] = mem[addr];
				}
			}
		}
	}

	uint8_t mget(uint16_t addr)
	{
		if(addr >= 0xfea0 && addr <= 0xfeff) return 0;

		if(addr < 0x100) // BIOS or cartidge header
		{
			if(bios_ran) return cartidge_data[addr];
			else return bios[addr];
		}
		else if ((addr >= 0x4000) && (addr <= 0x7fff)) // ROM
		{
			addr -= 0x4000;
			return cartidge_data[addr + (selectedROMBank*0x4000)];
		}
		else if (RAMEnabled && (addr >= 0xa000) && (addr <= 0xbfff)) // RAM
		{
			addr -= 0xa000;
			return RAM[addr + (selectedRAMBank*0x2000)];
		}
		else
		{
			if(addr >= 0xe000 && addr <= 0xfdff) addr -= 0x2000;
			return mem[addr];
		}
	}

    uint16_t _stack_pop()
	{
		uint16_t ret = mem[reg_sp] | (mem[reg_sp+1] << 8);
		reg_sp += 2;
        return ret;
	}

	void _stack_push(uint16_t v)
	{
		reg_sp -= 2;
		mem[reg_sp] = (v & 0xff);
        mem[reg_sp+1] = (v & 0xff00) >> 8;
	}

	void reset()
	{
        gpu_mode = 1;
        gpu_vblank = false;

        MBCType = 0;
		selectedROMBank = 1;
		selectedRAMBank = 0;
		RAMEnabled = false;
		ROMBanking = true;

        memset(framebuffer_pixels, 0, 23040);
        SDL_UpdateTexture(framebuffer, NULL, framebuffer_pixels, 160 * sizeof(Uint32));


        reg_a = reg_b = reg_c = reg_d = reg_e = reg_h = reg_l = reg_f = reg_sp = reg_pc = 0;
        memset(mem, 0, 0x10000);

		IME = false;
        mem[0xffff] = 0; // Disable interrupts
        mem[0xff0f] = 0; // Clear interrupt requests
        mem[0xff40] = 0; // LCD off
		LCD_Enabled = false;
		gpu_modeclock = 456;
		mem[0xff44] = 0;
		mem[0xff41] &= ~(0x03);
		mem[0xff41] |= 0x01;
		ticks = 0;

        mem[0xff42] = mem[0xff43] = 0; // BG scroll values
		mem[0xff50] = 0; // Enable DMG ROM

		stopped = false;
        bios_ran = false;
        memcpy(mem, cartidge_data, 0x8000);
        memcpy(mem, bios, 0x100);

        char buf[16];
		memcpy(buf, &cartidge_data[0x134], 16);
		gameTitle = buf;
	}

    void next(double delta)
    {
    	if(stopped) return;
        ticks = 0;

        // FF04 - DIV - Divider Register (R/W)
        DIV += 16384.0 * delta;
        mem[0xff04] = (int)(floor(DIV)) % 0x100;

        // FF07 - TAC - Timer Control (R/W)
        if(mem[0xff07] & 0x04)
		{
			if(mem[0xff07] & 0x02)
			{
				if(mem[0xff07] & 0x01)
					TIMA += 16384.0 * delta;
				else
					TIMA += 65536.0 * delta;
			}
			else
			{
				if(mem[0xff07] & 0x01)
					TIMA += 262144.0 * delta;
				else
					TIMA += 4096.0 * delta;
			}

			if(mem[0xff07] > 0xff)
			{
				mem[0xff07] = mem[0xff06];

				// Request interrupt
				mem[0xff0f] |= 0x04;
			}
		}

		trace.push_back(reg_pc);
        opcode_map[mget(reg_pc)]();
        gpu_modeclock += ticks;

        if(!bios_ran && mem[0xff50] != 0)
        {
            bios_ran = true;
            memcpy(mem, cartidge_data, 0x100);

            uint8_t x = 0;
            for(int i=0x134; i<= 0x14c; x = x - mem[i++] - 1) {}
            if(cartidge_data[0x14d] != x) std::cout << "Checksum fail.\n";

            MBCType = cartidge_data[0x147] > 0 && cartidge_data[0x147] <= 3 ? 1 : cartidge_data[0x147] > 3 ? 2 : 0;
            if(MBCType != 0) std::cout << "MBC" << (int)MBCType << " reported by ROM.\n";

            onEmulationEvent(EMU_EV_BIOS_END);
        }

        // Serial
        if(mem[0xff02] & 0x81)
		{
			std::cout << mem[0xff01];
			mem[0xff01] = mem[0xff02] = 0;
		}
    }

    // TODO
    Uint32 gpu_sprite_pixel_color(uint16_t x, uint16_t y, uint16_t palette_addr)
    {
		uint8_t tx = x/8;
        uint8_t ty = y/8;
        uint16_t index = mem[0x8000 + (tx + (ty * 32))];
        uint16_t offset = index * 16;
        uint16_t tile_addr = 0x8000 + offset;
        uint8_t b1 = mem[tile_addr + (y%8)*2];
        uint8_t b2 = mem[tile_addr + (y%8)*2 + 1];

        uint8_t color = ((b1 >> (7-(x%8))) & 0x01) | (((b2 >> (7-(x%8))) & 0x01) << 1);

        switch(color)
        {
            case 0:
                return 0xffffffff;
                color = mem[palette_addr] & 0x03;
                break;
            case 1:
                color = (mem[palette_addr] & 0x0c) >> 2;
                break;
            case 2:
                color = (mem[palette_addr] & 0x30) >> 4;
                break;
            case 3:
                color = (mem[palette_addr] & 0xc0) >> 6;
                break;
        }

        return 0xffffffff - 0x003f3f3f * color;
    }

    Uint32 gpu_pixel_color(uint16_t x, uint16_t y, uint16_t tile_map_addr)
    {
    	uint16_t tile_data_addr = mem[0xff40] & 0x10 ? 0x8000 : 0x8800;

        uint8_t tx = x/8;
        uint8_t ty = y/8;
        uint16_t index = mem[tile_map_addr + (tx + (ty * 32))];
        uint16_t offset = index * 16;
        if(tile_data_addr == 0x8800)
        {
            int16_t s = index & 0x80 ? -((~index)+1) : index;
            offset = s * 16;
        }
        uint16_t tile_addr = tile_data_addr + offset;
        uint8_t b1 = mem[tile_addr + (y%8)*2];
        uint8_t b2 = mem[tile_addr + (y%8)*2 + 1];

        uint8_t color = ((b1 >> (7-(x%8))) & 0x01) | (((b2 >> (7-(x%8))) & 0x01) << 1);

        switch(color)
        {
            case 0:
                return 0xffffffff;
                color = mem[0xff47] & 0x03;
                break;
            case 1:
                color = (mem[0xff47] & 0x0c) >> 2;
                break;
            case 2:
                color = (mem[0xff47] & 0x30) >> 4;
                break;
            case 3:
                color = (mem[0xff47] & 0xc0) >> 6;
                break;
        }

        return 0xffffffff - 0x003f3f3f * color;
    }

    void gpu_draw_scanline()
    {
        uint8_t raster_y = mem[0xff44];
		uint8_t scroll_x = mem[0xff43];
		uint8_t scroll_y = mem[0xff42];
		uint8_t window_x = mem[0xff4b] - 7;
		uint8_t window_y = mem[0xff4a];

		for(uint8_t raster_x = 0; raster_x < 160; ++raster_x)
		{

			// Background
			if(mem[0xff40] & 0x01)
			{
				framebuffer_pixels[raster_x + raster_y*160] = gpu_pixel_color(raster_x + scroll_x, raster_y + scroll_y, mem[0xff40] & 0x08 ? 0x9c00 : 0x9800);
			}

			// Window
			if(mem[0xff40] & 0x20)
			{
				framebuffer_pixels[raster_x + raster_y*160] = gpu_pixel_color(raster_x, raster_y, mem[0xff40] & 0x40 ? 0x9c00 : 0x9800);
			}

			// Sprites (TODO)

		}
    }

    void gpu_step()
    {
    	// FF40 - LCDC - LCD Control (R/W) -- Bit 7 - LCD Display Enable (0=Off, 1=On)
		if(!(mem[0xff40] & 0x80))
		{
			if(LCD_Enabled)
			{
				gpu_modeclock = 456;
				mem[0xff44] = 0;
				mem[0xff41] &= ~(0x03);
				mem[0xff41] |= 0x01;
				onEmulationEvent(EMU_EV_LCD_OFF);
				LCD_Enabled = false;
			}
			return;
		}

		if(!LCD_Enabled) LCD_Enabled = true;

		uint8_t scanline = mem[0xff44];
		uint8_t status = mem[0xff41];
		uint8_t prevMode = gpu_mode;

		// Raster logic
        if(gpu_modeclock >= 456)
		{
			gpu_modeclock %= 456;

			++scanline;; // Scanline advance

			if(scanline == 144) // Entering v-blank
			{
				gpu_draw_scanline();
                SDL_UpdateTexture(framebuffer, 0, framebuffer_pixels, 160 * 4);
                gpu_vblank = true;
                gpu_mode = 1;
                mem[0xff0f] |= 0x01; // Request LCD v-blank interrupt
			}
			else if(scanline > 153)
			{
				scanline = 0;
			}
			else if(scanline < 144)
			{
				gpu_draw_scanline();
			}
		}
		else if(gpu_modeclock >= 201 && gpu_modeclock <= 207)
		{
			gpu_mode = 0;
		}
		else if(gpu_modeclock >= 77 && gpu_modeclock <= 83)
		{
			gpu_mode = 2;
		}
		else if(gpu_modeclock >= 169 && gpu_modeclock >= 175)
		{
			gpu_mode = 3;
		}

		if(scanline == mem[0xff45])
		{
			status |= 0x04;
			if(status & 0x40)
			{
				mem[0xff0f] |= 0x02; // Request LCD status interrupt
			}
		}

		if(prevMode != gpu_mode)
		{
				 if(gpu_mode == 0 && status & 0x08) mem[0xff0f] |= 0x02; // Request LCD status interrupt (hblank)
			else if(gpu_mode == 1 && status & 0x10) mem[0xff0f] |= 0x02; // Request LCD status interrupt (vblank)
			else if(gpu_mode == 2 && status & 0x20) mem[0xff0f] |= 0x02; // Request LCD status interrupt (OAM)
		}

		status = (status & ~0x03) | (gpu_mode & 0x03);

		mem[0xff44] = scanline;
		mem[0xff41] = status;
    }

    void process_interrupts()
    {
        if(IME)
        {
            if(mem[0xffff] & 0x01 && mem[0xff0f] & 0x01) { IME = false; mem[0xff0f] &= 0b11111110; _stack_push(reg_pc); reg_pc = 0x0040; } // VBLANK
            if(mem[0xffff] & 0x02 && mem[0xff0f] & 0x02) { IME = false; mem[0xff0f] &= 0b11111101; _stack_push(reg_pc); reg_pc = 0x0048; } // LCD STAT
            if(mem[0xffff] & 0x04 && mem[0xff0f] & 0x04) { IME = false; mem[0xff0f] &= 0b11111011; _stack_push(reg_pc); reg_pc = 0x0050; } // TIMER
            if(mem[0xffff] & 0x08 && mem[0xff0f] & 0x08) { IME = false; mem[0xff0f] &= 0b11110111; _stack_push(reg_pc); reg_pc = 0x0058; } // SERIAL
            if(mem[0xffff] & 0x10 && mem[0xff0f] & 0x10) { IME = false; mem[0xff0f] &= 0b11101111; _stack_push(reg_pc); reg_pc = 0x0060; } // JOYPAD
        }
    }

    void int40()
    {
        mem[0xff0f] |= 0x01;
    }

    void int48()
    {
        mem[0xff0f] |= 0x02;
    }

    void int50()
    {
        mem[0xff0f] |= 0x04;
    }

    void int58()
    {
        mem[0xff0f] |= 0x08;
    }

    void int60()
    {
        mem[0xff0f] |= 0x10;
    }

    void illegal()
    {
    	std::cout << "Encountered undefined opcode at " << std::hex << (int)reg_pc << ": " << (int)mem[reg_pc] << ". Halting.\n";

		std::cout << "Dumping trace... ";
    	std::ofstream of;
    	of.open("trace.txt", std::ios::out);
    	std::stringstream s;
    	for(unsigned int i=0; i<trace.size(); ++i)
		{
			s << std::hex << (int)trace[i] << " (" << (int)mem[trace[i]] << ")" << "\n";
		}
		of.write(s.str().c_str(), s.str().size());
		of.close();
		std::cout << "done.\n";

    	stopped = true;
    }

    void nop()
	{
		++reg_pc;
	}
    void ldbcd16()
    {
        reg_b = mem[reg_pc+2] << 8;
        reg_c = mem[reg_pc+1];
        reg_pc += 3;
        ticks = 12;
    }
    void ld_bc_a()
    {
    	mset(reg_bc(), reg_a);
    	reg_pc += 1;
    	ticks = 8;
    }
    void incbc()
    {
    	uint16_t v = reg_bc() + 1;
    	reg_b = (v & 0xff00) >> 8;
    	reg_c = v & 0x00ff;
    	reg_pc++;
    	ticks=8;
    }
    void incb()
 	{
 		reg_f &= 0xbf;

 		if(reg_b == 0x0f) reg_f |= 0x20;
 		else reg_f &= 0xdf;

 		reg_b++;

 		if(reg_b == 0) reg_f |= 0x80;
 		else reg_f &= 0b01110000;

    	reg_pc++;
    	ticks=4;
    }
    void decb()
    {
    	reg_f |= 0x40;
 		if(reg_b == 0x10) reg_f |= 0x20;
 		else reg_f &= 0b11010000;
 		--reg_b;
 		if(reg_b == 0) reg_f |= 0x80;
 		else reg_f &= 0b01110000;
    	reg_pc++;
    	ticks=4;
    }
    void ldbd8()
    {
    	reg_b = mem[reg_pc+1];
    	reg_pc+=2;
    	ticks=8;
    }
    void rlca()
    {
    	reg_f |= (reg_a & 0x80) >> 3;
    	reg_a = reg_a << 1;
    	reg_a |= (reg_f & 0x10) >> 4;
    	reg_pc++;
    	ticks=4;
    }
    void ld_a16_sp()
    {
    	mset(mem[reg_pc + 1] | (mem[reg_pc + 2] << 8), reg_sp);
    	reg_pc+=3;
    	ticks=20;
    }
    void addhlbc()
    {
    	if(reg_c + reg_l > 0xff || reg_b + reg_h > 0xff) reg_f |= 0x10;
    	else reg_f &= 0xef;

    	if(reg_h + reg_b > 0xff || reg_l + reg_c > 0xff) reg_f |= 0x20;
    	else reg_f &= 0xdf;

    	reg_f &= 0xbf;

    	uint16_t sum = reg_hl() + reg_bc();
    	reg_h = (sum & 0xff00) >> 8;
    	reg_l = sum & 0x00ff;

    	reg_pc++;
    	ticks=8;
    }
    void lda_bc_()
    {
    	reg_a = mget(mem[reg_pc+1] | (mem[reg_pc+2] << 8));
    	reg_pc++;
    	ticks=8;
    }
    void decbc()
    {
    	uint16_t v = reg_bc() - 1;
    	reg_b = (v & 0xff00) >> 8;
    	reg_c = v & 0x00ff;
    	++reg_pc;
    	ticks=8;
    }
    void incc()
    {
    	reg_f &= 0xbf;
    	if(reg_c == 0x0f) reg_f |= 0x20;
    	else reg_f &= 0xdf;
    	++reg_c;
    	if(reg_c == 0) reg_f |= 0x80;
    	else reg_f &= 0x7f;
    	++reg_pc;
    	ticks=4;
    }
    void decc()
    {
        if(reg_c == 0) reg_f |= 0x10;
        else reg_f &= 0b11100000;
        if(reg_c == 0x10) reg_f |= 0x20;
        else reg_f &= 0b11010000;
        --reg_c;
        if(reg_c == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ticks=4;
        ++reg_pc;
    }
    void ldcd8()
    {
    	reg_c = mem[reg_pc+1];
    	reg_pc+=2;
    	ticks=8;
    }
    void rrca()
    {
    	reg_f |= (reg_a & 0x01) << 4;
    	reg_a = reg_a >> 1;
    	reg_a |= (reg_f & 0x10) << 3;
    	++reg_pc;
    	ticks=4;
    }
    void stop()
    {
    	std::cout << "CPU STOP\n";
    	emu::regdump();
    	stopped = true;
    	ticks=4;
    }
    void ldded16()
    {
    	reg_d = mem[reg_pc+2];
    	reg_e = mem[reg_pc+1];
    	reg_pc+=3;
    	ticks=12;
    }
    void ld_de_a()
    {
    	mset(reg_de(), reg_a);
    	++reg_pc;
    	ticks=8;
    }
    void incde()
    {
    	uint16_t v = reg_de() + 1;
    	reg_d = (v & 0xff00) >> 8;
    	reg_e = v & 0x00ff;
    	reg_pc++;
    	ticks=8;
    }
    void incd()
    {
    	reg_f &= 0xbf;
    	if(reg_d == 0x0f) reg_f |= 0x20;
    	else reg_f &= 0xdf;
    	reg_d++;
    	if(reg_d == 0) reg_f |= 0x80;
    	else reg_f &= 0x7f;
        ++reg_pc;
        ticks=4;
    }
    void decd()
    {
    	reg_f |= 0x40;
    	if(reg_d == 0x10) reg_f |= 0x20;
    	else reg_f &= 0b11010000;
    	--reg_d;
    	if(reg_d == 0) reg_f |= 0x80;
    	else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=4;
    }
    void lddd8()
    {
    	reg_d = mem[reg_pc+1];
    	reg_pc+=2;
    	ticks=8;
    }
    void rla()
    {
    	reg_f &= 0b00010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_a & 0x80) >> 3;
        reg_a = ((reg_a << 1) & 0b11111110) | c;
        ++reg_pc;
        ticks=4;
    }
    void jrr8()
    {
    	uint8_t v = mem[reg_pc+1];
    	int8_t s = v & 0x80 ? -((~v)+1) : v;
    	reg_pc += s + 2;
    	ticks = 12;
    }
    void addhlde()
    {
		if(reg_e + reg_l > 0xff || reg_d + reg_h > 0xff) reg_f |= 0x10;
    	else reg_f &= 0xef;

    	if(reg_h + reg_d > 0xff || reg_l + reg_e > 0xff) reg_f |= 0x20;
    	else reg_f &= 0xdf;

    	reg_f &= 0xbf;

    	uint16_t sum = reg_hl() + reg_de();
    	reg_h = (sum & 0xff00) >> 8;
    	reg_l = sum & 0x00ff;
    	++reg_pc;
    	ticks=8;
    }
    void lda_de_()
    {
    	reg_a = mget(reg_de());
    	++reg_pc;
    	ticks=8;
    }
    void decde()
    {
    	uint16_t v = reg_de() - 1;
    	reg_d = (v & 0xff00) << 8;
    	reg_e = v & 0x00ff;
    	++reg_pc;
    	ticks=8;
    }
    void ince()
    {
    	reg_f &= 0xbf;
    	if(reg_e == 0x0f) reg_f |= 0x20;
    	else reg_f &= 0xdf;
    	++reg_e;
    	if(reg_e == 0) reg_f |= 0x80;
    	else reg_f &= 0x7f;
    	++reg_pc;
    	ticks=4;
    }
    void dece()
    {
    	reg_f |= 0x40;
    	if(reg_e == 0x10) reg_f |= 0x20;
    	else reg_f &= ~0x20;
    	--reg_e;
    	if(reg_e == 0) reg_f |= 0x80;
    	else reg_f &= ~0x80;
    	++reg_pc;
    	ticks=4;
    }
    void lded8()
    {
    	reg_e = mem[reg_pc+1];
    	reg_pc+=2;
    	ticks=8;
    }
    void rra()
    {
    	reg_f = 0;
    	uint8_t cb = (reg_f & 0x10) << 3;
    	reg_f |= (reg_a & 0x01) << 4;
    	reg_a = (reg_a >> 1) | cb;
    	++reg_pc;
    	ticks=4;
    }
    void jrnzr8()
    {
    	if(reg_f & 0x80)
    	{
	    	reg_pc+=2;
	    	ticks=8;
	    }
	    else
	    {
	    	uint8_t v = mem[reg_pc+1];
	    	int8_t s = v & 0x80 ? -((~v)+1) : v;
	    	reg_pc += s + 2;
	    	ticks = 12;
	    }
    }
    void ldhld16()
    {
    	reg_h = mem[reg_pc+2];
    	reg_l = mem[reg_pc+1];
    	reg_pc+=3;
    	ticks=12;
    }
    void ld_hlplus_a()
    {
    	uint16_t v = reg_hl();
    	mem[v++] = reg_a;
    	reg_h = (v & 0xff00) >> 8;
    	reg_l = v & 0x00ff;
    	++reg_pc;
    	ticks=8;
    }
    void inchl()
    {
    	uint16_t v = reg_hl() + 1;
    	reg_h = (v & 0xff00) >> 8;
    	reg_l = v & 0x00ff;
    	++reg_pc;
    	ticks=8;
    }
    void inch()
    {
    	reg_f &= ~0x40;
    	if(reg_h == 0x0f) reg_f |= 0x20;
    	else reg_f &= ~0x20;
    	++reg_h;
    	if(reg_h == 0) reg_f |= 0x80;
    	else reg_f &= ~0x80;
    	++reg_pc;
    	ticks=4;
    }
    void dech()
    {
    	reg_f |= 0x40;
    	if(reg_h == 0x0f) reg_f |= 0x20;
    	else reg_f &= 0xdf;
    	--reg_h;
    	if(reg_h == 0) reg_f |= 0x80;
    	else reg_f &= 0x7f;
    	++reg_pc;
    	ticks=4;
    }
    void ldhd8()
    {
    	reg_h = mem[reg_pc+1];
    	reg_pc+=2;
    	ticks=8;
    }
    void daa()
    {
    	// All this can probably be done with a couple of math operations

    	bool n = (reg_f & 0x40) != 0;
    	bool c = (reg_f & 0x10) != 0;
    	bool h = (reg_f & 0x20) != 0;
    	uint8_t hi = (reg_a & 0xf0) >> 4;
    	uint8_t lo = reg_a & 0x0f;

    	if(!n && !c)
    	{
    		if(hi > 0 && hi < 0x9 && !h && lo > 0 && lo < 0x9)
    		{
    			reg_f &= 0xef;
    		}
    		else if((hi >= 0x0 && hi <= 0x8 && !h && lo >= 0xa && lo <= 0xf) ||
    			(hi >= 0x0 && hi <= 0x9 && h && lo >= 0x0 && lo <= 0x3))
			{
				reg_a += 0x06;
				reg_f &= 0xef;
			}
			else if(hi >= 0xa && hi <= 0xf && !h && lo >= 0x0 && lo <= 0x9)
			{
				reg_a += 0x60;
				reg_f |= 0x10;
			}
			else if((hi >= 0x9 && hi <= 0xf && !h && lo >= 0xa && lo <= 0xf) ||
				(hi >= 0xa && hi <= 0xf && h && lo >= 0x0 && lo <= 0x3))
			{
				reg_a += 0x66;
				reg_f |= 0x10;
			}
    	}
    	if(!n && c)
    	{
    		if(hi >= 0x0 && hi <= 0x2 && !h && lo >= 0 && lo <= 9)
    		{
    			reg_a += 0x60;
    			reg_f |= 0x10;
    		}
    		else if((hi >= 0x0 && hi <= 0x2 && !h && lo >= 0xa && lo <= 0xf) ||
    			(hi >= 0x0 && hi <= 0x3 && h && lo >= 0x0 && lo <= 0x3))
    		{
    			reg_a += 0x66;
    			reg_f |= 0x10;
    		}
    	}
    	if(n && !c)
    	{
    		if(hi >= 0x0 && hi <= 0x9 && !h && lo >= 0x0 && lo <= 0x9)
    		{
    			reg_f &= 0xef;
    		}
    		else if(hi >= 0 && hi <= 0x8 && h && lo >= 0x6 && lo < 0xf)
    		{
    			reg_a += 0xfa;
    			reg_f &= 0xef;
    		}
    	}
    	if(n && c)
    	{
    		if(hi >= 0x7 && hi < 0xf && !h && lo >= 0 && lo <= 0x9)
    		{
    			reg_a += 0xa0;
    			reg_f |= 0x10;
    		}
    		else if(hi >= 0x6 && hi < 0xf && !h && lo >= 6 && lo <= 0xf)
    		{
    			reg_a += 0x9a;
    			reg_f |= 0x10;
    		}
    	}

    	if(reg_a == 0) reg_f |= 0x80;
    	else reg_f &= 0x7f;

    	++reg_pc;
    	ticks=4;
    }
    void jrzr8()
    {
    	if(reg_f & 0x80)
    	{
	    	uint8_t v = mem[reg_pc+1];
	    	int8_t s = v & 0x80 ? -((~v)+1) : v;
	    	reg_pc += s + 2;
	    	ticks = 12;
	    }
	    else
	    {
	    	reg_pc+=2;
	    	ticks=8;
	    }
    }
    void addhlhl()
    {
    	reg_f &= 0b10110000;
    	if(( (reg_hl() & 0xfff) + (reg_hl() & 0xfff) ) & 0x1000) reg_f |= 0x20;
    	else reg_f &= 0b11010000;
    	if( (reg_hl() + reg_hl()) & 0x10000) reg_f |= 0x10;
    	else reg_f &= 0b11100000;
    	uint16_t v = reg_hl() + reg_hl();
    	reg_h = (v & 0xff00) >> 8;
    	reg_l = v & 0x00ff;
    	++reg_pc;
    	ticks=8;
    }
    void lda_hlplus_()
	{
		reg_a = mget(reg_hl());
		uint16_t v = reg_hl() + 1;
		reg_h = (v & 0xff00) >> 8;
		reg_l = v & 0x00ff;
		++reg_pc;
		ticks=8;
	}
    void dechl()
    {
    	uint16_t v = reg_hl() - 1;
    	reg_h = (v & 0xff00) >> 8;
    	reg_l = v & 0x00ff;
    	++reg_pc;
    	ticks=8;
    }
    void incl()
	{
		reg_f &= 0xbf;
    	if(reg_l == 0x0f) reg_f |= 0x20;
    	else reg_f &= 0xdf;
    	++reg_l;
    	if(reg_l == 0) reg_f |= 0x80;
    	else reg_f &= 0x7f;
    	++reg_pc;
    	ticks=4;
	}
    void decl()
	{
		reg_f |= 0x40;
    	if(reg_l == 0x0f) reg_f |= 0x20;
    	else reg_f &= 0xdf;
    	--reg_l;
    	if(reg_l == 0) reg_f |= 0x80;
    	else reg_f &= 0x7f;
    	++reg_pc;
    	ticks=4;
	}
    void ldld8()
	{
		reg_l = mem[reg_pc+1];
		reg_pc+=2;
		ticks=8;
	}
    void cp_l()
	{
		reg_a = !reg_a;
		reg_f |= 0x60;
		++reg_pc;
		ticks=4;
	}
    void jrncr8()
	{
		if(reg_f & 0x10)
		{
			reg_pc+=2;
			ticks=8;
		}
		else
		{
			uint8_t v = mem[reg_pc+1];
			int8_t s = v & 0x80 ? -((~v)+1) : v;
			reg_pc += s + 2;
			ticks=12;
		}
	}
    void ldspd16()
   {
        reg_sp = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
        reg_pc += 3;
        ticks = 12;
    }
    void ld_hlminus_a()
	{
		mset(reg_hl(), reg_a);
		uint16_t v = reg_hl() - 1;
		reg_h = (v & 0xff00) >> 8;
		reg_l = v & 0x00ff;
		++reg_pc;
		ticks=8;
	}
    void incsp()
	{
		++reg_sp;
		++reg_pc;
		ticks=8;
	}
    void inc_hl_()
	{
		uint16_t v = mget(reg_hl());
		reg_f &= 0b10110000;
		if(((v&0xf) + 1)&0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		mset(reg_hl(), v+1);
		if(mem[reg_hl()] == 0) reg_f |= 0x80;
		++reg_pc;
		ticks=12;
	}
    void dec_hl_()
	{
		uint16_t v = mget(reg_hl());
		reg_f |= 0x40;
		if(((v&0xff) - 1)&0x1000) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		mset(reg_hl(), v-1);
		if(mem[reg_hl()] == 0) reg_f |= 0x80;
		++reg_pc;
		ticks=12;
	}
    void ld_hl_d8()
	{
        mset(reg_hl(), mem[reg_pc+1]);
        ticks=12;
        reg_pc+=2;
    }
    void scf()
	{
        reg_f&=0b10010000;
        reg_f|=0x10;
        ticks=4;
        ++reg_pc;
    }
    void jrcr8()
	{
        if(reg_f & 0x10)
		{
            uint8_t v=mem[reg_pc+1];
            int8_t s = v & 0x80 ? -((~v)+1) : v;
			reg_pc += s + 2;
            ticks = 12;
        }
        else
		{
        	reg_pc+=2;
            ticks = 8;
        }
    }
    void addhlsp()
	{
		reg_f &= 0b10110000;
		if(((reg_hl()&0xff) + ((reg_sp&0xff) & 0x100))) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		if(((reg_hl()&0xfff) + ((reg_sp&0xfff) & 0x1000))) reg_f |= 0x20;
		else reg_f &= 0b11010000;
        uint16_t v = reg_hl() + reg_sp;
		reg_h = (v & 0xff00) >> 8;
		reg_l = v & 0x00ff;
        ticks=8;
        ++reg_pc;
    }
    void lda_hlminus_()
	{
        reg_a+=mget(reg_hl());
        uint16_t s =reg_hl()-1;
        reg_h=(s&0xff00)>>8;
        reg_l=(s&0x00ff);
        ticks=8;
        ++reg_pc;
    }
    void decsp()
	{
        reg_sp--;
        ticks=8;
        ++reg_pc;
    }
    void inca()
	{
		reg_f &= 0b10110000;
		if(reg_a == 0xff) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		if(reg_a == 0x0f) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		++reg_a;
		++reg_pc;
		ticks=4;
    }
    void deca()
	{
		reg_f |= 0x40;
		if(reg_a == 0x01) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		if(reg_a == 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		--reg_a;
		++reg_pc;
		ticks=4;
    }
    void ldad8()
	{
        reg_a=mem[reg_pc+1];
        ticks=8;
        reg_pc+=2;
    }
    void ccf()
	{
        reg_f |= !(reg_f & 0x10) & 0x10;
        reg_f &= 0x9f;
        ticks=4;
        reg_pc+=1;
    }
    void ldbb()
	{
        ticks=4;
        reg_pc+=1;
    }
    void ldbc()
	{
        reg_b=reg_c;
        ticks=4;
        reg_pc+=1;
    }
    void ldbd(){
        reg_b=reg_d;
        ticks=4;
        reg_pc+=1;
    }
    void ldbe(){
        reg_b=reg_e;
        ticks=4;
        reg_pc+=1;
    }
    void ldbh(){
        reg_b=reg_h;
        ticks=4;
        reg_pc+=1;
    }
    void ldbl(){
        reg_b=reg_l;
        ticks=4;
        reg_pc+=1;
    }
    void ldb_hl_(){
        reg_b=mget(reg_hl());
        ticks=8;
        reg_pc+=1;
    }
    void ldba(){
        reg_b=reg_a;
        ticks=4;
        reg_pc+=1;
    }
    void ldcb(){
        reg_c=reg_b;
        ticks=4;
        reg_pc+=1;
    }
    void ldcc(){
        ticks=4;
        reg_pc+=1;
    }
    void ldcd(){
        reg_c=reg_d;
        ticks=4;
        reg_pc+=1;
    }
    void ldce(){
        reg_c=reg_e;
        ticks=4;
        reg_pc+=1;
    }
    void ldch(){
        reg_c=reg_h;
        ticks=4;
        reg_pc+=1;
    }
    void ldcl(){
        reg_c=reg_l;
        ticks=4;
        reg_pc+=1;
    }
    void ldc_hl_(){
        reg_c=mget(reg_hl());
        ticks=4;
        reg_pc+=1;
    }
    void ldca(){
        reg_c=reg_a;
        ticks=4;
        reg_pc+=1;
    }
    void lddb(){
        reg_d=reg_b;
        ticks=4;
        reg_pc+=1;
    }
    void lddc(){
        reg_d=reg_c;
        ticks=4;
        reg_pc+=1;
    }
    void lddd(){
        ticks=4;
        reg_pc+=1;
    }
    void ldde(){
        reg_d=reg_e;
        ticks=4;
        reg_pc+=1;
    }
    void lddh(){
        reg_d=reg_h;
        ticks=4;
        reg_pc+=1;
    }
    void lddl()
	{
        reg_d=reg_l;
        ticks=4;
        reg_pc+=1;
    }
    void ldd_hl_()
	{
        reg_d=mget(reg_hl());
        ticks=8;
        reg_pc+=1;
    }
    void ldda()
	{
        reg_d=reg_a;
        ticks=4;
        reg_pc+=1;
    }
    void ldeb()
	{
        reg_e=reg_b;
        ticks=4;
        reg_pc+=1;
    }
    void ldec()
	{
        reg_e=reg_c;
        ticks=4;
        reg_pc+=1;
    }
    void lded()
	{
        reg_e=reg_d;
        ticks=4;
        reg_pc+=1;
    }
    void ldee()
	{
        ticks=4;
        reg_pc+=1;
    }
    void ldeh()
	{
        reg_e=reg_h;
        ticks=4;
        reg_pc+=1;
    }
    void ldel()
	{
        reg_e=reg_l;
        ticks=4;
        reg_pc+=1;
    }
    void lde_hl_()
	{
        reg_e=mget(reg_hl());
        ticks=8;
        reg_pc+=1;
    }
    void ldea()
	{
        reg_e=reg_a;
        ticks=4;
        reg_pc+=1;
    }
    void ldhb()
	{
        reg_h=reg_b;
        ticks=4;
        reg_pc+=1;
    }
    void ldhc()
	{
        reg_h=reg_c;
        ticks=4;
        reg_pc+=1;
    }
    void ldhd()
	{
        reg_h=reg_d;
        ticks=4;
        reg_pc+=1;
    }
    void ldhe()
	{
        reg_h=reg_e;
        ticks=4;
        reg_pc+=1;
    }
    void ldhh()
	{
        ticks=4;
        reg_pc+=1;
    }
    void ldhl()
	{
        reg_h=reg_l;
        ticks=4;
        reg_pc+=1;
    }
    void ldh_hl_()
	{
        reg_h=mget(reg_hl());
        ticks=8;
        reg_pc+=1;
    }
    void ldha()
	{
        reg_h=reg_a;
        ticks=4;
        reg_pc+=1;
    }
    void ldlb()
	{
        reg_l=reg_b;
        ticks=4;
        reg_pc+=1;
    }
    void ldlc()
	{
        reg_l=reg_c;
        ticks=4;
        reg_pc+=1;
    }
    void ldld()
	{
        reg_l=reg_d;
        ticks=4;
        reg_pc+=1;
    }
    void ldle()
	{
        reg_l=reg_e;
        ticks=4;
        reg_pc+=1;
    }
    void ldlh()
	{
        reg_l=reg_h;
        ticks=4;
        reg_pc+=1;
    }
    void ldll()
	{
        ticks=4;
        reg_pc+=1;
    }
    void ldl_hl_()
	{
        reg_l=mget(reg_hl());
        ticks=8;
        reg_pc+=1;
    }
    void ldla()
    {
        reg_l=reg_a;
        ticks=4;
        reg_pc+=1;
    }
    void ld_hl_b()
	{
        mset(reg_hl(), reg_b);
        ticks=8;
        reg_pc+=1;
    }
    void ld_hl_c()
	{
        mset(reg_hl(), reg_c);
        ticks=4;
        reg_pc+=1;
    }
    void ld_hl_d()
	{
        mset(reg_hl(), reg_d);
        ticks=4;
        reg_pc+=1;
    }
    void ld_hl_e()
	{
        mset(reg_hl(), reg_e);
        ticks=8;
        reg_pc+=1;
    }
    void ld_hl_h()
	{
        mset(reg_hl(), reg_h);
        ticks=8;
        reg_pc+=1;
    }
    void ld_hl_l()
	{
        mset(reg_hl(), reg_l);
        ticks=8;
        reg_pc+=1;
    }
    void halt()
	{
        ticks=4;
    }
    void ld_hl_a()
	{
        mset(reg_hl(), reg_a);
        ticks=8;
        reg_pc+=1;
    }
    void ldab()
	{
        reg_a=reg_b;
        ticks=4;
        reg_pc+=1;
    }
    void ldac()
	{
        reg_a=reg_c;
        ticks=4;
        reg_pc+=1;

    }
    void ldad()
	{
        reg_a=reg_d;
        ticks=4;
        reg_pc+=1;
    }
    void ldae()
	{
        reg_a=reg_e;
        ticks=4;
        reg_pc+=1;
    }
    void ldah()
	{
        reg_a=reg_h;
        ticks=4;
        reg_pc+=1;
    }
    void ldal()
	{
        reg_a=reg_l;
        ticks=4;
        reg_pc+=1;
    }
    void lda_hl_()
	{
        reg_a=mget(reg_hl());
        ticks=8;
        reg_pc+=1;
    }
    void ldaa()
	{
        ticks=4;
        reg_pc+=1;
    }
    void addab()
	{
        reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_b&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_b) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_b;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void addac()
	{
        reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_c&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_c) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_c;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void addad()
	{
        reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_d&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_d) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_d;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void addae()
	{
        reg_f &= 0b10110000;
		if(( (reg_a&0xf) + (reg_e&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_e) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_e;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void addah()
	{
        reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_h&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_h) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_h;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void addal()
	{
        reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_l&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_l) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_l;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void adda_hl_()
	{
		uint8_t v = mget(reg_hl());
        reg_f &= 0b10110000;
		if(((reg_a&0xf) + (v&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + v) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void addaa()
	{
        reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_a&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_a) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_a;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
    }
    void adcab()
	{
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_b&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_b + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_b + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void adcac()
	{
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_c&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_c + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_c + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void adcad()
	{
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_d&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_d + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_d + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void adcae()
	{
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_e&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_e + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_e + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void adcah()
	{
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_h&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_h + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_h + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void adcal()
	{
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_l&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_l + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_l + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void adca_hl_()
	{
		uint8_t v = mget(reg_hl());
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (v&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + v + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += v + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void adcaa()
	{
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (reg_a&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + reg_a + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += reg_a + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void subb()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_b)&0x10)) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_b > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_b;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void subc()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_c)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_c > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_c;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void subd()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_d)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_d > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_d;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sube()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_e)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_e > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_e;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void subh()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_h)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_h > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_h;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void subl()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_l)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_l > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_l;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sub_hl_()
	{
		uint8_t v = mget(reg_hl());
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-v)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(v > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void suba()
	{
		reg_f |= 0xc0;
		if(reg_a & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		reg_f &= 0b11100000;
		reg_a = 0;
		++reg_pc;
		ticks=4;
	}
    void sbcab()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_b-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_b+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_b + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sbcac()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_c-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_c+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_c + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sbcad()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_d-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_d+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_d + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sbcae()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_e-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_e+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_e + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sbcah()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_h-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_h+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_h + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sbcal()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_l-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_l+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_l + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sbca_hl()
	{
		uint8_t v = mget(reg_hl());
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-v-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((v+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= v + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void sbcaa()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_a-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= reg_a + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void andb()
	{
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= reg_b;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void andc()
	{
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= reg_c;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void andd()
	{
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= reg_d;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void ande()
	{
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= reg_e;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void andh()
	{
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= reg_h;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void andl()
	{
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= reg_l;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void and_hl_()
	{
		uint8_t v = mget(reg_hl());
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void anda()
	{
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xorb()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a ^= reg_b;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xorc()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a ^= reg_c;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xord()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a ^= reg_d;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xore()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a ^= reg_e;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xorh()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a ^= reg_h;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xorl()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a ^= reg_l;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xor_hl_()
	{
		uint8_t v = mget(reg_hl());
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a ^= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void xora()
	{
		reg_f &= 0b10000000;
		reg_f |= 0xa0;
		reg_a = 0;
		++reg_pc;
		ticks=4;
	}
    void orb()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a |= reg_b;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void orc()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a |= reg_c;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void ord()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a |= reg_d;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void ore()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a |= reg_e;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void orh()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a |= reg_h;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void orl()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a |= reg_l;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void or_hl_()
	{
		uint8_t v = mget(reg_hl());
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		reg_a |= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void ora()
	{
		reg_f &= 0b10000000;
		reg_f |= 0x20;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cpb()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_b)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_b > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		uint8_t a = reg_a - reg_b;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cpc()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_c)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_c > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		uint8_t a = reg_a - reg_c;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cpd()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_d)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_d > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		uint8_t a = reg_a - reg_d;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cpe()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_e)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_e > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		uint8_t a = reg_a - reg_e;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cph()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_h)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_h > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		uint8_t a = reg_a - reg_h;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cpl()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_l)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(reg_l > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		uint8_t a = reg_a - reg_l;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cp_hl_()
	{
		uint8_t v = mget(reg_hl());
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-v)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(v > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
        uint8_t a = reg_a;
		a -= v;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void cpa()
	{
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-reg_a)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		reg_f &= 0b11100000;
		uint8_t a = reg_a - reg_a;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		++reg_pc;
		ticks=4;
	}
    void retnz()
	{
		if(reg_f & 0x80)
		{
			++reg_pc;
			ticks=8;
		}
		else
		{
			reg_pc = _stack_pop();
			ticks=20;
		}
	}
    void popbc()
	{
		uint16_t bc = _stack_pop();
		reg_b = (bc & 0xff00) >> 8;
		reg_c = bc & 0x00ff;
		++reg_pc;
		ticks=12;
	}
    void jpnza16()
	{
		if(reg_f & 0x80)
		{
			reg_pc+=3;
			ticks=12;
		}
		else
		{
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=16;
		}
	}
    void jpa16()
	{
		reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
		ticks=16;
	}
    void callnza16()
	{
		if(reg_f & 0x80)
		{
			reg_pc+=3;
			ticks=12;
		}
		else
		{
			_stack_push(reg_pc+3);
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=24;
		}
	}
    void pushbc()
	{
		_stack_push(reg_bc());
		++reg_pc;
		ticks=16;
	}
    void addad8()
	{
		uint8_t v = mget(reg_pc+1);
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (v&0xf)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + v) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc+=2;
		ticks=8;
	}
	void rst(uint8_t f)
	{
		_stack_push(reg_pc+3);
		reg_pc = f;
		reg_sp -= 2;
		ticks=16;
	}
    void rst00h()
	{
		rst(0);
	}
    void retz()
	{
		if(reg_f & 0x80)
		{
			reg_pc = _stack_pop();
			ticks=20;
		}
		else
		{
			++reg_pc;
			ticks=8;
		}
	}
    void ret()
	{
		reg_pc = _stack_pop();
		ticks=16;
	}
    void jpza16()
	{
		if(reg_f & 0x80)
		{
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=16;
		}
		else
		{
			reg_pc+=3;
			ticks=12;
		}
	}
    void prefix_cb()
	{
		cb_prefix_map[mget(++reg_pc)]();
	}
    void callza16()
	{
		if(reg_f & 0x80)
		{
			_stack_push(reg_pc+3);
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=24;
		}
		else
		{
			reg_pc+=3;
			ticks=12;
		}
	}
    void calla16()
	{
		_stack_push(reg_pc+3);
		reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
		ticks=24;
	}
    void adcad8()
	{
		uint8_t v = mem[reg_pc+1];
		reg_f &= 0b10110000;
		if(((reg_a&0xf) + (v&0xf) + (reg_f & 0x10?1:0)) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + v + (reg_f & 0x10?1:0)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a += v + (reg_f & 0x10?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc += 2;
		ticks = 8;
	}
    void rst08h()
	{
		rst(0x08);
	}
    void retnc()
	{
		if(reg_f & 0x80)
		{
			++reg_pc;
			ticks=8;
		}
		else
		{
			reg_pc = _stack_pop();
			ticks=20;
		}
	}
    void popde()
	{
		uint16_t de = _stack_pop();
		reg_d = (de & 0xff00) >> 8;
		reg_e = de & 0x00ff;
		++reg_pc;
		ticks=12;
	}
    void jpnca16()
	{
		if(reg_f & 0x10)
		{
			reg_pc+=3;
			ticks=12;
		}
		else
		{
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=16;
		}
	}
    void callnca16()
	{
		if(reg_f & 0x10)
		{
			reg_pc+=3;
			ticks=12;
		}
		else
		{
			_stack_push(reg_pc+3);
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=24;
		}
	}
    void pushde()
	{
		_stack_push(reg_de());
		++reg_pc;
		ticks=16;
	}
    void subd8()
	{
		uint8_t v = mem[reg_pc+1];
		reg_f |= 0x40;
		if(( (reg_a & 0x0f) + (v & 0x0f) ) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_a + v) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc+=2;
		ticks=8;
	}
    void rst10h()
	{
		rst(0x10);
	}
    void retc()
	{
		if(reg_f & 0x10)
		{
			reg_pc = _stack_pop();
			ticks=20;
		}
		else
		{
			++reg_pc;
			ticks=8;
		}
	}
	void reti()
	{
        IME = true;
		ret();
	}
	void jpca16()
	{
		if(reg_f & 0x10)
		{
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=16;
		}
		else
		{
			reg_pc+=3;
			ticks=12;
		}
	}
	void callca16()
	{
		if(reg_f & 0x10)
		{
			_stack_push(reg_pc+3);
			reg_pc = mem[reg_pc+1] | (mem[reg_pc+2] << 8);
			ticks=24;
		}
		else
		{
			reg_pc+=3;
			ticks=12;
		}
	}
	void sbcad8()
	{
		uint8_t v = mget(reg_pc+1);
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-v-(reg_f&0x20?1:0))&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((v+(reg_f&0x20?1:0)) > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_a -= v + (reg_f&0x20?1:0);
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc+=2;
		ticks=8;
	}
	void rst18h()
	{
		rst(0x18);
	}
	void ldh_a8_a()
	{
		mset(0xff00 + mem[reg_pc+1], reg_a);
		reg_pc+=2;
		ticks=12;
	}
    void pophl()
	{
		uint16_t hl = _stack_pop();
		reg_h = (hl & 0xff00) >> 8;
		reg_l = hl & 0x00ff;
		++reg_pc;
		ticks=12;
	}
	void ld_c_a()
	{
		mset(0xff00 + reg_c, reg_a);
		++reg_pc;
		ticks=8;
	}
	void pushhl()
	{
		_stack_push(reg_hl());
		++reg_pc;
		ticks=16;
	}
	void andd8()
	{
		uint8_t v = mem[reg_pc+1];
		reg_f &= 0b10100000;
		reg_f |= 0x20;
		reg_a &= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc+=2;
		ticks=8;
	}
	void rst20h()
	{
		rst(0x20);
	}
	void addspr8()
	{
		reg_f &= 0b00110000;
		uint8_t v = mem[reg_pc+1];
		int8_t s = v & 0x80 ? -((~v)+1) : v;
		if(((reg_sp&0xff) + s) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		if(((reg_sp&0xfff) + s) & 0x1000) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		reg_sp += s;
		reg_pc+=2;
		ticks=16;
	}
	void jp_hl_()
	{
		reg_pc = mget(reg_hl());
		ticks=4;
	}
	void ld_a16_a()
	{
		mset(mem[reg_pc+1] | (mem[reg_pc+2] << 8), reg_a);
		reg_pc+=3;
		ticks=16;
	}
	void xord8()
	{
		uint8_t v = mem[reg_pc+1];
		reg_f &= 0b10000000;
		reg_a ^= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc+=2;
		ticks=8;
	}
	void rst28h()
	{
		rst(0x28);
	}
	void ldha_a8_()
	{
		reg_a = mget(0xff00 + mem[reg_pc+1]);
		reg_pc+=2;
		ticks=12;
	}
	void popaf()
	{
		uint16_t af = _stack_pop();
		reg_a = (af & 0xff00) >> 8;
		reg_f = af & 0x00ff;
		++reg_pc;
		ticks=12;
	}
	void lda_c_()
	{
		reg_a = mget(0xff00 + reg_c);
		++reg_pc;
		ticks=8;
	}
	void di()
	{
		IME = false;
		++reg_pc;
		ticks=4;
	}
	void pushaf()
	{
		_stack_push(reg_af());
		++reg_pc;
		ticks=16;
	}
	void ord8()
	{
		uint8_t v = mem[reg_pc+1];
		reg_f &= 0b10000000;
		reg_a |= v;
		if(reg_a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc+=2;
		ticks=8;
	}
	void rst30h()
	{
		rst(0x30);
	}
	void ldhlspplusr8()
	{
		reg_f &= 0b00110000;
		uint8_t v = mem[reg_pc+1];
		int8_t s = v & 0x80 ? -((~v)+1) : v;
		uint16_t off = reg_sp + s;
		if(( ((reg_h & 0xf) + ((off & 0xff00) >> 8)) & 0xf) & 0x10) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if((reg_l + ((off & 0xff00) >> 8)) & 0x100) reg_f |= 0x10;
		else reg_f &= 0b11100000;
		reg_h += (off & 0xff00) >> 8;
		reg_l += off & 0x00ff;
		reg_pc+=2;
		ticks=12;
	}
	void ldsphl()
	{
		reg_sp += reg_hl();
		++reg_pc;
		ticks=8;
	}
	void lda_a16_()
	{
		reg_a = mget(mem[reg_pc+1] | (mem[reg_pc+2] << 8));
		reg_pc+=3;
		ticks=16;
	}
	void ei()
	{
		IME = true;
		++reg_pc;
		ticks=4;
	}
	void cpd8()
	{
		uint8_t v = mem[reg_pc+1];
		reg_f |= 0x40;
		if(reg_a & 0x10 && !((reg_a-v)&0x10) ) reg_f |= 0x20;
		else reg_f &= 0b11010000;
		if(v > reg_a) reg_f |= 0x10;
		else reg_f &= 0b11100000;
        uint8_t a = reg_a;
		a -= v;
		if(a == 0) reg_f |= 0x80;
		else reg_f &= 0b01110000;
		reg_pc+=2;
		ticks=8;
	}
	void rst38h()
	{
		rst(0x38);
	}

    // Prefix CB

    void cb_rlcb()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_b & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        reg_b = (reg_b << 1) | c;
        if(reg_b == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlcc()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_c & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        reg_c = (reg_c << 1) | c;
        if(reg_c == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlcd()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_d & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        reg_d = (reg_d << 1) | c;
        if(reg_d == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlce()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_e & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        reg_e = (reg_e << 1) | c;
        if(reg_e == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlch()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_h & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        reg_h = (reg_h << 1) | c;
        if(reg_h == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlcl()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_l & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        reg_l = (reg_l << 1) | c;
        if(reg_l == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlc_hl_()
    {
    	uint16_t v = mget(reg_hl());
    	reg_f &= 0b10000000;
        uint8_t c = ((v & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        mset(reg_hl(), (v << 1) | c);
        if(mem[reg_hl()] == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlca()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_a & 0x80) >> 3) & 0x10;
        reg_f |= c;
        c = c >> 4;
        reg_a = (reg_a << 1) | c;
        if(reg_a == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }

    void cb_rrcb()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_b & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        reg_b = (reg_b >> 1) | c;
        if(reg_b == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrcc()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_c & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        reg_c = (reg_c >> 1) | c;
        if(reg_c == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrcd()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_d & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        reg_d = (reg_d >> 1) | c;
        if(reg_d == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrce()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_e & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        reg_e = (reg_e >> 1) | c;
        if(reg_e == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrch()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_h & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        reg_h = (reg_h >> 1) | c;
        if(reg_h == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrcl()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_l & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        reg_l = (reg_l >> 1) | c;
        if(reg_l == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrc_hl_()
    {
    	uint16_t v = mget(reg_hl());
    	reg_f &= 0b10000000;
        uint8_t c = ((v & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        mset(reg_hl(), (v >> 1) | c);
        if(mem[reg_hl()] == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrca()
    {
    	reg_f &= 0b10000000;
        uint8_t c = ((reg_a & 0x01) << 4) & 0x10;
        reg_f |= c;
        c = c << 3;
        reg_a = (reg_a >> 1) | c;
        if(reg_a == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }

    void cb_rlb()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_b & 0x80) >> 3;
        reg_b = ((reg_b << 1) & 0b11111110) | c;
        if(reg_b == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlc()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_c & 0x80) >> 3;
        reg_c = ((reg_c << 1) & 0b11111110) | c;
        if(reg_c == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rld()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_d & 0x80) >> 3;
        reg_d = ((reg_d << 1) & 0b11111110) | c;
        if(reg_d == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rle()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_e & 0x80) >> 3;
        reg_e = ((reg_e << 1) & 0b11111110) | c;
        if(reg_e == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rlh()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_h & 0x80) >> 3;
        reg_h = ((reg_h << 1) & 0b11111110) | c;
        if(reg_h == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rll()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_l & 0x80) >> 3;
        reg_l = ((reg_l << 1) & 0b11111110) | c;
        if(reg_l == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rl_hl_()
    {
    	uint16_t v = mget(reg_hl());
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (v & 0x80) >> 3;
        mset(reg_hl(), ((v << 1) & 0b11111110) | c);
        if(mem[reg_hl()] == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rla()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) >> 4;
        reg_f &= 0b11100000;
        reg_f |= (reg_a & 0x80) >> 3;
        reg_a = ((reg_a << 1) & 0b11111110) | c;
        if(reg_a == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }

    void cb_rrb()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (reg_b & 0x01) << 4;
        reg_b = ((reg_b >> 1) & 0b01111111) | c;
        if(reg_b == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrc()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (reg_c & 0x01) << 4;
        reg_c = ((reg_c >> 1) & 0b01111111) | c;
        if(reg_c == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrd()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (reg_d & 0x01) << 4;
        reg_d = ((reg_d >> 1) & 0b01111111) | c;
        if(reg_d == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rre()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (reg_e & 0x01) << 4;
        reg_e = ((reg_e >> 1) & 0b01111111) | c;
        if(reg_e == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrh()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (reg_h & 0x01) << 4;
        reg_h = ((reg_h >> 1) & 0b01111111) | c;
        if(reg_h == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rrl()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (reg_l & 0x01) << 4;
        reg_l = ((reg_l >> 1) & 0b01111111) | c;
        if(reg_l == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rr_hl_()
    {
    	uint16_t v = mget(reg_hl());
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (v & 0x01) << 4;
        mset(reg_hl(), ((v >> 1) & 0b01111111) | c);
        if(mem[reg_hl()] == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_rra()
    {
        reg_f &= 0b10010000;
        uint8_t c = (reg_f & 0x10) << 3;
        reg_f &= 0b11100000;
        reg_f |= (reg_a & 0x01) << 4;
        reg_a = ((reg_a >> 1) & 0b01111111) | c;
        if(reg_a == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }

    void cb_slab()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_b & 0x80) >> 3;
        reg_b = (reg_b << 1) & 0b11111110;
        if(reg_b == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_slac()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_c & 0x80) >> 3;
        reg_c = (reg_c << 1) & 0b11111110;
        if(reg_c == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_slad()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_d & 0x80) >> 3;
        reg_d = (reg_d << 1) & 0b11111110;
        if(reg_d == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_slae()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_e & 0x80) >> 3;
        reg_e = (reg_e << 1) & 0b11111110;
        if(reg_e == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_slah()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_h & 0x80) >> 3;
        reg_h = (reg_h << 1) & 0b11111110;
        if(reg_h == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_slal()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_l & 0x80) >> 3;
        reg_l = (reg_l << 1) & 0b11111110;
        if(reg_l == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_sla_hl_()
    {
    	uint16_t v = mget(reg_hl());
        reg_f &= 0b10000000;
        reg_f |= (v & 0x80) >> 3;
        mset(reg_hl(), (v << 1) & 0b11111110);
        if(mem[reg_hl()] == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_slaa()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_a & 0x80) >> 3;
        reg_a = (reg_a << 1) & 0b11111110;
        if(reg_a == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }

    void cb_srab()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_b & 0x01) << 4;
        reg_b = (reg_b & 0x80) | (reg_b >> 1);
        if(reg_b == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_srac()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_c & 0x01) << 4;
        reg_c = (reg_c & 0x80) | (reg_b >> 1);
        if(reg_c == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_srad()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_d & 0x01) << 4;
        reg_d = (reg_d & 0x80) | (reg_b >> 1);
        if(reg_d == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_srae()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_e & 0x01) << 4;
        reg_e = (reg_e & 0x80) | (reg_b >> 1);
        if(reg_e == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_srah()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_h & 0x01) << 4;
        reg_h = (reg_h & 0x80) | (reg_b >> 1);
        if(reg_h == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_sral()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_l & 0x01) << 4;
        reg_l = (reg_l & 0x80) | (reg_b >> 1);
        if(reg_l == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_sra_hl_()
    {
    	uint16_t v = mget(reg_hl());
        reg_f &= 0b10000000;
        reg_f |= (v & 0x01) << 4;
        mset(reg_hl(), (v & 0x80) | (reg_b >> 1));
        if(mem[reg_hl()] == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }
    void cb_sraa()
    {
        reg_f &= 0b10000000;
        reg_f |= (reg_a & 0x01) << 4;
        reg_a = (reg_a & 0x80) | (reg_b >> 1);
        if(reg_a == 0) reg_f |= 0x80;
        else reg_f &= 0b01110000;
        ++reg_pc;
        ticks=8;
    }


    void cb_swapb()
    {
    	reg_f = 0;
    	if(reg_b == 0) reg_f |= 0x80;
    	reg_b = ((reg_b & 0x0f) << 4) | ((reg_b & 0xf0) >> 4);
        ++reg_pc;
        ticks=8;
    }
    void cb_swapc()
    {
    	reg_f = 0;
    	if(reg_c == 0) reg_f |= 0x80;
    	reg_c = ((reg_c & 0x0f) << 4) | ((reg_c & 0xf0) >> 4);
        ++reg_pc;
        ticks=8;
    }
    void cb_swapd()
    {
    	reg_f = 0;
    	if(reg_d == 0) reg_f |= 0x80;
    	reg_d = ((reg_d & 0x0f) << 4) | ((reg_d & 0xf0) >> 4);
        ++reg_pc;
        ticks=8;
    }
    void cb_swape()
    {
    	reg_f = 0;
    	if(reg_e == 0) reg_f |= 0x80;
    	reg_e = ((reg_e & 0x0f) << 4) | ((reg_e & 0xf0) >> 4);
        ++reg_pc;
        ticks=8;
    }
    void cb_swaph()
    {
    	reg_f = 0;
    	if(reg_h == 0) reg_f |= 0x80;
    	reg_h = ((reg_h & 0x0f) << 4) | ((reg_h & 0xf0) >> 4);
        ++reg_pc;
        ticks=8;
    }
    void cb_swapl()
    {
    	reg_f = 0;
    	if(reg_l == 0) reg_f |= 0x80;
    	reg_l = ((reg_l & 0x0f) << 4) | ((reg_l & 0xf0) >> 4);
        ++reg_pc;
        ticks=8;
    }
    void cb_swap_hl_()
    {
    	uint16_t v = mget(reg_hl());
    	reg_f = 0;
    	if(v == 0) reg_f |= 0x80;
    	mset(reg_hl(), ((v & 0x0f) << 4) | ((v & 0xf0) >> 4));
        ++reg_pc;
        ticks=8;
    }
    void cb_swapa()
    {
    	reg_f = 0;
    	if(reg_a == 0) reg_f |= 0x80;
    	reg_a = ((reg_a & 0x0f) << 4) | ((reg_a & 0xf0) >> 4);
        ++reg_pc;
        ticks=8;
    }


    void cb_srlb()
    {
    	reg_f &= 0b10000000;
    	reg_f |= (reg_b & 0x01) << 4;
    	reg_b = (reg_b >> 1) & 0b01111111;
    	if(reg_b == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }
    void cb_srlc()
    {
    	reg_f &= 0b10000000;
    	reg_f |= (reg_c & 0x01) << 4;
    	reg_c = (reg_c >> 1) & 0b01111111;
    	if(reg_c == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }
    void cb_srld()
    {
    	reg_f &= 0b10000000;
    	reg_f |= (reg_d & 0x01) << 4;
    	reg_d = (reg_d >> 1) & 0b01111111;
    	if(reg_d == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }
    void cb_srle()
    {
    	reg_f &= 0b10000000;
    	reg_f |= (reg_e & 0x01) << 4;
    	reg_e = (reg_e >> 1) & 0b01111111;
    	if(reg_e == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }
    void cb_srlh()
    {
    	reg_f &= 0b10000000;
    	reg_f |= (reg_h & 0x01) << 4;
    	reg_h = (reg_h >> 1) & 0b01111111;
    	if(reg_h == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }
    void cb_srll()
    {
    	reg_f &= 0b10000000;
    	reg_f |= (reg_l & 0x01) << 4;
    	reg_l = (reg_l >> 1) & 0b01111111;
    	if(reg_l == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }
    void cb_srl_hl_()
    {
    	uint16_t v = mget(reg_hl());
    	reg_f &= 0b10000000;
    	reg_f |= (v & 0x01) << 4;
    	mset(reg_hl(), (v >> 1) & 0b01111111);
    	if(mem[reg_hl()] == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }
    void cb_srla()
    {
    	reg_f &= 0b10000000;
    	reg_f |= (reg_a & 0x01) << 4;
    	reg_a = (reg_a >> 1) & 0b01111111;
    	if(reg_a == 0) reg_f |= 0x80;
    	else reg_f &= 0b01111111;
        ++reg_pc;
        ticks=8;
    }

    void cb_bit0b() { reg_f&=0b10110000; if(reg_b&=0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1b() { reg_f&=0b10110000; if(reg_b&=0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2b() { reg_f&=0b10110000; if(reg_b&=0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3b() { reg_f&=0b10110000; if(reg_b&=0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4b() { reg_f&=0b10110000; if(reg_b&=0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5b() { reg_f&=0b10110000; if(reg_b&=0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6b() { reg_f&=0b10110000; if(reg_b&=0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7b() { reg_f&=0b10110000; if(reg_b&=0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_bit0c() { reg_f&=0b10110000; if(reg_c&=0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1c() { reg_f&=0b10110000; if(reg_c&=0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2c() { reg_f&=0b10110000; if(reg_c&=0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3c() { reg_f&=0b10110000; if(reg_c&=0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4c() { reg_f&=0b10110000; if(reg_c&=0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5c() { reg_f&=0b10110000; if(reg_c&=0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6c() { reg_f&=0b10110000; if(reg_c&=0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7c() { reg_f&=0b10110000; if(reg_c&=0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_bit0d() { reg_f&=0b10110000; if(reg_d&=0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1d() { reg_f&=0b10110000; if(reg_d&=0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2d() { reg_f&=0b10110000; if(reg_d&=0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3d() { reg_f&=0b10110000; if(reg_d&=0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4d() { reg_f&=0b10110000; if(reg_d&=0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5d() { reg_f&=0b10110000; if(reg_d&=0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6d() { reg_f&=0b10110000; if(reg_d&=0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7d() { reg_f&=0b10110000; if(reg_d&=0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_bit0e() { reg_f&=0b10110000; if(reg_e&=0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1e() { reg_f&=0b10110000; if(reg_e&=0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2e() { reg_f&=0b10110000; if(reg_e&=0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3e() { reg_f&=0b10110000; if(reg_e&=0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4e() { reg_f&=0b10110000; if(reg_e&=0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5e() { reg_f&=0b10110000; if(reg_e&=0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6e() { reg_f&=0b10110000; if(reg_e&=0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7e() { reg_f&=0b10110000; if(reg_e&=0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_bit0h() { reg_f&=0b10110000; if(reg_h&=0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1h() { reg_f&=0b10110000; if(reg_h&=0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2h() { reg_f&=0b10110000; if(reg_h&=0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3h() { reg_f&=0b10110000; if(reg_h&=0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4h() { reg_f&=0b10110000; if(reg_h&=0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5h() { reg_f&=0b10110000; if(reg_h&=0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6h() { reg_f&=0b10110000; if(reg_h&=0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7h() { reg_f&=0b10110000; if(reg_h&=0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_bit0l() { reg_f&=0b10110000; if(reg_l&=0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1l() { reg_f&=0b10110000; if(reg_l&=0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2l() { reg_f&=0b10110000; if(reg_l&=0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3l() { reg_f&=0b10110000; if(reg_l&=0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4l() { reg_f&=0b10110000; if(reg_b&=0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5l() { reg_f&=0b10110000; if(reg_l&=0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6l() { reg_f&=0b10110000; if(reg_l&=0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7l() { reg_f&=0b10110000; if(reg_l&=0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_bit0_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7_hl_() { reg_f&=0b10110000; if(mget(reg_hl())&0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_bit0a() { reg_f&=0b10110000; if(reg_a&=0x01) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit1a() { reg_f&=0b10110000; if(reg_a&=0x02) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit2a() { reg_f&=0b10110000; if(reg_a&=0x04) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit3a() { reg_f&=0b10110000; if(reg_a&=0x08) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit4a() { reg_f&=0b10110000; if(reg_a&=0x10) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit5a() { reg_f&=0b10110000; if(reg_a&=0x20) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit6a() { reg_f&=0b10110000; if(reg_a&=0x40) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }
    void cb_bit7a() { reg_f&=0b10110000; if(reg_a&=0x80) reg_f&=0b01110000; else reg_f|=0x80; ++reg_pc; ticks=8; }

    void cb_res0b() { reg_b&=0b11111110; ++reg_pc; ticks=8; }
    void cb_res1b() { reg_b&=0b11111101; ++reg_pc; ticks=8; }
    void cb_res2b() { reg_b&=0b11111011; ++reg_pc; ticks=8; }
    void cb_res3b() { reg_b&=0b11110111; ++reg_pc; ticks=8; }
    void cb_res4b() { reg_b&=0b11101111; ++reg_pc; ticks=8; }
    void cb_res5b() { reg_b&=0b11011111; ++reg_pc; ticks=8; }
    void cb_res6b() { reg_b&=0b10111111; ++reg_pc; ticks=8; }
    void cb_res7b() { reg_b&=0b01111111; ++reg_pc; ticks=8; }

    void cb_res0c() { reg_c&=0b11111110; ++reg_pc; ticks=8; }
    void cb_res1c() { reg_c&=0b11111101; ++reg_pc; ticks=8; }
    void cb_res2c() { reg_c&=0b11111011; ++reg_pc; ticks=8; }
    void cb_res3c() { reg_c&=0b11110111; ++reg_pc; ticks=8; }
    void cb_res4c() { reg_c&=0b11101111; ++reg_pc; ticks=8; }
    void cb_res5c() { reg_c&=0b11011111; ++reg_pc; ticks=8; }
    void cb_res6c() { reg_c&=0b10111111; ++reg_pc; ticks=8; }
    void cb_res7c() { reg_c&=0b01111111; ++reg_pc; ticks=8; }

    void cb_res0d() { reg_d&=0b11111110; ++reg_pc; ticks=8; }
    void cb_res1d() { reg_d&=0b11111101; ++reg_pc; ticks=8; }
    void cb_res2d() { reg_d&=0b11111011; ++reg_pc; ticks=8; }
    void cb_res3d() { reg_d&=0b11110111; ++reg_pc; ticks=8; }
    void cb_res4d() { reg_d&=0b11101111; ++reg_pc; ticks=8; }
    void cb_res5d() { reg_d&=0b11011111; ++reg_pc; ticks=8; }
    void cb_res6d() { reg_d&=0b10111111; ++reg_pc; ticks=8; }
    void cb_res7d() { reg_d&=0b01111111; ++reg_pc; ticks=8; }

    void cb_res0e() { reg_e&=0b11111110; ++reg_pc; ticks=8; }
    void cb_res1e() { reg_e&=0b11111101; ++reg_pc; ticks=8; }
    void cb_res2e() { reg_e&=0b11111011; ++reg_pc; ticks=8; }
    void cb_res3e() { reg_e&=0b11110111; ++reg_pc; ticks=8; }
    void cb_res4e() { reg_e&=0b11101111; ++reg_pc; ticks=8; }
    void cb_res5e() { reg_e&=0b11011111; ++reg_pc; ticks=8; }
    void cb_res6e() { reg_e&=0b10111111; ++reg_pc; ticks=8; }
    void cb_res7e() { reg_e&=0b01111111; ++reg_pc; ticks=8; }

    void cb_res0h() { reg_h&=0b11111110; ++reg_pc; ticks=8; }
    void cb_res1h() { reg_h&=0b11111101; ++reg_pc; ticks=8; }
    void cb_res2h() { reg_h&=0b11111011; ++reg_pc; ticks=8; }
    void cb_res3h() { reg_h&=0b11110111; ++reg_pc; ticks=8; }
    void cb_res4h() { reg_h&=0b11101111; ++reg_pc; ticks=8; }
    void cb_res5h() { reg_h&=0b11011111; ++reg_pc; ticks=8; }
    void cb_res6h() { reg_h&=0b10111111; ++reg_pc; ticks=8; }
    void cb_res7h() { reg_h&=0b01111111; ++reg_pc; ticks=8; }

    void cb_res0l() { reg_l&=0b11111110; ++reg_pc; ticks=8; }
    void cb_res1l() { reg_l&=0b11111101; ++reg_pc; ticks=8; }
    void cb_res2l() { reg_l&=0b11111011; ++reg_pc; ticks=8; }
    void cb_res3l() { reg_l&=0b11110111; ++reg_pc; ticks=8; }
    void cb_res4l() { reg_l&=0b11101111; ++reg_pc; ticks=8; }
    void cb_res5l() { reg_l&=0b11011111; ++reg_pc; ticks=8; }
    void cb_res6l() { reg_l&=0b10111111; ++reg_pc; ticks=8; }
    void cb_res7l() { reg_l&=0b01111111; ++reg_pc; ticks=8; }

    void cb_res0_hl_() { mset(reg_hl(), mget(reg_hl())&0b11111110); ++reg_pc; ticks=8; }
    void cb_res1_hl_() { mset(reg_hl(), mget(reg_hl())&0b11111101); ++reg_pc; ticks=8; }
    void cb_res2_hl_() { mset(reg_hl(), mget(reg_hl())&0b11111011); ++reg_pc; ticks=8; }
    void cb_res3_hl_() { mset(reg_hl(), mget(reg_hl())&0b11110111); ++reg_pc; ticks=8; }
    void cb_res4_hl_() { mset(reg_hl(), mget(reg_hl())&0b11101111); ++reg_pc; ticks=8; }
    void cb_res5_hl_() { mset(reg_hl(), mget(reg_hl())&0b11011111); ++reg_pc; ticks=8; }
    void cb_res6_hl_() { mset(reg_hl(), mget(reg_hl())&0b10111111); ++reg_pc; ticks=8; }
    void cb_res7_hl_() { mset(reg_hl(), mget(reg_hl())&0b01111111); ++reg_pc; ticks=8; }

    void cb_res0a() { reg_a&=0b11111110; ++reg_pc; ticks=8; }
    void cb_res1a() { reg_a&=0b11111101; ++reg_pc; ticks=8; }
    void cb_res2a() { reg_a&=0b11111011; ++reg_pc; ticks=8; }
    void cb_res3a() { reg_a&=0b11110111; ++reg_pc; ticks=8; }
    void cb_res4a() { reg_a&=0b11101111; ++reg_pc; ticks=8; }
    void cb_res5a() { reg_a&=0b11011111; ++reg_pc; ticks=8; }
    void cb_res6a() { reg_a&=0b10111111; ++reg_pc; ticks=8; }
    void cb_res7a() { reg_a&=0b01111111; ++reg_pc; ticks=8; }

    void cb_set0b() { reg_b|=0x01; ++reg_pc; ticks=8; }
    void cb_set1b() { reg_b|=0x02; ++reg_pc; ticks=8; }
    void cb_set2b() { reg_b|=0x04; ++reg_pc; ticks=8; }
    void cb_set3b() { reg_b|=0x08; ++reg_pc; ticks=8; }
    void cb_set4b() { reg_b|=0x10; ++reg_pc; ticks=8; }
    void cb_set5b() { reg_b|=0x20; ++reg_pc; ticks=8; }
    void cb_set6b() { reg_b|=0x40; ++reg_pc; ticks=8; }
    void cb_set7b() { reg_b|=0x80; ++reg_pc; ticks=8; }

    void cb_set0c() { reg_c|=0x01; ++reg_pc; ticks=8; }
    void cb_set1c() { reg_c|=0x02; ++reg_pc; ticks=8; }
    void cb_set2c() { reg_c|=0x04; ++reg_pc; ticks=8; }
    void cb_set3c() { reg_c|=0x08; ++reg_pc; ticks=8; }
    void cb_set4c() { reg_c|=0x10; ++reg_pc; ticks=8; }
    void cb_set5c() { reg_c|=0x20; ++reg_pc; ticks=8; }
    void cb_set6c() { reg_c|=0x40; ++reg_pc; ticks=8; }
    void cb_set7c() { reg_c|=0x80; ++reg_pc; ticks=8; }

    void cb_set0d() { reg_d|=0x01; ++reg_pc; ticks=8; }
    void cb_set1d() { reg_d|=0x02; ++reg_pc; ticks=8; }
    void cb_set2d() { reg_d|=0x04; ++reg_pc; ticks=8; }
    void cb_set3d() { reg_d|=0x08; ++reg_pc; ticks=8; }
    void cb_set4d() { reg_d|=0x10; ++reg_pc; ticks=8; }
    void cb_set5d() { reg_d|=0x20; ++reg_pc; ticks=8; }
    void cb_set6d() { reg_d|=0x40; ++reg_pc; ticks=8; }
    void cb_set7d() { reg_d|=0x80; ++reg_pc; ticks=8; }

    void cb_set0e() { reg_e|=0x01; ++reg_pc; ticks=8; }
    void cb_set1e() { reg_e|=0x02; ++reg_pc; ticks=8; }
    void cb_set2e() { reg_e|=0x04; ++reg_pc; ticks=8; }
    void cb_set3e() { reg_e|=0x08; ++reg_pc; ticks=8; }
    void cb_set4e() { reg_e|=0x10; ++reg_pc; ticks=8; }
    void cb_set5e() { reg_e|=0x20; ++reg_pc; ticks=8; }
    void cb_set6e() { reg_e|=0x40; ++reg_pc; ticks=8; }
    void cb_set7e() { reg_e|=0x80; ++reg_pc; ticks=8; }

    void cb_set0h() { reg_h|=0x01; ++reg_pc; ticks=8; }
    void cb_set1h() { reg_h|=0x02; ++reg_pc; ticks=8; }
    void cb_set2h() { reg_h|=0x04; ++reg_pc; ticks=8; }
    void cb_set3h() { reg_h|=0x08; ++reg_pc; ticks=8; }
    void cb_set4h() { reg_h|=0x10; ++reg_pc; ticks=8; }
    void cb_set5h() { reg_h|=0x20; ++reg_pc; ticks=8; }
    void cb_set6h() { reg_h|=0x40; ++reg_pc; ticks=8; }
    void cb_set7h() { reg_h|=0x80; ++reg_pc; ticks=8; }

    void cb_set0l() { reg_l|=0x01; ++reg_pc; ticks=8; }
    void cb_set1l() { reg_l|=0x02; ++reg_pc; ticks=8; }
    void cb_set2l() { reg_l|=0x04; ++reg_pc; ticks=8; }
    void cb_set3l() { reg_l|=0x08; ++reg_pc; ticks=8; }
    void cb_set4l() { reg_l|=0x10; ++reg_pc; ticks=8; }
    void cb_set5l() { reg_l|=0x20; ++reg_pc; ticks=8; }
    void cb_set6l() { reg_l|=0x40; ++reg_pc; ticks=8; }
    void cb_set7l() { reg_l|=0x80; ++reg_pc; ticks=8; }

    void cb_set0_hl_() { mset(reg_hl(), mget(reg_hl())|0x01); ++reg_pc; ticks=8; }
    void cb_set1_hl_() { mset(reg_hl(), mget(reg_hl())|0x02); ++reg_pc; ticks=8; }
    void cb_set2_hl_() { mset(reg_hl(), mget(reg_hl())|0x04); ++reg_pc; ticks=8; }
    void cb_set3_hl_() { mset(reg_hl(), mget(reg_hl())|0x08); ++reg_pc; ticks=8; }
    void cb_set4_hl_() { mset(reg_hl(), mget(reg_hl())|0x10); ++reg_pc; ticks=8; }
    void cb_set5_hl_() { mset(reg_hl(), mget(reg_hl())|0x20); ++reg_pc; ticks=8; }
    void cb_set6_hl_() { mset(reg_hl(), mget(reg_hl())|0x40); ++reg_pc; ticks=8; }
    void cb_set7_hl_() { mset(reg_hl(), mget(reg_hl())|0x80); ++reg_pc; ticks=8; }

    void cb_set0a() { reg_a|=0x01; ++reg_pc; ticks=8; }
    void cb_set1a() { reg_a|=0x02; ++reg_pc; ticks=8; }
    void cb_set2a() { reg_a|=0x04; ++reg_pc; ticks=8; }
    void cb_set3a() { reg_a|=0x08; ++reg_pc; ticks=8; }
    void cb_set4a() { reg_a|=0x10; ++reg_pc; ticks=8; }
    void cb_set5a() { reg_a|=0x20; ++reg_pc; ticks=8; }
    void cb_set6a() { reg_a|=0x40; ++reg_pc; ticks=8; }
    void cb_set7a() { reg_a|=0x80; ++reg_pc; ticks=8; }

    void init_opcode_maps()
    {
        // Explicitly laid out for debugging purposes
        opcode_map[0x00] = nop;
        opcode_map[0x01] = ldbcd16;
        opcode_map[0x02] = ld_bc_a;
        opcode_map[0x03] = incbc;
        opcode_map[0x04] = incb;
        opcode_map[0x05] = decb;
        opcode_map[0x06] = ldbd8;
        opcode_map[0x07] = rlca;
        opcode_map[0x08] = ld_a16_sp;
        opcode_map[0x09] = addhlbc;
        opcode_map[0x0a] = lda_bc_;
        opcode_map[0x0b] = decbc;
        opcode_map[0x0c] = incc;
        opcode_map[0x0d] = decc;
        opcode_map[0x0e] = ldcd8;
        opcode_map[0x0f] = rrca;
        opcode_map[0x10] = stop;
        opcode_map[0x11] = ldded16;
        opcode_map[0x12] = ld_de_a;
        opcode_map[0x13] = incde;
        opcode_map[0x14] = incd;
        opcode_map[0x15] = decd;
        opcode_map[0x16] = lddd8;
        opcode_map[0x17] = rla;
        opcode_map[0x18] = jrr8;
        opcode_map[0x19] = addhlde;
        opcode_map[0x1a] = lda_de_;
        opcode_map[0x1b] = decde;
        opcode_map[0x1c] = ince;
        opcode_map[0x1d] = dece;
        opcode_map[0x1e] = lded8;
        opcode_map[0x1f] = rra;
        opcode_map[0x20] = jrnzr8;
        opcode_map[0x21] = ldhld16;
        opcode_map[0x22] = ld_hlplus_a;
        opcode_map[0x23] = inchl;
        opcode_map[0x24] = inch;
        opcode_map[0x25] = dech;
        opcode_map[0x26] = ldhd8;
        opcode_map[0x27] = daa;
        opcode_map[0x28] = jrzr8;
        opcode_map[0x29] = addhlhl;
        opcode_map[0x2a] = lda_hlplus_;
        opcode_map[0x2b] = dechl;
        opcode_map[0x2c] = incl;
        opcode_map[0x2d] = decl;
        opcode_map[0x2e] = ldld8;
        opcode_map[0x2f] = cp_l;
        opcode_map[0x30] = jrncr8;
        opcode_map[0x31] = ldspd16;
        opcode_map[0x32] = ld_hlminus_a;
        opcode_map[0x33] = incsp;
        opcode_map[0x34] = inc_hl_;
        opcode_map[0x35] = dec_hl_;
        opcode_map[0x36] = ld_hl_d8;
        opcode_map[0x37] = scf;
        opcode_map[0x38] = jrcr8;
        opcode_map[0x39] = addhlsp;
        opcode_map[0x3a] = lda_hlminus_;
        opcode_map[0x3b] = decsp;
        opcode_map[0x3c] = inca;
        opcode_map[0x3d] = deca;
        opcode_map[0x3e] = ldad8;
        opcode_map[0x3f] = ccf;
        opcode_map[0x40] = ldbb;
        opcode_map[0x41] = ldbc;
        opcode_map[0x42] = ldbd;
        opcode_map[0x43] = ldbe;
        opcode_map[0x44] = ldbh;
        opcode_map[0x45] = ldbl;
        opcode_map[0x46] = ldb_hl_;
        opcode_map[0x47] = ldba;
        opcode_map[0x48] = ldcb;
        opcode_map[0x49] = ldcc;
        opcode_map[0x4a] = ldcd;
        opcode_map[0x4b] = ldce;
        opcode_map[0x4c] = ldch;
        opcode_map[0x4d] = ldcl;
        opcode_map[0x4e] = ldc_hl_;
        opcode_map[0x4f] = ldca;
        opcode_map[0x50] = lddb;
        opcode_map[0x51] = lddc;
        opcode_map[0x52] = lddd;
        opcode_map[0x53] = ldde;
        opcode_map[0x54] = lddh;
        opcode_map[0x55] = lddl;
        opcode_map[0x56] = ldd_hl_;
        opcode_map[0x57] = ldda;
        opcode_map[0x58] = ldeb;
        opcode_map[0x59] = ldec;
        opcode_map[0x5a] = lded;
        opcode_map[0x5b] = ldee;
        opcode_map[0x5c] = ldeh;
        opcode_map[0x5d] = ldel;
        opcode_map[0x5e] = lde_hl_;
        opcode_map[0x5f] = ldea;
        opcode_map[0x60] = ldhb;
        opcode_map[0x61] = ldhc;
        opcode_map[0x62] = ldhd;
        opcode_map[0x63] = ldhe;
        opcode_map[0x64] = ldhh;
        opcode_map[0x65] = ldhl;
        opcode_map[0x66] = ldh_hl_;
        opcode_map[0x67] = ldha;
        opcode_map[0x68] = ldlb;
        opcode_map[0x69] = ldlc;
        opcode_map[0x6a] = ldld;
        opcode_map[0x6b] = ldle;
        opcode_map[0x6c] = ldlh;
        opcode_map[0x6d] = ldll;
        opcode_map[0x6e] = ldl_hl_;
        opcode_map[0x6f] = ldla;
        opcode_map[0x70] = ld_hl_b;
        opcode_map[0x71] = ld_hl_c;
        opcode_map[0x72] = ld_hl_d;
        opcode_map[0x73] = ld_hl_e;
        opcode_map[0x74] = ld_hl_h;
        opcode_map[0x75] = ld_hl_l;
        opcode_map[0x76] = halt;
        opcode_map[0x77] = ld_hl_a;
        opcode_map[0x78] = ldab;
        opcode_map[0x79] = ldac;
        opcode_map[0x7a] = ldad;
        opcode_map[0x7b] = ldae;
        opcode_map[0x7c] = ldah;
        opcode_map[0x7d] = ldal;
        opcode_map[0x7e] = lda_hl_;
        opcode_map[0x7f] = ldaa;
        opcode_map[0x80] = addab;
        opcode_map[0x81] = addac;
        opcode_map[0x82] = addad;
        opcode_map[0x83] = addae;
        opcode_map[0x84] = addah;
        opcode_map[0x85] = addal;
        opcode_map[0x86] = adda_hl_;
        opcode_map[0x87] = addaa;
        opcode_map[0x88] = adcab;
        opcode_map[0x89] = adcac;
        opcode_map[0x8a] = adcad;
        opcode_map[0x8b] = adcae;
        opcode_map[0x8c] = adcah;
        opcode_map[0x8d] = adcal;
        opcode_map[0x8e] = adca_hl_;
        opcode_map[0x8f] = adcaa;
        opcode_map[0x90] = subb;
        opcode_map[0x91] = subc;
        opcode_map[0x92] = subd;
        opcode_map[0x93] = sube;
        opcode_map[0x94] = subh;
        opcode_map[0x95] = subl;
        opcode_map[0x96] = sub_hl_;
        opcode_map[0x97] = suba;
        opcode_map[0x98] = sbcab;
        opcode_map[0x99] = sbcac;
        opcode_map[0x9a] = sbcad;
        opcode_map[0x9b] = sbcae;
        opcode_map[0x9c] = sbcah;
        opcode_map[0x9d] = sbcal;
        opcode_map[0x9e] = sbca_hl;
        opcode_map[0x9f] = sbcaa;
        opcode_map[0xa0] = andb;
        opcode_map[0xa1] = andc;
        opcode_map[0xa2] = andd;
        opcode_map[0xa3] = ande;
        opcode_map[0xa4] = andh;
        opcode_map[0xa5] = andl;
        opcode_map[0xa6] = and_hl_;
        opcode_map[0xa7] = anda;
        opcode_map[0xa8] = xorb;
        opcode_map[0xa9] = xorc;
        opcode_map[0xaa] = xord;
        opcode_map[0xab] = xore;
        opcode_map[0xac] = xorh;
        opcode_map[0xad] = xorl;
        opcode_map[0xae] = xor_hl_;
        opcode_map[0xaf] = xora;
        opcode_map[0xb0] = orb;
        opcode_map[0xb1] = orc;
        opcode_map[0xb2] = ord;
        opcode_map[0xb3] = ore;
        opcode_map[0xb4] = orh;
        opcode_map[0xb5] = orl;
        opcode_map[0xb6] = or_hl_;
        opcode_map[0xb7] = ora;
        opcode_map[0xb8] = cpb;
        opcode_map[0xb9] = cpc;
        opcode_map[0xba] = cpd;
        opcode_map[0xbb] = cpe;
        opcode_map[0xbc] = cph;
        opcode_map[0xbd] = cpl;
        opcode_map[0xbe] = cp_hl_;
        opcode_map[0xbf] = cpa;
        opcode_map[0xc0] = retnz;
        opcode_map[0xc1] = popbc;
        opcode_map[0xc2] = jpnza16;
        opcode_map[0xc3] = jpa16;
        opcode_map[0xc4] = callnza16;
        opcode_map[0xc5] = pushbc;
        opcode_map[0xc6] = addad8;
        opcode_map[0xc7] = rst00h;
        opcode_map[0xc8] = retz;
        opcode_map[0xc9] = ret;
        opcode_map[0xca] = jpza16;
        opcode_map[0xcb] = prefix_cb;
        opcode_map[0xcc] = callza16;
        opcode_map[0xcd] = calla16;
        opcode_map[0xce] = adcad8;
        opcode_map[0xcf] = rst08h;
        opcode_map[0xd0] = retnc;
        opcode_map[0xd1] = popde;
        opcode_map[0xd2] = jpnca16;
        opcode_map[0xd3] = illegal;
        opcode_map[0xd4] = callnca16;
        opcode_map[0xd5] = pushde;
        opcode_map[0xd6] = subd8;
        opcode_map[0xd7] = rst10h;
        opcode_map[0xd8] = retc;
        opcode_map[0xd9] = reti;
        opcode_map[0xda] = jpca16;
        opcode_map[0xdb] = illegal;
        opcode_map[0xdc] = callca16;
        opcode_map[0xdd] = illegal;
        opcode_map[0xde] = sbcad8;
        opcode_map[0xdf] = rst18h;
        opcode_map[0xe0] = ldh_a8_a;
        opcode_map[0xe1] = pophl;
        opcode_map[0xe2] = ld_c_a;
        opcode_map[0xe3] = illegal;
        opcode_map[0xe4] = illegal;
        opcode_map[0xe5] = pushhl;
        opcode_map[0xe6] = andd8;
        opcode_map[0xe7] = rst20h;
        opcode_map[0xe8] = addspr8;
        opcode_map[0xe9] = jp_hl_;
        opcode_map[0xea] = ld_a16_a;
        opcode_map[0xeb] = illegal;
        opcode_map[0xec] = illegal;
        opcode_map[0xed] = illegal;
        opcode_map[0xee] = xord8;
        opcode_map[0xef] = rst28h;
        opcode_map[0xf0] = ldha_a8_;
        opcode_map[0xf1] = popaf;
        opcode_map[0xf2] = lda_c_;
        opcode_map[0xf3] = di;
        opcode_map[0xf4] = illegal;
        opcode_map[0xf5] = pushaf;
        opcode_map[0xf6] = ord8;
        opcode_map[0xf7] = rst30h;
        opcode_map[0xf8] = ldhlspplusr8;
        opcode_map[0xf9] = ldsphl;
        opcode_map[0xfa] = lda_a16_;
        opcode_map[0xfb] = ei;
        opcode_map[0xfc] = illegal;
        opcode_map[0xfd] = illegal;
        opcode_map[0xfe] = cpd8;
        opcode_map[0xff] = rst38h;

        cb_prefix_map[0x00] = cb_rlcb;
        cb_prefix_map[0x01] = cb_rlcc;
        cb_prefix_map[0x02] = cb_rlcd;
        cb_prefix_map[0x03] = cb_rlce;
        cb_prefix_map[0x04] = cb_rlch;
        cb_prefix_map[0x05] = cb_rlcl;
        cb_prefix_map[0x06] = cb_rlc_hl_;
        cb_prefix_map[0x07] = cb_rlca;
        cb_prefix_map[0x08] = cb_rrcb;
        cb_prefix_map[0x09] = cb_rrcc;
        cb_prefix_map[0x0a] = cb_rrcd;
        cb_prefix_map[0x0b] = cb_rrce;
        cb_prefix_map[0x0c] = cb_rrch;
        cb_prefix_map[0x0d] = cb_rrcl;
        cb_prefix_map[0x0e] = cb_rrc_hl_;
        cb_prefix_map[0x0f] = cb_rrca;
        cb_prefix_map[0x10] = cb_rlb;
        cb_prefix_map[0x11] = cb_rlc;
        cb_prefix_map[0x12] = cb_rld;
        cb_prefix_map[0x13] = cb_rle;
        cb_prefix_map[0x14] = cb_rlh;
        cb_prefix_map[0x15] = cb_rll;
        cb_prefix_map[0x16] = cb_rl_hl_;
        cb_prefix_map[0x17] = cb_rla;
        cb_prefix_map[0x18] = cb_rrb;
        cb_prefix_map[0x19] = cb_rrc;
        cb_prefix_map[0x1a] = cb_rrd;
        cb_prefix_map[0x1b] = cb_rre;
        cb_prefix_map[0x1c] = cb_rrh;
        cb_prefix_map[0x1d] = cb_rrl;
        cb_prefix_map[0x1e] = cb_rr_hl_;
        cb_prefix_map[0x1f] = cb_rra;
        cb_prefix_map[0x20] = cb_slab;
        cb_prefix_map[0x21] = cb_slac;
        cb_prefix_map[0x22] = cb_slad;
        cb_prefix_map[0x23] = cb_slae;
        cb_prefix_map[0x24] = cb_slah;
        cb_prefix_map[0x25] = cb_slal;
        cb_prefix_map[0x26] = cb_sla_hl_;
        cb_prefix_map[0x27] = cb_slaa;
        cb_prefix_map[0x28] = cb_srab;
        cb_prefix_map[0x29] = cb_srac;
        cb_prefix_map[0x2a] = cb_srad;
        cb_prefix_map[0x2b] = cb_srae;
        cb_prefix_map[0x2c] = cb_srah;
        cb_prefix_map[0x2d] = cb_sral;
        cb_prefix_map[0x2e] = cb_sra_hl_;
        cb_prefix_map[0x2f] = cb_sraa;
        cb_prefix_map[0x30] = cb_swapb;
        cb_prefix_map[0x31] = cb_swapc;
        cb_prefix_map[0x32] = cb_swapd;
        cb_prefix_map[0x33] = cb_swape;
        cb_prefix_map[0x34] = cb_swaph;
        cb_prefix_map[0x35] = cb_swapl;
        cb_prefix_map[0x36] = cb_swap_hl_;
        cb_prefix_map[0x37] = cb_swapa;
        cb_prefix_map[0x38] = cb_srlb;
        cb_prefix_map[0x39] = cb_srlc;
        cb_prefix_map[0x3a] = cb_srld;
        cb_prefix_map[0x3b] = cb_srle;
        cb_prefix_map[0x3c] = cb_srlh;
        cb_prefix_map[0x3d] = cb_srll;
        cb_prefix_map[0x3e] = cb_srl_hl_;
        cb_prefix_map[0x3f] = cb_srla;
        cb_prefix_map[0x40] = cb_bit0b;
        cb_prefix_map[0x41] = cb_bit1b;
        cb_prefix_map[0x42] = cb_bit2b;
        cb_prefix_map[0x43] = cb_bit3b;
        cb_prefix_map[0x44] = cb_bit4b;
        cb_prefix_map[0x45] = cb_bit5b;
        cb_prefix_map[0x46] = cb_bit6b;
        cb_prefix_map[0x47] = cb_bit7b;
        cb_prefix_map[0x48] = cb_bit0c;
        cb_prefix_map[0x49] = cb_bit1c;
        cb_prefix_map[0x4a] = cb_bit2c;
        cb_prefix_map[0x4b] = cb_bit3c;
        cb_prefix_map[0x4c] = cb_bit4c;
        cb_prefix_map[0x4d] = cb_bit5c;
        cb_prefix_map[0x4e] = cb_bit6c;
        cb_prefix_map[0x4f] = cb_bit7c;
        cb_prefix_map[0x50] = cb_bit0d;
        cb_prefix_map[0x51] = cb_bit1d;
        cb_prefix_map[0x52] = cb_bit2d;
        cb_prefix_map[0x53] = cb_bit3d;
        cb_prefix_map[0x54] = cb_bit4d;
        cb_prefix_map[0x55] = cb_bit5d;
        cb_prefix_map[0x56] = cb_bit6d;
        cb_prefix_map[0x57] = cb_bit7d;
        cb_prefix_map[0x58] = cb_bit0e;
        cb_prefix_map[0x59] = cb_bit1e;
        cb_prefix_map[0x5a] = cb_bit2e;
        cb_prefix_map[0x5b] = cb_bit3e;
        cb_prefix_map[0x5c] = cb_bit4e;
        cb_prefix_map[0x5d] = cb_bit5e;
        cb_prefix_map[0x5e] = cb_bit6e;
        cb_prefix_map[0x5f] = cb_bit7e;
        cb_prefix_map[0x60] = cb_bit0h;
        cb_prefix_map[0x61] = cb_bit1h;
        cb_prefix_map[0x62] = cb_bit2h;
        cb_prefix_map[0x63] = cb_bit3h;
        cb_prefix_map[0x64] = cb_bit4h;
        cb_prefix_map[0x65] = cb_bit5h;
        cb_prefix_map[0x66] = cb_bit6h;
        cb_prefix_map[0x67] = cb_bit7h;
        cb_prefix_map[0x68] = cb_bit0l;
        cb_prefix_map[0x69] = cb_bit1l;
        cb_prefix_map[0x6a] = cb_bit2l;
        cb_prefix_map[0x6b] = cb_bit3l;
        cb_prefix_map[0x6c] = cb_bit4l;
        cb_prefix_map[0x6d] = cb_bit5l;
        cb_prefix_map[0x6e] = cb_bit6l;
        cb_prefix_map[0x6f] = cb_bit7l;
        cb_prefix_map[0x70] = cb_bit0_hl_;
        cb_prefix_map[0x71] = cb_bit1_hl_;
        cb_prefix_map[0x72] = cb_bit2_hl_;
        cb_prefix_map[0x73] = cb_bit3_hl_;
        cb_prefix_map[0x74] = cb_bit4_hl_;
        cb_prefix_map[0x75] = cb_bit5_hl_;
        cb_prefix_map[0x76] = cb_bit6_hl_;
        cb_prefix_map[0x77] = cb_bit7_hl_;
        cb_prefix_map[0x78] = cb_bit0a;
        cb_prefix_map[0x79] = cb_bit1a;
        cb_prefix_map[0x7a] = cb_bit2a;
        cb_prefix_map[0x7b] = cb_bit3a;
        cb_prefix_map[0x7c] = cb_bit4a;
        cb_prefix_map[0x7d] = cb_bit5a;
        cb_prefix_map[0x7e] = cb_bit6a;
        cb_prefix_map[0x7f] = cb_bit7a;
        cb_prefix_map[0x80] = cb_res0b;
        cb_prefix_map[0x81] = cb_res1b;
        cb_prefix_map[0x82] = cb_res2b;
        cb_prefix_map[0x83] = cb_res3b;
        cb_prefix_map[0x84] = cb_res4b;
        cb_prefix_map[0x85] = cb_res5b;
        cb_prefix_map[0x86] = cb_res6b;
        cb_prefix_map[0x87] = cb_res7b;
        cb_prefix_map[0x88] = cb_res0c;
        cb_prefix_map[0x89] = cb_res1c;
        cb_prefix_map[0x8a] = cb_res2c;
        cb_prefix_map[0x8b] = cb_res3c;
        cb_prefix_map[0x8c] = cb_res4c;
        cb_prefix_map[0x8d] = cb_res5c;
        cb_prefix_map[0x8e] = cb_res6c;
        cb_prefix_map[0x8f] = cb_res7c;
        cb_prefix_map[0x90] = cb_res0d;
        cb_prefix_map[0x91] = cb_res1d;
        cb_prefix_map[0x92] = cb_res2d;
        cb_prefix_map[0x93] = cb_res3d;
        cb_prefix_map[0x94] = cb_res4d;
        cb_prefix_map[0x95] = cb_res5d;
        cb_prefix_map[0x96] = cb_res6d;
        cb_prefix_map[0x97] = cb_res7d;
        cb_prefix_map[0x98] = cb_res0e;
        cb_prefix_map[0x99] = cb_res1e;
        cb_prefix_map[0x9a] = cb_res2e;
        cb_prefix_map[0x9b] = cb_res3e;
        cb_prefix_map[0x9c] = cb_res4e;
        cb_prefix_map[0x9d] = cb_res5e;
        cb_prefix_map[0x9e] = cb_res6e;
        cb_prefix_map[0x9f] = cb_res7e;
        cb_prefix_map[0xa0] = cb_res0h;
        cb_prefix_map[0xa1] = cb_res1h;
        cb_prefix_map[0xa2] = cb_res2h;
        cb_prefix_map[0xa3] = cb_res3h;
        cb_prefix_map[0xa4] = cb_res4h;
        cb_prefix_map[0xa5] = cb_res5h;
        cb_prefix_map[0xa6] = cb_res6h;
        cb_prefix_map[0xa7] = cb_res7h;
        cb_prefix_map[0xa8] = cb_res0l;
        cb_prefix_map[0xa9] = cb_res1l;
        cb_prefix_map[0xaa] = cb_res2l;
        cb_prefix_map[0xab] = cb_res3l;
        cb_prefix_map[0xac] = cb_res4l;
        cb_prefix_map[0xad] = cb_res5l;
        cb_prefix_map[0xae] = cb_res6l;
        cb_prefix_map[0xaf] = cb_res7l;
        cb_prefix_map[0xb0] = cb_res0_hl_;
        cb_prefix_map[0xb1] = cb_res1_hl_;
        cb_prefix_map[0xb2] = cb_res2_hl_;
        cb_prefix_map[0xb3] = cb_res3_hl_;
        cb_prefix_map[0xb4] = cb_res4_hl_;
        cb_prefix_map[0xb5] = cb_res5_hl_;
        cb_prefix_map[0xb6] = cb_res6_hl_;
        cb_prefix_map[0xb7] = cb_res7_hl_;
        cb_prefix_map[0xb8] = cb_res0a;
        cb_prefix_map[0xb9] = cb_res1a;
        cb_prefix_map[0xba] = cb_res2a;
        cb_prefix_map[0xbb] = cb_res3a;
        cb_prefix_map[0xbc] = cb_res4a;
        cb_prefix_map[0xbd] = cb_res5a;
        cb_prefix_map[0xbe] = cb_res6a;
        cb_prefix_map[0xbf] = cb_res7a;
        cb_prefix_map[0xc0] = cb_set0b;
        cb_prefix_map[0xc1] = cb_set1b;
        cb_prefix_map[0xc2] = cb_set2b;
        cb_prefix_map[0xc3] = cb_set3b;
        cb_prefix_map[0xc4] = cb_set4b;
        cb_prefix_map[0xc5] = cb_set5b;
        cb_prefix_map[0xc6] = cb_set6b;
        cb_prefix_map[0xc7] = cb_set7b;
        cb_prefix_map[0xc8] = cb_set0c;
        cb_prefix_map[0xc9] = cb_set1c;
        cb_prefix_map[0xca] = cb_set2c;
        cb_prefix_map[0xcb] = cb_set3c;
        cb_prefix_map[0xcc] = cb_set4c;
        cb_prefix_map[0xcd] = cb_set5c;
        cb_prefix_map[0xce] = cb_set6c;
        cb_prefix_map[0xcf] = cb_set7c;
        cb_prefix_map[0xd0] = cb_set0d;
        cb_prefix_map[0xd1] = cb_set1d;
        cb_prefix_map[0xd2] = cb_set2d;
        cb_prefix_map[0xd3] = cb_set3d;
        cb_prefix_map[0xd4] = cb_set4d;
        cb_prefix_map[0xd5] = cb_set5d;
        cb_prefix_map[0xd6] = cb_set6d;
        cb_prefix_map[0xd7] = cb_set7d;
        cb_prefix_map[0xd8] = cb_set0e;
        cb_prefix_map[0xd9] = cb_set1e;
        cb_prefix_map[0xda] = cb_set2e;
        cb_prefix_map[0xdb] = cb_set3e;
        cb_prefix_map[0xdc] = cb_set4e;
        cb_prefix_map[0xdd] = cb_set5e;
        cb_prefix_map[0xde] = cb_set6e;
        cb_prefix_map[0xdf] = cb_set7e;
        cb_prefix_map[0xe0] = cb_set0h;
        cb_prefix_map[0xe1] = cb_set1h;
        cb_prefix_map[0xe2] = cb_set2h;
        cb_prefix_map[0xe3] = cb_set3h;
        cb_prefix_map[0xe4] = cb_set4h;
        cb_prefix_map[0xe5] = cb_set5h;
        cb_prefix_map[0xe6] = cb_set6h;
        cb_prefix_map[0xe7] = cb_set7h;
        cb_prefix_map[0xe8] = cb_set0l;
        cb_prefix_map[0xe9] = cb_set1l;
        cb_prefix_map[0xea] = cb_set2l;
        cb_prefix_map[0xeb] = cb_set3l;
        cb_prefix_map[0xec] = cb_set4l;
        cb_prefix_map[0xed] = cb_set5l;
        cb_prefix_map[0xee] = cb_set6l;
        cb_prefix_map[0xef] = cb_set7l;
        cb_prefix_map[0xf0] = cb_set0_hl_;
        cb_prefix_map[0xf1] = cb_set1_hl_;
        cb_prefix_map[0xf2] = cb_set2_hl_;
        cb_prefix_map[0xf3] = cb_set3_hl_;
        cb_prefix_map[0xf4] = cb_set4_hl_;
        cb_prefix_map[0xf5] = cb_set5_hl_;
        cb_prefix_map[0xf6] = cb_set6_hl_;
        cb_prefix_map[0xf7] = cb_set7_hl_;
        cb_prefix_map[0xf8] = cb_set0a;
        cb_prefix_map[0xf9] = cb_set1a;
        cb_prefix_map[0xfa] = cb_set2a;
        cb_prefix_map[0xfb] = cb_set3a;
        cb_prefix_map[0xfc] = cb_set4a;
        cb_prefix_map[0xfd] = cb_set5a;
        cb_prefix_map[0xfe] = cb_set6a;
        cb_prefix_map[0xff] = cb_set7a;
    }

    void onEvent(const SDL_Event & e)
    {
    	mem[0xff0f] |= 0x10; // Request joypad interrupt

    	bool selectedDirectionKeys = mem[0xff00] & 0x10 && !(mem[0xff00] & 0x20);
		if(e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.sym)
			{
			case SDLK_DOWN:
				if(selectedDirectionKeys) mem[0xff00] &= ~(0x08);
				break;
			case SDLK_UP:
				if(selectedDirectionKeys) mem[0xff00] &= ~(0x04);
				break;
			case SDLK_LEFT:
				if(selectedDirectionKeys) mem[0xff00] &= ~(0x02);
				break;
			case SDLK_RIGHT:
				if(selectedDirectionKeys) mem[0xff00] &= ~(0x01);
				break;
			case SDLK_z:
				if(!selectedDirectionKeys) mem[0xff00] &= ~(0x01);
				break;
			case SDLK_x:
				if(!selectedDirectionKeys) mem[0xff00] &= ~(0x02);
				break;
			case SDLK_BACKSPACE:
				if(!selectedDirectionKeys) mem[0xff00] &= ~(0x04);
				break;
			case SDLK_RETURN:
				if(!selectedDirectionKeys) mem[0xff00] &= ~(0x08);
				break;
			}
		}
		else if(e.type == SDL_KEYUP)
			switch(e.key.keysym.sym)
			{
				case SDLK_DOWN:
					if(selectedDirectionKeys) mem[0xff00] |= 0x08;
					break;
				case SDLK_UP:
					if(selectedDirectionKeys) mem[0xff00] |= 0x04;
					break;
				case SDLK_LEFT:
					if(selectedDirectionKeys) mem[0xff00] |= 0x02;
					break;
				case SDLK_RIGHT:
					if(selectedDirectionKeys) mem[0xff00] |= 0x01;
					break;
				case SDLK_z:
					if(!selectedDirectionKeys) mem[0xff00] |= 0x01;
					break;
				case SDLK_x:
					if(!selectedDirectionKeys) mem[0xff00] |= 0x02;
					break;
				case SDLK_BACKSPACE:
					if(!selectedDirectionKeys) mem[0xff00] |= 0x04;
					break;
				case SDLK_RETURN:
					if(!selectedDirectionKeys) mem[0xff00] |= 0x04;
					break;
			}
    }
}

#endif // EMU_H
