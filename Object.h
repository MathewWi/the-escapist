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


#include <SDL/SDL.h>
#include "init.h"
#include "main.h"


class Object
{
protected:
	float posX;
	float posY;
	float speedX;
	float speedY;
	
public:
	SDL_Surface **awesome;
	SDL_Surface **sadface;
	Object();
	~Object();
    Object(int, int, float, float);
	float getSpeedX();
	float getSpeedY();
	int getX();
	int getY();
	
	void setX(int);
	void setY(int);
	void changeSpeedX(float);
	void changeSpeedY(float);
	void setSpeedX(float);
	void setSpeedY(float);
	void checkCollision();
	void blit(SDL_Surface*);
	void updateCo(int, float);
};
