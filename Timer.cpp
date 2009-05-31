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

int Timer::getTicks()
{
	if ( paused )
	{
		return pausedTicks - ticks;
	}
	else
	{
	  int temptick = 0;
	  temptick = SDL_GetTicks() - ticks;
	  if(temptick <= 0) return 0;
	  else return temptick;
    }
	
	
}

void Timer::reset()
{
	ticks = SDL_GetTicks();
	pausedTicks = SDL_GetTicks();
}

Timer::Timer()
{
	paused = true;
	started = false;
	ticks = 0;
	pausedTicks = 0;
}

void Timer::pause()
{
	paused = true;
	pausedTicks = SDL_GetTicks();
}

void Timer::resume()
{
	if ( paused )
	{
		paused = false;
		ticks = ticks - pausedTicks + SDL_GetTicks();
	}
}

void Timer::start()
{
	if (!started)
	{
	paused = false;
	started = true;
	ticks = SDL_GetTicks();
	}
}

bool Timer::isPaused()
{
	if ( paused ) return true;
	else return false;
}


