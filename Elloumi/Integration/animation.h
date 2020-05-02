#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>
#include "objet.h" 
#include "utility.h"
#include "depane.h" 

void setrects(SDL_Rect* clip , int LI , int HI , int frames ) ; 

void animate(SDL_Surface *screen , SDL_Surface *sprite ,SDL_Surface *sprite2,SDL_Surface *sprite3,SDL_Surface *Background , SDL_Rect positionFond ,  int running) ;  


#endif // JEU_H_INCLUDED
