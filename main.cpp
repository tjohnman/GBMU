#include "includes.h"
#include "emu.h"

#define WINDOW_SCALE 4

bool printMHz = false;
bool printRegMode = false;
void onFatalError(const std::string & msg, bool SDLInitialized = true);
SDL_Window * win;

void onEmulationEvent(int id)
{
	switch(id)
	{
	case EMU_EV_BIOS_END:
		SDL_SetWindowTitle(win, ("GBMU | " + emu::gameTitle).c_str());
		break;
	default:
		std::cout << "Unknown emulation event.\n";
		break;
	}
}

int main(int argc, char ** argv)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		onFatalError("Failed to initialize SDL");
		return 1;
	}

	win = SDL_CreateWindow("GBMU",
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										160*WINDOW_SCALE, 144*WINDOW_SCALE,
										SDL_WINDOW_MOUSE_FOCUS);
	if(!win)
	{
		onFatalError("Failed to create window");
		return 1;
	}

	SDL_Renderer * ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
	if(!ren)
	{
		onFatalError("Failed to create renderer");
		return 1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
	SDL_RenderSetLogicalSize(ren, 160, 144);

	emu::onEmulationEvent = onEmulationEvent;
    emu::framebuffer = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 160, 144);
    emu::init_opcode_maps();

    std::ifstream is;
    is.open("data/cpu_instrs.gb", std::ios::in);
    if(!is.is_open())
    {
        std::cout << "Failed to open specified cartidge.\n";
		return 1;
    }
    is.seekg(0, std::ios::end);
    size_t s = is.tellg();
    is.seekg(0, std::ios::beg);
    is.read((char*)emu::cartidge_data, s);
    is.close();

    Uint32 ticks = 0, prevTicks = 0;

    emu::reset();

	SDL_Event e;
	bool done = false;
	while(!done)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				done = true;
			}

            if(e.type == SDL_KEYUP)
            {
                switch(e.key.keysym.sym)
                {
					case SDLK_SPACE:
						printRegMode = !printRegMode;
						break;
					case SDLK_ESCAPE:
						done = true;
						break;
					default:
						if(printRegMode)
						{
							emu::next(0.001);
							emu::process_interrupts();
							emu::gpu_step();
							emu::regdump();
						}
						else
						{
							emu::onEvent(e);
						}
						break;
                }
            }
		}

        if(emu::gpu_vblank)
		{
			SDL_RenderCopy(ren, emu::framebuffer, 0, 0);
			SDL_RenderPresent(ren);

			emu::gpu_vblank = false;
		}
		else if((!emu::mem[0xff40] & 0x80)) // LCD disabled
		{
			SDL_RenderClear(ren);
			SDL_RenderPresent(ren);
		}

		if(!printRegMode && emu::reg_pc == -1)
		{
			std::cout << "Print Reg Mode ON\n";
			printRegMode = true;
		}

		if(!printRegMode)
		{
			prevTicks = ticks;
			ticks = SDL_GetTicks();

			emu::next((ticks - prevTicks) / 1000.0);
			emu::process_interrupts();
			emu::gpu_step();
		}
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}

void onFatalError(const std::string & msg, bool SDLInitialized)
{
	std::cout << msg << ": " << SDL_GetError() << "\n";
	if(SDLInitialized) SDL_Quit();
}
