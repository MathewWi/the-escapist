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
