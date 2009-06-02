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

#include "mainChar.h"

MainChar::MainChar(int x, int y, float s_x, float s_y)
{
	posX = x;
	posY = y;
	speedX = s_x;
	speedY = s_y;
	
	stopped = false;
	
}

MainChar::MainChar()
{
	speedX = 10;
	speedY = 10;
	
	stopped = false;
	
}

float MainChar::getSpeedX()
{
	return speedX;
}

float MainChar::getSpeedY()
{
	return speedY;
}

int MainChar::getX()
{
	return (int)posX;
}

int MainChar::getY()
{
	return (int)posY;
}

void MainChar::setX(int x)
{
	posX = (float)x;
}

void MainChar::setY(int y)
{
	posY = (float)y;
}

void MainChar::changeSpeedX(float x)
{
	speedX = x;
}

void MainChar::changeSpeedY(float y)
{
	speedY = y;
}

void MainChar::setSpeedX(float x)
{
	speedX = x;
}

void MainChar::setSpeedY(float y)
{
	speedY = y;
}

void MainChar::blit(SDL_Surface *screen)
{
	
	SDL_Rect offset;
	offset.x = (int)posX;
	offset.y = (int)posY;
	
	SDL_BlitSurface( *charSprite, NULL, screen, &offset );
}

void MainChar::checkCollision()
{
	if( posY < SCREEN_HEIGHT-SIZE_MAINCHAR ) stopped = false;
	
	if ( posX >= SCREEN_WIDTH-SIZE_MAINCHAR )
	{
		 speedX = -speedX*SURFACE_HARDNESS_WALL;
		 posX = SCREEN_WIDTH-SIZE_MAINCHAR;
		 
	}
	else if ( posX <= 0 )
	{
		speedX = -speedX*SURFACE_HARDNESS_WALL;
		posX = 0;
	}
	if ( posY >= SCREEN_HEIGHT-SIZE_MAINCHAR )
	{
		
		if( speedY >= 0.0)
		{
		speedY = 0.0;
		posY = SCREEN_HEIGHT-SIZE_MAINCHAR;
			
		}
		
		if ( !stopped )
		{
			Uint8 *keystates = SDL_GetKeyState( NULL );
			if( !keystates[ SDLK_LEFT ] && !keystates[ SDLK_RIGHT ])
			{ 
				speedX = 0.0;
				stopped = true;
			}
		}
		
		
	}
	else if ( posY <= 0 )
	{ 
		speedY = -speedY*SURFACE_HARDNESS_GROUND;
		posY = 0;
		
	}
}


MainChar::~MainChar()
{
	
}

void MainChar::updateCo(int ticks, float force)
{
	posX += speedX * (float)ticks/1000;
	posY += speedY * (float)ticks/1000;
	if (posX > SCREEN_WIDTH-SIZE_MAINCHAR) posX = SCREEN_WIDTH-SIZE_MAINCHAR;
	else if (posX < 0) posX = 0;

	if (posY > SCREEN_HEIGHT-SIZE_MAINCHAR) posY = SCREEN_HEIGHT-SIZE_MAINCHAR;
	else if (posY < 0) posY = 0;
	//posX += 1;
	//posY += 1;
	speedY += (float)ticks*(GRAVITY_CONS+force)/1000;
}



bool MainChar::handleInput()
{
	
if( SDL_PollEvent( &event ) )
{
		
	
   if (event.type == SDL_QUIT) return false;
		
    else if (event.type == SDL_KEYDOWN)
		{
			switch( event.key.keysym.sym )
			{
				case SDLK_UP: 
					if( posY == SCREEN_HEIGHT-SIZE_MAINCHAR ) 
					speedY = -600.0;
					
					
					break;
				case SDLK_LEFT:
					speedX = -500.0;
					if( posY < SCREEN_HEIGHT-SIZE_MAINCHAR ) speedX = speedX/2;
					break;
				case SDLK_RIGHT:
					speedX = 500.0;
					if( posY < SCREEN_HEIGHT-SIZE_MAINCHAR ) speedX = speedX/2;
					break;
				
				default: break;
			}
		}
	else if (event.type == SDL_KEYUP)
		{
			switch( event.key.keysym.sym )
			{
				case SDLK_LEFT:
					if( posY < SCREEN_HEIGHT-SIZE_MAINCHAR )
					{
						speedX = speedX/2;
					}
					else speedX = 0;
				break;
				
				case SDLK_RIGHT:
					if( posY < SCREEN_HEIGHT-SIZE_MAINCHAR )
						{
							speedX = speedX/2;
						}
						else speedX = 0;
				break;
				default: break;
			}
		}

}
	return true;
}	
