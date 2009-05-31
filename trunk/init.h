#include <SDL/SDL.h>
#include <string>
#include <sstream>
#include <SDL/SDL_image.h>

SDL_Surface* load_image(std::string);

bool init(std::string);

SDL_Surface* load_files(std::string);

void clean_up(SDL_Surface*);

void updateCaption(int, int);
