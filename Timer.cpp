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


