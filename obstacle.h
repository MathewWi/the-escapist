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

#include "init.h"


class MainChar;

class Obstacle
{
	protected:
	
	int x;
	int y;
	
	public:
	
	static int numberOfObjects;
	
	Obstacle();
	Obstacle(std::string);
	Obstacle(int, int, std::string);
	~Obstacle();
	
	SDL_Rect *collitionZones;
	
	//int getNumberOfCollitionZones();
	
	SDL_Surface* sprite;
	
	void blitObstacle(MainChar, SDL_Surface*);
	
	void setCollitionCoords(int, SDL_Rect );
	
	int getX();
	
	int getY();
	
	void setX(int);
	
	void setY(int);
	
	SDL_Rect getCollitionAreas(int);
	
};
