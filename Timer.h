#include <SDL/SDL.h>

class Timer{
public:
	int ticks;
	int pausedTicks;

	bool paused;
	bool started;

	Timer();
    
	int getTicks();

	void start();

	void pause();

	void resume();

	void reset();

	bool isPaused();
};
