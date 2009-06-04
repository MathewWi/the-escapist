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
#include <string>
#include <sstream>
#include <SDL/SDL_image.h>

SDL_Surface* load_image(std::string);

bool init(std::string);

SDL_Surface* load_files(std::string);

void clean_up(SDL_Surface*);

void updateCaption(int, int);

void apply_surface( int x, int y, SDL_Surface*, SDL_Surface*, SDL_Rect* );
