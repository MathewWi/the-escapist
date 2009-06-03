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


#include "obstacle.h"

#include "mainChar.h"

void Obstacle::blitObstacle(MainChar mainchar, SDL_Surface* destination)
{
	apply_surface(x + mainchar.offsetX, y + mainchar.offsetY, sprite, destination, NULL);
}

void Obstacle::setCollitionCoords(int a, SDL_Rect offsets)
{
	collitionZones[a].x = offsets.x;
	collitionZones[a].y = offsets.y;
	collitionZones[a].w = offsets.w;
	collitionZones[a].h = offsets.h;
}

int Obstacle::getX()
{
	return x;
}

int Obstacle::getY()
{
	return y;
}

SDL_Rect Obstacle::getCollitionAreas(int a)
{
	SDL_Rect offsets;
	
	offsets.x = x + (collitionZones+a)->x;
	offsets.y = y + (collitionZones+a)->y;
	offsets.w = (collitionZones+a)->w;
	offsets.h = (collitionZones+a)->h;
	
	return offsets;
}

void Obstacle::setX(int posX)
{
	x = posX;
}

void Obstacle::setY(int posY)
{
	y = posY;
}

Obstacle::Obstacle()
{
	x = 0;
	y = 0;
	sprite = NULL;
	numberOfObjects++;
}

Obstacle::Obstacle(std::string file)
{
	x = 0;
	y = 0;
	sprite = load_image(file);
	numberOfObjects++;
}

Obstacle::Obstacle(int posX, int posY, std::string file)
{
	x = posX;
	y = posY;
	sprite = load_image(file);
	numberOfObjects++;
}

Obstacle::~Obstacle()
{
	numberOfObjects--;
}
