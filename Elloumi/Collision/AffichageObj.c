#include stdio.h
#include  stdlib.h
#include  SDLSDL.h
#include SDLSDL_image.h
#include "Obj.h"


void affichageObj ( Objet obj , SDL_Surface screen) 
{

SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));
SDL_Flip(screen);

}
