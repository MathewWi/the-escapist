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
}

Obstacle::Obstacle(std::string file)
{
	x = 0;
	y = 0;
	sprite = load_image(file);
}

Obstacle::Obstacle(int posX, int posY, std::string file)
{
	x = posX;
	y = posY;
	sprite = load_image(file);
}

//int Obstacle::getNumberOfCollitionZones()
//{
//	return sizeof collitionZones / sizeof collitionZones*;
//}
