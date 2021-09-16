#include <SDL.h>
#include <iostream>
#include <math.h>

void rndColor(Uint8* r, Uint8* g, Uint8* b)
{
	*r = rand() % 256;
	*g = rand() % 256;
	*b = rand() % 256;
}

int main( int argc, char* args[] )
{
	atexit([] {
			std::cout << "Press a key to exit the application..." << std::endl;
			std::cin.get();
		});

	
	if ( SDL_Init( SDL_INIT_VIDEO ) == -1 )
	{
		std::cout << "[SDL initialization] Error during the SDL initialization: " << SDL_GetError() << std::endl;
		return 1;
	}

	const float twoPi = 2 * M_PI;
	int height = 600;
	int width = 800;

	SDL_Window *win = nullptr;
	win = SDL_CreateWindow("Hello SDL!", 100, 100, width, height, SDL_WINDOW_SHOWN);

    if (win == nullptr)
	{
		std::cout << "[Window creation] Error during the creation of an SDL window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *ren = nullptr;
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);	
																						
    if (ren == nullptr)
	{
        std::cout << "[Renderer creation] Error during the creation of an SDL renderer: " << SDL_GetError() << std::endl;
        return 1;
    }
	SDL_Event ev;
	bool quit = false;

	
	Sint32 mouseX = 0, mouseY = 0;
	Uint8 r = 0, g = 0, b = 0;

	int sections = 200;
	float circleRadius = 50;
	float rotationRadius = 100;
	float maxrotRadius = rotationRadius * 2;
	float interval = 5;
	bool direction = true;
	bool directionLock = false;

	float timer = 0;


	Uint32 last = SDL_GetTicks();
	while (!quit)
	{
		while ( SDL_PollEvent(&ev) )
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				if (ev.key.keysym.sym == SDLK_ESCAPE) 
					quit = true;
				else if (ev.key.keysym.sym == SDLK_q) 
					rotationRadius = std::min(rotationRadius + 10, (float)maxrotRadius);
				else if (ev.key.keysym.sym == SDLK_e) 
					rotationRadius = std::max(rotationRadius - 10, (float)0);
				else if (ev.key.keysym.sym == SDLK_SPACE)
				{
					direction = !direction;
					rndColor(&r, &g, &b);
				}
				break;
			case SDL_MOUSEMOTION:
				mouseX = ev.motion.x;
				mouseY = ev.motion.y;
				break;
			}
		}

		Uint32 current = SDL_GetTicks();
		Uint32 deltaTick = current - last; 
		float delta = deltaTick / (float) 1000;
		last = current;

		//Clear
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderClear(ren);

		//Draw rotating circle
		timer += direction ? delta : -delta;
		std::cout << timer << std::endl;

		float state = fmod(timer, interval) / interval;
		float dX = cos(twoPi * state) * rotationRadius;
		float dY = sin(twoPi * state) * rotationRadius;

		//Check detection
		float posX = (float) mouseX + dX;
		float posY = (float) mouseY + dY;
		
	
		if (posX + circleRadius > width
			|| posX - circleRadius < 0
			|| posY + circleRadius > height
			|| posY - circleRadius < 0)
		{
			if (!directionLock)
			{
				direction = !direction;
				rndColor(&r, &g, &b);
			}
			directionLock = true;
		}
		else
		{
			directionLock = false;
		}
		



		std::cout << direction << std::endl;

		SDL_SetRenderDrawColor(ren, r, g, b, 0);
		float c = twoPi / sections;
		for (int i = 0; i < sections; i++)
		{
			SDL_RenderDrawLine(ren,
				cos(c * i)		* circleRadius + posX,
				sin(c * i)		* circleRadius + posY, 
				cos(c * (i + 1))	* circleRadius + posX,
				sin(c * (i + 1))	* circleRadius + posY);
		}

		SDL_RenderPresent(ren);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	SDL_Quit();

	return 0;
}
