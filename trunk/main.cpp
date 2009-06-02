/*  the-escapist - SDL game
 *  Copyright (C) 2009 - ./glhf
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */




#include "Timer.h"
#include "init.h"
#include "Object.h"
#include "main.h"


void blitBackdrop(SDL_Surface* backdrop, SDL_Surface* screen, MainChar mainchar)
{
	SDL_Rect cutout;
	cutout.x = mainchar.getX() - SCREEN_WIDTH/2;
	if( cutout.x < 0) cutout.x = 0;
	cutout.y = mainchar.getY() - SCREEN_WIDTH/2;
	if ( cutout.y < 0) cutout.y = 0;
	cutout.w = SCREEN_WIDTH;
	cutout.h = SCREEN_HEIGHT;
	int x,y;
	x = 0;
	y = 0;
	
	apply_surface(x, y, backdrop, screen, cutout);
	
}




int main(int argc, char* argv[])
{
	Timer *mainTimer = new Timer();
	mainTimer->start();
	mainTimer->reset();
	
	Timer *framecounter = new Timer();
	int frames = 0;
	
	float force = 0.0;
	
	
	init("Init"); 
	
	SDL_Surface *surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	SDL_Surface *mainChar_Sprite = load_image("Data/Sprites/awesome.png");
	SDL_Surface *backdrop = load_image("Data/Backdrops/test_skybox.png");
	SDL_Surface *floor = load_image("Data/Backdrops/test_ground.PNG");
	SDL_Surface *platforms = load_image("Data/Backdrops/test_platforms.png");
	
	//unsigned int mycolor = SDL_MapRGB(surface->format, 20, 20, 20);
	
	srand((unsigned)time(0));
	
	MainChar *mainChar = new MainChar();
	
		 mainChar->charSprite = &mainChar_Sprite;
		 
		 mainChar->setX(rand()%(SCREEN_WIDTH-SIZE_AWESOME));
		 mainChar->setY(rand()%(SCREEN_HEIGHT-SIZE_AWESOME));
		 mainChar->setSpeedX(float(rand()%MAX_SPEED));
			if(rand()%2 == 1) mainChar->setSpeedX(-mainChar->getSpeedX());
		 mainChar->setSpeedY(float(rand()%MAX_SPEED));
			if(rand()%2 == 1) mainChar->setSpeedY(-mainChar->getSpeedY());
	 


	framecounter->start();
	framecounter->reset();
	mainTimer->reset();
	Timer *fpsCounter = new Timer();
	fpsCounter->start();
	fpsCounter->reset();
	bool running = true;

while (running)
{
	
	if (!mainChar->handleInput()) running = false;
	
	if ( fpsCounter->getTicks() >= 1000/FPS_CAP )
	{
		fpsCounter->reset();
		//SDL_FillRect(surface, &surface->clip_rect, mycolor);
		
		blitBackdrop(backdrop, surface, *mainChar);
		
			
			mainChar->checkCollision();
			mainChar->updateCo(mainTimer->getTicks(), force);
			mainChar->blit(surface);
			
			
		
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
	delete mainChar;
	
	
	clean_up(surface);
	clean_up(mainChar_Sprite);
	clean_up(backdrop);
	clean_up(floor);
	clean_up(platforms);
	
	SDL_Quit();
	
	return 0;
}
