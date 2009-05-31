#include "Timer.h"
#include "init.h"
#include "Object.h"
#include "main.h"

int main(int argc, char* argv[])
{
	Timer *mainTimer = new Timer();
	mainTimer->start();
	mainTimer->reset();
	
	Timer *framecounter = new Timer();
	int frames = 0;
	SDL_Event event;
	float force = 0.0;
	
	
	init("Init"); 
	
	//SDL_Surface *surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Surface *surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	SDL_Surface *awesomeTemp = load_image("awesome.png");
	SDL_Surface *sadfaceTemp = load_image("sadface.png");
	
	unsigned int mycolor = SDL_MapRGB(surface->format, 20, 20, 140);
	
	srand((unsigned)time(0));
	
	Object *awesome = new Object[NUMBER_OF_BALLS];
	for (int a = 0; a < NUMBER_OF_BALLS; a++)
	{
		 awesome[a].awesome = &awesomeTemp;
		 awesome[a].sadface = &sadfaceTemp;
		 awesome[a].setX(rand()%(SCREEN_WIDTH-SIZE_AWESOME));
		 awesome[a].setY(rand()%(SCREEN_HEIGHT-SIZE_AWESOME));
		 awesome[a].setSpeedX(float(rand()%MAX_SPEED));
			if(rand()%2 == 1) awesome[a].setSpeedX(-awesome[a].getSpeedX());
		 awesome[a].setSpeedY(float(rand()%MAX_SPEED));
			if(rand()%2 == 1) awesome[a].setSpeedY(-awesome[a].getSpeedY());
	 }


framecounter->start();
framecounter->reset();
mainTimer->reset();
Timer *fpsCounter = new Timer();
fpsCounter->start();
fpsCounter->reset();
bool running = true;

while (running)
{
	
	if( SDL_PollEvent( &event ) )
	{
		if (event.type == SDL_QUIT) running = false;
		
		else if (event.type == SDL_KEYDOWN)
		{
			switch( event.key.keysym.sym )
			{
				case SDLK_UP: 
				force = -900.0;
				
				break;
				default: break;
			}
		}
		else if (event.type == SDL_KEYUP)
		{
			switch( event.key.keysym.sym )
			{
				case SDLK_UP:
				force = 0.0; break;
				default: break;
			}
		}
	}
	
	
	
	else if ( fpsCounter->getTicks() >= 1000/FPS_CAP )
	{
		fpsCounter->reset();
		SDL_FillRect(surface, &surface->clip_rect, mycolor);
		for(int c = 0; c < NUMBER_OF_BALLS; c++)
		{
			awesome[c].checkCollision();
			awesome[c].updateCo(mainTimer->getTicks(), force);
			awesome[c].blit(surface);
			
		}	
		
		if ( SDL_Flip(surface) == -1 ) return 1;
		mainTimer->ticks = fpsCounter->ticks;
		frames++;
		if(frames%100 == 0) updateCaption(frames, framecounter->getTicks());
	}	
		
	
	SDL_Delay(1);
			
}
    delete mainTimer;
	delete framecounter;
delete fpsCounter;	
	delete[] awesome;
	
	
	
	clean_up(surface);
	clean_up(awesomeTemp);
	clean_up(sadfaceTemp);
	SDL_Quit();
	
	return 0;
}
