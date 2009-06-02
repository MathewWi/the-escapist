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

SDL_Surface* load_image(std::string file)
{
	SDL_Surface *loadedImage = NULL;
	loadedImage = IMG_Load(file.c_str());

    if( loadedImage != NULL) return loadedImage;
	else return NULL;
}

bool init(std::string caption)
{
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1){
		return false;
	}
	
    SDL_WM_SetCaption(caption.c_str(), NULL);
	
	return true;
}

SDL_Surface* load_files(std::string picsource)
{
    
    SDL_Surface *source = load_image( picsource );
    
    if( source == NULL )
    {
        return NULL;    
    }
    
    return source;    
}

void clean_up(SDL_Surface* source)
{
    
    SDL_FreeSurface( source );
  
}

void updateCaption(int frames, int ticks)
{
	float fps = (float)frames/(float)ticks*1000.0;
	std::ostringstream screen;
	screen << "FPS: " << fps << "  ||  " << "Frames: " << frames << "  ||  " << "MS: " << ticks;
	
	SDL_WM_SetCaption((screen.str()).c_str(), NULL);
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect spriteOffset )
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface( source, &spriteOffset, destination, &offset );
}

