#include "init.h"

SDL_Surface* load_image(std::string file)
{
	SDL_Surface *loadedImage = NULL;
	loadedImage = IMG_Load(file.c_str());
/*	SDL_Surface *optimizedImage = NULL;
	if (loadedImage != NULL){
		optimizedImage = SDL_DisplayFormat(loadedImage);
		
		SDL_FreeSurface(loadedImage);
		
		if (optimizedImage != NULL)
		{
		return optimizedImage;
		}
		else return NULL;
	
	}
	
	
	return NULL;*/
return loadedImage;
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

