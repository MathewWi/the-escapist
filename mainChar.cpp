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
//#define length(a) (sizeof a / sizeof a[0])

#include "mainChar.h"
#include "obstacle.h"

MainChar::MainChar(int x, int y, float s_x, float s_y)
{
	posX = x;
	posY = y;
	speedX = s_x;
	speedY = s_y;
	
	stopped = false;
	grounded = false;
	
}

MainChar::MainChar()
{
	speedX = 10;
	speedY = 10;
	
	stopped = false;
	grounded = false;
	
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
	offset.x = (int)posX + offsetX;
	offset.y = (int)posY + offsetY;
	
	SDL_BlitSurface( charSprite, NULL, screen, &offset );
}

void MainChar::checkCollision(Obstacle* objects)
{
	Uint8 *keystates = SDL_GetKeyState( NULL );
	
	if( (int)posY < MAP_HEIGHT-SIZE_MAINCHAR ) stopped = false;
	
	if ( (int)posX >= MAP_WIDTH-SIZE_MAINCHAR )
	{
		 speedX = -speedX*SURFACE_HARDNESS_WALL;
		 posX = MAP_WIDTH-SIZE_MAINCHAR;
		 
	}
	else if ( posX <= 0 )
	{
		speedX = -speedX*SURFACE_HARDNESS_WALL;
		posX = 0.0;
	}
	if ( (int)posY >= MAP_HEIGHT-SIZE_MAINCHAR )
	{
		
		if( speedY >= 0.0)
		{
		speedY = 0.0;
		posY = MAP_HEIGHT-SIZE_MAINCHAR;
		grounded = true;
			
		}
		
		if ( !stopped )
		{
			
			if( !keystates[ SDLK_LEFT ] && !keystates[ SDLK_RIGHT ])
			{ 
				speedX = 0.0;
				stopped = true;
				
			}
		}
		
		
	}
	else if ( (int)posY <= 0 )
	{ 
		speedY = -speedY*SURFACE_HARDNESS_GROUND;
		posY = 0;
		
	}
	
	// check with objects
	SDL_Rect collitionArea;
	
	for( int a = 0; a < Obstacle::numberOfObjects; a++)
	{
		collitionArea = objects[a].getCollitionAreas(0);
		if( posX + SIZE_MAINCHAR > collitionArea.x && posX < collitionArea.x + collitionArea.w && posY + SIZE_MAINCHAR > collitionArea.y && posY < collitionArea.y + collitionArea.h )
		{
			if( posX + SIZE_MAINCHAR/2 >= collitionArea.x && posX + SIZE_MAINCHAR/2 <= collitionArea.x + collitionArea.w && posY < collitionArea.y )
			{
				if( speedY >= 0.0)
				{
					speedY = 0.0;
					posY = collitionArea.y-SIZE_MAINCHAR;
					grounded = true;
			
				}
		
				if ( !stopped )
				{
					keystates = SDL_GetKeyState( NULL );
					if( !keystates[ SDLK_LEFT ] && !keystates[ SDLK_RIGHT ])
					{ 
						speedX = 0.0;
						stopped = true;
					}
				}
			}
			else if( posX + SIZE_MAINCHAR/2 >= collitionArea.x && posX + SIZE_MAINCHAR/2 <= collitionArea.x + collitionArea.w && posY > collitionArea.y + collitionArea.h )
			{
				speedX = -speedX*SURFACE_HARDNESS_WALL;
				posX = collitionArea.x - SIZE_MAINCHAR;
			}
			else 
			{
				speedY = -speedY*SURFACE_HARDNESS_GROUND;
				posY = collitionArea.y + collitionArea.h;
			}
		}
	
	}

}


MainChar::~MainChar()
{
	
}

void MainChar::updateCo(int ticks, float force)
{
	
	posX += speedX * (float)ticks/1000;
	posY += speedY * (float)ticks/1000;
	if (posX > MAP_WIDTH-SIZE_MAINCHAR) posX = MAP_WIDTH-SIZE_MAINCHAR;
	else if (posX < 0) posX = 0;

	if (posY > MAP_HEIGHT-SIZE_MAINCHAR) posY = MAP_HEIGHT-SIZE_MAINCHAR;
	else if (posY < 0) posY = 0;
	//posX += 1;
	//posY += 1;
	speedY += (float)ticks*(GRAVITY_CONS+force)/1000;
	
	
	//FIX THIS SHIT OMFG :'D
	offsetX = SCREEN_WIDTH/2 - (int)posX - SIZE_MAINCHAR/2;
	if ( (int)posX + SCREEN_WIDTH/2 + SIZE_MAINCHAR/2 > MAP_WIDTH ) offsetX += (int)posX + SCREEN_WIDTH/2 - MAP_WIDTH + SIZE_MAINCHAR/2;
	else if ( (int)posX + SIZE_MAINCHAR/2 <= SCREEN_WIDTH/2 ) offsetX = 0;
	offsetY = SCREEN_HEIGHT/2 - (int)posY - SIZE_MAINCHAR/2;
	if ( (int)posY + SIZE_MAINCHAR/2 + SCREEN_HEIGHT/2 > MAP_HEIGHT ) offsetY += (int)posY + SCREEN_HEIGHT/2 - MAP_HEIGHT + SIZE_MAINCHAR/2;
	else if ( (int)posY + SIZE_MAINCHAR/2 <= SCREEN_HEIGHT/2 ) offsetY = 0;
	
	
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
					if( grounded ) 
					speedY = -600.0;
					grounded = false;
					
					
					break;
				case SDLK_LEFT:
					speedX = -500.0;
					if( !grounded ) speedX = speedX/2;
					break;
				case SDLK_RIGHT:
					speedX = 500.0;
					if( !grounded ) speedX = speedX/2;
					break;
				
				default: break;
			}
		}
	else if (event.type == SDL_KEYUP)
		{
			switch( event.key.keysym.sym )
			{
				case SDLK_LEFT:
					if( !grounded )
					{
						speedX = speedX/2;
					}
					else speedX = 0;
				break;
				
				case SDLK_RIGHT:
					if( !grounded )
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
